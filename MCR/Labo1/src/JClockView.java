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

public abstract class JClockView extends JFrame {

   public JClockView(JChrono[] jChronos, String name) {
	  super(name);

	  addWindowListener(new WindowAdapter() {
		 @Override
		 public void windowClosing(WindowEvent e) {
			// Détache chaques chronomètres de leur chrono
			for (JChrono jChrono : jChronos)
			   jChrono.getChrono().detach(jChrono);
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
}

/**
 * Représente une vue avec les chronomètres Roman, Arabic et Digital
 */
class MixteClockView extends JClockView {
   public MixteClockView(Chrono chrono) {
	  super(new JChrono[]{new RomanChrono(chrono), new ArabicChrono(chrono), new DigitalChrono(chrono)},
			"Horloge Mixte");
   }
}

/**
 * Représente une vue avec un chronomètre analogique
 */
abstract class AnalogicClockView extends JClockView {

   public AnalogicClockView(JChrono jChrono, String name) {
	  super(jChrono, name);

	  addComponentListener(new ComponentAdapter() {
		 @Override
		 public void componentResized(ComponentEvent e) {
			jChrono.setSize(getContentPane().getSize());
		 }
	  });
   }
}

/**
 * Représente une vue avec le chronomètre Roman
 */
class RomanClockView extends AnalogicClockView {
   public RomanClockView(Chrono chrono) {super(new RomanChrono(chrono), "Horloge Romaine"); }
}

/**
 * Représente une vue avec le chronomètre Arabic
 */
class ArabicClockView extends AnalogicClockView {
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