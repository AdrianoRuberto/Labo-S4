package Factory;

import Bouncable.Form;
import Displayers.Displayer;
import Renderable.Renderable;

public abstract class FormFactory {
   protected final int MAX_SPEED = 10;
   public abstract Form create(Renderable renderable, Displayer displayer);
}
