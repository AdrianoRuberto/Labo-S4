import java.util.LinkedList;

public abstract class Subject {
   private LinkedList<Observator> observators = new LinkedList<>();

   public void attach(Observator o) {
	  if (o == null) throw new RuntimeException("Observator is null");
	  observators.push(o);
   }

   public void detach(Observator o) {
	  observators.remove(o);
   }

   public void notifyObservators() {
	  for (Observator o : observators)
		 o.update();
   }
}
