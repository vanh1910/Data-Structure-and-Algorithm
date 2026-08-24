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

int n;
int a[maxn];
int ans = 0;
int ans1 = 0;
void backtrack(int i, int n, int x){
    if (i == 0){
        for (int color = 1; color <=x; ++color){
            a[i] = color;
            backtrack(i + 1, n, x);
        }
    }else if (i == n){
        ans ++;
        for (int j = 0; j < n; ++j){
             cout << a[j] << " ";
        }
        cout << endl;
        return;
    }
    else if (i < n - 1){
        for (int color = 1; color <= x; ++color){
            if (color != a[i - 1]){
                a[i] = color;
                backtrack(i + 1, n, x);
            }
        }
    }else if (i == n - 1){
        for (int color = 1; color <= x; ++color){
            if (color != a[i - 1] && color != a[0]){
                a[i] = color;
                backtrack(i + 1, n, x);
            }
        }
    }
}

void backtrack2(int i, int n, int x){
    if (i == 0){
        for (int color = 1; color <=x; ++color){
            a[i] = color;
            backtrack2(i + 1, n, x);
        }
    }else if (i == 1){
        for (int color = 1; color <= x; ++color){
            if (color != a[i - 1]){
                a[i] = color;
                backtrack2(i + 1, n, x);
            }
        }
    }else if (i % 2 == 0){
        for (int color = 1; color <= x; ++color){
            if (color !=a[i-2]){
                a[i] = color;
                backtrack2(i + 1, n, x);
            }
        }
    }else if (i % 2 == 1){
        for (int color = 1; color <= x; ++color){
            if (color != a[i - 1] && color != a[i - 2]){
                a[i] = color;
                backtrack2(i + 1, n, x);
            }
        }
    }else if (i == n){
        ans1++;
        for (int j = 0; j < n /2; ++j){
            cout << a[j] << " " << a[j+1] << " ";
            cout << endl;
        }
        cout << endl;
        return;
    }
}

void solve(){
    int n; cin >> n;
    int k; cin >> k;
    int x; cin >> x;
    backtrack(0, k, x);
    //backtrack2(0, n*2, x);
    cout << ans;

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
