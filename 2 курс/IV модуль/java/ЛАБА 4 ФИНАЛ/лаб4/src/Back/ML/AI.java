package Back.ML;

import java.util.Random;

public class AI {
    float [] k = new float[14];
//6+4+4
    public int[] shouldClick(int x_cursor, int y_cursor, int x_small, int y_small, int time_left){
        int[] list = new int[3];
        list[0] = 0;
        if (k[0]*x_cursor+k[1]*y_cursor+k[2]*x_small+k[3]*y_small+k[4]*time_left+k[5]<0) list[0] = 1;
        float tmp = 1000*(k[6]*x_cursor+k[7]*x_small+k[8]*time_left+k[9]);
        //float tmp = k[6]*x_cursor+k[7]*y_cursor+k[8]*x_small+k[9]*y_small+k[10]*time_left+k[11];
        /*if (tmp >= 0 && tmp <= 1000)*/ list[1] = Math.round(tmp);

        //tmp = k[12]*x_cursor+k[13]*y_cursor+k[14]*x_small+k[15]*y_small+k[16]*time_left+k[17];
        tmp = 600*(k[10]*y_cursor+k[11]*y_small+k[12]*time_left+k[13]);
        /*if (tmp >= 0 && tmp <= 600)*/ list[2] = Math.round(tmp);

        return list;
    }

    public AI(float[]k){
        for(int i=0; i<14; i++) this.k[i] = k[i];
    }

    AI(AI parent, float delta){
        Random rng = new Random();
        for(int i=0; i<6; i++) k[i] = parent.k[i]-delta+rng.nextFloat()*delta*2;
        for(int i=6; i<10; i++) k[i] = parent.k[i]-delta+rng.nextFloat()*delta*2;
        for(int i=10; i<14; i++) k[i] = parent.k[i]-delta+rng.nextFloat()*delta*2;
    }

    void output(){
        for(int i=0; i<14; i++){
            if(i == 6 || i == 10)
                System.out.println();
            System.out.print(k[i]+"f, ");
        }
        System.out.println();
    }
}
