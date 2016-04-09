public class SquareFactory {
   private static SquareFactory instance;

   private SquareFactory() {}

   public static SquareFactory getInstance() {
	  if (instance == null) instance = new SquareFactory();
	  return instance;
   }

   public Square generate(Renderable renderer, Displayer displayer) {
	  return new Square(renderer, displayer);
   }
}