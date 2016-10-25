import javax.swing.*;

import java.awt.BorderLayout;

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

  public Window(){

    panel = new JPanel();

    button1 = new JButton("Bouton 1");
    button2 = new JButton("Bouton 2");
    buttonExit = new JButton("EXIT");

    textArea = new JTextArea(5,5);

    //button1.addActionListener(new Button1Listner());
    //button2.addActionListener(new Button2Listner());

    setTitle("Client Multimédia");
    setSize(300, 150);
    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    setLocationRelativeTo(null);
    //pack();
    panel.setLayout(new GridLayout(1, 3));
    //getContentPane().add(button1, BorderLayout.CENTER);
    panel.add(button1);
    panel.add(button2);
    panel.add(buttonExit);

    setLayout(new BorderLayout());
    add(textArea, BorderLayout.CENTER);
    add(panel, BorderLayout.SOUTH);
    setVisible(true);
  }

  //Classes imbriquées
  class Button1Listner implements ActionListener{
    public void actionPerformed(ActionEvent e){
      System.out.println("Bouton 1 appuyé");
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
    }
  }
}
