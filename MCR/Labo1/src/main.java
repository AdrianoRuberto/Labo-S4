/**
 * Créer le menu avec les différents boutons pour gérer les chronomètres
 *
 * @author Adriano Ruberto
 * @author Matthieu Villard
 * @version 1.0
 */

import javax.swing.*;
import java.awt.*;

public class main {

   public static void main(String... args) {
	  Chrono chrono = new Chrono();
	  JFrame frame = new JFrame();
	  frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

	  JPanel mainPanel = new JPanel();
	  mainPanel.setLayout(new GridLayout(2, 0));
	  frame.add(mainPanel);

	  JPanel clockCreator = new JPanel();
	  mainPanel.add(clockCreator);
	  JPanel clockControl = new JPanel();
	  mainPanel.add(clockControl);

	  final JButton rom = new JButton("Horloge romaine");
	  clockCreator.add(rom);
	  rom.addActionListener(e -> new RomanClockView(chrono));

	  final JButton arab = new JButton("Horloge arabe");
	  clockCreator.add(arab);
	  arab.addActionListener(e -> new ArabicClockView(chrono));

	  final JButton num = new JButton("Horloge numérique");
	  clockCreator.add(num);
	  num.addActionListener(e -> new DigitalClockView(chrono));

	  final JButton mixte = new JButton("Horloge mixte");
	  clockCreator.add(mixte);
	  mixte.addActionListener(e -> new MixteClockView(chrono));

	  final JButton start = new JButton("Démarrer");
	  clockControl.add(start);
	  start.addActionListener(e -> chrono.start());

	  final JButton stop = new JButton("Arreter");
	  clockControl.add(stop);
	  stop.addActionListener(e -> chrono.stop());

	  final JButton reset = new JButton("Réinitialiser");
	  clockControl.add(reset);
	  reset.addActionListener(e -> chrono.reset());

	  final JButton quit = new JButton("Quitter");
	  clockControl.add(quit);
	  quit.addActionListener(e -> System.exit(0));

	  frame.pack();
	  frame.setVisible(true);
   }
}