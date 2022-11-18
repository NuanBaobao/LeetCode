//
// Created by 张进华 on 2022/5/5.
//

//
// Created by 张进华 on 2022/5/5.
//

# include<iostream>
# include <memory>
#include <cstring>
# include <vector>
# include <stack>

using namespace std;

// 图的邻接矩阵存储
const int MAX_SIZE = 1e2 + 5; // 顶点数目最大值
int n, m;
stack<int> stak;

// 函数声明
inline void add_edge(int Matrix_Graph[][MAX_SIZE], int u, int v, int w); // 内置函数inline,频繁使用添加边的信息
void dfs_graph(int G[][MAX_SIZE], vector<int>& vis, vector<int>& trace);
void dfs(int G[][MAX_SIZE], int u, vector<int>& vis, vector<int>& trace);
void dfs_no_rc(int G[][MAX_SIZE], int u, vector<int> &vis, vector<int>& trace, stack<int>& stak);

int main(void)
{
    vector<int> trace, vis(MAX_SIZE, 0);

    // 二维数组的创建
    // 方法1 静态创建
    int Matrix_Graph[MAX_SIZE][MAX_SIZE];
    memset(Matrix_Graph, -1, sizeof(Matrix_Graph));

    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int u, v , w;
        cin >> u >> v >> w;
        add_edge(Matrix_Graph, u, v, w);
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << Matrix_Graph[i][j] << " ";
        }
        cout << endl;
    }

    dfs_graph(Matrix_Graph, vis, trace);
    return 0;
}

// 添加边的信息
void add_edge(int Matrix_Graph[][MAX_SIZE], int u, int v, int w){
    Matrix_Graph[u][v] = w;
}

void dfs_graph(int G[][MAX_SIZE], vector<int> &vis, vector<int> &trace){
    for(int i = 1; i <= n; i++){
        trace.clear();
        if(!vis[i]){
//            dfs(G, i, vis, trace);
            dfs_no_rc(G, i, vis, trace, stak);
        }
        for(int j = 0; j < trace.size(); j++){
            cout << trace[j] << " -> ";
        }
    }
}

void dfs(int G[][MAX_SIZE], int u, vector<int> &vis, vector<int> &trace){
    trace.push_back(u);
    vis[u] = 1;
    for(int i = 1; i <= n; i++){
        if(G[u][i] != -1 && vis[i] != 1){
            vis[i] = 1;
            dfs(G, i, vis, trace);
        }
    }
}

void dfs_no_rc(int G[][MAX_SIZE], int u, vector<int> &vis, vector<int>& trace, stack<int>& stak){
    vis[u] = 1;
    stak.push(u);
    while(!stak.empty()){
        int node = stak.top();
        stak.pop();
        trace.push_back(node);  // 访问该顶点并将其子节点入栈
        for(int i = 1; i <= n; i++){
            if(G[node][i] != -1 && vis[i] != 1){
                vis[i] = 1;
                stak.push(i);
            }
        }
    }
}
/*
6 8
1 2 3
1 4 0
3 6 67
6 6 0
3 5 0
2 5 5
5 4 6
4 2 0
 */
