#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 2*10e5+10;

int n;
pair <int,int> t[4*MAXN];
string s;

pair<int,int> combine(pair<int,int> a, pair<int,int> b){
    int x = a.fi - min(a.fi, b.se);
    int y = b.se - min(a.fi, b.se);
    pair<int,int> tmp = {x + b.fi, a.se + y};
    return tmp; 
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        if (s[tl] == '('){
            t[v].fi = 1;
        }else{
            t[v].se = 1;
        }
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        t[v] = combine(t[2*v], t[2*v+1]);
    }
}

pair<int,int> ok(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return {0,0};
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return combine(
        ok(v*2, tl, tm, l, min(r, tm)),
        ok(v*2+1, tm+1, tr, max(l, tm+1), r)
    );
}

void update(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        t[v] = {t[v].se, t[v].fi};
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos);
        else
            update(v*2+1, tm+1, tr, pos);
        t[v] = combine(t[v*2],t[v*2+1]);
    }
}

void sol(){
    int n, q; 
    cin >> n >> q;
    cin >> s;
    build(1,0,n-1);
    while (q--){
        int typ,x,y; cin >> typ >> x >> y;
        --x; --y;
        if (typ == 1){
            if (s[x] != s[y]){
                update(1,0,n-1,x);
                update(1,0,n-1,y);
            }
        }else{
            pair<int,int> ans = ok(1,0,n-1,x,y);
            if (ans.fi == 0 && ans.se == 0){
                cout << "YES\n";
            }else{
                cout << "NO\n";
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sol();

    return 0;
}