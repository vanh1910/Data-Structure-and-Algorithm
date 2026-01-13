#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = INT_MAX;

void sol(){
    string s; 
    cin >> s;
    //cout << s << " ";
    int n = s.length();
    int st = -1,en = -1;
    for (int i = 0; i < n; ++i){
        if (s[i] == 'a'){
            st = en = i + 2;
        }        
    }
    s = "00" + s + "00";
    if (st == -1){
        cout << "NO\n";
        return;
    }
    char cur = 'a';
    for (int i = 0; i < n; ++i){
        cur++;

        if (s[st-1] == s[en+1] && s[st-1] != '0'){
            cout << "NO\n";
            return;
        }
        if (s[st-1] == s[en+1] && s[st-1] == '0'){
            cout << "YES\n";
            return;
        }
        if (s[st-1] == cur){
            st--;
        } 
        else if (s[en+1] == cur){
            en++;
        }
        else{
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    
}   

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--){
        sol();
        //cout << t << endl;
    }
    return 0;
}