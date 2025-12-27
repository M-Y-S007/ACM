#include<bits/stdc++.h>
using namespace std;
struct S{
	int sex;
	double h;
}a[2010]; 
bool cmp(S a,S b){
	if(a.h!=b.h)return a.h<b.h;
}
int main(){
	int T,n;
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n; 
	
	for(int i=1;i<=n;i++){
		cin>>a[i].sex;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i].h;
	}
	sort(a+1,a+n+1,cmp);
	bool c=true;
	for(int i=1;i<=n;i++){
		if(a[i].sex==0){
			if(!c)cout<<" ";
			cout<<a[i].h;
			c=false;
		}
	}cout<<endl;
	c=true;
	for(int i=1;i<=n;i++){
		if(a[i].sex==1){
			if(!c)cout<<" ";
			cout<<a[i].h;
			c = false;
		}
	}cout<<endl;
	cout<<endl;
	}
	return 0;
}
