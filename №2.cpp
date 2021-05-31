#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int countNum = 0;
int MAX = 0;
int numberMax;
 
vector<int> mnogitely(int number, vector<int> vec){
	for(int i = 2; i < sqrt(number) + 1e-5;){
		if (number % i == 0){
            vec.push_back(i);
            number /= i;
        }
        else i++;
    }
   
    if ( number > 1 ) vec.push_back(number);
    return vec;
}

void cheking(int number){
    vector<int> mnogitel = mnogitely(number, mnogitel);
    if(mnogitel.size() == 3){
        bool yesOrNo = true;
        int x = mnogitel[0]%10;
        for(int i = 0; i < 3; i++){
            if(mnogitel[i]%10 != x) yesOrNo = false;
        }
        if(yesOrNo){
            countNum ++;
            int max = mnogitel[0], min = mnogitel[0];
            
            for(int i = 0; i < 3; i++){
                if(mnogitel[i] > max) max = mnogitel[i];
                else if(mnogitel[i] < min) min = mnogitel[i];
            }
            if(max-min > MAX){
                MAX = max - min;
                numberMax = number;
            }
        }
    }
}

void result(int a, int b){
    numberMax = a;
    for(int i = a; i <= b; i++){
        cheking(i);
    }
}

int main()
{
    int a, b;
    cin >> a >> b;
    result(a, b);
    if(countNum != 0){
        cout << countNum << " " << numberMax;
    }
    else cout << 0 << " " << 0;

    return 0;
}
