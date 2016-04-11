package Bouncable;

import Renderer.Renderable;

import java.awt.*;

public interface Bouncable {
   void draw();

   void move();

   Renderable getRenderable();

   Color getColor();

   Shape getShape();
}

