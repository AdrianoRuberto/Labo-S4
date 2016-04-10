package Bouncable;

import Displayers.Displayer;
import Renderable.Renderable;

import java.awt.*;


public abstract class Form implements Bouncable {

   private final Color color;
   private final Renderable renderable;
   private final Displayer displayer;

   protected Point position;
   protected Point movement;

   public Form(Renderable renderable, Displayer displayer, Color color, Point position, Point movement) {
	  this.color = color;
	  this.position = position;
	  this.renderable = renderable;
	  this.displayer = displayer;
	  this.movement = movement;

   }

   @Override
   public void draw() {
	  renderable.display(displayer.getGraphics(), this);
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

   public Renderable getRenderable() { return renderable; }
}