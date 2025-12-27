#include <iostream>
using namespace std;
int main(){
	
	int x=1,n=10,a,b,c;
	cin>>a>>b>>c;
	for(;n<=100;n++){
		if(n%3==a&&n%5==b&&n%7==c){
			cout<<n;
			x=0;
			break;
		}


	}
	if(x==1)cout<<"No answer";
	
	return 0;
}
