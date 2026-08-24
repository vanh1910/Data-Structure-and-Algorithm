#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = INT_MAX;

void sol(){
    int n; cin >> n;
    int a[n];
    int p1 = 0,p2 = n - 1;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }
    int flag = 0;
    string s = "";
    for (int i = 0; i < n; ++i){
        if (flag == 0){
            flag = 1;
            if (a[p1] > a[p2]){
                s.push_back('L');
                ++p1;
            }
            else{
                s.push_back('R');
                --p2;
            }
        }else{
            flag = 0;
            if (a[p1] < a[p2]){
                s.push_back('L');
                ++p1;
            }
            else{
                s.push_back('R');
                --p2;
            }
        }
    }
    cout << s << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--){
        sol();
    }

    return 0;
}