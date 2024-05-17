package Back;

import Back.ML.AI;
import UI.Cursor;
import UI.Pic;

import javax.swing.*;
import java.util.ArrayList;


public class Game implements Runnable {
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
    UI.Cursor cursor;

    public Game(JFrame frame){
        cursor = new Cursor();
        frame.add(cursor.curs);
        help = frame;
	    score_label = new JLabel("0");
	    
        label.setBounds(0, 0, 1000, 600);
        score_bar_back.setBounds(10,10,600, 50);
        score_bar.setBounds(33,10, a_score, 50);     
        score_label.setBounds(650,10,40,40);

        frame.add(score_label);
        frame.add(score_bar_back);
        frame.add(score_bar);
    }

    public void run(){

        circles.add(new Circle(help, score, a_score, cc, score_bar));
        AI ai = new AI(new float[]{0.441863f, -0.23721218f, 0.16914546f, -0.01605624f, 0.33772004f, 0.46586043f,
                -0.2462011f, 0.2178669f, -0.1945402f, -0.40845215f,
                -0.12985784f, 0.2939337f, -0.4655137f, -0.25391614f});
        while(true){
		    if (a_score<=0) {
			System.exit(0);
		    }
            score_bar.setBounds(10, 10, a_score, 50);
            score_bar.repaint();

            ArrayList<Circle> cc = new ArrayList<Circle>();//list for deleting
            if (time % 500 == 0) circles.add(new Circle(help, score, a_score, cc, score_bar));//adding circle every 0.5s
            Circle round = circles.get(0);
            int             time_left = (round.xs - round.xb) * 5;

            int[] tmp = ai.shouldClick(cursor.curs.getX()+10, cursor.curs.getY()+10, round.xs+50, round.ys+50, time_left);

            cursor.move(tmp[1],tmp[2]);
            //cursor.move(circles.get(0).xs+50, circles.get(0).ys+50);//checking how cursor works
            if ((tmp[0] == 0) && (round.inCircle(cursor.curs.getX()+10,cursor.curs.getY()+10))) {
                round.do_doing();
            }
                for (Circle c : circles) {
		//auto deleting in case of inactivity
                if ((c.xs - c.xb < -15)) {
                    cc.add(c);
                    a_score -= 50;
                    score_bar.setBounds(10,10, a_score, 50);
                    score_bar.repaint();
                }
		//decreasing distance between big and small
                c.big_size -= 10;
                c.xb += 5;
                c.yb += 5;
                c.change();
                help.repaint();
            }
	    //deleting
            for (Circle c : cc) {
                c.hide(help);
                circles.remove(c);
            }
            score_label.setText(""+score);
            try{
                time += 25;
                Thread.sleep(25);
            } catch(Exception e){
                return;
            }
        }
    }
    static void setScore(int value){
        score = value;
    }
    static void setA_score(int value){
        a_score = value;
    }
}

