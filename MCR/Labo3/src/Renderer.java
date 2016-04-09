import java.awt.*;

class FillRenderer implements Renderable {

   private static FillRenderer instance;

   private FillRenderer() {}

   public static FillRenderer getInstance() {
	  if (instance == null) instance = new FillRenderer();
	  return instance;
   }

   @Override
   public void display(Graphics2D g, Bouncable b) {
	  g.setColor(b.getColor());
	  Shape s = b.getShape();
	  g.fill(s);
	  g.draw(s);
   }
}

class BorderRenderer implements Renderable {
   private static BasicStroke bs = new BasicStroke(2);
   private static BorderRenderer instance;

   private BorderRenderer() {}

   public static BorderRenderer getInstance() {
	  if (instance == null) instance = new BorderRenderer();
	  return instance;
   }

   @Override
   public void display(Graphics2D g, Bouncable b) {
	  g.setColor(b.getColor());
	  g.setStroke(bs);
	  g.draw(b.getShape());
   }
}
