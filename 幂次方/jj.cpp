#include <iostream>
using namespace std;
#include <vector>
#include <cmath>

string func(int n){
    if(n==0)return "0";
    if(n==1)return "2(0)";
    if(n==2)return "2";
    vector<int>powers;
    int temp = n;
    int exponent = 0;
    while(temp > 0){
        if(temp & 1){
            powers.push_back(exponent);
        }
        temp >>= 1;
        exponent++;
    }
    string result = "";
    for(int i = powers.size() - 1; i >= 0; i--){
        int power = powers[i];
        if(power == 0){
            result += "2(0)";
        }else if(power == 1){
            result += "2";
        }else{
            result += "2(" + func(power) + ")";
        }
        if(i > 0){
            result += "+";
        }
        
    }
    return result;
}


int main(){
    int n;
    cin >> n;
    cout<<func(n)<<endl;
    return 0;
}