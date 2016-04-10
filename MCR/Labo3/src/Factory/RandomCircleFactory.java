package Factory;

import Bouncable.Circle;
import Displayers.Displayer;
import Renderable.Renderable;

import java.awt.*;
import java.util.Random;

public class RandomCircleFactory extends FormFactory {

   private static RandomCircleFactory instance;
   private final Random rand = new Random();
   private final double MAX_RADIUS = 50;

   private RandomCircleFactory() {}

   public static RandomCircleFactory getInstance() {
	  if (instance == null) instance = new RandomCircleFactory();
	  return instance;
   }

   @Override
   public Circle create(Renderable renderable, Displayer displayer) {
	  return new Circle(renderable, displayer, new Color(rand.nextInt()),
						new Point(rand.nextInt(displayer.getWidth()), rand.nextInt(displayer.getHeight())),
						new Point(1 + rand.nextInt(MAX_SPEED), 1 + rand.nextInt(MAX_SPEED)),
						rand.nextDouble() * MAX_RADIUS);
   }
}
