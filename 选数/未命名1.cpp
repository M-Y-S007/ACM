#include<iostream>
#include <cmath>
#include <vector>
using namespace std;
int n,k;
int count = 0;
vector<int>nums;
bool isPrime(int x){
	if(x==2)return true;
	if(x==1)return false;
	int l = sqrt(x);
	for(int i=3;i<=l;i++){
		if(x%i==0)return false;
	}
	return true;
}
void func(int start,int selected,int sum){
	if(selected = k){
		if(isPrime(sum)){
			count++;
		}
	
	return;}
	if(n - start < k - selected){
		return;
	}
	for(int i=start;i<n;i++){
		func(i+1,selected+1,sum+nums[i]);
	}
}
int main(){
	cin>>n>>k;
	nums.resize(n);
	for(int i=0;i<n;i++){
		cin>>nums[i];
	}
	func(0,0,0);
	int ans = count;
	cout<<ans<<endl;
	return 0;
}

