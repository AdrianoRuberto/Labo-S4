/**
 * Représente une vue (fenêtre) avec un/des chronomètre(s)
 *
 * @author Adriano Ruberto
 * @author Matthieu Villard
 * @version 1.0
 */

import javax.swing.*;
import java.awt.*;
import java.awt.event.ComponentAdapter;
import java.awt.event.ComponentEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class JClockView extends JFrame {

   JChrono[] jChronos;

   public JClockView(JChrono[] jChronos, String name) {
	  super(name);
	  this.jChronos = jChronos;
	  addWindowListener(new WindowAdapter() {
		 @Override
		 public void windowClosing(WindowEvent e) {
			// Détache chaques chronomètres de leur chrono
			for (JChrono jChrono : jChronos)
			   jChrono.getChrono().detach(jChrono);
		 }
	  });

	  addComponentListener(new ComponentAdapter() {
		 @Override
		 public void componentResized(ComponentEvent e) {
			Dimension d = e.getComponent().getSize();

			int size = (int)Math.min(d.getWidth() / jChronos.length, d.getHeight() / jChronos.length);
			resizeChronos(new Dimension(size, size));
		 }
	  });

	  JPanel panel = new JPanel();
	  panel.setLayout(new FlowLayout());
	  getContentPane().add(panel);

	  for (JChrono jChrono : jChronos)
		 panel.add(jChrono);

	  setVisible(true);
	  pack();
   }

   public JClockView(JChrono jChrono, String name) {
	  this(new JChrono[]{jChrono}, name);
   }

   /**
	* Resize chaque horloge de la vue
	*
	* @param d la nouvelle dimension pour les horloges
	*/
   public void resizeChronos(Dimension d) {
	  for (JChrono jChrono : jChronos)
		 jChrono.setSize(d);
   }
}

/**
 * Représente une vue avec les chronomètres Roman, Arabic et Digital
 */
class MixteClockView extends JClockView {
   public MixteClockView(Chrono chrono) {
	  super(new JChrono[]{new RomanChrono(chrono), new ArabicChrono(chrono), new DigitalChrono(chrono)},
			"Horloge Mixte");
   }

   // Pour ne pas resize les horloges dans une mixte
   public void resizeChronos(Dimension d) { }
}

/**
 * Représente une vue avec le chronomètre Roman
 */
class RomanClockView extends JClockView {
   public RomanClockView(Chrono chrono) {super(new RomanChrono(chrono), "Horloge Romaine"); }
}

/**
 * Représente une vue avec le chronomètre Arabic
 */
class ArabicClockView extends JClockView {
   public ArabicClockView(Chrono chrono) {
	  super(new ArabicChrono(chrono), "Horloge Arabe");
   }
}

/**
 * Représente une vue avec le chronomètre Digital
 */
class DigitalClockView extends JClockView {
   public DigitalClockView(Chrono chrono) {
	  super(new DigitalChrono(chrono), "Horloge Numérique");
   }
}