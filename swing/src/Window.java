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

    button1.addActionListener(new Button1Listner());
    button2.addActionListener(new Button2Listner());

    add(button1);
    add(button2);

    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    setTitle("Client Multimédia");
    setSize(300, 300);
    pack();
    setVisible(true);
  }

  //Classes imbriquées
  class Button1Listner implements ActionListener{
    public void actionPerformed(ActionEvent e){

    }
  }

  class Button2Listner implements ActionListener{
    public void actionPerformed(ActionEvent e){
      System.out.println("COUCOU");
    }
  }

  class ButtonExitListner implements ActionListener{
    public void actionPerformed(ActionEvent e){

    }
  }
}
