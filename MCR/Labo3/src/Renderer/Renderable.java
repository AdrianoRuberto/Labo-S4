package Renderer;

import Bouncable.Bouncable;

import java.awt.*;

public interface Renderable {
   void display(Graphics2D g, Bouncable b);
}