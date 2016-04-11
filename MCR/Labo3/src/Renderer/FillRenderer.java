/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_3
 Fichier     : FillRenderer.java
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 11.04.2106

 But         :  Représente un afficheur qui permet d'afficher une forme pleine

 ----------------------------------------------------------------------------------
 */

package Renderer;

import Bouncable.Bouncable;

import java.awt.*;

public class FillRenderer implements Renderable {

   private static FillRenderer instance;

   private FillRenderer() {}

   public static FillRenderer getInstance() {
	  if (instance == null) instance = new FillRenderer();
	  return instance;
   }

    /**
     * Affiche la forme et son contenu
     */
   @Override
   public void display(Graphics2D g, Bouncable b) {
	  g.setColor(b.getColor());
	  Shape s = b.getShape();
	  g.fill(s);
	  g.draw(s);
   }
}
