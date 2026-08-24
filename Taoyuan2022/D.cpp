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
constexpr int maxn = 1e4 + 10;
constexpr bool typetest = 0;
const int base = 8517;


void open(){
	if(fopen(task".input", "r")){
		freopen (task".input", "r", stdin);
		freopen (task".output", "w", stdout);
	}
}

int n;
int a[maxn];
vector <int> graph[maxn];
int par[maxn];
int cost[maxn];
vector<int> tips;
int ans[maxn];
bool passed[maxn];

void dfs(int u, int par, int c){
    if (par != -1) {
        ans[u] += c;
    }
    for (int i = 0; i < graph[u].size(); ++i){
        int x = graph[u][i];
        if (passed[x]) continue;
        passed[x] = true;
        if (x != par){
            dfs(x, u, c);
        }
    }

}

void solve(){
    int n, th; cin >> n >> th;
    for (int i = 0; i < n;++i){
        par[i] = -1;
    }
    for (int i = 0; i < n; ++i){
        int x, y, z, c;
        cin >> x >> y >> z >> c;
        graph[x].push_back(z);
        graph[x].push_back(y);
        par[x] = z;
        par[x] = y;
        cost[x] = c;
        ans[x] = c;
    }
    for (int i = 0; i < n; ++i){
        if (par[i] == -1){
            tips.push_back(i);
        }
    }
    for (int i = 0; i < n; ++i){
        passed[i] = false;
    }

    for (int i = 2; i <= n+1; ++i){
        for (int j = 0; j <= n+1; ++j){
            passed[j] = false;
        }
        passed[i] = true;
        dfs(i,-1, cost[i]);
        // for (int j = 0; j <= n+1; ++j){
        //     //cout << ans[j] << " ";
        // }
        // cout << endl;
    }
    int mx = 0;

    for (int i = 2; i<= n+1; ++i){
        if (ans[i] >= th){
            cout << i << " " << ans[i] << "\n";
            ++mx;
        }

    }
    cout<< mx << endl;
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
