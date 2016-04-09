package Factory;

import Bouncable.Square;
import Displayers.Displayer;
import Renderable.Renderable;

public class SquareFactory extends FormFactory {

   private static SquareFactory instance;

   private SquareFactory() {}

   public static SquareFactory getInstance() {
	  if (instance == null) instance = new SquareFactory();
	  return instance;
   }

   @Override
   public Square create(Renderable renderable, Displayer displayer) {
	  return new Square(renderable, displayer);
   }
}