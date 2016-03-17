/****************************************************************
 * Auteur:	    Matthieu Villard                               *
 * Date:     	11.03.2016		                *
 * Projet:	    Horloges synchronisées                          *
 ****************************************************************
 */
import java.util.Observable;

public class Clock extends Observable implements Runnable
{
	private int duration = 0;
	private int timeOut;
	private Thread thread;

	public Clock (int timeOut) {
		super();
		this.timeOut = timeOut;
		thread = new Thread(this);
	}

	public void start(){
		thread.start();
	}

	public void run() {
		while(true){
			try {
				Thread.sleep(timeOut);
			} catch (InterruptedException ex) {}
			duration = ++duration % 60;
			setChanged();
			notifyObservers();
			synchronized (this) {
				if (duration == 0)
					notifyAll();
			}
		}
	}

	public int getDuration(){
		return duration;
	}

}
