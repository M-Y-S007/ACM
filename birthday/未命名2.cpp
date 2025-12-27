#include<bits/stdc++.h>
using namespace std;
struct node
{
	string name;
	int y;
	int m;
	int d;
	int id;
}student[110];
bool cmp(node,node);
bool cmp(node a,node b){
	if(a.y!=b.y)return a.y<b.y;
	else{
		if(a.m!=b.m){
			return a.m<b.m;
			
		}
		else{
			if(a.d!=b.d){
				return a.d<b.d;
				
			}
			else{
				return a.id>b.id;
			}
		}
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>student[i].name>>student[i].y>>student[i].m>>student[i].d;
		student[i].id=i;
	}
	sort(student,student+n,cmp);
	for(int i=0;i<n;i++){
		cout<<student[i].name<<endl;
	}
	
	return 0;
}
