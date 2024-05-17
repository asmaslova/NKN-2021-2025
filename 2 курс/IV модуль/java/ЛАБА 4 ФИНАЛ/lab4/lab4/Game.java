import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.Clip;
import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.io.File;
import java.util.Random;
import java.util.ArrayList;


class Game implements Runnable {
    protected static int score = 0;
    protected static int a_score = 600;
    JFrame help;
    ArrayList<Circle> cc = new ArrayList<Circle>(0);
    ArrayList<Circle> circles = new ArrayList<Circle>();
    Pic label = new Pic("pics/2.jpg");
    Pic score_bar_back = new Pic("pics/score_bar_back.png"); 
    Pic score_bar = new Pic("pics/score_bar.png");
    int time = 0;
    JLabel score_label;
    Random rng = new Random();
    Cursor cursor;

    Game(JFrame frame){
        cursor = new Cursor();
        frame.add(cursor.curs);
        help = frame;
        label.setBounds(0, 0, 1000, 600);
        
        //frame.add(label);

        score_bar_back.setBounds(10,10,600, 50);
        score_bar.setBounds(33,10, a_score, 50);
        score_label = new JLabel("0");
        score_label.setBounds(650,10,40,40);

        frame.add(score_label);
        frame.add(score_bar_back);
        frame.add(score_bar);

    }


    public void run(){

        circles.add(new Circle(help, score, a_score, cc, score_bar));

        while(true){

			if (a_score<=0) {
				System.exit(0);
			}

            score_bar.setBounds(10, 10, a_score, 50);
            score_bar.repaint();
            //System.out.println(a_score);
            final boolean[] clickProcessed = {false};

            ArrayList<Circle> cc = new ArrayList<Circle>();
            if (time % 500 == 0) circles.add(new Circle(help, score, a_score, cc, score_bar));
            Circle round = circles.get(circles.size() - 1);
            score_label.setText(""+score);

            cursor.move(circles.get(0).xs+50, circles.get(0).ys+50);
            //circles.get(0);

            for (Circle c : circles) {

                if ((c.xs - c.xb < -15)) {
                    cc.add(c);
                    a_score -= 50;
                    score_bar.setBounds(10,10, a_score, 50);
                    score_bar.repaint();
                }
                c.big_size -= 10;
                c.xb += 5;
                c.yb += 5;
                c.change();
                help.repaint();
            }
            for (Circle c : cc) {
                c.hide(help);
                circles.remove(c);
            }
            try{
                time += 25;
                Thread.sleep(25);
            } catch(Exception e){
                return;
            };
        }
    }
    static void setScore(int value){
        score = value;
    }
    static void setA_score(int value){
        a_score = value;
    }
}

