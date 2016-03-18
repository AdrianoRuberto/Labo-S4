import javax.swing.*;
import java.awt.*;
import java.util.Observable;
import java.util.Observer;

/**
 * @author Adriano Ruberto
 * @author Matthieu Villard
 * @version 1.0
 */
public class ClockView extends JFrame implements Observer {
   private final static int LARGEUR = 100;        // largeur fenêtre de l'emetteur
   private final static int HAUTEUR = 100;        // hauteur fenêtre de l'emetteur

   private JLabel displayField = new JLabel("00");
   private Font fonte = new Font("TimeRoman", Font.BOLD, 80);

   // Constructeur
   public ClockView(int posX, int posY) {
	  getContentPane().add("North", displayField);
	  displayField.setSize(LARGEUR, HAUTEUR);
	  displayField.setFont(fonte);
	  setTitle("Emetteur");

	  pack();
	  setLocation(posX, posY);
	  setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	  setVisible(true);
   }

   public void update(Observable o, Object arg) {
	  if (o instanceof Clock) {
		 Clock clock = (Clock) o;
		 displayField.setText(String.valueOf(clock.getDuration()));
	  }
   }
}
