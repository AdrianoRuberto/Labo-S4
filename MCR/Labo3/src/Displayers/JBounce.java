package Displayers;

import Bouncable.Bouncable;
import Factory.*;
import Renderable.*;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.concurrent.ConcurrentLinkedQueue;

public class JBounce extends JFrame implements Displayer, KeyListener {

   private ConcurrentLinkedQueue<Bouncable> bouncers = new ConcurrentLinkedQueue<>();

   public JBounce() {
	  setPreferredSize(new Dimension(500, 500));
	  requestFocus();


	  pack();
	  setVisible(true);
	  addKeyListener(this);
   }

   @Override
   public Graphics2D getGraphics() {
	  return (Graphics2D) super.getGraphics();
   }

   @Override
   public void repaint() {
	  super.repaint();
	  for (Bouncable b : bouncers)
		 b.draw();
   }

   public void update() {
	  for (Bouncable b : bouncers)
		 b.move();
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
			bouncers = new ConcurrentLinkedQueue<>();
			break;
		 case KeyEvent.VK_B: // Génère 10 cercles et 10 carres possédant une bordure.
			for (int i = 0; i < 10; ++i) {
			   bouncers.add(CircleFactory.generate(BorderRenderer.getInstance(), this));
			   bouncers.add(SquareFactory.generate(BorderRenderer.getInstance(), this));
			}
			break;
		 case KeyEvent.VK_F: // générer 10 cercles et 10 pleins
			for(int i = 0; i < 10; ++i){
			   bouncers.add(CircleFactory.generate(FillRenderer.getInstance(), this));
			   bouncers.add(SquareFactory.generate(FillRenderer.getInstance(), this));
			}
			break;
		 case KeyEvent.VK_Q: // Quitter le programme
			System.exit(0);
			break;
	  }
   }

   @Override
   public void keyReleased(KeyEvent e) {

   }

}
