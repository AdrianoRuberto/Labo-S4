/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_3
 Fichier     : Bouncable.java
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 11.04.2106

 But         :  Représente une forme qui rebondit, déclenche l'affichage de cell-ci et ses
                déplacements

 ----------------------------------------------------------------------------------
 */
package Bouncable;

import Renderer.Renderable;

import java.awt.*;

public interface Bouncable
{
   /**
    * Déclenche l'affichage de la forme sur le displayer
    * @return
    */
   void draw();

   /**
    * Déplace l'objet dans le plan
    * @return
    */
   void move();

   /**
    * Retourne une instance d'un afficheur responsable de l'affichage de la forme
    * @return le Renderable responsable de l'affichage
    */
   Renderable getRenderable();

   /**
    * @return la couleur de la forme
    */
   Color getColor();

   /**
    * @return le type de forme (carré, rond)
    */
   Shape getShape();
}

