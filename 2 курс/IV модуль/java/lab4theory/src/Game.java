import javax.swing.*;
import java.util.Random;

class Game implements Runnable {
    Pic topBar, botBar, bird;
    float by = 0;
    Game(JFrame frame){
        topBar = new Pic("images/bar.png");
        frame.add(topBar);
        botBar = new Pic("images/bar.png");
        frame.add(botBar);
        bird = new Pic("images/bird.png");
        frame.add(bird);
        bird.setBounds(80,150,20,20);
        genBars();
    }

    void genBars(){
        Random rng = new Random();
        int h = 50+rng.nextInt(100);
        topBar.setBounds(200,0,50,200-h);
        botBar.setBounds(200, 300-h,50,h);

    }

    public void run(){
        int delay = 30;
        while(true){
            bird.setLocation(bird.getX(), (int)(bird.getY()+by*delay/1000));
            by+=3;
            topBar.setLocation(topBar.getX()-1, topBar.getY());
            botBar.setLocation(botBar.getX()-1, botBar.getY());
            if(bird.getBounds().intersects(topBar.getBounds()) || bird.getBounds().intersects(botBar.getBounds()) || bird.getY()<=0 || bird.getY()>=280){
                return;
            }
            if(topBar.getX()<-50){
                genBars();
            }
            try{
                Thread.sleep(delay);
            } catch(Exception e){
                return;
            }
        }
    }

}
