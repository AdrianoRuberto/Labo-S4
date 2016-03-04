import junit.framework.TestCase;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;

public class AnnuaireTest extends TestCase {

   private Annuaire annuaire = new Annuaire();

   @Before
   public void setUp() throws Exception {

   }

   @After
   public void tearDown() throws Exception {

   }

   @Test
   public void testGetPersonne() throws Exception {

   }

   @Test
   public void testAddPersonne() throws Exception {

   }

   @Test
   public void testDelPersonne() throws Exception {

   }

   @Test
   public void testChangeNomPersonne() throws Exception {

   }

   @Test
   public void testChangePrenomPersonne() throws Exception {

   }

   @Test
   public void testChangeAnneePersonne() throws Exception {

   }

   @Test
   public void testGetAnneePersonne() throws Exception {

   }

   @Test
   public void testGetNomPersonne() throws Exception {

   }

   @Test
   public void testGetPrenomPersonne() throws Exception {

   }

   @Test
   public void testExist() throws Exception {
	  assertFalse(annuaire.Exist("coucou"));
   }

   @Test
   public void testGetNombrePersonnes() throws Exception {
	  assertEquals(annuaire.getNombrePersonnes(), 3);
   }
}
