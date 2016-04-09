package Renderable;

import Bouncable.Bouncable;

import java.awt.*;

public class BorderRenderer implements Renderable {
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
