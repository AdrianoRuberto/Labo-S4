public class Singleton {
   private static Singleton instance;
   private int data;  // état du singleton

   private Singleton() { } // constructeur privé

   public static Singleton getInstance() {
	  if (instance == null) instance = new Singleton();  // instanciation retardée
	  return instance;
   }

   public int getData() {
	  return data;
   }

   public void setData(int data) {
	  this.data = data;
   }
}
