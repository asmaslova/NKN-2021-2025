package Back.ML;

import Back.Circle;
import UI.Cursor;
import UI.Pic;

import javax.swing.*;
import java.util.ArrayList;

public class Simulator{
    protected static int score = 0;
    protected static int  a_score = 600;

    JFrame help;
    ArrayList<Circle> circles = new ArrayList<Circle>();
    int time = 0;
    Cursor cursor = new Cursor();
    Pic score_bar;
    ArrayList<Circle> cc = new ArrayList<>(10);
    AI ai;
    Simulator(AI ai){
        this.ai = ai;
        score = 0;
        a_score = 600;
    }
     
    boolean isCircle(int x, int y){
        for(Circle c: circles){
            if((x < c.xs + c.small_size) && (x > c.xs)){
                if((y < c.ys + c.small_size) && (y > c.ys)){
                         return true;
                }
            }
        }
        return false;
    }

    public int run(){

        circles.add(new Circle(help, score, a_score, cc, score_bar));
        int total_time = 0;
        int time_left;
        while(score<100000) {
            if (a_score <= 0) {
                return total_time;
            }
            //for deleting
            //circle disappearing first
            if(circles.size() == 0)
                circles.add(new Circle(help, score, a_score, cc, score_bar));
            //
            Circle round = circles.get(0);
            time_left = (round.xs - round.xb) * 5;
            //adding new every 0.5s
            if (time % 500 == 0) circles.add(new Circle(help, score, a_score, cc, score_bar));
            //deciding click or not
            int[] tmp = ai.shouldClick(cursor.curs.getX()+10, cursor.curs.getY()+10, round.xs+50, round.ys+50, time_left);
            
            cursor.move(tmp[1],tmp[2]);
            //+10 for center of circle instead of edge of square
            if ((tmp[0] == 0) && (isCircle(cursor.curs.getX()+10,cursor.curs.getY()+10))){
                if (((round.xs - round.xb) < 15)) {
                    score += 300;
                    a_score += 40;
                } else if (round.xs - round.xb < 25) {
                    score += 200;
                    a_score += 20;
                } else if (round.xs - round.xb < 40) {
                    score += 100;
                    a_score += 10;
                } else if (round.xs - round.xb < 60) {
                    a_score -= 20;
                } else {
                    a_score -= 50;
                }
                //deleting
                cc.add(round);
            }
            //auto deleting
            for (Circle c : circles) {
                if ((c.xs - c.xb < -15)) {
                    cc.add(c);
                    a_score -= 50;
                }
                c.big_size -= 10;
                c.xb += 5;
                c.yb += 5;
                c.change();

            }
            for (Circle c : cc) {
                circles.remove(c);
            }
            time += 25;
            total_time += 25;
        }
        return total_time;

    }
    public static void setScore(int value){
        score = value;
    }
    public static void setA_score(int value){
        a_score = value;
    }
}
