package Factory;

import Bouncable.*;

public abstract class FormFactory {
   public static class RandomBorderFactory extends FormFactory {
	  public static RandomSquare createSquare() { return new BorderRandomSquare(); }

	  public static RandomCircle createCircle() { return new BorderRandomCircle(); }
   }

   public static class RandomFillFactory extends FormFactory {
	  public static RandomSquare createSquare() { return new FullRandomSquare(); }

	  public static RandomCircle createCircle() { return new FullRandomCircle(); }

   }
}
