#include<bits/stdc++.h>

// This is not final solution, but leetcode have different output with local and codeforces, will finish later

class Solution {
public:
    std::string fractionToDecimal(int numerator, int denominator) {
        int n = numerator, d = denominator;
        int x = n;
        std::string s,f;

        std::unordered_map<int,int> m;

        s.push_back('0' + n/d);
        if (n % d == 0){
            return s;
        }
        x = n % d; 
        s.push_back('.');
        m[0] = 1;
        m[n] = 1;

        while (true){
            m[x] = 1;
            f.push_back(char ('0'  + (x * 10 / d)));
            
            x = x * 10 % d;
            if (m[x] == 1){
                break;
            }
        }


        if (x != 0){
            x = x*10 / d;
            for (char i; i < f.length(); i++){
                if (x == f[i] - '0'){
                    s.push_back('(');
                }
                s.push_back(f[i]);
            }
            s.push_back(')');
        }else{
            s = s + f;
        }
        return s;
    }
};


int main(){
    Solution sol ;
    int n, d; std:: cin >> n >> d;
    std :: cout << sol.fractionToDecimal(n,d);

}