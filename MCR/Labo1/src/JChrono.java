/**
 * Représente la partie graphique d'un chronomètre
 *
 * @author Adriano Ruberto
 * @author Matthieu Villard
 * @version 1.0
 */

import javax.swing.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public abstract class JChrono extends JPanel implements Observator {

   private Chrono chrono;

   public JChrono(Chrono chrono) {
	  addMouseListener(new MouseAdapter() {
		 @Override
		 public void mousePressed(MouseEvent e) {
			chrono.switchState();
		 }
	  });
	  this.chrono = chrono;
	  chrono.attach(this);
   }

   /**
	* @return le chrono
	*/
   public Chrono getChrono() { return chrono; }
}
