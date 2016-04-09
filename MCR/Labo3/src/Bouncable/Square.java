package Bouncable;

import Displayers.Displayer;
import Renderable.Renderable;

import java.awt.*;
import java.awt.geom.Rectangle2D;

public class Square extends Form {

   private Rectangle2D.Double square;

   public Square(Renderable renderer, Displayer displayer) {
	  super(renderer, displayer);
	  double size = rand.nextDouble() * 50;
	  square = new Rectangle2D.Double(position.x, position.y, size, size);
   }

   @Override
   public void move() {
	  super.move();
	  square.x = position.x;
	  square.y = position.y;
   }

   @Override
   public Shape getShape() {
	  return square;
   }
}
