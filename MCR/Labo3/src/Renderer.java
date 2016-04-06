import java.awt.*;

class FillRenderer implements Renderable {

   @Override
   public void display(Graphics2D g, Bouncable b) {
	  g.setColor(b.getColor());
	  Shape s = b.getShape();
	  g.fill(s);
	  g.draw(s);
   }
}

class BorderRenderer implements Renderable {
   @Override
   public void display(Graphics2D g, Bouncable b) {
	  g.setColor(b.getColor());
	  g.draw(b.getShape());
   }
}
