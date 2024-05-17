import java.util.Random;
import java.util.Scanner;


class Field{
    int height;
    int width;
    int pos;
    char [][] cells;
    char [] cell = {'_', '*', '#', '$', ' '};
    public Field(int height, int width){
        this.height = height;
        this.width = width;
        cells = new char[height][width];
    }
    void fill_the_field(){
        Random rng = new Random();
        for (int i = 0; i < height; i++){
            for (int j = 0; j < width; j++){
                if (i == 0 || j == 0 || i == height-1 || j == width-1) cells[i][j] = '#';
                else{
                int dice = rng.nextInt(100);
                if (dice < 50) cells[i][j] = '_';
                else if (dice < 75) cells[i][j] = '#';
                else if (dice < 90) cells[i][j] = '$';
                else cells[i][j] = '*';
            }}}
        if (width % 2 == 0){
            pos = (width - 2) / 2;
            cells[height - 1][pos] = ' '; 
            cells[height - 1][pos + 1] = ' ';
            cells[0][pos] = ' '; 
            cells[0][pos + 1] = ' ';
        }
        else {
            pos = (width - 2) / 2 + 1;
            cells[height - 1][pos] = ' ';
            cells[0][pos] = ' ';
        }
    }
    void show_the_field(){
        for (int i = 0; i < height; i++){
            for (int j = 0; j < width; j++){
                System.out.print(cells[i][j] + " ");}
            System.out.print("\n");
        }
    }
}
//////////////////////////////UNIT////////////////////////
class Unit{
    int health;
    int mana;
    int score;
    String name;
    int x;
    int y;
    Field floor;
    boolean game_over = false;
////////////////////////CONSTRUCTOR//////////////////////    
    Unit(int x, int y, Field field){
        this.x = x;
        this.y = y;
        this.health = 50;
        this.score = 0;
        floor = field;
        floor.cells[y][x] = '&';
    }
////////////////////////////UPDATE//////////////////////////    
    void update_the_field(int nx, int ny){
    floor.cells[ny][nx] = '&';
    floor.cells[y][x] = '_';    
    }
/////////////////////////////MOVE/////////////////////////    
    void move(String key){
        int x_next = x;
        int y_next = y;

        switch (key){
            case "W": y_next --; break; 
            case "S": y_next ++; break;
            case "D": x_next ++; break; 
            case "A": x_next --; break;
            default:
            System.out.println("Incorrect input! Try again!"); return;
        }
        
        if (!can_move(x_next, y_next)) System.out.println("There is a wall!");
        else{
            
            if (floor.cells[y_next][x_next] == '*'){
                this.health -= 10;
            }
            else if (floor.cells[y_next][x_next] == '$'){
                this.score += 10;
                
        }
        update_the_field(x_next, y_next);
        x = x_next;
        y = y_next;
    }}
/////////////////////////////CAN/MOVE//////////////////////    
    boolean can_move(int x_next, int y_next){
        if (floor.cells[y_next][x_next] != '#') return true;
        else return false;
    }
////////////////////////////////////////////////////////////
    int how_mamy_dollars(){
        int dollars = 0;
        for (int i = 1; i < floor.height-1; i++)
        for (int j = 1; j < floor.width-1; j++)
        if (floor.cells[i][j] == '$') dollars ++;
        return dollars;
    }
/////////////////////////////GAME/OVER//////////////////////
    void is_game_over(){
        if (health <= 0){
            System.out.println("You're DEADGE. Your score is: " + Integer.toString(score));
            game_over = true;}
        else if (how_mamy_dollars() == 0 || (x == floor.pos || x == floor.pos + 1) & y == 0){ 
            System.out.println("Congratulation! This floor is completed. Your score is: " + Integer.toString(score));
            game_over = true;
        }   
    }
}
    
///////////////////////////MAIN//////////////////////////
public class Main
{
	public static void main(String[] args) {
	    System.out.println("Welcome! You can move using keys listed below:\n" + "'W' for moving forward\n" + "'S' for moving back");
		System.out.println("'A' for moving left\n" + "'D' for moving right");
		System.out.println("Please, enter keys one per input. Enjoy the game!");
	    Field field1 = new Field(11, 11);
		field1.fill_the_field();
		Unit Bob = new Unit(field1.pos, field1.height - 1, field1);
		field1.show_the_field();
		
		while(!Bob.game_over){
		    
    		System.out.println("Your hp is: "); System.out.println(Bob.health);
    		System.out.println("Your score is: "); System.out.println(Bob.score);
		    System.out.println("Press the key");
		    Scanner key = new Scanner(System.in);
		    Bob.move(key.nextLine());
    		field1.show_the_field();
    		Bob.is_game_over();

    		
		}
	}
}
