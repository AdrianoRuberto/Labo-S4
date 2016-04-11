/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_3
 Fichier     : RandomCircle.java
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 11.04.2106

 But         :  Représente une forme ronde

 ----------------------------------------------------------------------------------
 */

package Bouncable;

import java.awt.*;
import java.awt.geom.Ellipse2D;

public abstract class RandomCircle extends RandomForm {

   private Ellipse2D.Double circle = new Ellipse2D.Double(position.x, position.y, size, size);

   public RandomCircle() { super(); }

   public void move() {
	  super.move();
       // Met à jour la position du cercle
	  circle.x = position.x;
	  circle.y = position.y;
   }

   @Override
   public Shape getShape() { return circle; }
}
