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

constexpr int MOD = 1e9 + 7;
constexpr int oo = 1e9 + 7;
constexpr ll inf = 1e18 + 5;
constexpr int maxn = 3e5 + 10;
constexpr bool typetest = 1;
const int base = 8517;



void open(){
    if(fopen(task".input", "r")){
        freopen (task".input", "r", stdin);
        freopen (task".output", "w", stdout);
    }
}



void read(){    

}    


void init(){

}

int p[maxn+10];
int dp[maxn+10];
int ba[maxn+10];

void dfs(vector<vector<int>> &g, int u){
    if (g[u].size() == 0){
        p[u] = 0;
        return;
    }
    int l = g[u][0], r = g[u][1];
    dfs(g,l);
    dfs(g,r);
    p[u] =(p[l] + p[r] + 4) % MOD;
}

void dfs2(vector<vector<int>> &g , vector<vector<int>> &prt, vector<vector<int>> &prt2, int u){
    if (g[u].size() == 0){
        return;
    }
    int l = g[u][0], r = g[u][1];
    dp[l] = (dp[u] + p[l] + 1) % MOD;
    dp[r] = (dp[u] + p[r] + 1) % MOD;
    prt[l].push_back(p[l]);
    prt[l].push_back(1);
    prt[l].push_back(dp[u]);
    prt[r].push_back(p[r]);
    prt[r].push_back(1);
    prt[r].push_back(dp[u]);
    //cout << l// << r << endl;
    dfs2(g,prt, prt2, l);
    dfs2(g,prt, prt2, r);


    prt2[u].push_back(1);
    prt2[u].push_back(p[l]);
    prt2[u].push_back(1);
    prt2[u].push_back(1);
    prt2[u].push_back(p[r]);
    prt2[u].push_back(1);
}



void solve(){
    int n, q; cin >> n >> q;
    for (int i = 1; i<=n; ++i){
        p[i] = 0;
        dp[i] = 0;
        ba[i] = 0;
    }
    vector<vector<int>> g(n+2);
    vector<vector<int>> prt(n+2);
    vector<vector<int>> prt2(n+2);
    for (int i = 1; i<=n; ++i){
        int x,y;
        cin >> x >> y;
        if (x==y){
            continue;
        }
        g[i].push_back(x);
        g[i].push_back(y);
        
        // else{
            ba[x] = i;
            ba[y] = i;
        // }
    }
    dfs(g, 1);
    dp[1] = p[1] + 1;
    dfs2(g,prt, prt2,1);
    prt2[1].push_back(1);
    // for (int i = 1; i<=n ; ++i){
    //     cout << dp[i] << " " << p[i] << endl;
    // }
    for (int i = 1; i<=n ; ++i){
        // cout << dp[i] << " " << p[i] << endl;
        // cout << i << "i\n";
        // for (int &j : prt[i]){
        //     cout << j << " ";
        // }
        // cout << endl;
        // cout << i << "i\n";
        // for (int &j : prt2[i]){
        //     cout << j << " ";
        // }
        // cout << endl;
    }
    // cout << q << endl;
    while (q--){
        int v,k; 
        cin >> v >> k;
        int tmp = k;
        int u = v;
        // cout << "v\n";
        bool flag = 0, br = 0;
        int ans = -1;
        while (tmp > 0){
            // cout << flag << " " << u << " " << tmp << endl;
            int sum = 0;
            if (u == 1) flag = 1;int cnt = 0;
            if (!flag){
                
                for (int &i : prt[u]){
                    ++cnt;
                    sum += i;
                    if (sum == tmp){
                        ans = ba[u];
                        if (cnt == 1) ans = u;
                        br = 1;
                        break;
                    }
                    else if (sum > tmp){
                        if (cnt == 1){
                            flag = 1;
                            break;
                        }
                        else{
                            u = ba[u];
                            tmp -= sum - i;
                            break;
                        }
                    }
                }
            }else{
                for (int &i : prt2[u]){
                    cnt++;
                    sum += i;
                    // cout << sum << endl;
                    if (sum == tmp){
                        if (cnt <= 2) ans = g[u][0];
                        else if (cnt == 3 || cnt == 6) ans = u;
                        else if (cnt <= 5) ans = g[u][1];
                        else ans = 0; 
                        br = 1;
                        break;
                    }else if (sum >tmp){
                        if (cnt == 2){
                            u = g[u][0];
                            tmp = sum - i;
                        }else{
                            u = g[u][1];
                            tmp = sum - i;
                        }
                        break;
                    }
                }
            }
            if (br){
                break;
            }
        }
        if (ans == -1){
            ans = u;
        }
        cout << ans << " ";
    }
    cout << endl;

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
        read();
        init();
        solve();
    }
}