/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_3
 Fichier     : BorderRenderer.java
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 11.04.2106

 But         :  Représente un afficheur qui permet d'afficher une forme non pleine

 ----------------------------------------------------------------------------------
 */

package Renderer;

import Bouncable.Bouncable;

import java.awt.*;

public class BorderRenderer implements Renderable {

   private final static BasicStroke bs = new BasicStroke(2);
   private static BorderRenderer instance;

   private BorderRenderer() {}

   public static BorderRenderer getInstance() {
	  if (instance == null) instance = new BorderRenderer();
	  return instance;
   }

    /**
     * Affiche la forme
     */
   @Override
   public void display(Graphics2D g, Bouncable b) {
	  g.setColor(b.getColor());
	  g.setStroke(bs);
	  g.draw(b.getShape());
   }
}
