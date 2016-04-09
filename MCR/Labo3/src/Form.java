import java.awt.*;
import java.awt.geom.Rectangle2D;
import java.util.Random;

public abstract class Form implements Bouncable {

   private final static int MAX_SPEED = 1;
   protected static Random rand = new Random();
   private final Color color;
   private final Renderable renderer;
   private final Displayer displayer;

   protected Point position;
   protected Point movement = new Point(1 + rand.nextInt(MAX_SPEED), 1 + rand.nextInt(MAX_SPEED));

   public Form(Color color, Point position, Renderable renderer, Displayer displayer) {
	  this.color = color;
	  this.position = position;
	  this.renderer = renderer;
	  this.displayer = displayer;
   }

   @Override
   public void draw() {
	  renderer.display(displayer.getGraphics(), this);
   }

   @Override
   public void move() {
	  if(position.x + movement.x < 0 || position.x + movement.x > displayer.getWidth()) movement.x *= -1;
	  if(position.y + movement.y < 0 || position.y + movement.y > displayer.getHeight()) movement.y *= -1;
	  position.x += movement.x;
	  position.y += movement.y;
   }

   @Override
   public Color getColor() { return color; }

   @Override
   public Renderable getRenderer() { return renderer; }
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

class Square extends Form {

   private Rectangle2D.Double square;

   public Square(Renderable renderer, Displayer displayer) {
	  this(new Color(rand.nextInt()), renderer, displayer, new Point(rand.nextInt(500), rand.nextInt(500)),
		   rand.nextDouble() * 20);
   }

   public Square(Color color, Renderable renderer, Displayer displayer, Point pos, double size) {
	  super(color, pos, renderer, displayer);
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