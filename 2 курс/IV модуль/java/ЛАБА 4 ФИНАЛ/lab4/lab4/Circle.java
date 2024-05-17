import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.geom.AffineTransform;
import java.util.ArrayList;
import java.util.Random;

public class Circle extends JComponent {
    private Game game;
    Pic small_circle = new Pic("pics/circle_small.png");
    Pic big_circle = new Pic("pics/circle_big.png");
    int xs, ys, xb, yb;
    int small_size = 100;
    int big_size = 300;
    int score, a_score;
    ArrayList<Circle> black_list;
    Pic score_bar;

    Circle (JFrame frame, int score, int a_score, ArrayList<Circle> black_list, Pic score_bar){

        this.score = score;
        this.a_score = a_score;
        this.black_list = black_list;
        this.score_bar = score_bar;

        Random rng = new Random();
        xs = 150 + rng.nextInt(350);
        ys = 150 + rng.nextInt(350);
        xb = xs - 100;
        yb = ys - 100;
        small_circle.setBounds(xs,ys,small_size,small_size);
        big_circle.setBounds(xb,yb,big_size,big_size);

        if (frame != null){
        frame.add(small_circle);
        frame.add(big_circle);
        }

        small_circle.addMouseListener(new MouseListener() {
            @Override
            public void mouseClicked(MouseEvent e) {
                do_doing();

            }

            @Override
            public void mousePressed (MouseEvent e){

            }

            @Override
            public void mouseReleased (MouseEvent e){

            }

            @Override
            public void mouseEntered (MouseEvent e){

            }

            @Override
            public void mouseExited (MouseEvent e){

            }
        });
    }

    void hide(JFrame frame){
        frame.remove(small_circle);
        frame.remove(big_circle);
    }
    void change(){
        big_circle.setBounds(xb,yb,big_size,big_size);

    }
    void do_doing(){
        if ((xs - xb) < 15) {
            score += 300;
            a_score += 40;
                        /*Numbers wow = new Numbers(help,score);
                        wow.setBounds(round.xs,round.ys,100,20);
                        wow.add(help);
                        wow.setVisible(true);
                        try{
                            Thread.sleep(70);
                        } catch(Exception a){
                            return;
                        };
                        wow.setVisible(false);*/
        } else if (xs - xb < 25) {
            score += 200;
            a_score += 20;
                        /*Numbers wow = new Numbers(help,score);
                        wow.setBounds(round.xs,round.ys,100,20);
                        wow.add(help);
                        wow.setVisible(true);
                        try{
                            Thread.sleep(70);
                        } catch(Exception a){
                            return;
                        };
                        wow.setVisible(false);*/
        } else if (xs - xb < 40) {
            score += 100;
            a_score += 10;
                        /*Numbers wow = new Numbers(help,score);
                        wow.setBounds(round.xs,round.ys,100,20);
                        wow.add(help);
                        wow.setVisible(true);
                        try{
                            Thread.sleep(70);
                        } catch(Exception a){
                            return;
                        };
                        wow.setVisible(false);*/
        } else if (xs - xb < 60) {
            //game.score -= 100;
            a_score -= 20;
                        /*Numbers wow = new Numbers(help,score);
                        wow.setBounds(round.xs,round.ys,100,20);
                        wow.add(help);
                        wow.setVisible(true);
                        try{
                            Thread.sleep(130);
                        } catch(Exception a){
                            return;
                        };
                        wow.setVisible(false);*/
        } else {
            //game.score -= 300;
            a_score -= 50;
                        /*Numbers wow = new Numbers(help,score);
                        wow.setBounds(round.xs,round.ys,100,20);
                        wow.add(help);
                        wow.setVisible(true);
                        try{
                            Thread.sleep(130);
                        } catch(Exception a){
                            return;
                        };
                        wow.setVisible(false);*/

        }

        big_circle.setVisible(false);
        small_circle.setVisible(false);
        black_list.add(Circle.this);
        if (a_score > 600) a_score = 600;

        if (score_bar != null) {
            Game.setScore(score);
            Game.setA_score(a_score);
            score_bar.setBounds(10, 10, a_score, 50);
            score_bar.repaint();
        }
        else{
            Simulator.setScore(score);
            Simulator.setA_score(a_score);
        }
        //System.out.println(a_score);
    }
}