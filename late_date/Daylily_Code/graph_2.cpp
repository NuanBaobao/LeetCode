//
// Created by 张进华 on 2022/5/5.
//

# include<iostream>
# include <memory>
#include <cstring>
# include <vector>
# include <stack>
# include<queue>

using namespace std;
const int MAX_SIZE = 1e2 + 5;

// 链式前向星实现图的存储
struct Edge {
    int u, v, w, next;
};

class Graph {
public:
    int n, m;
    int head[MAX_SIZE], tot = 1; //tot 是 Edges 的下标
    int vis[MAX_SIZE]; // 标记数组
    stack<int> stak;  // dfs辅助栈
    queue<int> que; // bfs辅助队列
    vector<int> trace;
    Edge Edges[MAX_SIZE];
public:
    Graph(){m = 1, n = 0;}
    void add_edge(int u, int v, int w);

    void dfs(int u);

    void bfs(int u);

    void dfs_no_rc(int u);

    void bfs_graph();

    void dfs_graph();
};

int main(void) {
    Graph res;
    cin >> res.n >> res.m;
    int u, v, w;
    memset(res.head, -1, sizeof(res.head)); // head初始值默认没有连接边

    for (int i = 0; i < res.m; i++) {
        cin >> u >> v >> w;
        res.add_edge(u, v, w);
    }
    for (int i = 1; i <= res.tot; i++) {
        for (int j = res.head[i]; j != -1; j = res.Edges[j].next) {
            cout << res.Edges[j].u << " -> " << res.Edges[j].v << " , W = " << res.Edges[j].w << endl;
        }
    }

    res.dfs_graph();

    return 0;
}

void Graph::add_edge(int u, int v, int w) {
    //构造一条边
    Edges[tot].u = u;
    Edges[tot].v = v;
    Edges[tot].w = w;
    //指明新加入边的前驱节点
    Edges[tot].next = head[u];
    head[u] = tot++;
}

void Graph::dfs(int u) {
    vis[u] = 1;
    trace.push_back(u);
    for (int i = head[u]; i != -1; i = Edges[i].next) {
        if (!vis[Edges[i].v]) {
            vis[Edges[i].v] = 1;
            dfs(Edges[i].v);
        }
    }
}

void Graph::bfs(int u) {
    // 从顶点u出发，广度优先搜索图
    trace.push_back(u); // 访问初始顶点v
    vis[u] = 1;  // 对v做已访问标记
    que.push(u); // 顶点u入队列

    while (!que.empty()) {
        int node = que.front(); // 顶点u出队列
        que.pop();
        for (int v = head[node]; v != -1; v = Edges[v].next) {
            // 检测u的所有邻居节点
            if (!vis[v]) {
                // v 为u的未访问的邻接顶点
                trace.push_back(v);  // 访问顶点v
                vis[v] = 1; // 对v做已访问标记
                que.push(v); // 顶点v入队列
            }
        }
    }
}

// 使用栈来标记下一步可能访问的顶点，同时使用了访问标记数组vis[i]标记第i个顶点是否在栈内或曾经在栈内(是否被访问过),若是则以后不能进栈
void Graph::dfs_no_rc(int u) {
    // 从顶点u开始深度优先遍历，依次遍历一个连通分量的所有顶点
    stak.push(u);  // u入栈并置vis[u]
    vis[u] = 1;
    while (!stak.empty()) {
        int node = stak.top();  // 栈中退出一个顶点
        stak.pop();
        trace.push_back(node);  // 访问该顶点并将其子节点入栈
        for (int i = head[node]; i != -1; i = Edges[i].next) {
            // 遍历node的所有邻接顶点
            if (!vis[Edges[i].v]) {
                // 未经过栈(未访问)的顶点进栈
                stak.push(Edges[i].v);
                // 做标记，避免再次入栈
                vis[Edges[i].v] = 1;
            }
        }
    }
}

void Graph::bfs_graph() {
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) {
        trace.clear();
        if (!vis[i]) {
            bfs(i);
        }
        for (int j = 0; j < trace.size(); j++) {
            cout << trace[j] << " -> ";
        }
        cout << endl;
    }
}

void Graph::dfs_graph() {
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) {
        trace.clear();
        if (!vis[i]) {
//             dfs(head, Edges, vis, trace, i);
            dfs_no_rc(i);
        }
        for (int j = 0; j < trace.size(); j++) {
            cout << trace[j] << " -> ";
        }
        cout << endl;
    }
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
