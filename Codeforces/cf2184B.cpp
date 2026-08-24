#include <bits/stdc++.h>
using namespace std;
#define ll long long

void sol(){
    ll s, k, m; 
    cin >> s >> k >> m;
    if (s < k) {
        ll t = m %k;
        if (t < s) {
            cout << s- t << endl;
        } else {
            cout << "0\n";
        }
    } 
    else {
        ll t = m % k;
        ll c = m / k; 
        
        if (c % 2 == 0) {
            cout << s - t << endl;
        } else {
            cout << k - t << endl;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        sol();
    }
    return 0;
}