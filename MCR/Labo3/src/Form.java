import java.awt.*;
import java.awt.geom.Rectangle2D;
import java.util.Random;

public abstract class Form implements Bouncable {

   private final static int MAX_SPEED = 10;
   protected static Random rand = new Random();
   private final Color color;

   protected Point position = new Point();
   private Point movement = new Point(rand.nextInt(MAX_SPEED), rand.nextInt(MAX_SPEED));

   public Form(Color color) {
	  this.color = color;
   }

   @Override
   public void draw() {
	  // getRenderer().display();
   }

   @Override
   public Color getColor() {
	  return color;
   }

   @Override
   public void move() {
	  position.x += movement.x;
	  position.y += movement.y;
   }

   @Override
   public Renderable getRenderer() {
	  return null;
   }
}
/*
abstract class Circle extends Form {
   public Circle(Color color, Renderable renderer) {
	  super(color, renderer);
   }
}

class FullCircle extends Circle {
   public FullCircle(Color color, Renderable renderer) {
	  super(color, renderer);
   }

}

class BorderCircle extends Circle {

   public BorderCircle(Color color, Renderable renderer) {
	  super(color, renderer);
   }

}
*/

abstract class Square extends Form {

   protected final double width = rand.nextDouble() * 50;
   protected final double height = rand.nextDouble() * 50;

   public Square(Color color) {
	  super(color);
   }

   @Override
   public Shape getShape() {
	  return new Rectangle2D.Double(position.x, position.y, width, height);
   }
}



