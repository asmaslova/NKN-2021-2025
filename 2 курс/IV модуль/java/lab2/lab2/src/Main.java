// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.Random;
import javax.swing.*;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
class Main extends JFrame {
    Main() {
        super("Hatsune Miku: Yandere Love");
        setSize(Toolkit.getDefaultToolkit().getScreenSize().width, Toolkit.getDefaultToolkit().getScreenSize().height);
        setDefaultCloseOperation(3);
        setLayout(null);

        JPanel game = new JPanel();
        game.setBounds(0, 0, 1920, 1080);
        game.setLayout(null);
        add(game);

        JPanel mainMenu = new JPanel();
        mainMenu.setBounds(0, 0, 1920, 1080);
        mainMenu.setLayout(null);
        add(mainMenu);

        JButton start_game = new JButton("Начать игру");
        start_game.setBounds(1400, 400, 400, 100);
        mainMenu.add(start_game);

        JButton close_game = new JButton("Покинуть игру");
        close_game.setBounds(1400, 520, 400, 100);
        mainMenu.add(close_game);

        JLabel startLabel = new JLabel(new ImageIcon("miku_pic/start.jpeg"));
        startLabel.setBounds(0, 0, 1920, 1080);
        mainMenu.add(startLabel);

        JButton game_menu = new JButton("Главное меню");
        game_menu.setBounds(0, 44, 228, 63);
        game.add(game_menu);

        JPanel gameMenu = new JPanel();
        gameMenu.setBounds(0, 0, 1920, 1080);
        gameMenu.setLayout(null);
        add(gameMenu);

        JButton continue_game = new JButton("Продолжить игру");
        continue_game.setBounds(760, 400, 400, 100);
        gameMenu.add(continue_game);

        JButton leave_game = new JButton("Покинуть игру");
        leave_game.setBounds(760, 520, 400, 100);
        gameMenu.add(leave_game);

        JLabel pauseLabel = new JLabel(new ImageIcon("miku_pic/pause.jpg"));
        pauseLabel.setBounds(0, 0, 1920, 1080);
        gameMenu.add(pauseLabel);

        String text1 = "miku_pic/uwu.txt";
        String text = readFile(text1);
        JButton textArea = new JButton(text);
        textArea.setBounds(20, 140, 300, 100);
        textArea.setFont(new Font("Arial", Font.BOLD, 15));
        textArea.setBackground(new Color(255, 197, 0));
        game.add(textArea);

        start_game.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent a){
                mainMenu.setVisible(false);
                game.setVisible(true);
            }
        });

        close_game.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent a){
                System.exit(0);
            }
        });

        leave_game.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent a){
                System.exit(0);
            }
        });

        game_menu.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent a){
                game_menu.setVisible(false);
                game.setVisible(false);
                gameMenu.setVisible(true);
                }
        });

        continue_game.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent a){
                game_menu.setVisible(true);
                game.setVisible(true);
                gameMenu.setVisible(false);
            }
        });




        setVisible(true);
        game.setVisible(false);
        gameMenu.setVisible(false);
    }
    public static void main (String[]args){
        new Main();

    }
}