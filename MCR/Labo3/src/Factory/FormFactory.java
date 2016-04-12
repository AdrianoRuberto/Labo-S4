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
   public abstract RandomSquare createSquare();

   public abstract RandomCircle createCircle();

}


