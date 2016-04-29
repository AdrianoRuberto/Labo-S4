package controllers;

import com.thoughtworks.xstream.XStream;

import models.*;

import java.io.BufferedWriter;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.StringReader;
import java.io.Writer;
import java.text.ParseException;
import java.util.Arrays;
import java.util.Calendar;
import java.util.stream.Stream;

import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;

import org.jboss.logging.annotations.Transform;
import org.w3c.dom.Attr;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.xml.sax.ErrorHandler;
import org.xml.sax.InputSource;
import org.xml.sax.SAXException;
import org.xml.sax.SAXParseException;
import org.xml.sax.XMLReader;
import org.xml.sax.helpers.DefaultHandler;

import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerConfigurationException;
import javax.xml.transform.TransformerException;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;
import javax.xml.transform.OutputKeys;


public class XMLSerializer
{
	private DocumentBuilder builder = null;
	private Document document = null;
	private File schema = null;
	
	public XMLSerializer() throws Exception{
		super();
		
		final DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
		
		try {
		    builder = factory.newDocumentBuilder();
		}
		catch (final ParserConfigurationException e) {
			throw new Exception(e);
		}
	}

	public XMLSerializer(String dtd) throws Exception{
		super();
		
		final DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
		if(dtd != null){
			factory.setValidating(true);
			factory.setNamespaceAware(false);
			schema = new File(dtd);
		}
		
		try {
		    builder = factory.newDocumentBuilder();
		}
		catch (final ParserConfigurationException e) {
			throw new Exception(e);
		}
	}
	
	public void toXML(Object obj, Writer out) throws IOException, TransformerException, ParserConfigurationException, SAXException {
		final Document document = generateDocument((GlobalData)obj);
		/*
	     * Display results
	     */
		final TransformerFactory transformerFactory = TransformerFactory.newInstance();
	    final Transformer transformer = transformerFactory.newTransformer();
	    final DOMSource src = new DOMSource(document);
	    final ByteArrayOutputStream outputStream = new ByteArrayOutputStream();
	    //final StreamResult result = new StreamResult(System.out);
			
	    //prologue
	    transformer.setOutputProperty(OutputKeys.VERSION, "1.0");
	    transformer.setOutputProperty(OutputKeys.ENCODING, "UTF-8");
	    transformer.setOutputProperty(OutputKeys.STANDALONE, "yes");
	    if(schema != null)
	    	transformer.setOutputProperty(OutputKeys.DOCTYPE_SYSTEM, schema.getPath());
	    		
	    //format
	    transformer.setOutputProperty(OutputKeys.INDENT, "yes");
	    transformer.setOutputProperty("{http://xml.apache.org/xslt}indent-amount", "2");
			
	    //output
	    transformer.transform(src, new StreamResult(out)); // real output
	    transformer.transform(src, new StreamResult(outputStream));	// output for validation
	    
	    // validation
	    InputStream is = new ByteArrayInputStream(outputStream.toByteArray());
	    ValidationHandler handler = new ValidationHandler();
		
		// Use the validating parser
        SAXParserFactory factory = SAXParserFactory.newInstance();
        factory.setValidating(true);

        // Parse the input
        SAXParser saxParser = factory.newSAXParser();
        saxParser.parse(new ByteArrayInputStream(outputStream.toByteArray()), handler);
        new ByteArrayInputStream(outputStream.toByteArray());
	}
	
	private Document generateDocument(GlobalData globalData){
		if(builder == null)
			return null;
		
		document = builder.newDocument();
	
		document.appendChild(
			// root tag
			createNode("projections", 
				// projection tag
				globalData.getProjections().stream().map(p -> createNode("projection",
						// date tag
						createNode("date", parseDate(p.getDateHeure())),
						// room number tag
						createNode("noSalle", p.getSalle().getNo()),
						// film tag
						createNode("film", 
							// title tag 
							createNode("titre", p.getFilm().getTitre()),
							// synopsis tag
							createOptionalNode("synopsis", p.getFilm().getSynopsis()),
							// duration tag
							createOptionalNode("duree", String.valueOf(p.getFilm().getDuree())),
							// photo tag
							createOptionalNode("photo", p.getFilm().getPhoto()),
							// roles tag
							createOptionalNode("roles", 
								// use stream to construct each role tag
								p.getFilm().getRoles().stream().map(role -> createNode("role", 
										// personnage tag
										createOptionalNode("personnage", role.getPersonnage()),
										// place tag
										createOptionalNode("place", String.valueOf(role.getPlace())),
										// actor tag, warning : lazy mode could generate errors
										createNode("acteur", 
												// name tag
												createNode("nom", role.getActeur().getNom()),
												// originalName tag
												createOptionalNode("nomNaissance", role.getActeur().getNomNaissance()),
												// sexe tag
												setAttribute(createNode("sexe", ""), "valeur", role.getActeur().getSexe().name()),
												// birthDate tag
												createOptionalNode("dateNaissance", parseDate(role.getActeur().getDateNaissance())),
												// dateOfDeath tag
												createOptionalNode("dateDeces", parseDate(role.getActeur().getDateDeces())),
												// biography tag
												createOptionalNode("biographie", role.getActeur().getBiographie())
										)
									)
								).toArray(size -> new Element[size])
							),
							// critics tag
							createOptionalNode("critiques",
								// use stream to construct each critic tag
								p.getFilm().getCritiques().stream().map(critic -> createNode("critique",
										// label tag
										createOptionalNode("texte", critic.getTexte()),
										// grade tag
										createOptionalNode("note", String.valueOf(critic.getNote()))
									)
								).toArray(size -> new Element[size])
							),
							// genres tag
							createOptionalNode("genres",
								// use stream to construct each genre tag
								p.getFilm().getGenres().stream().map(genre -> createNode("genre", 
										genre.getLabel()
									)
								).toArray(size -> new Element[size])
							),
							// keywords tag
							createOptionalNode("motsCles", 
								// use stream to construct each keyword tag
								p.getFilm().getMotcles().stream().map(keyWord -> createNode("motCle", 
										keyWord.getLabel()
									)
								).toArray(size -> new Element[size])
							),
							// languages tag
							createOptionalNode("langages",
								// use stream to construct each language tag
								p.getFilm().getLangages().stream().map(language -> createNode("langage", 
										language.getLabel()
									)
								).toArray(size -> new Element[size])
							)
						)
					)
				).toArray(size -> new Element[size])
			)
		);
		
		return document;
	}
	
	private Element createNode(String elementTitle, String value){
		final Element element = document.createElement(elementTitle);
		element.appendChild(document.createTextNode(value));
		return element;
	}
	
	private Element createNode(String elementTitle, Element... elements){
		final Element element = document.createElement(elementTitle);
		Arrays.stream(elements).filter(el -> el != null).forEach(el -> element.appendChild(el));
		return element;
	}
	
	private Element createOptionalNode(String elementTitle, String value){
		if(value == null || value.isEmpty())
			return null;
		return createNode(elementTitle, value);
	}
	
	private Element createOptionalNode(String elementTitle, Element... elements){
		for(Element element : elements){
			if(element != null)
				return createNode(elementTitle, elements);
		}
		return null;
	}
	
	private Element setAttribute(Element element, String title, String value){
         element.setAttribute(title,  value);
         return element;
	}
	
	private String parseDate(Calendar date){
		String str = "";
		try{
			str = new DateLabelFormatter().valueToString(date);
		}
		catch(ParseException e){
			e.printStackTrace();
		}
		return str;
	}
	
	private class ValidationHandler extends DefaultHandler
	{
	    //===========================================================
	    // SAX ErrorHandler methods
	    //===========================================================

	    // treat validation errors as fatal
	    public void error(SAXParseException e)
	    throws SAXParseException
	    {
	        throw e;
	    }

	    // dump warnings too
	    public void warning(SAXParseException err)
	    throws SAXParseException
	    {
	        System.out.println("** Warning"
	            + ", line " + err.getLineNumber()
	            + ", uri " + err.getSystemId());
	        System.out.println("   " + err.getMessage());
	    }
	}
}
