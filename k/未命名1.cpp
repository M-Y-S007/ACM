#include<iostream>
using namespace std;
long long a[5000005];

void quicksort(int l, int r) {
    if (l >= r) return;
    
    long long pivot = a[(l + r) / 2];
    int i = l, j = r;
    
    while (i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    
    quicksort(l, j);
    quicksort(i, r);
}

int main(){
	long long n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	quicksort(0,n-1);
	cout<<a[k]<<endl;
    return 0;
}
