package Bouncable;

import Renderer.FillRenderer;
import Renderer.Renderable;

import java.awt.*;

public class FullRandomCircle extends RandomCircle {

   public FullRandomCircle() { super(); }

   @Override
   public Renderable getRenderable() { return FillRenderer.getInstance(); }

   @Override
   public Color getColor() { return Color.BLUE; }
}
