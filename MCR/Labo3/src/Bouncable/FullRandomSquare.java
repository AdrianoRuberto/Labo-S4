/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_3
 Fichier     : FullRandomSquare.java
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 11.04.2106

 But         :  Représente une forme carrée remplie

 ----------------------------------------------------------------------------------
 */

package Bouncable;

import Renderer.FillRenderer;
import Renderer.Renderable;

import java.awt.*;

public class FullRandomSquare extends RandomSquare {

   public FullRandomSquare() { super(); }

   /**
    * Renvoie la bonne instance de Renderable
    * @return FillRenderer
    */
   @Override
   public Renderable getRenderable() { return FillRenderer.getInstance(); }

   @Override
   public Color getColor() { return Color.ORANGE; }
}
