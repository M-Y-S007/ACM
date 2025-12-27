#include<iostream>
#include<algorithm>
using namespace std;
int a[30005];
int main(){

    int n,w;


    cin>>w>>n;
    int k=n-1;
    for(int i = 0; i < n; i++){
        cin>>a[i];

    }
    sort(a, a + n);
/*    for(int j = 0; j < n; j++){
        if(j > k){
            break;
        }
        if(j == k){
            s++;
            break;
        }
        if(w - a[j] < a[k]){
            t++;
            j--;
            k--;    
        }
        else{
            s++;
            k--;
                                    这段代码并不是最简单的
        }
        
    }*/
    int left = 0, right = n-1, count = 0;
    while(left <= right){
        if(a[left] + a[right] <= w)left++;
        right--;
        count++;
    }
    cout << count;
}