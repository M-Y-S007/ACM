/*#include<bits/stdc++.h>
using namespace std;
int n;
string s1, s2, s3;
int val[26];
bool used[10];
int carry[30];

bool check(int col){
    for(int i = 0; i <= col; i++){
        int idx1 = n - 1 - i;
        int idx2 = n - 1 - i;
        int idx3 = n - 1 - i;

        int a = (idx1 >= 0) ? val[s1[idx1] - 'A'] : 0;
        int b = (idx2 >= 0) ? val[s2[idx2] - 'A'] : 0;
        int c = (idx3 >= 0) ? val[s3[idx3] - 'A'] : 0;

        if(a == -1 || b == -1 || c == -1){
            continue;
        }

        int sum = a + b + (i > 0 ? carry[i - 1] : 0);
        if(sum % n != c) return false;

        carry[i] = sum / n;

    }
    return true;
}*/

#include<bits/stdc++.h>
using namespace std;
int n;
string s1, s3, s2;

int main(){
    cin >> n;
    cin >> s1 >> s2 >> s3;

    vector<char> letters;
    bool seen[26] = {false};

    for(char c : s1){
        if(!seen[c - 'A']){
            seen[c - 'A'] = true;
            letters.push_back(c);
        }
    }
    for(char c : s2){
        if(!seen[c - 'A']){
            seen[c - 'A'] = true;
            letters.push_back(c);
        }
    }
    for(char c : s3){
        if(!seen[c - 'A']){
            seen[c - 'A'] = true;
            letters.push_back(c);
        }
    }
    sort(letters.begin(), letters.end());

    vector<int> digits(n);

    for(int i = 0; i < n; i++){
        digits[i] = i;
    }

    do{
        int val[26] = {0};
        for(int i = 0; i < n; i++){
            val[letters[i] - 'A'] = digits[i];
        }
        bool vaild = true;
        int carry = 0;

        for(int i = n - 1; i >= 0; i--){
            int a = val[s1[i] - 'A'];
            int b = val[s2[i] - 'A'];
            int c = val[s3[i] - 'A'];

            int sum = a + b + carry;
            if(sum % n != c){
                vaild = false;
                break;
            }
            carry = sum / n;
        }
        if(vaild && carry == 0){
            for(int i = 0; i < n; i++){
                cout << val[i] << " ";
            }
            cout << "\n";
            break;
        }
    }while(next_permutation(digits.begin(), digits.end()));

    return 0;
}

