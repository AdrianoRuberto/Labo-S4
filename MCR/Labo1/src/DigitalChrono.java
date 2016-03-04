/**
 * Représente la partie graphique d'un chrono digital
 *
 * @author Adriano Ruberto
 * @author Matthieu Villard
 * @version 1.0
 */

import java.awt.*;

public class DigitalChrono extends JChrono {

   private Label label = new Label();

   public DigitalChrono(Chrono chrono) {
	  super(chrono);

	  add(label, BorderLayout.CENTER);
	  update();
   }

   @Override
   public void update() {
	  String secondes = String.format("%02d", (int) getChrono().getSec());
	  String minutes = String.format("%02d", (int) getChrono().getMin());
	  String hours = String.format("%02d", (int) getChrono().getHour());
	  label.setText(hours + "h " + minutes + "m " + secondes + "s");
   }
}