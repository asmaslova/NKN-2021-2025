#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    vector<string> field, res;
    int w;
    cin >> w; cin.ignore();
    int h;
    cin >> h; cin.ignore();
    for (int i = 0; i < h; i++) {
        string line;
        getline(cin, line);
        field.push_back(line);
    }

    for(int i=0; i<h; i++){
        string res_line = "";
        for(int j=0; j<w; j++){
            int bordering_mines = 0;
            if(field[i][j]=='x') res_line += '.';
            else{
                if(i>0 && j>0 && field[i-1][j-1] == 'x') bordering_mines++;
                if(i>0 && field[i-1][j] == 'x') bordering_mines++;
                if(i>0 && j<w-1 && field[i-1][j+1] == 'x') bordering_mines++;
                if(j>0 && field[i][j-1] == 'x') bordering_mines++;
                if(j<w-1 && field[i][j+1] == 'x') bordering_mines++;
                if(i<h-1 && j>0 && field[i+1][j-1] == 'x') bordering_mines++;
                if(i<h-1 && field[i+1][j] == 'x') bordering_mines++;
                if(i<h-1 && j<w-1 && field[i+1][j+1] == 'x') bordering_mines++;
                if(bordering_mines==0) res_line += '.';
                else res_line += to_string(bordering_mines);
            }
        }
        res.push_back(res_line);
    }
    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    for(int i=0; i<h; i++) cout << res[i] << endl;

}
