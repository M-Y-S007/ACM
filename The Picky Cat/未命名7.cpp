#include<bits/stdc++.h>
using namespace std;
int a[100010];
int abs_arr[100010];
int main(){
	int t,n,p,k;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j];
			abs_arr[j]=abs(a[j]);
		}
		int target=abs(a[1]);
		sort(abs_arr+1,abs_arr+1+n);
		int k=1;
		for(int h=1;h<=n;h++){
			if(abs_arr[h]==target){
				k=h;
				break;
			}
		}
		if(k<=(n+1)/2){
			cout<<"YES"<<endl; 
		}else{
			cout<<"NO"<<endl;
		}
	}
	
	return 0;
}
