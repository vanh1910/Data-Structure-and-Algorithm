#include<bits/stdc++.h>
using namespace std;

// BFS from given source s
vector<int> bfs(vector<vector<int>>& adj)  {
    queue<int> qu;
    qu.push(0);
    int n = adj.size();
    bool visited[n] = {false};
    visited[0] = 1;
    vector<int> ans;
    ans.push_back(0);
    
    while(!qu.empty()){
        int u = qu.front();
        qu.pop();
        for (int& v : adj[u]){
            if (!visited[v]){
                visited[v] = 1;
                qu.push(v);
                ans.push_back(v);
            }
        }
    }
    return ans;
}

int main()  {

    vector<vector<int>> adj = {{1,2}, {0,2,3}, {0,4}, {1,4}, {2,3}};
    vector<int> ans = bfs(adj);
    for(auto i:ans) {
        cout<<i<<" ";
    }
    return 0;
}