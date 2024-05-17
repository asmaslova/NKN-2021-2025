import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.geom.AffineTransform;
import java.util.ArrayList;
import java.util.Random;

public class Main extends JFrame {
    int x = 40;
    int y = 40;
    int w = 50;
    int h = 50;
    int a,b;

    Image img;
//    int angle = 0;
    Main() {

        super("Lab2");
        setSize(500, 500);
        setDefaultCloseOperation(3);
        setLayout(null);

        JButton button = new JButton("+");
        button.setBounds(x,y,10,10);
        add(button);

        Cursor cursor = button.getCursor();
        button.setCursor(Cursor.getPredefinedCursor(Cursor.CROSSHAIR_CURSOR));

        Pic pic = new Pic("uwuu.jpg");
        pic.setBounds(x+100,y+100,w+50,h+50);
        add(pic);

        img = new ImageIcon("uwuu.jpg").getImage();

        ArrayList<Pic> meteors = new ArrayList<Pic>(10);
        for(int i = 0; i<10;i++){
            meteors.add(createMeteor());
        }

        button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                meteors.add(createMeteor());
            }
        });

        Thread rotateThread = new Thread(new Runnable() {
            @Override
            public void run() {
                while(true){
                    for(Pic pic : meteors){
                        pic.angle+=3;
                        pic.repaint();
                    }
                    try{
                        Thread.sleep(10);
                    } catch(Exception e){
                        return;
                    };
                }
            }
        });
        rotateThread.start();
/*
        Timer timer = new Timer(25, new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {
                x += 3;
//                angle += 2;
                pic.setLocation(x,y);
                pic.angle += 2;
//                repaint();


            }
        });
//        timer.start();

 */

        Parallel p = new Parallel(pic);
        Thread th = new Thread(p);
        th.start();

        setVisible(true);
    }
//    @Override
//    public void paint(Graphics g){
//        super.paint(g);
////        g.drawRect(x,y,40,40);
////        g.drawImage(img,x,y,w,h,null);
//        Graphics2D g2 = (Graphics2D) g;
//        AffineTransform at = g2.getTransform();
//        at.rotate(Math.toRadians(angle),x+w/2,y+w/2);
//        g2.setTransform(at);
//        g2.drawImage(img,x,y,w,h,null);
//        g2.drawImage(img,x,y+100,w,h,null);
//        at.rotate(-Math.toRadians(angle),x+w/2,y+w/2);
//        at.rotate(-Math.toRadians(angle),x,y+100);
//        g2.setTransform(at);
//        g2.drawImage(img,x,y+100,w,h,null);
//        g2.drawImage(img,x-100,y+100,w,h,null);
//    }

    Pic createMeteor(){
        Random rng = new Random();
        Pic pic = new Pic("cute.jpg");
        pic.setBounds(rng.nextInt(getWidth()),rng.nextInt(getHeight()),a=100+rng.nextInt(20), b=100+rng.nextInt(20));
        add(pic);
        return pic;
    }

    public static void main(String[] args) {

        System.out.println("Hello world!");
        new Main();

    }
}