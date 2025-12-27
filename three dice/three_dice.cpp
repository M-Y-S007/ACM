#include <iostream>
using namespace std;
int main(){
	
	int A,B,i,j,m,n,u,v;
	cin>>A>>B;
	for(int i=0;i<=3;i++){
		for(int j=0;i+j<=3;j++){
			if(i+4*j==A)
			break;
		}
	}
	for(int m=0;m<=3;m++){
		for(int n=0;m+n<=3;n++){
			for(int u=0;m+u+n<=3;u++){
				for(int v=0;m+u+n+v<=3;v++){
					if(2*m+3*n+5*u+6*v==B){
						break;
					}
				}
			}
		}
	}
	if(i+j+m+u+v+n==3)cout<<"Yes";
	else cout<<"No";
	return 0;
}
