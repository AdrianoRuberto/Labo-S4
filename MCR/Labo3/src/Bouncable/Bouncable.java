package Bouncable;

import java.awt.*;
import Renderable.Renderable;

public interface Bouncable {
   void draw();
   void move();
   Renderable getRenderer();
   Color getColor();
   Shape getShape();
}

