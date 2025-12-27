#include <iostream>
using namespace std;
int main(){
	
	int n,num,x=0,y=0,name,p=1,u;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>num;
		a[i]=num;
	}
	for(int j=0;j<n;j++){
		if(a[j]%2==0)x+=1;
		else y+=1;
	}
	if(x>y){
		name=2;
		for(int u=0;u<n;u++){
    	    for(int u=0;u<n;u++){
    	    	if(a[u]==name){
    	    		name+=2;
				}
			} 
		}
	}
	else{
		name=1;
		for(int u=0;u<n;u++){
			for(int u=0;u<n;u++){
				if(a[u]==name){
					name+=2;
				}
			}
		}
	}
	cout<<name;
	
	return 0;
}
