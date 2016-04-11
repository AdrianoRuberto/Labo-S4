/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_3
 Fichier     : BorderRandomSquare.java
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 11.04.2106

 But         :  Représente une forme carrée non remplie

 ----------------------------------------------------------------------------------
 */

package Bouncable;

import Renderer.BorderRenderer;
import Renderer.Renderable;

import java.awt.*;

public class BorderRandomSquare extends RandomSquare {

   public BorderRandomSquare() { super(); }

   /**
    * Renvoie la bonne instance de Renderable
    * @return BorderRenderer
    */
   @Override
   public Renderable getRenderable() { return BorderRenderer.getInstance(); }

   @Override
   public Color getColor() { return Color.RED; }
}
