import java.util.LinkedList;

public class BounceApp {
   private LinkedList<Bouncable> bouncers = new LinkedList<>();

   private JBounce jBounce = new JBounce();

   public BounceApp() {

   }

   public static void main(String... args) {
	  new BounceApp().loop();
   }

   public void loop() {
	  while (true) {
		 // Logical
		 for (Bouncable b : bouncers) {
			b.move();
		 }

		 jBounce.repaint();
	  }
   }
}
