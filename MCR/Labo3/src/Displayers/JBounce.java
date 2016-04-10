package Displayers;

import Bouncable.Bouncable;

import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyAdapter;
import java.util.concurrent.ConcurrentLinkedQueue;

public class JBounce extends JFrame implements Displayer {

   private static JBounce instance;
   private ConcurrentLinkedQueue<Bouncable> bouncers = new ConcurrentLinkedQueue<>();

   private JBounce() {
	  setPreferredSize(new Dimension(500, 500));
	  requestFocus();
	  setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	  pack();
	  setVisible(true);
   }

   public static JBounce getInstance() {
	  if (instance == null) instance = new JBounce();
	  return instance;
   }

   @Override
   public Graphics2D getGraphics() {
	  return (Graphics2D) super.getGraphics();
   }

   @Override
   public void repaint() {
	  super.repaint();
	  for (Bouncable b : bouncers)
		 b.getRenderable().display(getGraphics(), b);

   }

   public void update() {
	  for (Bouncable b : bouncers)
		 b.move();
   }

   @Override
   public void addKeyListener(KeyAdapter ka) {
	  super.addKeyListener(ka);
   }

   public ConcurrentLinkedQueue<Bouncable> getBouncers() {return bouncers;}

   public void setBouncers(ConcurrentLinkedQueue<Bouncable> bouncers) {this.bouncers = bouncers;}

}
