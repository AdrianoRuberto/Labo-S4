package Factory;

import Bouncable.Circle;
import Bouncable.Square;
import Displayers.Displayer;
import Displayers.JBounce;
import Renderer.BorderRenderer;
import Renderer.FillRenderer;

import java.awt.*;
import java.util.Random;

public abstract class FormFactory {

   private static final int MAX_SPEED = 10;
   private static int MAX_SIZE = 25;
   private static Random rand = new Random();
   private static Displayer displayer = JBounce.getInstance();

   public static class RandomBorderedSquareFactory extends FormFactory {
	  public static Square create() {
		 return new Square(BorderRenderer.getInstance(), Color.RED,
						   new Point(rand.nextInt(displayer.getWidth()), rand.nextInt(displayer.getHeight())),
						   new Point(1 + rand.nextInt(MAX_SPEED), 1 + rand.nextInt(MAX_SPEED)), rand.nextInt(MAX_SIZE));
	  }
   }

   public static class RandomFillSquareFactory extends FormFactory {
	  public static Square create() {
		 return new Square(FillRenderer.getInstance(), Color.ORANGE,
						   new Point(rand.nextInt(displayer.getWidth()), rand.nextInt(displayer.getHeight())),
						   new Point(1 + rand.nextInt(MAX_SPEED), 1 + rand.nextInt(MAX_SPEED)), rand.nextInt(MAX_SIZE));
	  }
   }

   public static class RandomBorderedCircleFactory extends FormFactory {
	  public static Circle create() {
		 return new Circle(BorderRenderer.getInstance(), Color.GREEN,
						   new Point(rand.nextInt(displayer.getWidth()), rand.nextInt(displayer.getHeight())),
						   new Point(1 + rand.nextInt(MAX_SPEED), 1 + rand.nextInt(MAX_SPEED)), rand.nextInt(MAX_SIZE));
	  }
   }

   public static class RandomFillCircleFactory extends FormFactory {
	  public static Circle create() {
		 return new Circle(FillRenderer.getInstance(), Color.BLUE,
						   new Point(rand.nextInt(displayer.getWidth()), rand.nextInt(displayer.getHeight())),
						   new Point(1 + rand.nextInt(MAX_SPEED), 1 + rand.nextInt(MAX_SPEED)), rand.nextInt(MAX_SIZE));
	  }
   }

}
