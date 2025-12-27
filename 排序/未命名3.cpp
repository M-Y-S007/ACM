#include<iostream>
using namespace std;
int a [100];
int n;
void quicksort(int left,int right){
	if(left>right)return;
	int i=left;
	int j=right;
	int mid=(left+right)/2;
	int p=a[mid];
	while(i<=j){
		while(a[i]<p) i++;
		while(a[j]>p) j--;
		if(i<=j){
			swap(a[i],a[j]);
			i++;
			j--;
		}
	}
	if(left<j) quicksort(left,j);
	if(i<right) quicksort(i,right);
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	quicksort(0,n-1);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	
	return 0;
}
