#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        while (numBottles >= numExchange){
            ans += numBottles / numExchange;
            numBottles = numBottles%numExchange + numBottles/numExchange;
            //cout << numBottles << endl;
        }
        return ans;
    }
};

int main(){
    int a,b; cin >> a >> b;
    Solution sol;
    cout << sol.numWaterBottles(a,b);
}