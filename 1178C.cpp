#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = INT_MAX;
const int modn = 998244353;
void sol(){
    int w,h;
    cin >> w >> h;
    ll ans = 1;
    for (int i =0; i < w+h; ++i){
        ans *= 2;
        ans %= modn;
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >>t;
    while (t--){
        sol();
    }

    return 0;
}