/**
 * Représente un chronomètre
 *
 * @author Adriano Ruberto
 * @author Matthieu Villard
 * @version 1.0
 */

import java.util.Timer;
import java.util.TimerTask;

public class Chrono extends Subject {
   private Timer timer;
   private long time;

   public Chrono() { timer = null; }

   /**
	* @return le temps en heure
	*/
   public double getHour() { return (double) time / 60 / 60 % 24; }

   /**
	* @return le temps en minute
	*/
   public double getMin() { return (double) time / 60 % 60; }

   /**
	* @return le temps en seconde
	*/
   public double getSec() {
	  return time % 60;
   }

   /**
	* Pour démarrer le chrono
	*/
   public void start() {
	  if (timer == null) {
		 timer = new Timer();

		 timer.schedule(new TimerTask() {
			// Créer une tâche qui incrémente toute les secondes le temps de 1
			public void run() {
			   time++;
			   notifyObservators();
			}
		 }, 0, 1000);
	  }
   }

   /**
	* Permet de reset le chrono et de remettre le temps à 0
	*/
   public void reset() {
	  time = 0;
	  notifyObservators();
   }

   /**
	* Permet de stopper le chrono et de supprimer la tâche
	*/
   public void stop() {
	  timer.cancel();
	  timer.purge();
	  timer = null;
	  notifyObservators();
   }

   /**
	* Permute entre l'état stop et start
	*/
   public void switchState() {
	  if (timer == null) start();
	  else stop();
   }
}
