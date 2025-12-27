#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct p{
	int num;
	int time;
}a[1005];
bool cmp(p a,p b){
	return a.time<b.time;
}
int main(){
	int n;
	int first=1;
	float sum=0.00;
	cin>>n;
	for(int i=1;i<=n;i++){
		a[i].num=i;
	}
	for(int j=1;j<=n;j++){
		cin>>a[j].time;
	}
	sort(a+1,a+n+1,cmp);
	for(int k=1;k<=n;k++){
		if(first){
			cout<<a[k].num;
			first=0;
		}
		else cout<<" "<<a[k].num;
		sum+=a[k].time*(n-k);
	}
	cout<<endl;
	printf("%.2f",sum/n);
} 
