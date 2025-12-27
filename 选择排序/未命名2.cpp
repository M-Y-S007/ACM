#include<stdio.h>
int main(){
	int i,j,k,p,t;
	int a[10]={1,9,6,8,4,3,5,2,7,10};

	for(int i=0;i<10;i++){
		int min=a[i]; 
		p=i; 
		for(int j=i;j<10;j++){
			if(a[j]<min){
				min=a[j];
				p=j;
			}
		}
		t=a[i];
		a[i]=a[p];
		a[p]=t;
	}
	for(int k=0;k<10;k++){
		printf("%d ",a[k]);
	}
}
