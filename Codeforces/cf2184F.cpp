#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e5 + 3;
vector<vector<int>> tree (MAXN, vector<int> (0));
int parent[MAXN], child[MAXN];
vector<int> leaf;
int timer = 0;

void dfs(int l[], int r[], int u, int p){
    l[u] = ++timer;
    for (int &i :tree[u]){
        if (i == p){
            continue;
        }
        parent[i] = u;
        dfs(l, r, i, u);
        child[u] += child [i];
    }
    if (tree[u].size() == 1){
        if (parent[u] == tree[u][0]){
            child[u] = 1;
            leaf.push_back(u);
        }
    }
    r[u] = timer;
    
}

void sol(){
    timer = 0;
    int n; cin >> n;
    
    tree = vector<vector<int>> (n+3, vector<int>(0));
    parent[1] = 0;
    for (int i = 1; i < n; ++i){
        int x,y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    int l[n+3], r[n+3];
    leaf = vector<int> (0);
    for (int i = 1; i <= n; ++i){
        child[i] = 0;
        parent[i] = 0;
    }
    // sort(leaf.begin(), leaf.end());
    dfs(l,r,1,1);
    // for (int i = 1; i <= n; ++i){
    //     cout << l[i] << " " << r[i] << endl;;
    // }
    // for (int i = 1; i <= n; ++i){
    //     for (int &j:tree[i]){
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // // }
    // for (int &i : leaf){
    //     cout << i << " ";
    // }
    int len = leaf.size();
    int dp[len + 3][3] = {};
    dp[0][0] = 1;
    for (int i = 1; i <= len; ++i){
        int x = leaf[i - 1];
        //cout << x << endl;
        int out = r[x];
        while (x != 0){
            // cout << leaf[i-1] << " " << x << " " << child[x] << " ok\n";
            for (int cnt = 0; cnt < 3; ++ cnt){
                if (i - child[x] >= 0 && dp[i-child[x]][cnt] == 1){
                    dp[i][(cnt + 1) % 3] = 1;
                } 
            }
            x = parent[x];
            if (r[x] > out ){
                break;
            }
        }
    }
    // for (int i = 0; i <= len; ++i){
    //     cout<< dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << endl;
    // }
    if (dp[len][0] == 1) cout <<"yes\n";
    else cout << "no\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--){
        //cout << "test\n";
        sol();
    }

    return 0;
}