import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.geom.AffineTransform;
import java.util.ArrayList;
import java.util.Random;

public class Main extends JFrame {
    Main() {

        super("Lab4");
        setSize(200, 300);
        setDefaultCloseOperation(3);
        setLayout(null);
        Game game = new Game(this);
        new Thread(game).start();
        addKeyListener(new KeyListener() {
            @Override
            public void keyTyped(KeyEvent e) {

            }

            @Override
            public void keyPressed(KeyEvent e) {
                if (e.getKeyCode() == KeyEvent.VK_SPACE) {
                    game.by = -30;
                }

            }

            @Override
            public void keyReleased(KeyEvent e) {

            }
        });

        setVisible(true);
    }



    public static void main(String[] args) {

        System.out.println("Hello world!");
        new Main();

    }
}