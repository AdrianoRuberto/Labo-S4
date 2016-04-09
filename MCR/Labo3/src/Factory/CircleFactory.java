package Factory;

import Bouncable.Circle;
import Displayers.Displayer;
import Renderable.Renderable;

public class CircleFactory {

   private CircleFactory() {}

   public static Circle generate(Renderable renderer, Displayer displayer) {
	  return new Circle(renderer, displayer);
   }
}
