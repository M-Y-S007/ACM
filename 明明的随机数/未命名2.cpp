#include<iostream>
using namespace std;
int a[110];
void quicksort(int l,int r){
	int i=l,j=r;
	int p=a[(l+r)/2];
	if(l>=r)return;
	while(i<=j){
		while(a[i]<p)i++;
		while(a[j]>p)j--;
		if(i<=j){
			swap(a[i],a[j]);
			i++;
			j--;
		}
	}
	quicksort(l,j);
	quicksort(i,r);
	
}
int main(){
	int N;
	int count=0; 
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>a[i];
	}
	for(int j=0;j<N;j++){
		if(a[j]!=-1){
		
		
		for(int k=j+1;k<N;k++){
			if(a[j]==a[k]&&a[j]!=-1){
				count++;
				a[k]=-1;
			}
		}
		}
	}
	quicksort(0,N-1);
	int M=N-count;
	cout<<M<<endl;
	for(int i=N-M;i<N;i++){
		if(a[i]!=-1)
		cout<<a[i]<<" ";
	}
	
}
