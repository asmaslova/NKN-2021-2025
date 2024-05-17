package Back;

import javax.sound.sampled.Clip;
import java.util.ArrayList;
import java.util.Random;

public class Pidor {

    //хуй



    /*
    private Clip badEndingMusic;
    private Clip baddestEndingMusic;*/

    ArrayList<Pic> circles = new ArrayList<Pic>(10);
    circles.add(createTriangle(1150, 700));
    circles.add(createTriangle(1180, 700));
    circles.add(createTriangle(1165, 675));

    Thread thinThread = new Thread(new Runnable() {
        @Override
        public void run(){
            while(true){
                for(Pic pic : triangles){
                    pic.angle += 4;
                    pic.repaint();}
                try{
                    Thread.sleep(13);
                }
                catch(Exception e){
                    return;
                }}}});
        rotateThread.start();

    Pic createTriangle(int x, int y){
        Random rng = new Random();
        Pic pic = new Pic("miku_pic/blade.png");
        pic.setBounds(x,y, 50, 50);

        return pic;
    }

    void hide_triangles(ArrayList <Pic> triangles){
        for(Pic pic : triangles){
            pic.setVisible(false);
            //pic.repaint();
        }
    }
}

