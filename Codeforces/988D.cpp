#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second

void sol(){
    int n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }
    map <ll,int> mp;
    for (int i = 0; i < n; ++i){
        mp[a[i]]++;
    }
    for (int i = 0; i < n; ++i){
        for (int bit = 0; bit <= 30; ++bit){
            ll dis = (1ll << bit);
            if (mp.find(a[i] + dis) != mp.end() && mp.find(a[i] + 2 * dis) != mp.end()){
                cout << 3 << endl;
                cout << a[i] << " " << a[i] + dis << " " << a[i] + 2 * dis << endl;
                return;
            }
            
        }
    }
    for (int i = 0; i < n; ++i){
        for (int bit = 0; bit <= 30; ++bit){
            ll dis = (1ll << bit);
            if (mp.find(a[i] + dis) != mp.end()){
                cout << 2 << endl;
                cout << a[i] << " " << a[i] + dis << endl;
                return;
            }
        }
    }
    cout << 1 << endl;
    cout << a[0] << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--){
        sol();
    }
}