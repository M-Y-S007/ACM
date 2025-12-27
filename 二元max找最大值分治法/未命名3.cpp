#include<stdio.h>
int max(int a,int b){
	if(a>b)return a;
	else return b;
}
int find_max(int arr[],int l,int r){
	if(l==r)return arr[l];
	int mid=(l+r)/2;
    int find_left_max=find_max(arr,l,mid);
    int find_right_max=find_max(arr,mid+1,r);
	return max(find_left_max,find_right_max);
}
int main(){
	int arr[]={1,23,5,56,7,8,9,98,5,4,3,46,5,5,3,464};
	printf("%d",find_max(arr,0,15));
}
