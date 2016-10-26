import javax.swing.*;

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.Color;

import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Window extends JFrame{ // fenetre principale

  private static final long serialVersionUID = 1L;

  private JPanel  panel;
  private JButton button1;
  private JButton button2;
  private JButton buttonExit;
  private JTextArea textArea;
  private JTextField textField;
  private JScrollPane scroll;
  private JMenuBar menuBar;
  private JMenu menu;
  private JToolBar toolBar;


  public Window(){

    //new
    panel = new JPanel();
    button1 = new JButton("Bouton 1");
    button2 = new JButton("Bouton 2");
    buttonExit = new JButton("EXIT");
    textField = new JTextField();
    textArea = new JTextArea(5,5);
    scroll = new JScrollPane(textArea);
    menuBar = new JMenuBar();
    menu = new JMenu("A Menu");
    toolBar = new JToolBar("ToolBar");

    //Action
    FindAction findAction = new FindAction();
    PlayAction playAction = new PlayAction();
    ExitAction exitAction = new ExitAction();

    button1.setAction(findAction);
    button2.setAction(playAction);
    buttonExit.setAction(exitAction);

    //Parametre fenetre
    setTitle("Client Multimédia");
    setSize(400, 200);
    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    setLocationRelativeTo(null);
    //pack(); //minimise la fenetre lors de son ouverture
    setMinimumSize(new Dimension(300,300));
    setLayout(new BorderLayout());

    //Menu
    menuBar.add(menu);
    setJMenuBar(menuBar);

    //toolBar
    setPreferredSize(new Dimension(450, 130));
    add(toolBar, BorderLayout.PAGE_START);

    //panel pour les boutons et le textField
    panel.setLayout(new GridLayout(1, 4));
    panel.add(textField);
    panel.add(button1);
    panel.add(button2);
    panel.add(buttonExit);

    //Ajout des composants sur la fenetre
    add(scroll, BorderLayout.CENTER);
    add(panel, BorderLayout.SOUTH);

    setVisible(true);
  }

  //Classes imbriquées
  class FindAction extends AbstractAction {
    public FindAction() {
        super("Find");
    }

    public void actionPerformed(ActionEvent e) {
        System.out.println("FIND");
    }
  }

  class PlayAction extends AbstractAction {
    public PlayAction() {
        super("Play");
    }

    public void actionPerformed(ActionEvent e) {
        System.out.println("PLAY");
    }
  }

  class ExitAction extends AbstractAction {
    public ExitAction() {
        super("Exit");
    }

    public void actionPerformed(ActionEvent e) {
        System.out.println("EXIT");
    }
  }
}
