#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/**
 * Save humans, destroy zombies!
 **/

int main()
{

    // game loop
    while (1) {
        int x;
        int y;
        int minx = 99999;
        int miny = 99999;
        int index;
        int zindex;
        cin >> x >> y; cin.ignore();
        int human_count;
        cin >> human_count; cin.ignore();
        int humx[human_count];
        int humy[human_count];
        int humid[human_count];
        for (int i = 0; i < human_count; i++) {
            int human_id;
            int human_x;
            int human_y;
            cin >> human_id >> human_x >> human_y; cin.ignore();
            humx[i] = human_x;
            humy[i] = human_y;
            humid[i] = human_id;
        }
        int zombie_count;
        cin >> zombie_count; cin.ignore();
        int zomx[zombie_count];
        int zomy[zombie_count];
        int zomid[zombie_count];
        for (int i = 0; i < zombie_count; i++) {
            int zombie_id;
            int zombie_x;
            int zombie_y;
            int zombie_xnext;
            int zombie_ynext;
            cin >> zombie_id >> zombie_x >> zombie_y >> zombie_xnext >> zombie_ynext; cin.ignore();
            zomx[i] = zombie_x;
            zomy[i] = zombie_y;
            zomid[i] = zombie_id;

        }

        for (int i=0; i<human_count; i++){
            for (int j=0; j<zombie_count; j++){
                if ((pow((humx[i]-zomx[j]),2)+pow((humy[i]-zomy[j]),2))<(pow(minx,2)+pow(miny,2))){
                    if(((pow((zomx[j]-humx[i]),2)+pow((zomy[j]-humy[i]),2))/160000) >= ((pow(x-humx[i],2)-2000+(pow(y-humy[i],2)))/1000000)){
                        minx = abs(humx[i] - zomx[j]);
                        miny = abs(humy[i] - zomy[j]);
                        index = humid[i];
                        zindex = zomid[j];
                    }
                }
            }
        }

        for (int j=0; j<zombie_count; j++){
            if (zomid[j] == zindex){
                cout << zomx[j] << " " << zomy[j] << endl;
                break;
            }
        }
    }
}