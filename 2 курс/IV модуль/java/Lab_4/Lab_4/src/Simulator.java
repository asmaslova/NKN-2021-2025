import javax.swing.*;
import java.util.Random;

public class Simulator {
    PIc topBar, botBar, bird;
    void genBars(){
        Random rng = new Random();
        int h = 50 + rng.nextInt(100);
        topBar.setBounds(200, 0, 50, 200-h);
        botBar.setBounds(200, 300-h, 50, h);
    }
    Simulator(){
        topBar = new PIc("Img/duck2.png");
        botBar = new PIc("Img/duck2.png");
        bird = new PIc("Img/duck2.png");
        bird.setBounds(80,150,40,20);
        genBars();
    }

    float vy = 0;

    public int run(AI ai) {
        int delay = 30;
        int total_time = 0;
        while (total_time < 10000000) {
            total_time += delay;
            if (ai.shouldJump(topBar.getX(), bird.getY(), botBar.getHeight(), vy))
                vy = -30;

            bird.setLocation(bird.getX(), (int) (bird.getY() + (vy * delay / 1000)));
            vy += 3;
            topBar.setLocation(topBar.getX() - 1, topBar.getY());
            botBar.setLocation(botBar.getX() - 1, botBar.getY());
            if (bird.getBounds().intersects(topBar.getBounds()) || bird.getBounds().intersects(botBar.getBounds()) || bird.getY() > 280 || bird.getY() < 0)
                return total_time;
            if (topBar.getX() < -50) {
                genBars();
            }
        }
        return total_time;
    }

}
