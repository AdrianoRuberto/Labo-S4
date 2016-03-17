import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Observable;
import java.util.Observer;

/**
 * Created by matthieu.villard on 11.03.2016.
 */
public class WatchView extends JFrame implements Observer
{
    private int minutes = 0;       	// Compteurs de la pendule
    private int seconds = 0;
    private int hours = 0;
    private static int SIZE = 100; // Taille de la demi-fenétre
    private Canvas canvas;
    private Label lbl;
    private JButton addMinute;

    //------------------------------------------------------------------------
    class Canvas extends JPanel {

        public Canvas() {
            setBackground(Color.white);
        }

        public void paintComponent (Graphics g) {
            super.paintComponent(g);
            drawNeedles(g);
        }

        public Dimension getPreferredSize() {
            return new Dimension (2 * SIZE, 2 * SIZE);
        }

        public void drawNeedles(Graphics g) {
            // calculer les coordonnées des aiguilles
            int cosxm = (int)(SIZE + (SIZE / 2)*
                    Math.cos(2*((double)minutes/60*Math.PI - Math.PI/4)));
            int sinym = (int)(SIZE + (SIZE / 2)*
                    Math.sin(2*((double)minutes/60*Math.PI - Math.PI/4)));
            int cosxh = (int)(SIZE + (SIZE/4)*
                    Math.cos(2*((double)hours/12*Math.PI - Math.PI/4)));
            int sinyh = (int)(SIZE+(SIZE/4)*
                    Math.sin(2*((double)hours/12*Math.PI - Math.PI/4)));

            g.setColor(Color.red);
            g.drawLine(SIZE,SIZE,
                    (int)(SIZE + (SIZE-20.0)*
                            Math.cos(2*((double)seconds/60*Math.PI - Math.PI/4))),
                    (int) (SIZE+(SIZE-20)*
                            Math.sin(2*((double)seconds/60*Math.PI - Math.PI/4))));

            g.setColor(Color.blue);
            g.drawLine(SIZE,SIZE,cosxm,sinym);
            g.drawLine(SIZE,SIZE,cosxh,sinyh);
        }
    }

    //------------------------------------------------------------------------
    public WatchView (String name, int posX, int posY) {

        canvas = new Canvas();
        lbl = new Label("00:00:00");
        addMinute = new JButton("+");
        addMinute.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                minutes++;
                refresh();
            }
        });
        setTitle(name);
        getContentPane().add (canvas, BorderLayout.CENTER);
        getContentPane().add(lbl, BorderLayout.SOUTH);
        getContentPane().add(addMinute, BorderLayout.NORTH);

        pack();
        setResizable(false);
        setLocation (posX, posY);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    public void update(Observable o, Object arg) {
        if (o instanceof  Watch)  {
            Watch  watch = (Watch)o;
            hours = watch.getHours();
            minutes = watch.getMinutes();
            seconds = watch.getSeconds();
            refresh();
        }
    }

    private void refresh(){
        canvas.repaint();
        lbl.setText(String.format("%02d", hours) + ":" + String.format("%02d", minutes) + ":" + String.format("%02d", seconds));
    }
}
