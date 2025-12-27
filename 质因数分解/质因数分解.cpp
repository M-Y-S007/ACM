#include <iostream>
using namespace std;
int main(){
	
	int n,c;
	
	cin>>n;
	for(int i=2;i<n;i++){
        c=i;
		if(n%c==0){
		    break;
		}

	}
	int a=n/c;
	cout<<a;
	return 0;
} 
