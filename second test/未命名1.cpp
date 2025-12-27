/*#include<iostream>
using namespace std;
long long a[100005];
int N;
void quicksort(int left,int right){
	int i=left;
	int j=right;
	int mid=(left+right)/2;
	long long p=a[mid];
	if(j<=i)return;
	while(i<=j){
		while(a[i]<p)i++;
		while(a[j]>p)j--;
		if(i<=j){
			swap(a[i],a[j]);
			i++;
			j--;
		}
	}
	if(left<j) quicksort(left,j);
	if(right>i) quicksort(i,right);
}
int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>a[i];
	}
	quicksort(0,N-1);
    for(int i=0;i<N-1;i++){
    	cout<<a[i]<<" ";
	}
	cout<<a[N-1];
	return 0;
} */
#include<iostream>
using namespace std;
long long a[110];
int main(){
    int p,j;
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>a[i];
    }
    int max=a[0];
    for(int i=0;i<N;i++){
        if(max<a[i]){
            p=i;
            max=a[i];
        }
    }
    a[p]=0;
    int sec = a[0];
    for(int i=0;i<N;i++){
        if(max<a[i]){
            int j=i;
            sec=a[i];
        }
    }
    cout<<j+1;
    return 0;
}
