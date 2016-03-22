import java.util.LinkedList;

public class BounceApp {
   private LinkedList<Bouncable> bouncers;

   public BounceApp() {

   }

   public void loop() {
	  // Logical
	  for(Bouncable b : bouncers){
		 b.move();
	  }
	  // Draw
   }

   public static void main(String ... args){
	  new BounceApp().loop();
   }
}
