package Bouncable;

import Displayers.Displayer;
import Renderable.Renderable;

import java.awt.*;
import java.awt.geom.Rectangle2D;

public class Square extends Form {

   private Rectangle2D.Double square;

   public Square(Renderable renderable, Displayer displayer, Color color, Point position, Point movement, double size) {
	  super(renderable, displayer, color, position, movement);
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
