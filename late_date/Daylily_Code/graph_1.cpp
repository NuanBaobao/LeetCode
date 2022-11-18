//
// Created by 张进华 on 2022/5/5.
//
# include<iostream>
# include <memory>
#include <cstring>
# include <vector>
# include <stack>

using namespace std;
const int MAX_SIZE = 1e5 + 5;


// 邻接表实现图的存储
struct Edge{
    int u, v, w;
};

class Graph{
public:
    int n, m;
    vector<Edge> G[80];
    int vis[80];
    stack<int> stak;
    vector<int> trace;
public:
    void add_edge(int u, int v, int w){
        G[u].push_back({u, v, w});
    }
    void dfs(int u){
        vis[u] = 1;
        trace.push_back(u);
        for(int i = 0; i < G[u].size(); i++){
            if(!vis[G[u][i].v]){
                vis[G[u][i].v] = 1;
                dfs(G[u][i].v);
            }
        }
    }
    void dfs_no_rc(int u){
        stak.push(u);
        vis[u] = 1;
        while(!stak.empty()){
            int node = stak.top();
            stak.pop();
            trace.push_back(node);
            for(int i = 0; i < G[node].size(); i++){
                if(!vis[G[node][i].v]){
                    stak.push(G[node][i].v);
                    vis[G[node][i].v] = 1;
                }
            }
        }
    }
    void dfs_graph(){
        memset(vis, 0, sizeof(vis));
        for(int i = 1; i <= n; i++){
            trace.clear();
            if(!vis[i]){
                // dfs(i);
                dfs_no_rc(i);
            }
            for(int j = 0; j < trace.size(); j++){
                cout << trace[j] <<" -> ";
            }
            cout << endl;
        }
    }
};

int main(void)
{
    cout << "please input the number of node, edge in graph!" << endl;
    Graph res;
    cin >> res.n >> res.m;

    cout << "please input the graph" << endl;

    int u, v, w;
    for(int i = 0; i < res.m; i++){
        cin >> u >> v >> w;
        res.add_edge(u, v, w);
    }

    for(int i = 1; i <= res.n ; i++){
        for(int j = 0; j < res.G[i].size(); j++){
            cout  << res.G[i][j].u << " -> " << res.G[i][j].v << " , w = " << res.G[i][j].w  << endl;
        }
    }

    res.dfs_graph();
    return 0;
}
/*
6 8
1 2 0
1 4 0
3 6 0
6 6 0
3 5 0
2 5 0
5 4 0
4 2 0
 */