#include <bits/stdc++.h>
using namespace std;

#define bit(i,x) (((x) >> (i)) & 1)
#define bug cerr << "here" << '\n'
#define task ""
#define ii pair <int, int>

using ll = long long;
using vi = vector <int>;
using vvi = vector <vi>;
using vii = vector <ii>;

constexpr int MOD = 998244353;
constexpr int oo = 1e9 + 7;
constexpr ll inf = 1e18 + 5;
constexpr int maxn = 3e5 + 10;
constexpr bool typetest = 0;
const int base = 8517;


void open(){
	if(fopen(task".input", "r")){
		freopen (task".input", "r", stdin);
		freopen (task".output", "w", stdout);
	}
}


void solve(){
    char dice[17][7];
    int dp[17][7];

    for (int i = 0; i <= 16; ++i){
        for (int j = 1; j <= 6; ++j){
            dp[i][j] = oo;
        }
    }
    
    for (int i = 1; i <= 6; ++i){
        string inp; cin >> inp;
        for (int j = 1; j <= 16; ++j){
            dice[j][i] = inp[j - 1];
        }
    }
    for (int i = 1; i <= 16; ++i){
        for (int j = 1; j <= 6; ++j){
            
        }
    }
}


int32_t main(){
	open();
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	
	t = 1;
	if (typetest)
		cin >> t;
	for (int _ = 1; _ <= t; ++_){
		// cout << "Case #" << _ << '\n';
		solve();
	}
}