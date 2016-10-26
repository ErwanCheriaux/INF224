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

    //Listner
    button1.addActionListener(new Button1Listner());
    button2.addActionListener(new Button2Listner());
    buttonExit.addActionListener(new ButtonExitListner());

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
  class Button1Listner implements ActionListener{
    public void actionPerformed(ActionEvent e){
      textArea.append(textField.getText() + "\r\n");
    }
  }

  class Button2Listner implements ActionListener{
    public void actionPerformed(ActionEvent e){
      System.out.println("Bouton 2 appuyé");
    }
  }

  class ButtonExitListner implements ActionListener{
    public void actionPerformed(ActionEvent e){
      System.out.println("Bouton exit appuyé");
      System.exit(0);
    }
  }
}
