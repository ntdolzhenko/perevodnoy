#include <iostream>
#include <vector>
using namespace std;
int countRoads;

int main(){
	int N, from = 1, to;
	vector<vector <int> > roads;
	cin >> N;
	cin >> to;
	cin >> countRoads;
	int Time[countRoads][countRoads], Weight[countRoads][countRoads];
	
	for(int i = 0; i < countRoads; i++){
	    for(int j = 0; j < countRoads; j++){
	        Time[i][j] = 0;
	        Weight[i][j] = 0;
	    }
	}
	
	for(int i = 0; i < countRoads; i++){
	    vector<int> vec(4);
	    for(int x = 0; x < 4; x++){
			int xx;
			cin >> xx;
			vec.push_back(xx);
		 }
	    roads.push_back(vec);
	}
	
	int m, n, M;
	cin >> m >> n;
	M = m + n;
	
	for(int i = 0; i < countRoads; i ++){
	    vector<int> vec = roads[i];
	    Time[vec[0]][vec[1]] = vec[2];
	    Weight[vec[0]][vec[1]] = vec[3];
	    
	    Time[vec[1]][vec[0]] = vec[2];
	    Weight[vec[1]][vec[0]] = vec[3];
	}
	
	
	int min = 0, node = 0;
    bool visited[countRoads] = {false};
    int times[countRoads] = {999999};
    times[from] = 0;
    visited[from] = true;
    
    for(int i = 0; i < countRoads; i ++){
        min = 999999;
        for(int j = 0; j < countRoads; j++){
            if(!visited[j] && times[j] < min){
                min = times[j];
                node = j;
            }
        }
        visited[node] = true;
        for(int j = 0; j < countRoads; j++){
            if(!visited[j] && Time[node][j] && Time[node][j] + times[node] < times[j] && M <= Weight[node][j]){
                times[j] = Time[node][j] + times[node];
            }
        }
        if(node == to) break;
    }
    
    if(times[to] != 999999) cout << -1;
    else cout << times[to];
    
    return 0;
}
