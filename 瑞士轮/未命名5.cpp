#include<bits/stdc++.h>
using namespace std;

struct P{
	int pm;
	int fs;
	int sl;
	int id;
}a[200010];

bool cmp(P a,P b){
	if(a.fs!=b.fs){
		return a.fs>b.fs;
	}
	else return a.id<b.id;
}

int main(){
	int N,R,Q;
	cin>>N>>R>>Q;
	for(int i=1;i<=2*N;i++){
		cin>>a[i].fs;
	}
    for(int i=1;i<=2*N;i++){
		cin>>a[i].sl;
		a[i].id=i;
	}
	for(int i=1;i<=R;i++){
		for(int j=2;j<=2*N;j+=2){
			if(a[j].sl>a[j-1].sl){
				a[j].fs++;
			
			}
			else a[j-1].fs++;
		}
		sort(a,a+2*N,cmp);
	}
	cout<<a[Q].id;
}
