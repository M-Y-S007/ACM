#include <iostream>
using namespace std;
#include <string>

string func(){
	int k;
	char ch;
	string s = "",str = "";
	while(cin>>ch){
		if(ch=='['){
			cin>>k;
			str = func();
			while(k--){
				s += str;
			}
		}else if(ch == ']'){
			return s;
		}else{
			s += ch;
		}
	}
	return s;
}



int main(){
	
	cout<<func();

	
	return 0;
}
