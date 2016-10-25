import javax.swing.*;

public class Window extends JFrame{ // fenetre principale

  JButton button1 = null;
  JButton button2 = null;
  JButton buttonExit = null;

  public Window(){

    button1 = new JButton("SUPER BOUTON");
    add(button1);

    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    setTitle("Client Multimédia");
    pack();
    setVisible(true);
  }
}
