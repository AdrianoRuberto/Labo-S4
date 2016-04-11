/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_3
 Fichier     : FullRandomCircle.java
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 11.04.2106

 But         :  Représente une forme ronde remplie

 ----------------------------------------------------------------------------------
 */

package Bouncable;

import Renderer.FillRenderer;
import Renderer.Renderable;

import java.awt.*;

public class FullRandomCircle extends RandomCircle {

   public FullRandomCircle() { super(); }

   /**
    * Renvoie la bonne instance de Renderable
    * @return FillRenderer
    */
   @Override
   public Renderable getRenderable() { return FillRenderer.getInstance(); }

   @Override
   public Color getColor() { return Color.BLUE; }
}
