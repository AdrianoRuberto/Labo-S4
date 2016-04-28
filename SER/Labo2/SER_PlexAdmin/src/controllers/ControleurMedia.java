package controllers;

import java.io.BufferedWriter;
import java.io.FileOutputStream;
import java.io.OutputStreamWriter;

import com.thoughtworks.xstream.XStream;

import models.*;
import views.*;

public class ControleurMedia {

	private ControleurGeneral ctrGeneral;
	private static MainGUI mainGUI;
	private ORMAccess ormAccess;
	
	private GlobalData globalData;

	public ControleurMedia(ControleurGeneral ctrGeneral, MainGUI mainGUI, ORMAccess ormAccess){
		this.ctrGeneral=ctrGeneral;
		ControleurMedia.mainGUI=mainGUI;
		this.ormAccess=ormAccess;
	}

	public void sendJSONToMedia(){
		new Thread(){
			public void run(){
				mainGUI.setAcknoledgeMessage("Envoi JSON ... WAIT");
				//long currentTime = System.currentTimeMillis();
				try {
					globalData = ormAccess.GET_GLOBAL_DATA();
				}
				catch (Exception e){
					mainGUI.setErrorMessage("Construction XML impossible", e.toString());
				}
				
				JSONSerializer serializer = new JSONSerializer();
				writeToFile("data.json", serializer, globalData);
			}
		}.start();
	}
	
	private static void writeToFile(String filename, JSONSerializer serializer, Object data) {
		try {
			BufferedWriter out = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(filename), "UTF-8"));
			serializer.toJSON(data, out);
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}