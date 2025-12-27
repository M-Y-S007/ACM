/*#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int f[n];
	int s,sum=0;
	for(int i=1;i<=n;i++)
	{
		s=0;                            超时了哈哈哈哈哈哈哈 
		for(int j=1;j<=i;j++)           此算法的时间复杂度为O(n^2)在n较小的时候还行，n比较大的时候就不行了 
		{
			if(i%j==0)s++;
		}
		f[i-1]=s;
		sum+=f[i-1];
	}
	cout<<sum<<endl;
	return 0;
}*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long sum = 0;                  //时间复杂度为O(n*logn) 
    
    for (int i = 1; i <= n; i++) {
        sum += n / i;
    }
    
    cout << sum << endl;
    return 0;
}

