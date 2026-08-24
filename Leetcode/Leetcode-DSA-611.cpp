#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        vector<int> e;
        for (int i = 0; i < nums.size(); ++i){
            if (nums[i] > 0) e.push_back(nums[i]);
        }
        int n = e.size();
        if (n < 3) return 0;
        sort(e.begin(), e.end());
        int ans = 0;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < i; ++j){
                int sum = e[i] + e[j];
                int dis = abs(e[i] - e[j]);
                int up = (lower_bound(e.begin(), e.end(), sum) - e.begin());
                int low = (upper_bound(e.begin(), e.end(), dis) - e.begin());

                ans += up - low;
                if (j >= low) ans--;
                if (i <= up) ans--;

            }
        }
        


        return ans/3;
    }
};
 
int main(){
    int n; cin >> n;
    vector<int> x;
    int a;
    for (int i = 0; i < n; ++i){
        cin >> a;
        x.push_back(a);
    }
    Solution sol;
    cout << sol.triangleNumber(x);
}