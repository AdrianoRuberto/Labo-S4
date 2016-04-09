package Factory;

import Bouncable.Square;
import Displayers.Displayer;
import Renderable.Renderable;

public class SquareFactory {

   private SquareFactory() {}

   public static Square generate(Renderable renderer, Displayer displayer) {
	  return new Square(renderer, displayer);
   }
}