import Displayers.JBounce;
import Factory.CircleFactory;
import Factory.SquareFactory;
import Renderable.BorderRenderer;
import Renderable.FillRenderer;

import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.util.concurrent.ConcurrentLinkedQueue;

public class BounceApp {

   private JBounce jBounce = new JBounce();


   public BounceApp() {
	  jBounce.setTitle("Labo 3 - Bouncable");

	  jBounce.addKeyListener(new KeyAdapter() {
		 @Override
		 public void keyPressed(KeyEvent e) {
			switch (e.getKeyCode()) {
			   case KeyEvent.VK_E: // Efface l'affichage
				  jBounce.setBouncers(new ConcurrentLinkedQueue<>());
				  break;
			   case KeyEvent.VK_B: // Génère 10 cercles et 10 carres possédant une bordure.
				  for (int i = 0; i < 10; ++i) {
					 jBounce.getBouncers().add(CircleFactory.getInstance().create(BorderRenderer.getInstance(), jBounce));
					 jBounce.getBouncers().add(SquareFactory.getInstance().create(BorderRenderer.getInstance(), jBounce));
				  }
				  break;
			   case KeyEvent.VK_F: // générer 10 cercles et 10 pleins
				  for (int i = 0; i < 10; ++i) {
					 jBounce.getBouncers().add(CircleFactory.getInstance().create(FillRenderer.getInstance(), jBounce));
					 jBounce.getBouncers().add(SquareFactory.getInstance().create(FillRenderer.getInstance(), jBounce));
				  }
				  break;
			   case KeyEvent.VK_Q: // Quitter le programme
				  System.exit(0);
				  break;
			}

		 }
	  });
   }

   public static void main(String... args) {
	  new BounceApp().loop();
   }

   public void loop() {
	  long before;
	  final int TARGET_FPS = 30;
	  final long OPTIMAL_TIME = 1000000000 / TARGET_FPS;

	  while (true) {
		 before = System.nanoTime();

		 // Logique
		 jBounce.update();

		 // Affichage
		 jBounce.repaint();

		 // Attente pour que le nombre d'image soit constante
		 try {
			long timeToWait = (before - System.nanoTime() + OPTIMAL_TIME) / 1000000;
			if (timeToWait > 0) Thread.sleep(timeToWait);
		 } catch (InterruptedException e) {
			e.printStackTrace();
		 }

	  }
   }
}
