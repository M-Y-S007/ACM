#include<iostream>
using namespace std;

struct Stu{
	string nm;
	int sc;
}a[105];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].nm>>a[i].sc;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i;j++){
			bool sw=false;
			
			if(a[j].sc<a[j+1].sc||a[j].sc==a[j+1].sc&&a[j].nm>a[j+1].nm){
				Stu t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	for(int i=1;i<n;i++){
		cout<<a[i].nm<<" "<<a[i].sc<<endl;
		
	}
	return 0;
}
