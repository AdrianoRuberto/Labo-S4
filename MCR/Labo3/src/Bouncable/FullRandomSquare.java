package Bouncable;

import Renderer.FillRenderer;
import Renderer.Renderable;

import java.awt.*;

public class FullRandomSquare extends RandomSquare {

   public FullRandomSquare() { super(); }

   @Override
   public Renderable getRenderable() { return FillRenderer.getInstance(); }

   @Override
   public Color getColor() { return Color.ORANGE; }
}
