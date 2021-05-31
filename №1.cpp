#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int count = 0;
int maxNum;

void cheking(int number){
    if(number/10 != 0){
        int n2, n1, num = number, num2 = number;
        n1 = number%100;
        int countRaz = 0;
        while(number){
			countRaz ++;
			number/=10;
		}
		for(int i = 0; i < countRaz; i++){
			num2/=10;
			if(i == countRaz -3) n2 = num2;
		}
        if(n1 != n2){
            if(num%(n1-n2) == 0){
				count ++;
				maxNum = num;
			}
        }
    }
}

void result(int a, int b){
	for(int i = a; i <= b; i++) cheking(i);
	cout << count << " " << maxNum;
}


int main(){
    int a,b;
    cin >> a >> b;
    result(a,b);
	return 0;
}
