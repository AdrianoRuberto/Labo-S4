import java.util.Observable;
import java.util.Observer;

/**
 * Created by matthieu.villard on 11.03.2016.
 */
public class Watch extends Observable implements Runnable, Observer
{
    private int hours = 0;
    private int minutes = 0;
    private int seconds = 0;
    private int timeOut;
    private int memTimeOut;
    private Thread thread;
    private Clock refClock;
    private int minutesPlus = 0;
    private boolean synchReached = false;

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
            if(seconds == 0) {
                synchronized (refClock) {
                    try {
                        while (minutesPlus > 0)
                            refClock.wait();
                        minutesPlus = 0;
                    } catch (InterruptedException ex) {
                    }
                }
                if(synchReached){
                    if(minutesPlus >= 0){
                        synchReached = false;
                        timeOut = memTimeOut;
                    }
                    else
                        minutesPlus++;
                }
            }
        }
    }

    public void update(Observable o, Object arg) {
        if (o instanceof  Clock)  {
            Clock  clock = (Clock)o;
            if(seconds != 0){
                synchReached = true;
                memTimeOut = timeOut;
                timeOut = 10;
            }
            minutesPlus--;
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

    public void incrementMinutes() {
        minutesPlus++;
        minutes = ++minutes % 60 ;
        if (minutes == 0) {
            hours = ++hours % 24;
        }
    }

    private void incrementSeconds(){
        seconds ++;
        if (seconds == 60) {
            seconds = 0;
            incrementMinutes();
        }
    }
}
