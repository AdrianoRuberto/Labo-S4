import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Observable;
import java.util.Observer;

/**
 * @author Adriano Ruberto
 * @author Matthieu Villard
 * @version 1.0
 */

public class WatchView extends JFrame implements Observer {
   private static int SIZE = 100; // Taille de la demi-fenétre
   private Canvas canvas;
   private Label lbl;
   private JButton addMinute;
   private Watch watch;

   //------------------------------------------------------------------------
   public WatchView(Watch watch, String name, int posX, int posY) {
	  this.watch = watch;

	  canvas = new Canvas();
	  lbl = new Label("00:00:00");
	  addMinute = new JButton("+");

	  addMinute.addActionListener(new ActionListener() {
		 public void actionPerformed(ActionEvent e) {
			watch.incrementMinutes();
			refresh();
		 }
	  });

	  setTitle(name);
	  getContentPane().add(canvas, BorderLayout.CENTER);
	  getContentPane().add(lbl, BorderLayout.SOUTH);
	  getContentPane().add(addMinute, BorderLayout.NORTH);

	  pack();
	  setResizable(false);
	  setLocation(posX, posY);
	  setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	  setVisible(true);
   }

   public void update(Observable o, Object arg) {
	  refresh();
   }

   private void refresh() {
	  canvas.repaint();
	  lbl.setText(String.format("%02d", watch.getHours()) + ":" + String.format("%02d", watch.getMinutes()) + ":" +
				  String.format("%02d", watch.getSeconds()));
   }

   //------------------------------------------------------------------------
   class Canvas extends JPanel {

	  public Canvas() {
		 setBackground(Color.white);
	  }

	  public void paintComponent(Graphics g) {
		 super.paintComponent(g);
		 drawClockHand(g);

	  }

	  public void drawClockHand(Graphics g){

		 int cosxm = (int) (SIZE + (SIZE / 2) * Math.cos(2 * ((double) watch.getMinutes() / 60 * Math.PI - Math.PI / 4)));
		 int sinym = (int) (SIZE + (SIZE / 2) * Math.sin(2 * ((double) watch.getMinutes() / 60 * Math.PI - Math.PI / 4)));
		 int cosxh = (int) (SIZE + (SIZE / 4) * Math.cos(2 * ((double) watch.getHours() / 12 * Math.PI - Math.PI / 4)));
		 int sinyh = (int) (SIZE + (SIZE / 4) * Math.sin(2 * ((double) watch.getHours() / 12 * Math.PI - Math.PI / 4)));
		 g.setColor(Color.red);
		 g.drawLine(SIZE, SIZE,
					(int) (SIZE + (SIZE - 20.0) * Math.cos(2 * ((double) watch.getSeconds() / 60 * Math.PI - Math.PI / 4))),
					(int) (SIZE + (SIZE - 20) * Math.sin(2 * ((double) watch.getSeconds() / 60 * Math.PI - Math.PI / 4))));
		 g.setColor(Color.blue);
		 g.drawLine(SIZE, SIZE, cosxm, sinym);
		 g.drawLine(SIZE, SIZE, cosxh, sinyh);
	  }

	  public Dimension getPreferredSize() {
		 return new Dimension(2 * SIZE, 2 * SIZE);
	  }
   }
}
