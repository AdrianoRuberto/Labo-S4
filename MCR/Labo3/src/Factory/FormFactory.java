package Factory;

import Bouncable.Form;
import Displayers.Displayer;
import Renderable.Renderable;

public abstract class FormFactory {
   public abstract Form create(Renderable renderable, Displayer displayer);
}
