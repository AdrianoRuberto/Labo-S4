import java.util.Random;

/****************************************************************
 * Auteur:	    Eric Lefrançois                                 *
 * Groupe:	    HES_SO  Informatique & Télécommunications       *
 * Fichier:     1er Octobre 2015-  DEPART		                *
 * Projet:	    Horloges synchronisées                          *
 ****************************************************************
*/




public class Amorce {
    public static void main (String argv[]){

        Clock transmitter = new Clock(200);
        transmitter.addObserver(new ClockView(0, 0));
        transmitter.start();

        Watch refWatch = new Watch(200, transmitter);
        refWatch.addObserver(new WatchView(refWatch, "H", 0, 150));
        transmitter.addObserver(refWatch);
        refWatch.start();

        Random r = new Random();
        for(int i = 0; i < 5; i++){
            Watch watch = new Watch((int)(400 * r.nextFloat()), transmitter);
            watch.addObserver(new WatchView(watch, "H" + i, 220 + i * 220, 150));
            transmitter.addObserver(watch);
            watch.start();
        }

    }
}
