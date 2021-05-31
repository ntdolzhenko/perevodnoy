#include <iostream>
#include <vector>
using namespace std;

vector<string> list;

bool countGlasnyh(string word, int m){
    int c = 0;
    for(unsigned int i = 0; i < word.size(); i++){
        if(word[i] == 'I' || word[i] == 'A') c++;
    }
    if(c >= m) return true;
    else return false;

}
void anagram(string str, int len, int m, string line = ""){
	if(len == 0 && list.size()!=0){
		int x = 1;
        for(unsigned int i = 0; i < list.size(); i++){
            if(line == list[i]){
                x = 0;
                break;
            }
        }
        if(x != 0 && countGlasnyh(line, m)) list.push_back(line);
        return;
	}

    for(unsigned int i = 0; i < str.size(); i++) anagram(str, len - 1, m, line + str[i]);
}

vector<string> sorting(vector<string> vec){
    for(unsigned int i = 0; i < vec.size()-1; i++){
        for(unsigned int j = vec.size()-2; j >= i; j--){
            if(vec[i] > vec[j+1]){
                string a = vec[i];
                vec[i] = vec[j+1];
                vec[j+1] = a;
            }
        }
    }
    return vec;
}

void result(unsigned int k){
    if(k >= list.size()) cout << "ERROR";
    else{
        list = sorting(list);
        cout << list.size() << " " << list[k];
    }
}

int main(){
    int len, count, k;
    string line = "INFA";
    cin >> len >> count >> k;
    
    anagram(line, len, count);
    result(k);
	return 0;
}

