#include <bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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

const double twoInches = 50.8; // 2 inches in millimeters
const double maxRadius = 80; // Maximum radius in millimeters
bool checkValidEuclideanDistance(int x1, int y1, int x2, int y2, int d1, int d2){
    // Calculate the squared distance between the two points
    int dx = x2 - x1;
    int dy = y2 - y1;
    //cout << "debug "<< x1 << " " << y1 << " " << x2 << " " << y2 << " " << d1 << " " << d2 << endl;
    double r1 = d1 / 2.0; // Convert diameter to radius
    double r2 = d2 / 2.0; // Convert diameter to radius
    const double twoInches = 50.8; // 2 inches in millimeters
    // Compare the squared distance with the square of d
    double distanceSquared = dx * dx + dy * dy;
    double distance = sqrt(distanceSquared) - r1 - r2;
    //cout << "debug distance: " << distance << endl << x1 << " " << y1 << " " << x2 << " " << y2 << " " << endl;
    return distance <= twoInches;
}

set<int> graph[maxn];
const int maxDis = 211;

struct DSU {
    vector<int> parent, size;
    DSU(int n) : parent(n), size(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (size[rootX] < size[rootY]) {
                swap(rootX, rootY);
            }
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }
    }
    int numberOfComponents() {
        unordered_set<int> uniqueRoots;
        for (int i = 0; i < int(parent.size()); ++i) {
            //cout << i << " " << find(i) << endl;
            uniqueRoots.insert(find(i));
        }
        //cout << uniqueRoots.size() << endl;
        return uniqueRoots.size();
    }
};

//check if each points degree is at least 2
bool checkDegree(int n){
    for (int i = 0; i < n; ++i){
        if (graph[i].size() < 2){
            return false;
        }
    }
    return true;
}

void solve(){
    int n; cin >> n;
    int x[n], y[n], d[n];
    DSU dsu(n);
    map<int, map<int, vector<int>>> grid; // x, y -> index
    for (int i = 0; i < n; ++i){
        cin >> x[i] >> y[i] >> d[i];
        int gX = x[i] / maxDis;
        int gY = y[i] / maxDis;
        if (grid[gX][gY].empty()){
            grid[gX][gY] = vector<int>();
        }
        grid[gX][gY].push_back(i);
    }
    ii directions[9] = {{0, 0}, {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
    for (int i = 0; i < n; ++i){
        for (int direction = 0; direction < 9; ++direction){
            int gX = x[i] / maxDis + directions[direction].first;
            int gY = y[i] / maxDis + directions[direction].second;
            if (grid.find(gX) != grid.end() && grid[gX].find(gY) != grid[gX].end()){
                for (int j : grid[gX][gY]){
                    if (i != j && checkValidEuclideanDistance(x[i], y[i], x[j], y[j], d[i], d[j])){
                        graph[i].insert(j);
                        graph[j].insert(i);
                        dsu.unite(i, j);
                    }
                }
            }
        }
    }
    int components = dsu.numberOfComponents();
    //cout << "debug components: " << components << endl;
    //debug graph
    // for (int i = 0; i < n; ++i){
    //     cout << "debug graph[" << i << "]: ";
    //     for (const auto &j : graph[i]){
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    if (components == 1){
        if (n >= 7){
            if (checkDegree(n)){
                cout << "yes\n";
            }else{
                cout << "no\n";
            }
        }else{
            cout << "yes\n";
        }
    }else{
        cout << "no\n";
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