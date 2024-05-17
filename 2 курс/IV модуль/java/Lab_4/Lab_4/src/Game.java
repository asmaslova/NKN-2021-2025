import javax.swing.*;
import java.util.Random;

public class Game implements Runnable{
    PIc topBar, botBar, bird;
    void genBars(){
        Random rng = new Random();
        int h = 50 + rng.nextInt(100);
        topBar.setBounds(200, 0, 50, 200-h);
        botBar.setBounds(200, 300-h, 50, h);
    }
    Game(JFrame frame){
        topBar = new PIc("Img/duck2.png");
        frame.add(topBar);
        botBar = new PIc("Img/duck2.png");
        frame.add(botBar);
        bird = new PIc("Img/duck2.png");
        frame.add(bird);
        bird.setBounds(80,150,40,20);
        genBars();
    }

    float vy = 0;

    @Override
    public void run() {
        int delay = 30;
        AI ai = new AI (new float[] {40.423004f, -15.827821f, 35.770454f, -73.18256f, -164.33836f});
        while (true){
            bird.setLocation(bird.getX(),  (int) (bird.getY() +(vy*delay/1000)));
            vy += 3;
            topBar.setLocation(topBar.getX() - 1, topBar.getY());
            botBar.setLocation(botBar.getX() - 1, botBar.getY());


            if( ai.shouldJump(topBar.getX(), bird.getY(), botBar.getHeight(), vy))//jump of ai
                vy = -30;
            if (bird.getBounds().intersects(topBar.getBounds()) || bird.getBounds().intersects(botBar.getBounds()) || bird.getY() > 280 || bird.getY() < 0)
                return;
            if (topBar.getX() < -50)
                genBars();
            try {
                Thread.sleep(delay);
            } catch (Exception e){
                return;
            }
        }

    }
}
