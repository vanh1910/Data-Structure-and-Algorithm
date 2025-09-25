#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int dp[n][n];
        int ans = INT_MAX;
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < n; ++i){
            dp[i][0] = triangle[i][0] + dp[i-1][0];
            for (int j = 1; j < i; ++j){
                dp[i][j] = triangle[i][j] + min(dp[i-1][j], dp[i-1][j-1]);
            }
            dp[i][i] = triangle[i][i] + dp[i-1][i-1];
        }

        for (int i = 0; i < n; ++i){
            ans = min(ans, dp[n-1][i]);
        }

        return ans;
    }
};

int main(){
    int n; cin >> n;
    vector<vector<int>> tri (n,vector<int> (n,0));
    for (int i = 0; i < n; ++i){
        for (int j = 0; j <= i; ++j){
            cin >> tri[i][j];
        }
    }
    Solution sol;
    cout << sol.minimumTotal(tri);
}