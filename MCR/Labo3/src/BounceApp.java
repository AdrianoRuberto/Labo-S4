import Displayers.JBounce;

public class BounceApp {

   private JBounce jBounce = new JBounce();


   public BounceApp() {

   }

   public static void main(String... args) {
	  new BounceApp().loop();
   }

   // http://www.java-gaming.org/index.php?topic=24220.0
   public void loop() {
	  long lastLoopTime;
	  final int TARGET_FPS = 30;
	  final long OPTIMAL_TIME = 1000000000 / TARGET_FPS;

	  while (true) {
		 long now = System.nanoTime();
		 lastLoopTime = now;

		 // Logical
		 jBounce.update();

		 // Draw
		 jBounce.repaint();

		 // Wait for the fps
		 try {
			long timeToWait = (lastLoopTime - System.nanoTime() + OPTIMAL_TIME) / 1000000;
			if (timeToWait > 0) Thread.sleep(timeToWait);
		 } catch (InterruptedException e) {
			e.printStackTrace();
		 }

	  }
   }
}
