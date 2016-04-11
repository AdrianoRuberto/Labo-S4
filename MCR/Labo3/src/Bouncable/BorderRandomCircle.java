/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_3
 Fichier     : BorderRandomCircle.java
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 11.04.2106

 But         :  Représente une forme ronde non remplie

 ----------------------------------------------------------------------------------
 */

package Bouncable;

import Renderer.BorderRenderer;
import Renderer.Renderable;

import java.awt.*;

public class BorderRandomCircle extends RandomCircle {

   public BorderRandomCircle() { super(); }

   /**
    * Renvoie la bonne instance de Renderable
    * @return BorderRenderer
    */
   @Override
   public Renderable getRenderable() { return BorderRenderer.getInstance(); }

   @Override
   public Color getColor() { return Color.GREEN; }
}
