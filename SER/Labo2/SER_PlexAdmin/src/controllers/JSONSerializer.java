package controllers;

import java.io.Writer;
import java.text.ParseException;
import java.util.Calendar;
import java.util.stream.Stream;

import org.w3c.dom.Document;
import org.w3c.dom.Element;

import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import com.google.gson.JsonArray;
import com.google.gson.JsonElement;
import com.google.gson.JsonObject;
import com.google.gson.JsonPrimitive;

import models.DateLabelFormatter;
import models.GlobalData;

public class JSONSerializer 
{
	private Gson builder = new GsonBuilder().setPrettyPrinting().create();
	
	public JSONSerializer(){
		
	}
	
	public void toJSON(Object obj, Writer out){
		builder.toJson(generateDocument((GlobalData)obj), out);
	}
	
	private JsonElement generateDocument(GlobalData globalData){
		if(builder == null)
			return null;
		
		return new Element().addChildren("projections",
			globalData.getProjections().stream().map(
				p -> new Element().addProperty("date", parseDate(p.getDateHeure()))
								 .addProperty("titre", p.getFilm().getTitre())
								 .addChildren("acteurs", 
									p.getFilm().getRoles().stream().filter(role -> role.getPlace() <= 2).map(role -> new JsonPrimitive(role.getActeur().getNom())).toArray(size -> new JsonPrimitive[size])
								  )
								 .getRoot()
			).toArray(size -> new JsonElement[size])
		).getRoot();
	}
	
	private class Element
	{
		JsonObject root = new JsonObject();
		
		Element addProperty(String property, String value){
			if(value == null || value.isEmpty())
				return this;
			root.addProperty(property, value);
			return this;
		}
		
		Element addChild(String property, JsonObject child){
			if(child == null || child.isJsonNull())
				return this;
			root.add(property, child);
			return this;
		}
		
		Element addChildren(String property, JsonArray children){
			if(children == null || children.isJsonNull())
				return this;
			root.add(property, children);
			return this;
		}
		
		Element addChildren(String property, JsonElement... children){
			if(children == null || children.length == 0)
				return this;
			JsonArray validChildren = new JsonArray();
			for(JsonElement el : children){
				if(el != null && !el.isJsonNull())
					validChildren.add(el);
			}
			return addChildren(property, validChildren);
		}
		
		public JsonObject getRoot(){
			return root;
		}
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
}
