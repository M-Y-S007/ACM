#include <iostream>
using namespace std;

int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	if(a+b<=c||b+c<=a||a+c<=b)
	cout<<"Not triangle"<<endl;
	if(a*a+b*b==c*c||b*b+c*c==a*a||a*a+c*c==b*b)
	cout<<"Right triangle"<<endl;
	if((a*a+b*b>c*c&&c*c+b*b>a*a&&a*a+c*c>b*b)&&(a+b>c&&b+c>a&&a+c>b))
	cout<<"Acute triangle"<<endl;
	if((a*a+b*b<c*c||c*c+b*b<a*a||a*a+c*c<b*b)&&(a+b>c&&b+c>a&&a+c>b))
	cout<<"Obtuse triangle"<<endl;
	if((a==b||b==c||c==a)&&(a+b>c&&b+c>a&&a+c>b))
	cout<<"Isosceles triangle"<<endl;
	if(a==b&&b==c&&c==a) 
	cout<<"Equilateral triangle"<<endl;
	
	return 0;
	
}
