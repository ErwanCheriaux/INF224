import javax.swing.*;

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.Color;

import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Window extends JFrame{ // fenetre principale

  private static final long serialVersionUID = 1L;

  private Client client;

  private JPanel  panel;
  private JButton buttonFind;
  private JButton buttonPlay;
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
    buttonFind = new JButton("Bouton 1");
    buttonPlay = new JButton("Bouton 2");
    buttonExit = new JButton("EXIT");
    textField = new JTextField();
    textArea = new JTextArea(5,5);
    scroll = new JScrollPane(textArea);
    menuBar = new JMenuBar();
    menu = new JMenu("Menu");
    toolBar = new JToolBar("ToolBar");

    //Action
    FindAction findAction = new FindAction();
    PlayAction playAction = new PlayAction();
    ExitAction exitAction = new ExitAction();

    buttonFind.setAction(findAction);
    buttonPlay.setAction(playAction);
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
    menu.add(findAction);
    menu.add(playAction);
    menu.add(exitAction);
    menuBar.add(menu);
    toolBar.add(findAction);
    toolBar.add(playAction);
    toolBar.add(exitAction);
    menuBar.add(toolBar);
    setJMenuBar(menuBar);

    //panel pour les boutons et le textField
    panel.setLayout(new GridLayout(1, 4));
    panel.add(textField);
    panel.add(buttonFind);
    panel.add(buttonPlay);
    panel.add(buttonExit);

    //Ajout des composants sur la fenetre
    add(scroll, BorderLayout.CENTER);
    add(panel, BorderLayout.SOUTH);

    setVisible(true);

    try {
      client = new Client(Client.DEFAULT_HOST, Client.DEFAULT_PORT);
    } catch (java.io.IOException e) {
      client = null;
    }
  }

  //Classes imbriquées
  private class FindAction extends AbstractAction {
    private FindAction() {
        super("Find");
    }

    public void actionPerformed(ActionEvent e) {
        String text = textField.getText();

        System.out.println("FIND: "+ text);
        text = client.send("find "+ text);
        textArea.append(text);
    }
  }

  private class PlayAction extends AbstractAction {
    private PlayAction() {
        super("Play");
    }

    public void actionPerformed(ActionEvent e) {
        System.out.println("PLAY");
    }
  }

  private class ExitAction extends AbstractAction {
    private ExitAction() {
        super("Exit");
    }

    public void actionPerformed(ActionEvent e) {
        System.out.println("EXIT");
        System.exit(0);
    }
  }
}
