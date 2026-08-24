#include <bits/stdc++.h>
using namespace std;

//I tried O(n) but suffering with modulo

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> c (n+2, vector<int>(n+2,0));
        for (int i = 1; i<=n ; ++i){
            c[i][0] = 1 ;
            c[i][i] = 1;
            for (int j = 1; j < n; ++j){
                c[i][j] = c[i-1][j-1] + c[i-1][j];  
                c[i][j] %= 10;
            }
        }    
        int ans = 0;
        for (int i = 0; i < n; ++i){
            ans += nums[i] * c[n][i];
            ans %= 10;
        }
        return ans;
    }
};
int main(){
    int x = 5;
    //cin >> n;
    vector <int> in (x,0);
    for (int i = 0; i < x; ++i){
        in[i] = i+1;
    }
    Solution sol;
    cout << sol.triangularSum(in);
}