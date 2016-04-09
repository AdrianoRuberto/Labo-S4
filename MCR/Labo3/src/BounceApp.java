public class BounceApp {

   private JBounce jBounce = new JBounce();


   public BounceApp() {

   }

   public static void main(String... args) {
	  new BounceApp().loop();
   }

   public void loop() {
	  while (true) {

		 // Logical
		 jBounce.update();

		 // Draw
		 jBounce.repaint();

	  }
   }
}
