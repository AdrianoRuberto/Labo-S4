import java.util.Observable;

/**
 * Created by matthieu.villard on 11.03.2016.
 */
public class Watch extends Observable implements Runnable
{
    private int hours = 0;
    private int minutes = 0;
    private int seconds = 0;
    private int timeOut;
    private Thread thread;
    private Clock refClock;

    public Watch(int timeOut, Clock refClock){
        super();
        this.timeOut = timeOut;
        this.refClock = refClock;
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
            incrementSeconds();
            setChanged();
            notifyObservers();
            if(seconds == 0 && refClock.getDuration() != seconds)
                synchronized(refClock) {
                    try {
                        refClock.wait();
                    } catch (InterruptedException ex) {
                    }
                }
        }
    }

    public int getHours(){
        return hours;
    }

    public int getMinutes(){
        return minutes;
    }

    public int getSeconds(){
        return seconds;
    }

    private void incrementSeconds(){
        seconds ++;
        if (seconds == 60) {
            seconds = 0;
            incrementMinutes();
        }
    }

    private void incrementMinutes() {
        minutes = ++minutes % 60 ;
        if (minutes == 0) {
            hours = ++hours % 24;
        }
    }
}
