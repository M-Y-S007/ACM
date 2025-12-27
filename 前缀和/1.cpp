#include<iostream>
using namespace std;
#define get_sum(L,R)(L?sum[R]-sum[L-1]:sum[R])
int main(){
	const int n=5;
	int arr[n]={1,3,7,5,2};
	int sum[n];
	sum[0]=arr[0];
	for(int i=0;i<n;i++){
		sum[i]=sum[i-1]+arr[i];
	}
		cout<<get_sum(2,4);
	return 0;
}
