#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = INT_MAX;

void sol(){
    int n; cin >> n;
    int a[n], b[n];
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }
    for (int i=0; i<n; ++i){
        cin >> b[i];
    }
    int ans = 0;
    int x[n+1] = {}, y[n+1] = {};
    for (int i = 1; i<=n; ++i){
        x[i] = y[i] = -1;
    }
    for (int i=n-1; i>=0; --i){
        if (a[i] == b[i]){
            ans = i+1;
            break;
        }
        if (y[a[i]] >-1 && y[a[i]] != i + 1){
            ans = i+1;
            break;
        }
        if (x[b[i]] >-1 && x[b[i]] != i + 1){
            ans = i+1;
            break;
        }
        if (x[a[i]] > -1){
            ans = i+1;
            break;
        }
        if (y[b[i]] > -1){
            ans = i+1;
            break;
        }
        x[a[i]] = max(x[a[i]], i);
        y[b[i]] = max(y[b[i]], i);
        
    }
    cout << ans << endl;
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