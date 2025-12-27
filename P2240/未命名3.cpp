#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct gold{
	int num;
	int value;
	double price;
}a[105];
bool cmp(gold a,gold b){
	return a.price>b.price;
}
int main(){
	int N,T;
	float sum=0.0;
	cin>>N>>T;
	for(int i=0;i<N;i++){
		cin>>a[i].num>>a[i].value;
		a[i].price=(double)a[i].value/a[i].num;
	}
	sort(a,a+N,cmp);
	for(int j=1;j<=N;j++){
		if(T<=0)break;
		if(T>a[j].num){
			sum+=a[j].value;
			T-=a[j].num;
		}
		else{
			sum+=T*a[j].price;
			T=0;
		}
		
	}
	printf("%.2f",sum); 
	return 0;
}
