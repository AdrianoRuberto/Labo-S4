package Displayers;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ComponentAdapter;
import java.awt.event.ComponentEvent;
import java.awt.event.KeyAdapter;
import java.awt.image.BufferedImage;

public class JBounce extends JFrame implements Displayer {

   private static JBounce instance;
   private BufferedImage bi;

   private JBounce() {
	  setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	  setSize(new Dimension(500, 500));
	  bi = new BufferedImage(getWidth(), getHeight(), BufferedImage.TYPE_INT_ARGB);

	  // Pour le resize de l'image, mettre à jour l'image bufferisée
	  addComponentListener(new ComponentAdapter() {
		 @Override
		 public void componentResized(ComponentEvent e) {
			super.componentResized(e);
			bi = new BufferedImage(getWidth(), getHeight(), BufferedImage.TYPE_INT_ARGB);
		 }
	  });
	  setVisible(true);
   }

   public static JBounce getInstance() {
	  if (instance == null) instance = new JBounce();
	  return instance;
   }

   public void repaint() {
	  Graphics2D g2 = (Graphics2D) super.getGraphics();
	  g2.setColor(Color.white);
	  g2.fillRect(0, 0, getWidth(), getHeight());
	  g2.drawImage(bi, 0, 0, null);
   }

   @Override
   public Graphics2D getGraphics() {
	  return (Graphics2D) bi.getGraphics();
   }


   @Override
   public void addKeyListener(KeyAdapter ka) {
	  super.addKeyListener(ka);
   }

   public void clear() {
	  Graphics2D g2 = (Graphics2D) bi.getGraphics();
	  g2.setBackground(Color.white);
	  g2.clearRect(0, 0, getWidth(), getHeight());
   }
}
