/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_3
 Fichier     : RandomFullFactory.java
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 11.04.2106

 But         :  Représente une fabrique qui permet de créer des carrés ou des cercles
 				remplis.

 ----------------------------------------------------------------------------------
 */

package Factory;

import Bouncable.FullRandomCircle;
import Bouncable.FullRandomSquare;
import Bouncable.RandomCircle;
import Bouncable.RandomSquare;

public class RandomFullFactory extends FormFactory {

   private static RandomFullFactory instance;

   private RandomFullFactory() {}

   public static RandomFullFactory getInstance() {
	  if (instance == null) instance = new RandomFullFactory();
	  return instance;
   }

   public RandomSquare createSquare() { return new FullRandomSquare(); }

   public RandomCircle createCircle() { return new FullRandomCircle(); }

}
