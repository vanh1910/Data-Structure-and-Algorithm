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
constexpr int maxn = 1e3 + 10;
constexpr bool typetest = 0;
const int base = 8517;


void open(){
	if(fopen(task".input", "r")){
		freopen (task".input", "r", stdin);
		freopen (task".output", "w", stdout);
	}
}

int n;

struct DSU{
	int par[maxn];
	void init (int n){
		for (int i = 1; i <= n; ++i){
			par[i] = -1;
		}
	}

	int findpar (int v){
		return par[v] < 0 ? v : par[v] = findpar(par[v]);
	}

	void merge (int u, int v){
		u = findpar (u);
		v = findpar (v);
		if (u == v) return;

		if (par[u] > par[v]) swap (u, v);
		par[u] += par[v];
		par[v] = u;
	}
}dsu;

void solve(){
	cin >> n;
	dsu.init (1000);
	while(n--){
		int u, v;
		cin >> u >> v;
		int pu, pv;
		pu = dsu.findpar (u);
		pv = dsu.findpar (v);
		if (pu == pv){
			cout << "Y\n";
		}else{
			cout << "N\n";
			dsu.merge (u, v);
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