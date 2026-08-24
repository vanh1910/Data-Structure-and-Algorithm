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
    ll n,w;
    cin >> n >> w;
    ll p[n], t[n];
    double ans = 0;
    for (int i = 0; i < n; ++i){
        cin >> p[i] >> t[i];
        
    }
    double l = 0, r = 1e18;
    for (int i = 0; i < 100; ++i){
        double mid = (l + r) / 2;
        double sum = 0;
        for (int j = 0; j < n; ++j){
            sum += max(0.0, p[j] * (mid - 2 * t[j]));
        }
        if (sum >= w){
            ans = mid;
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << fixed << setprecision(6) << ans;
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