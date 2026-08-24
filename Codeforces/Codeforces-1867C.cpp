#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = INT_MAX;

void sol(){
    int n;
    cin >> n;
    int a[n+1], mex = 0;
    a[0] = -1; 
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for (int i = 1; i <=n; ++i){
        if (a[i] == mex){
            mex ++;
        }
        else{
            break;
        }
    }
    cout << mex << endl;
    int y = 0;
    while (y!=-1){
        cin >> y;
        if (y < 0){
            return;
        }
        cout << y << endl;
        cout.flush();
    }
    return;
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