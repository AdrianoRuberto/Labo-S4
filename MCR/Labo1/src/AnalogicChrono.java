/**
 * Représente la partie graphique d'un chronomètre analogique
 * <p>
 * Labo
 *
 * @author Adriano Ruberto
 * @author Matthieu Villard
 * @version 1.0
 */

import javax.imageio.ImageIO;
import java.awt.*;
import java.io.File;
import java.io.IOException;

public class AnalogicChrono extends JChrono {

   private int clockSize = 200;
   private Image img;

   public AnalogicChrono(Chrono chrono, String pathFile) {
	  super(chrono);

	  setPreferredSize(new Dimension(clockSize, clockSize));
	  setLayout(new FlowLayout(FlowLayout.CENTER));

	  // Lis l'image et la resize
	  try {
		 img = ImageIO.read(new File(pathFile)).getScaledInstance(clockSize, clockSize, 0);
	  } catch (IOException e) {
		 e.printStackTrace();
	  }

   }

   @Override
   public void update() { repaint(); }

   @Override
   public void paint(Graphics g) {
	  super.paint(g);

	  g.drawImage(img, 0, 0, null);

	  // On met le point [0,0] au centre de la montre
	  g.translate(clockSize / 2, clockSize / 2);

	  Graphics2D gr = (Graphics2D) g;

	  // On dessine les aiguilles
	  int size = Math.min(clockSize, clockSize);
	  drawClockHand(gr, getChrono().getHour(), 12, 7, size / 7, Color.BLACK);
	  drawClockHand(gr, getChrono().getMin(), 60, 5, size / 5, Color.BLUE);
	  drawClockHand(gr, getChrono().getSec(), 60, 3, size / 3, Color.RED);
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

   @Override
   public void setSize(Dimension d) {
	  setPreferredSize(d);
	  clockSize = (int) Math.min(d.getHeight() - 40, d.getWidth());
	  img = img.getScaledInstance(clockSize, clockSize, Image.SCALE_SMOOTH);
   }
}

/**
 * Représente un chrono avec des chiffres arabes
 */
class ArabicChrono extends AnalogicChrono {
   public ArabicChrono(Chrono chrono) {
	  super(chrono, "img/clock2.jpg");
   }
}

/**
 * Représente un chrono avec des chiffres romains
 */
class RomanChrono extends AnalogicChrono {
   public RomanChrono(Chrono chrono) {
	  super(chrono, "img/clock1.jpg");
   }
}