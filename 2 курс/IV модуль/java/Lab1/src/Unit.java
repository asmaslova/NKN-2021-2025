public class Unit {
    int hp, score;
    int x, y;
    Field field;
    Unit(Field field, int x, int y){
        this.field = field;
        this.x = x;
        this.y = y;
        hp = 10;
        score = 0;
    }
    void move(char key){
        int nx = x, ny = y;
        switch (key) {
            case 'w': ny--; break;
            case 's': ny++; break;
            case 'a': nx--; break;
            case 'd': nx++; break; //d
            default: System.out.println("Unknown key."); return;
        }
        if(!field.canGo(ny,nx)) {
            System.out.println("Can't go!");
            nx = x;
            ny = y;
            return;
        }
        if(field.matrix[ny][nx]=='|') {
            System.out.println("Can't go!");
            nx = x;
            ny = y;
            return;
        }
        if(field.canGo(ny,nx)&&field.matrix[ny][nx]=='$'){
            score++;
            field.matrix[ny][nx] = '_';
        }
        if(field.canGo(ny,nx)&&field.matrix[ny][nx]=='*'){
            hp--;
        }
        x = nx;
        y = ny;
        System.out.println(nx+"       "+ny);
    }
}

