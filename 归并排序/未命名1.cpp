#include<iostream>
using namespace std;
int a[8],tmp[8];
void merge(int l,int mid,int r){
	if(l>=r)return;
	int i=l;
	int j=mid+1;
	int k=l;
    while(i<=mid&&j<=r){
    	if(a[i]<a[j]){
    		tmp[k++]=a[i++];
		}
		else{
			tmp[k++]=a[j++];
	}
	}
	while(i<=mid){
		tmp[k++]=a[i++];
	}
	while(j<=r){
		tmp[k++]=a[j++];
	}
	for(int i=l;i<=r;i++){
		a[i]=tmp[i];
	}
}
void mergesort(int l,int r){
	if(l>=r)return;
	int i=l;
	int j=r;
	int mid=(l+r)/2;
	mergesort(l,mid);
	mergesort(mid+1,r);
	merge(l,mid,r);
}
int main(){
	for(int i=0;i<8;i++){
		cin>>a[i];
	}
	mergesort(0,7);
	for(int j=0;j<8;j++){
		cout<<a[j]<<" ";
	}
}
