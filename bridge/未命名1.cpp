#include<iostream>
using namespace std;
int main(){
	int mx=0,mn=0;
	int L,N,a;
	cin>>L>>N;
	for(int i=1;i<=N;i++){
		cin>>a;
		if(a<L/2){
			mx=max(mx,L-a+1);
			mn=max(mn,a);
		}
		else{
			mx=max(mx,a);
			mn=max(mn,L-a+1);
		}
	}
	cout<<mn<<" "<<mx;
	return 0;
}
