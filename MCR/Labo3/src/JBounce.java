import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.LinkedList;

public class JBounce extends JFrame implements Displayer, KeyListener {

   private LinkedList<Bouncable> bouncers = new LinkedList<>();


   public JBounce() {
	  setPreferredSize(new Dimension(500, 500));
	  requestFocus();

	  pack();
	  setVisible(true);
	  addKeyListener(this);
   }

   @Override
   public int getWidth() {
	  return 200;
   }

   @Override
   public int getHeight() {
	  return 200;
   }

   @Override
   public Graphics2D getGraphics() {
	  return null;
   }

   @Override
   public void repaint() {
	  for (Bouncable b : bouncers)
		 b.draw();
   }

   public void update() {
	  for (Bouncable b : bouncers)
		 b.move();
   }

   @Override
   public void setTitle(String s) {

   }

   @Override
   public void addKeyListener(KeyAdapter ka) {
	  super.addKeyListener(ka);
   }

   @Override
   public void keyTyped(KeyEvent e) {

   }

   @Override
   public void keyPressed(KeyEvent e) {
	  switch (e.getKeyCode()) {
		 case KeyEvent.VK_E: // Efface l'affichage
			bouncers = new LinkedList<>();
			break;
		 case KeyEvent.VK_B: // Génère 10 cercles et 10 carres possédant une bordure.
			break;
		 case KeyEvent.VK_F: // générer 10 cercles et 10 pleins
			break;
		 case KeyEvent.VK_Q: // Quitter le programme
			break;
	  }
   }

   @Override
   public void keyReleased(KeyEvent e) {

   }

}
