package Bouncable;

import Renderable.Renderable;
import Displayers.*;

import java.awt.*;
import java.awt.geom.Ellipse2D;

public class Circle extends Form {

   private Ellipse2D.Double circle;

   public Circle(Renderable renderable, Displayer displayer, Color color, Point position, Point movement, double rayon) {
	  super(renderable, displayer, color, position, movement);
	  circle = new Ellipse2D.Double(position.x, position.y, rayon, rayon);
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
