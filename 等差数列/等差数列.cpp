#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int n,x;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>x;
		a[i]=x;
	}
	if(n==1){
		cout<<1<<endl;
		return 0;
	}
	int ans=1;
	int curLen=1;
	int curDiff=a[1]-a[0];
	for(int i=1;i<n;i++){
		int diff=a[i]-a[i-1];
		if(diff ==curDiff){
			curLen++;
		}
		else{
			ans=max(ans,curLen);
			curLen=2;
			curDiff=diff;
		}
	}
	ans=max(ans,curLen);
	cout<<ans<<endl;
	return 0;
	
}
