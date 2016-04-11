import Bouncable.Bouncable;
import Displayers.JBounce;
import Factory.FormFactory;

import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.util.concurrent.ConcurrentLinkedQueue;

public class BounceApp {

   private ConcurrentLinkedQueue<Bouncable> bouncers = new ConcurrentLinkedQueue<>();

   public BounceApp() {
	  JBounce.getInstance().setTitle("Labo 3 - Bouncable");

	  JBounce.getInstance().addKeyListener(new KeyAdapter() {
		 @Override
		 public void keyPressed(KeyEvent e) {
			switch (e.getKeyCode()) {
			   case KeyEvent.VK_E: // Efface l'affichage
				  bouncers = new ConcurrentLinkedQueue<Bouncable>();
				  break;
			   case KeyEvent.VK_B: // Génère 10 cercles et 10 carres possédant une bordure.
				  for (int i = 0; i < 10; ++i) {
					 bouncers.add(FormFactory.RandomBorderFactory.createCircle());
					 bouncers.add(FormFactory.RandomBorderFactory.createSquare());
				  }
				  break;
			   case KeyEvent.VK_F: // générer 10 cercles et 10 pleins
				  for (int i = 0; i < 10; ++i) {
					 bouncers.add(FormFactory.RandomFullFactory.createCircle());
					 bouncers.add(FormFactory.RandomFullFactory.createSquare());
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
	  final long OPTIMAL_TIME = 1000 / 30;

	  while (true) {
		 before = System.currentTimeMillis();

		 JBounce.getInstance().clear();

		 for (Bouncable b : bouncers) {
			b.move();
			b.draw();
		 }

		 JBounce.getInstance().repaint();

		 // Attente pour que le nombre d'image soit constante
		 try {
			long timeToWait = (before - System.currentTimeMillis() + OPTIMAL_TIME);
			if (timeToWait > 0) Thread.sleep(timeToWait);
		 } catch (InterruptedException e) {
			e.printStackTrace();
		 }

	  }
   }
}
