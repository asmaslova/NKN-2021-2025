public class Cursor {
    Pic curs;
    Cursor() {
        curs = new Pic("pics/cursor.png");
        curs.setBounds(200, 200, 20, 20);
    }
    void move( int x, int y){
        int tx, ty;
        if (x - curs.getX() > 0) tx = Math.min(20, x - curs.getX());
        else tx = Math.max(-20, x - curs.getX());
        if (y - curs.getY() > 0) ty = Math.min(20, y - curs.getY());
        else ty = Math.max(-20, y - curs.getY());

        curs.setLocation(curs.getX() + tx,curs.getY() + ty);

        //timer+=10;
        //max speed 20;
        //min speed 1;
    }
}