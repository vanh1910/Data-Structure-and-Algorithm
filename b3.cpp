// C++ program to check if parentheses are balanced

#include <bits/stdc++.h>
using namespace std;

bool isBalanced(const string& s) {
    // Declare a stack to store the opening brackets
    stack<char> st;
    for (int i = 0; i < s.length(); ++i){
        if (s[i] == '[' || s[i] == '(' || s[i] == '{'){
            st.push(s[i]);
        }else{
            if (st.empty()){
                return false;
            }
            if (st.top() - s[i] <= 2){
                st.pop();
            }
            else return false;
        }
    }
    return true;
}

int main() {  
    string s = "{([])}";
    if (isBalanced(s))
        cout << "true";
    else
        cout << "false";
    return 0;
}