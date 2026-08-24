#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = INT_MAX;



void sol(){
    int n; 
    cin >> n;
    int a[n];
    int an = 0, binh = 0;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
        int x = sqrt(a[i]);
        if (x*x == a[i]){
            an ++;
        }
        else binh++;
    }

    if (an == binh){
        cout << 0;
        return;
    }

    if (an > binh){
        int one = 0;
        for (int i = 0; i < n; ++i){
            if (a[i] != 0){
                int x = sqrt(a[i]);
                if (x*x == a[i]){
                    one++;
                }
            }
        }
        int minus = (an - binh) / 2;
        int ans;
        if (minus <= one) ans = minus;
        else{
            ans = one + (minus - one) * 2;
        }
        cout << ans;
    }

    if (an < binh){
        vector<int> nsqn;
        for (int i = 0; i < n; ++i){
            int x = sqrt(a[i]);
            if (x*x != a[i]){
                nsqn.push_back(min(a[i] - x*x, (x+1)*(x+1) - a[i]));
            }
        }
        ll ans = 0;
        sort(nsqn.begin(), nsqn.end());
        for (int i = 0; i < (binh -an) / 2; ++i){
            ans += nsqn[i];
        }
        cout << ans;
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sol();

    return 0;
}