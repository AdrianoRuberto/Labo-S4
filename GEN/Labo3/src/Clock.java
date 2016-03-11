/****************************************************************
 * Auteur:	    Matthieu Villard                               *
 * Date:     	11.03.2016		                *
 * Projet:	    Horloges synchronisées                          *
 ****************************************************************
 */
import java.util.Observable;

public class Clock extends Observable
{
	private int timeOut;
	private int hours;
	private int minutes;
	private int seconds;

	public Clock (int timeOut) {
		super();
		this.timeOut = timeOut;
		hours = 0;
		minutes = 0;
		seconds = 0;
	}
}
