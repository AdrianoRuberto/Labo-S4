package Factory;

import Bouncable.Circle;
import Displayers.Displayer;
import Renderable.Renderable;

public class CircleFactory extends FormFactory {

   private static CircleFactory instance;

   private CircleFactory() {}

   public static CircleFactory getInstance() {
	  if (instance == null) instance = new CircleFactory();
	  return instance;
   }

   @Override
   public Circle create(Renderable renderable, Displayer displayer) {
	  return new Circle(renderable, displayer);
   }
}
