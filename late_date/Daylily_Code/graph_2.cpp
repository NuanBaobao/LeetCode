//
// Created by �Ž��� on 2022/5/5.
//

# include<iostream>
# include <memory>
#include <cstring>
# include <vector>
# include <stack>
# include<queue>

using namespace std;
const int MAX_SIZE = 1e2 + 5;

// ��ʽǰ����ʵ��ͼ�Ĵ洢
struct Edge {
    int u, v, w, next;
};

class Graph {
public:
    int n, m;
    int head[MAX_SIZE], tot = 1; //tot �� Edges ���±�
    int vis[MAX_SIZE]; // �������
    stack<int> stak;  // dfs����ջ
    queue<int> que; // bfs��������
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
    memset(res.head, -1, sizeof(res.head)); // head��ʼֵĬ��û�����ӱ�

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
    //����һ����
    Edges[tot].u = u;
    Edges[tot].v = v;
    Edges[tot].w = w;
    //ָ���¼���ߵ�ǰ���ڵ�
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
    // �Ӷ���u�����������������ͼ
    trace.push_back(u); // ���ʳ�ʼ����v
    vis[u] = 1;  // ��v���ѷ��ʱ��
    que.push(u); // ����u�����

    while (!que.empty()) {
        int node = que.front(); // ����u������
        que.pop();
        for (int v = head[node]; v != -1; v = Edges[v].next) {
            // ���u�������ھӽڵ�
            if (!vis[v]) {
                // v Ϊu��δ���ʵ��ڽӶ���
                trace.push_back(v);  // ���ʶ���v
                vis[v] = 1; // ��v���ѷ��ʱ��
                que.push(v); // ����v�����
            }
        }
    }
}

// ʹ��ջ�������һ�����ܷ��ʵĶ��㣬ͬʱʹ���˷��ʱ������vis[i]��ǵ�i�������Ƿ���ջ�ڻ�������ջ��(�Ƿ񱻷��ʹ�),�������Ժ��ܽ�ջ
void Graph::dfs_no_rc(int u) {
    // �Ӷ���u��ʼ������ȱ��������α���һ����ͨ���������ж���
    stak.push(u);  // u��ջ����vis[u]
    vis[u] = 1;
    while (!stak.empty()) {
        int node = stak.top();  // ջ���˳�һ������
        stak.pop();
        trace.push_back(node);  // ���ʸö��㲢�����ӽڵ���ջ
        for (int i = head[node]; i != -1; i = Edges[i].next) {
            // ����node�������ڽӶ���
            if (!vis[Edges[i].v]) {
                // δ����ջ(δ����)�Ķ����ջ
                stak.push(Edges[i].v);
                // ����ǣ������ٴ���ջ
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
