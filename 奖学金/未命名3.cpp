#include<bits/stdc++.h>
using namespace std;
struct S{
	int id;
	int yy;
	int yw;
	int sx;
	int sum;
}a[310];
bool cmp(S a,S b){
	if(a.sum==b.sum){
		if(a.yw==b.yw)return a.id<b.id;
		else return a.yw>b.yw;
	}
	else return a.sum>b.sum;
	
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].yy>>a[i].sx>>a[i].yy;
		a[i].id=i;
		a[i].sum = a[i].yy+a[i].sx+a[i].yw;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=5;i++){
		cout<<a[i].id<<" "<<a[i].sum<<endl;
		
	}
	return 0;
} 
