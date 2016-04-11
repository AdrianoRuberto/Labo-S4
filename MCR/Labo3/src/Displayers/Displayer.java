/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_3
 Fichier     : Displayer.java
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 11.04.2106

 But         :  Représente une interface d'affichage utilisée pour afficher les formes

 ----------------------------------------------------------------------------------
 */

package Displayers;

import java.awt.*;
import java.awt.event.KeyAdapter;

public interface Displayer {
   /**
    * @return la largeur de la fenêtre
    */
   int getWidth();

   /**
    * @return la hauteur de la fenêtre
    */
   int getHeight();

   /**
    * @return la l'objet qui permet de dessiner les formes
    */
   Graphics2D getGraphics();

   /**
    * Redessine la fenêtre
    * @return
    */
   void repaint();

   /**
    * Change le titre de la fenêtre
    * @return
    */
   void setTitle(String s);

   /**
    * Ajouter un listener pour éxécuter une action lors de l'activation d'une touche du clavier
    * @return
    */
   void addKeyListener(KeyAdapter ka);
}
