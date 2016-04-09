package Bouncable;

import Renderable.Renderable;
import Displayers.Displayer;

import java.awt.*;
import java.util.Random;


public abstract class Form implements Bouncable {

   private final static int MAX_SPEED = 10;
   protected static Random rand = new Random();
   private final Color color;
   private final Renderable renderer;
   private final Displayer displayer;

   protected Point position;
   protected Point movement = new Point(1 + rand.nextInt(MAX_SPEED), 1 + rand.nextInt(MAX_SPEED));

   public Form(Renderable renderer, Displayer displayer, Color color, Point position) {
	  this.color = color;
	  this.position = position;
	  this.renderer = renderer;
	  this.displayer = displayer;
   }

   public Form(Renderable renderer, Displayer displayer) {
	  this(renderer, displayer, new Color(rand.nextInt()),
		   new Point(rand.nextInt(displayer.getWidth()), rand.nextInt(displayer.getHeight())));
   }

   @Override
   public void draw() {
	  renderer.display(displayer.getGraphics(), this);
   }

   @Override
   public void move() {

	  // Set la nouvelle position
	  position.x += movement.x;
	  position.y += movement.y;

	  // Requillibrage si on est sorti de l'écran
	  if (position.x < 0 || position.x > displayer.getWidth()) {
		 movement.x = -movement.x;
		 position.x = (position.x < 0 ? 0 : displayer.getWidth());
	  }
	  if (position.y < 0 || position.y > displayer.getHeight()) {
		 movement.y = -movement.y;
		 position.y = (position.y < 0 ? 0 : displayer.getHeight());
	  }
   }

   @Override
   public Color getColor() { return color; }

   @Override
   public Renderable getRenderer() { return renderer; }
}