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

		 // On met le point [0,0] au centre de la montre
		 g.translate(SIZE, SIZE);

		 // On dessine les aiguilles
		 Graphics2D g2 = (Graphics2D) g;
		 drawClockHand(g2, watch.getHours(), 12, 5, 2 * SIZE / 7, Color.BLACK);
		 drawClockHand(g2, watch.getMinutes(), 60, 3, 2 * SIZE / 5, Color.BLUE);
		 drawClockHand(g2, watch.getSeconds(), 60, 1, 2 * SIZE / 3, Color.RED);
	  }

	  public Dimension getPreferredSize() {
		 return new Dimension(2 * SIZE, 2 * SIZE);
	  }


	  /**
	   * Permet de dessiner une aiguille d'une horloge depuis le point [0,0]
	   *
	   * @param g      Sur quel graphics dessiner
	   * @param time   Le temps
	   * @param max    Sur combien de temps doit être compté le temps
	   * @param width  La largeur de l'aiguille
	   * @param length La longueur de l'aiguille
	   * @param color  La couleur de l'aiguille
	   */
	  private void drawClockHand(Graphics2D g, double time, int max, int width, int length, Color color) {
		 double angle = (time / max) * 2 * Math.PI;
		 g.setStroke(new BasicStroke(width));
		 g.setColor(color);
		 g.drawLine(0, 0, (int) (Math.sin(angle) * length), (int) (-Math.cos(angle) * length));
	  }
   }
}
