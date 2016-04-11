package Bouncable;

import Displayers.Displayer;
import Displayers.JBounce;

import java.awt.*;
import java.util.Random;


public abstract class RandomForm implements Bouncable {

   private static final int MAX_SIZE = 25;
   private static final int MAX_SPEED = 10;
   private static final Displayer displayer = JBounce.getInstance();
   private static Random rand = new Random();
   protected final int size;
   protected Point position;
   private Point movement;

   public RandomForm() {
	  this.position = new Point(rand.nextInt(displayer.getWidth()), rand.nextInt(displayer.getHeight()));
	  this.movement = new Point(1 + rand.nextInt(MAX_SPEED), 1 + rand.nextInt(MAX_SPEED));
	  this.size = 1 + rand.nextInt(MAX_SIZE);
   }

   @Override
   public void draw() { getRenderable().display(displayer.getGraphics(), this); }

   @Override
   public void move() {
	  // Set la nouvelle position
	  position.x += movement.x;
	  position.y += movement.y;

	  // Requillibrage si on est sorti de l'écran
	  if (position.x < 0 || position.x + size > displayer.getWidth()) {
		 movement.x = -movement.x;
		 position.x = (position.x < 0 ? 0 : displayer.getWidth() - size);
	  }
	  if (position.y < 0 || position.y + size > displayer.getHeight()) {
		 movement.y = -movement.y;
		 position.y = (position.y < 0 ? 0 : displayer.getHeight() - size);
	  }
   }

}