#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int K = k;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> pos;

    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < 0){
            k--;
            if (cnt > 0){
                pos.push_back(cnt);
                ans++;
            }
            if (i == 0) ans++;
            cnt = 0;
        }else{  
            if (cnt == 0) ans++;   
            ++cnt;
        }
    }
    if (k < 0){
        cout << "-1\n";
        return 0;
    }
    //cout << ans << endl;
    if (cnt > 0) pos.push_back(cnt);
    if (a[0] >= 0) {
        pos.erase(pos.begin());
        ans --;
        //cout << pos.size() << endl;
    }
    //cout << ans << endl;
    if (pos.empty() && k > 0){
        cout << "0\n";
        return 0;
    }
    if (k == 0){
        cout << ans << endl;
    }
    else if (k > 0){
        //cout << k << endl;
        int x = pos.back();
        if (pos.empty()){
            cout << ans - 1 << endl;
            return 0;
        }
        pos.pop_back();
        sort(pos.begin(), pos.end());
        for (int i = 0; i < pos.size(); i++){
            if (k >= pos[i]){
                ans -= 2;
                k-= pos[i];
            }
        }
        //cout << k <<  x << ans << endl;
        if (k >= x){
            //cout << "ok" << endl;
            if (a[n-1] >= 0) ans--;
            else ans -= 2;
        }
        cout << ans << endl;
    }
}