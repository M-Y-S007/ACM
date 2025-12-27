#include <iostream>
using namespace std;
int a[110];
int count = 0;
int M,N;

void func(int start,int sum){
	if(sum==M){
		count++;
		return;
	}
	if(sum>M||start>=N){
		return;
	}
	func(start + 1,sum + a[start]);
	func(start + 1,sum);
	
	
}
int main(){
	cin>>N>>M;
	for(int i=0;i<N;i++){
		cin>>a[i];
	}
	func(0,0);
	cout<<count<<endl;
	return 0;
}
