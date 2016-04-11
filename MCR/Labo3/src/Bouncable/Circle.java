package Bouncable;

import Renderer.Renderable;

import java.awt.*;
import java.awt.geom.Ellipse2D;

public class Circle extends Form {

   private Ellipse2D.Double circle;

   public Circle(Renderable renderable, Color color, Point position, Point movement, int radius) {
	  super(renderable, color, position, movement, radius);
	  circle = new Ellipse2D.Double(position.x, position.y, radius, radius);
   }

   public void move() {
	  super.move();
	  circle.x = position.x;
	  circle.y = position.y;
   }

   @Override
   public Shape getShape() {
	  return circle;
   }
}
