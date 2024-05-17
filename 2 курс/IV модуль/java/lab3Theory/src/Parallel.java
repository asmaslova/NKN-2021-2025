import java.awt.*;

class Parallel implements Runnable{
    Pic pic;
    Parallel(Pic pic){this.pic = pic;}

    @Override
    public void run(){
        try{
            Thread.sleep(2000);
        } catch(Exception e){
            return;
        };
        for(int i = 0; i<500; i++) {
            pic.angle += 5;
            pic.repaint();
            try{
                Thread.sleep(10);
            } catch(Exception e){
                return;
            };
        }

/*        while(true) {
            pic.angle += 5;
            pic.repaint();
            try{
                Thread.sleep(50);
            } catch(Exception e){
                return;
            };
        }*/
    }
}
