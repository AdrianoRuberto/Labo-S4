/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_3
 Fichier     : RandomBorderFactory.java
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 11.04.2106

 But         :  Représente une fabrique qui permet de créer des carrés ou des cercles
 				avec bordure

 ----------------------------------------------------------------------------------
 */

package Factory;

import Bouncable.BorderRandomCircle;
import Bouncable.BorderRandomSquare;
import Bouncable.RandomCircle;
import Bouncable.RandomSquare;

public class RandomBorderFactory extends FormFactory {

   private static RandomBorderFactory instance;

   private RandomBorderFactory() {}

   public static RandomBorderFactory getInstance() {
	  if (instance == null) instance = new RandomBorderFactory();
	  return instance;
   }

   @Override
   public RandomSquare createSquare() { return new BorderRandomSquare(); }

   @Override
   public RandomCircle createCircle() { return new BorderRandomCircle(); }
}
