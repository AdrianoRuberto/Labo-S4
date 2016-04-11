/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_3
 Fichier     : FormFactory.java
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 11.04.2106

 But         :  Représente une fabrique qui permet de créer les formes désirées

 ----------------------------------------------------------------------------------
 */

package Factory;

import Bouncable.*;

public abstract class FormFactory {
   public static class RandomBorderFactory extends FormFactory {
	  public static RandomSquare createSquare() { return new BorderRandomSquare(); }

	  public static RandomCircle createCircle() { return new BorderRandomCircle(); }
   }

   public static class RandomFullFactory extends FormFactory {
	  public static RandomSquare createSquare() { return new FullRandomSquare(); }

	  public static RandomCircle createCircle() { return new FullRandomCircle(); }

   }
}
