package Bouncable;

import Renderer.Renderable;

import java.awt.*;
import java.awt.geom.Rectangle2D;

public class Square extends Form {

   private Rectangle2D.Double square;

   public Square(Renderable renderable, Color color, Point position, Point movement, int size) {
	  super(renderable, color, position, movement, size);
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
