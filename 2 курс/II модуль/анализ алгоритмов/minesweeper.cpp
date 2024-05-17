#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

vector<string> field;
int na, nb, h, w;

void no_bordering_mines(int i, int j){
    if(i>0 && j>0 && field[i-1][j-1] == '?')     {field[i-1][j-1]='n'; na--;};
    if(i>0 && field[i-1][j] == '?')              {field[i-1][j]='n'; na--;};
    if(i>0 && j<w-1 && field[i-1][j+1] == '?')   {field[i-1][j+1]='n'; na--;};
    if(j>0 && field[i][j-1] == '?')              {field[i][j-1]='n'; na--;};
    if(j<w-1 && field[i][j+1] == '?')            {field[i][j+1]='n'; na--;};
    if(i<h-1 && j>0 && field[i+1][j-1] == '?')   {field[i+1][j-1]='n'; na--;};
    if(i<h-1 && field[i+1][j] == '?')            {field[i+1][j]='n'; na--;};
    if(i<h-1 && j<w-1 && field[i+1][j+1] == '?') {field[i+1][j+1]='n'; na--;};
}

void found_b(int i, int j){
    if(i>0 && j>0 && field[i-1][j-1] > '0' && field[i-1][j-1] < '9')     {field[i-1][j-1]-=1;};
    if(i>0 && field[i-1][j] > '0' && field[i-1][j] < '9')                {field[i-1][j]-=1;};
    if(i>0 && j<w-1 && field[i-1][j+1] > '0' && field[i-1][j+1] < '9')   {field[i-1][j+1]-=1;};
    if(j>0 && field[i][j-1] > '0' && field[i][j-1] < '9')                {field[i][j-1]-=1;};
    if(j<w-1 && field[i][j+1] > '0' && field[i][j+1] < '9')              {field[i][j+1]-=1;};
    if(i<h-1 && j>0 && field[i+1][j-1] > '0' && field[i+1][j-1] < '9')   {field[i+1][j-1]-=1;};
    if(i<h-1 && field[i+1][j] > '0' && field[i+1][j] < '9')              {field[i+1][j]-=1;};
    if(i<h-1 && j<w-1 && field[i+1][j+1] > '0' && field[i+1][j+1] < '9') {field[i+1][j+1]-=1;};
}

void all_mines(int i, int j){
    if(i>0 && j>0 && field[i-1][j-1] == '?')     {field[i-1][j-1]='x'; na--; nb--; found_b(i-1, j-1);};
    if(i>0 && field[i-1][j] == '?')              {field[i-1][j]='x'; na--; nb--; found_b(i-1, j);};
    if(i>0 && j<w-1 && field[i-1][j+1] == '?')   {field[i-1][j+1]='x'; na--; nb--; found_b(i-1, j+1);};
    if(j>0 && field[i][j-1] == '?')              {field[i][j-1]='x'; na--; nb--; found_b(i, j-1);};
    if(j<w-1 && field[i][j+1] == '?')            {field[i][j+1]='x'; na--; nb--; found_b(i, j+1);};
    if(i<h-1 && j>0 && field[i+1][j-1] == '?')   {field[i+1][j-1]='x'; na--; nb--; found_b(i+1, j-1);};
    if(i<h-1 && field[i+1][j] == '?')            {field[i+1][j]='x'; na--; nb--; found_b(i+1, j);};
    if(i<h-1 && j<w-1 && field[i+1][j+1] == '?') {field[i+1][j+1]='x'; na--; nb--; found_b(i+1, j+1);};
}

void check_mines(int i, int j){
    int max_mines=0;
    if(i>0 && j>0 && field[i-1][j-1] == '?')     {max_mines++;};
    if(i>0 && field[i-1][j] == '?')              {max_mines++;};
    if(i>0 && j<w-1 && field[i-1][j+1] == '?')   {max_mines++;};
    if(j>0 && field[i][j-1] == '?')              {max_mines++;};
    if(j<w-1 && field[i][j+1] == '?')            {max_mines++;};
    if(i<h-1 && j>0 && field[i+1][j-1] == '?')   {max_mines++;};
    if(i<h-1 && field[i+1][j] == '?')            {max_mines++;};
    if(i<h-1 && j<w-1 && field[i+1][j+1] == '?') {max_mines++;};
    if('0' + max_mines==field[i][j]) all_mines(i, j);
}

int main()
{
    cin >> h >> w; cin.ignore();
    cin >> nb; cin.ignore();
    for (int i = 0; i < h; i++) {
        string line;
        getline(cin, line);
        field.push_back(line);
    }
    for(int i=0; i<h; i++)
        cerr << field[i] << endl;
    cerr << endl;

    for(int i=0; i<h; i++)
        for(int j=0; j<w; j++)
            if(field[i][j]=='?') na++;

    while(nb!=0){
        if(na==nb){
            for(int i=0; i<h; i++)
            for(int j=0; j<w; j++){
                if(field[i][j]=='?') field[i][j]='x';
            }
            na =0;
            nb=0;
        }
        else{
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(field[i][j]=='.' || field[i][j]=='0') no_bordering_mines(i, j);
                if(field[i][j] > '0' && field[i][j] < '9') {check_mines(i, j);};
            }
        }
        }
    }

    for(int i=0; i<w; i++)
        for(int j=0; j<h; j++)
            if(field[j][i]=='x') cout << i << " " << j << endl;
}
