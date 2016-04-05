import java.awt.*;
import java.awt.event.KeyAdapter;

public class JBounce implements Displayer{

   @Override
   public int getWidth() {
	  return 200;
   }

   @Override
   public int getHeight() {
	  return 200;
   }

   @Override
   public Graphics2D getGraphics() {
	  return null;
   }

   @Override
   public void repaint() {

   }

   @Override
   public void setTitle(String s) {

   }

   @Override
   public void addKeyListener(KeyAdapter ka) {

   }
}
