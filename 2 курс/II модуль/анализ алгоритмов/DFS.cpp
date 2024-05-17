#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int n; // the total number of nodes in the level, including the gateways
    int l; // the number of links
    int e; // the number of exit gateways
    cin >> n >> l >> e; cin.ignore();
    vector<set<int>> graph(n);

    for (int i = 0; i < l; i++) {
        int n1; // N1 and N2 defines a link between these nodes
        int n2;
        cin >> n1 >> n2; cin.ignore();
        graph[n1].insert(n2);
        graph[n2].insert(n1);
    }

    vector<int> exits(e);
    for (int i = 0; i < e; i++) {
        int ei; // the index of a gateway node
        cin >> ei; cin.ignore();
        exits[i] = ei;
    }

    // game loop
    while (1) {
        int si; // The index of the node on which the Bobnet agent is positioned this turn
        cin >> si; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        vector<int> q;
        q.push_back(si);
        int cur = 0;
        bool flag = true;
        while(flag){
            int u = q[cur];
            set <int> :: iterator it;
            for(it=graph[u].begin(); it != graph[u].end(); it++){
                for(int i=0; i<e; i++)
                    if(exits[i]==*it){
                        flag = false;
                        cout << u << " " << *it << endl;
                        graph[u].erase(*it);
                        graph[*it].erase(u);
                    }
                if (flag){
                    q.push_back(*it);
                }
                else break;
            }
            cur++;
        }
    }
}
