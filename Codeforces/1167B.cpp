#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = INT_MAX;


int a[6] = {4,8,15,16,23,42};
int inp[4];

bool isin(int il, int x){
    for (int i = 0 ; i < 6; ++i){
        if (il/x == a[i] && a[i] !=x){
            return true;
        }
    }
    return false;
}

bool rec(int x, int y){
    //cout << x << y << endl;
    if (isin(inp[0] , x) && isin(inp[1] , x) && isin(inp[2] , y) && isin(inp[3], y)){
        cout << "! " << inp[0] / x << " " << x << " " << inp[1] / x << " " << inp[2] / y << " " << y << " " << inp[3] /y << endl; 
        return true;
    }
    return false;

}

void sol(){
    
    
    cout << "? 1 2" << endl;
    cin >> inp[0];
    cout << "? 2 3" << endl;
    cin >> inp[1];
    cout << "? 4 5" << endl;
    cin >> inp[2];
    cout << "? 5 6" << endl;
    cin >> inp[3];

    int sec = __gcd(inp[0], inp[1]), fot = __gcd(inp[2], inp[3]);
    vector <int> x,y;
    for (int i = 0; i < 6; ++i){
        if (sec % a[i] == 0){
            x.push_back(a[i]);
        }
        if (fot % a[i] == 0){
            y.push_back(a[i]);
        }
    }
    for (int &i : x){
        for (int &j: y){
            if (rec(i,j)){
                return;
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