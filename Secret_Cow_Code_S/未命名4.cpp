#include <iostream>
using namespace std;
#include <string>
#include <vector>
vector<string>arr 
long long t = arr.length();
string func(int N,int a){
	
	if(t >= N){
		return arr[N];
	}
	else t *= 2;
}

int main(){
	int N;
	int i = 0;
    while(cin>>arr[i]){
    	i++;
	}
	cin>>N; 
	char ans = func(N,a);
	cout>>ans;
	return 0;
}
