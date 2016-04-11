package Bouncable;

import java.awt.*;
import java.awt.geom.Ellipse2D;

public abstract class RandomCircle extends RandomForm {

   private Ellipse2D.Double circle = new Ellipse2D.Double(position.x, position.y, size, size);

   public RandomCircle() { super(); }

   public void move() {
	  super.move();
	  circle.x = position.x;
	  circle.y = position.y;
   }

   @Override
   public Shape getShape() { return circle; }
}
