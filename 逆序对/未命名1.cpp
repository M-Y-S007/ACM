#include<iostream>
using namespace std;
int a[500005],tmp[500005];
long long cnt=0;
void merge(int l,int mid,int r){
	int i=l,j=mid+1,k=l;
	while(i<=mid&&j<=r){
		if(a[i]<=a[j])
		tmp[k++]=a[i++];
		else{
		tmp[k++]=a[j++];
		cnt=cnt+mid-i+1;
		}
	}
	while(i<=mid)
	tmp[k++]=a[i++];
	while(j<=r)
	tmp[k++]=a[j++];
	for(int i=l;i<=r;i++)
	a[i]=tmp[i];
}
void mergesort(int l,int r){
	if(l>=r)return;
	int mid=(l+r)/2;
	mergesort(l,mid);
	mergesort(mid+1,r);
	merge(l,mid,r);
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	mergesort(0,n-1);
	cout<<cnt;
	return 0;
}
