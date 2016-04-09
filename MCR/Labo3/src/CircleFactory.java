public class CircleFactory {
   private static CircleFactory instance;

   private CircleFactory() {}

   public static CircleFactory getInstance() {
	  if (instance == null) instance = new CircleFactory();
	  return instance;
   }

   public Circle generate(Renderable renderer, Displayer displayer){
	  return new Circle(renderer, displayer);
   }
}
