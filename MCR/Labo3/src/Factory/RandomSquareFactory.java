package Factory;

import Bouncable.Form;
import Bouncable.Square;
import Displayers.Displayer;
import Renderable.Renderable;

import java.awt.*;
import java.util.Random;

public class RandomSquareFactory extends FormFactory {

   private static RandomSquareFactory instance;
   private final double MAX_SIZE = 50;
   private final Random rand = new Random();

   private RandomSquareFactory() {}

   public static RandomSquareFactory getInstance() {
	  if (instance == null) instance = new RandomSquareFactory();
	  return instance;
   }

   @Override
   public Square create(Renderable renderable, Displayer displayer) {
	  return new Square(renderable, displayer, new Color(rand.nextInt()),
						new Point(rand.nextInt(displayer.getWidth()), displayer.getHeight()),
						new Point(1 + rand.nextInt(MAX_SPEED), 1 + rand.nextInt(MAX_SPEED)),
						rand.nextDouble() * MAX_SIZE);
   }
}