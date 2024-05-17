import javax.swing.*;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

public class Main extends JFrame {
    Main () {
        super("Flappy_Bird");
        setSize(200,300);
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
                if (e.getKeyCode() == KeyEvent.VK_SPACE)
                    game.vy = -30;

            }

            @Override
            public void keyReleased(KeyEvent e) {

            }
        });
        setVisible(true);
    }
    public static void main(String[] args) { new Main();}
}