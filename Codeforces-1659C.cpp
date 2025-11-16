#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 1e6 + 3;


ll a,b,n;
ll dp[MAXN];
ll loc[MAXN];
ll pre[MAXN];

ll cost(int x, int y){
    return (a + b) * abs(loc[x] - loc[y]);
}

void compute(int l, int r, int optl, int optr){
    if (l > r){
        return;
    }
    int mid = (l + r) / 2;
    
    int best = -1;
    ll val;
    for (int j = optl; j <= min(optr, mid - 1); ++j){
        val = dp[j] + cost(j,mid);
        if (val < dp[mid]){
            dp[mid] = val;
            best = j;
        }
    }

    // for (ll i = 1; i <= n; ++i){
    //     cout << dp[i] << " ";
    // }
    //cout << "lr" << l << r << " " << best << endl;

    compute(l, mid - 1, optl, best);
    compute(mid + 1, r, best, optr);
}

void sol(){
    cin >> n >> a >> b;

    for (ll i = 1; i <= n; ++i){
        cin >> loc [i];
        pre[i] = pre[i - 1] + loc[i];
        dp[i] = LLONG_MAX >> 2;
    }


    ll ans = LLONG_MAX;
    dp[1] = cost(0,1);
    compute(1,n,1,n);


    for (ll i = 0; i <= n; ++i){
        int x = dp[i] + (pre[n] - pre[i] - (n-i) * loc[i]) * b;
        ans = min(ans, dp[i] + (pre[n] - pre[i] - (n-i) * loc[i]) * b);
        //cout << dp[i] << " " << x << "\n";
    }
    cout << ans << endl;

}

int main(){
    loc[0] = 0;
    pre[0] = 0;
    dp[0] = 0;
    int t; cin >> t;
    while (t--){
        sol();
    }

}


// 0 378
// 27 321
// 45 318
// 108 318
// 117 404
// 189 567

// 318