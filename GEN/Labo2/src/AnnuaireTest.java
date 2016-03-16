import junit.framework.TestCase;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;

public class AnnuaireTest extends TestCase {

   private Annuaire annuaire = new Annuaire();

   @Before
   public void setUp() throws Exception {
	  annuaire = new Annuaire();
   }

   @After
   public void tearDown() throws Exception {
	  annuaire = null;
   }

   @Test
   public void testGetPersonne() throws Exception {
	  assertNotNull(annuaire.getPersonne("sb@hispeed.ch"));
	  assertNull(annuaire.getPersonne("null"));
   }

   @Test
   public void testGetSamePersonne() throws Exception {
	  Personne p = annuaire.getPersonne("sb@hispeed.ch");
	  assertSame(p, annuaire.getPersonne("sb@hispeed.ch"));
   }

   @Test
   public void testNotSamePersonne() throws Exception {
	  Personne p = annuaire.getPersonne("sb@hispeed.ch");
	  assertNotSame(p, annuaire.getPersonne("j.muller@gmail.com"));
   }

   @Test
   public void testChangeNomPersonne() throws Exception {
	  System.out.println("BECAUSE OF REASON [FAIL]");
	  fail();
   }

   @Test
   public void testExist() throws Exception {
	  assertFalse(annuaire.Exist("coucou"));
	  assertTrue(annuaire.Exist("sb@hispeed.ch"));
   }

   @Test
   public void testGetNombrePersonne() throws Exception {
	  assertEquals(annuaire.getNombrePersonnes(), 3);
   }
}
