import java.util.LinkedList;
import java.util.Observable;
import java.util.Observer;

/**
 * @author Adriano Ruberto
 * @author Matthieu Villard
 * @version 1.0
 */

public class Clock extends Observable implements Runnable {
   private int duration = 0;
   private int timeOut;
   private Thread thread;
   private LinkedList<Watch> watches;

   public Clock(int timeOut) {
	  super();
	  this.timeOut = timeOut;
	  thread = new Thread(this);
	  watches = new LinkedList<>();
   }

   public void start() {
	  thread.start();
   }

   public void run() {
	  while (true) {
		 try {
			Thread.sleep(timeOut);
		 } catch (InterruptedException ex) {}
		 duration = ++duration % 60;
		 setChanged();
		 notifyObservers();
		 synchronized (this) {
			if (duration == 0) {
			   notifyAll();
			   for (Watch w : watches) {
				  w.update(this, null);
			   }
			}
		 }
	  }
   }

   public synchronized void addObserver(Observer o) {
	  if (o instanceof Watch) {
		 watches.add((Watch) o);
	  } else super.addObserver(o);
   }

   public int getDuration() {
	  return duration;
   }

}
