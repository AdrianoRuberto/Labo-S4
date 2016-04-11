package Bouncable;

import Renderer.BorderRenderer;
import Renderer.Renderable;

import java.awt.*;

public class BorderRandomCircle extends RandomCircle {

   public BorderRandomCircle() { super(); }

   @Override
   public Renderable getRenderable() { return BorderRenderer.getInstance(); }

   @Override
   public Color getColor() { return Color.GREEN; }
}
