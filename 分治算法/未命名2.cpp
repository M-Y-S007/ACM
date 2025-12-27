#include<iostream>
using namespace std;
int n=8;
int a[8];
void quicksort(int l,int r){
	if(l>=r)return;
	int i=l;
	int j=r;
	int mid=(l+r)/2;
	int p=a[mid];
	while(i<=j){
		while(a[i]<p)i++;
		while(a[j]>p)j--;
		if(i<=j){
			swap(a[i],a[j]);
			i++;
			j--;
		}
	}
	if(l<j)quicksort(l,j);
	if(i<r)quicksort(i,r);
}
int main(){
	for(int i=0;i<8;i++){
		cin>>a[i];
	}
	quicksort(0,7);
	for(int j=0;j<8;j++){
		cout<<a[j]<<" ";
	}
}
