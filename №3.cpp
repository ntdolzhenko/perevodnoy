#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int maxLen = 0;
// char symbol;
vector<char> symboly;
vector<int> dliny;

void posledovatelnost(string line, char sym, int index){
	for(int i = 0; i < line.size(); i++){
	    if(line[i] == sym){
	        if(i - index -1 >= 0){
	           // if(line[i] < symbol) symbol = line[i];
	            if(i - index -1 > maxLen) maxLen = i - index -1;
	            symboly.push_back(line[i]);
	            dliny.push_back(i - index -1);
	        }
	    }
	}
}

void result(){
	string line;
	ifstream fin("input.txt");
	fin >> line;
	fin.close();
// 	symbol = line[0];
	for(int i = 0; i < line.size(); i++) posledovatelnost(line, line[i], i);
	if(maxLen!=0){
		int p = 0;
	    for(int i = 0; i < dliny.size(); i++){
	        if(dliny[i] == maxLen) p = i;
	    }
	    cout << symboly[p] << " " << maxLen;
	}
	else if(maxLen == 0){
	    for(int i = 0; i < symboly.size()-1; i++){
	        for(int j = symboly.size()-2; j >= i; j--){
	            if(symboly[i] < symboly[j+1]){
                    char a = symboly[i];
                    symboly[i] = symboly[j+1];
                    symboly[j+1] = a;
                }
	        }
	    }
	    cout << symboly[0] << " " << 0;
	}
	else if(symboly.size() == 0){
		cout << 0;
	}
}


int main(){
    result();
	return 0;
}
