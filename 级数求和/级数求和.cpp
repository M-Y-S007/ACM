#include <iostream>
using namespace std;
int main(){
	int k;
	int n=0;
	cin>>k;
	double Sn=0;
    while(Sn<=k){
    	n++;
		Sn+=1.0/n;
	}
	cout<<n;
	return 0;
}
