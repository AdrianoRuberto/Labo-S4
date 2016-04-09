package Renderable;

import Bouncable.Bouncable;

import java.awt.*;

public class FillRenderer implements Renderable {

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
