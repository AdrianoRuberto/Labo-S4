package Bouncable;

import Renderer.BorderRenderer;
import Renderer.Renderable;

import java.awt.*;

public class BorderRandomSquare extends RandomSquare {

   public BorderRandomSquare() { super(); }

   @Override
   public Renderable getRenderable() { return BorderRenderer.getInstance(); }

   @Override
   public Color getColor() { return Color.RED; }
}
