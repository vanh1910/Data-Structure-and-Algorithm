#include<bits/stdc++.h>
using namespace std;

// I feel bad for copying the solution, just too bad at coding, and little bit wrong in algorithm

class Solution {
public:
    // int minScoreTriangulation(vector<int>& values) {
    //     int n = values.size();
    //     vector<vector<int>> dp(n+3, vector<int>(n+3, 0));
    //     for (int i = 1; i < n - 1; ++i){
    //         dp[i][i+1] = values[i] * values[i+1] * values[0];
    //     }
    //     for (int i = 1; i < n - 2; ++i){
    //         dp[i][i+2] = 
    //         min(
    //             values[0] * (values[i]*values[i+1] + values[i+1]*values[i+2]),
    //             values[i] * (values[0]*values[i+2] + values[i+1]*values[i+2])
    //         );
    //     }


    //     for (int i = 3; i < n - 1; ++i){
    //         for (int j = 1; j + i < n; ++j){
    //             dp[j][j+i] = min(
    //                 dp[j][j+1] + dp[j+1][j+i],
    //                 dp[j+i-1][j+i] + dp[j][j+i-1]
    //             );
    //             //dp[j][j+i] = INT_MAX;
    //             for (int k = j + 1; k < j + i + 1; ++k){
    //                 dp[j][j+i] = min(
    //                     dp[j][j+i], 
    //                     dp[j][k] + dp[k][k+1] + dp[k+1][j+i]
    //                 );
    //             }
    //         }
    //     }
        
    //     for (int i = 1; i < n; ++i){
    //         for (int j = 1 ; i + j < n; ++j){
    //             cout << dp[j][i + j] << " ";
    //         }
    //         cout << endl;
    //     }

    //     return dp[1][n-1];
    // }

public:
    int minScoreTriangulation(vector<int>& values) {
        unordered_map<int, int> memo;
        int n = values.size();
        function<int(int, int)> dp = [&](int i, int j) -> int {
            if (i + 2 > j) {
                return 0;
            }
            if (i + 2 == j) {
                return values[i] * values[i + 1] * values[j];
            }
            int key = i * n + j;
            if (!memo.count(key)) {
                int minScore = INT_MAX;
                for (int k = i + 1; k < j; k++) {
                    minScore = min(minScore, values[i] * values[k] * values[j] +
                                                dp(i, k) + dp(k, j));
                }
                memo[key] = minScore;
            }
            return memo[key];
        };
        return dp(0, n - 1);
    }
};

int main(){
    int n; cin >> n;
    vector<int> in (n);
    for (int i = 0; i < n; ++i){
        cin >> in[i];
    }
    Solution sol;
    cout << sol.minScoreTriangulation(in);
}