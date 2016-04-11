/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_3
 Fichier     : RandomSquare.java
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 11.04.2106

 But         :  Représente une forme carrée

 ----------------------------------------------------------------------------------
 */

package Bouncable;

import java.awt.*;
import java.awt.geom.Rectangle2D;

public abstract class RandomSquare extends RandomForm {

   private Rectangle2D.Double square = new Rectangle2D.Double(position.x, position.y, size, size);

   public RandomSquare() { super(); }

   @Override
   public void move() {
	  super.move();
       // met à jour la position du carré
	  square.x = position.x;
	  square.y = position.y;
   }

   @Override
   public Shape getShape() {
	  return square;
   }
}
