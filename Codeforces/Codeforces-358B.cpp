#include <bits/stdc++.h>
using namespace std;

int main(){
    //input
    int n;
    cin >> n;
    string s, x, in;
    s = "<3";
    for (int i = 0; i < n; ++i){
        cin >> in;
        s += in;
        s += "<3";
    }
    cin >> x;
    //solution
    int p = 0;
    for (int i = 0; i < x.length(); ++i){
        if (s[p] == x[i]){
            ++p;
        }
    }
    if (p == s.length()) cout << "yes";
    else cout << "no";

}