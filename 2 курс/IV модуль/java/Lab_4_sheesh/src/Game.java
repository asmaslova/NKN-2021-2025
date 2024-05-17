import javax.swing.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.Random;

public class Game implements Runnable{
    PIc scoreBar, bird;
    int xs,ys,as=25,bs=25;
    int xb,yb,ab=50,bb=50, xbi, ybi;
    int score, a_score;
    JLabel circleSmall = new JLabel(new ImageIcon("pics/circle_small.png")); //24x24
    JLabel circleBig = new JLabel(new ImageIcon("pics/circle_big.png"));//50x50
    JLabel score_bar_back = new JLabel(new ImageIcon("pics/score_bar_back.png")); //50x50
    JLabel score_bar = new JLabel(new ImageIcon("pics/score_back.png")); //30x30

    /*void genBars(){
        Random rng = new Random();
        int h = 50 + rng.nextInt(100);
        //scoreBar.setBounds(200, 0, 50, 200-h);
    }*/

    Game(JFrame frame){
        Random rng = new Random();
        xs=rng.nextInt(500);
        ys=rng.nextInt(500);
        xbi=xb=xs-25; ybi=yb=ys-25;
        score=0; a_score=10;

        score_bar_back.setBounds(10,10,100, 50);
        score_bar.setBounds(20,20,a_score,30);

        circleSmall.setBounds(xs,ys,as,bs);
        circleBig.setBounds(xb,yb,ab,bb);

        frame.add(circleSmall);
        frame.add(circleBig);

        //scoreBar = new PIc(""); //раз в полсекунды появл., сеукнда на схождение
        //когда большой круг = маленький круг - 300
        //когда большой круг внутри маленького круга - -очки
        //когда большой круг-маленький круг=50 - 50
        //когда большой круг-маленький круг = 25 - 100
        while(true){

            for(int i=0;i<1000;i+=10){
                circleBig.setSize(ab-5,bb-5);
                circleBig.setLocation(xb-5,yb-5);
                circleBig.repaint();
            }
            try{
                Thread.sleep(10);
            } catch(Exception e){
                return;
            };

            circleSmall.addMouseListener(new MouseListener() {
                @Override
                public void mouseClicked(MouseEvent e) {
                    if((xs-xb)>(xs-5) && (xs-xb)>(xs+5)){
                        ab=50; bb=50;
                        score+=300;
                        a_score+=30;
                        xs = rng.nextInt(500);
                        ys = rng.nextInt(500);
                        xbi = xb = xs-25;
                        ybi = yb = ys-25;
                    } else if((xs-xb)<(xs-5) && (xs-xb)>xbi){
                        ab=50; bb=50;
                        score+=200;
                        a_score+=10;
                        xs = rng.nextInt(500);
                        ys = rng.nextInt(500);
                        xbi = xb = xs-25;
                        ybi = yb = ys-25;
                    } else if((xs-xb)>(xs+5)){
                        ab=50; bb=50;
                        score-=100;
                        a_score-=20;
                        xs = rng.nextInt(500);
                        ys = rng.nextInt(500);
                        xbi = xb = xs-25;
                        ybi = yb = ys-25;
                    } else if((xs-xb)<xbi){
                        ab=50; bb=50;
                        score-=100;
                        a_score-=20;
                        xs = rng.nextInt(500);
                        ys = rng.nextInt(500);
                        xbi = xb = xs-25;
                        ybi = yb = ys-25;
                    }
                }


                @Override
                public void mousePressed(MouseEvent e) {

                }

                @Override
                public void mouseReleased(MouseEvent e) {

                }

                @Override
                public void mouseEntered(MouseEvent e) {

                }

                @Override
                public void mouseExited(MouseEvent e) {

                }
            });
            score_bar.repaint();
        }
    }

        /*topBar = new PIc("Img/duck2.png");
        frame.add(topBar);
        botBar = new PIc("Img/duck2.png");
        frame.add(botBar);
        bird = new PIc("Img/duck2.png");
        frame.add(bird);
        bird.setBounds(80,150,40,20);
        genBars();*/


    float vy = 0;

    @Override
    public void run() {
        int delay = 30;
        AI ai = new AI (new float[] {-0.12063122f, 33.43747f, -0.06798172f, -79.229706f, -157.97679f});
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
