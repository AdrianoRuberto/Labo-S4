/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_3
 Fichier     : FillRenderer.java
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 11.04.2106

 But         :  Représente un afficheur qui permet d'afficher une forme pleine ou non

 ----------------------------------------------------------------------------------
 */
package Renderer;

import Bouncable.Bouncable;

import java.awt.*;

public interface Renderable {
   /**
    * Affiche la forme
    */
   void display(Graphics2D g, Bouncable b);
}
