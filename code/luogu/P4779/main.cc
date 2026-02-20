#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 1000*1000;

struct edge {
  int v, w;
  edge(int v, int w) : v(v), w(w) {}
};


struct node {
  int dis, u;
  node(int dis, int u) : dis(dis), u(u) {}
  bool operator>(const node& a) const { return dis > a.dis; }
};

vector<edge> e[maxn];
int dis[maxn], vis[maxn];
priority_queue<node, vector<node>, greater<node> > q;

void dijkstra(int n, int s) {
  memset(dis, 63, sizeof(dis));
  dis[s] = 0;
  q.push(node(0, s));
  while (!q.empty()) {
    int u = q.top().u;
    q.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    for (auto ed : e[u]) {
      int v = ed.v, w = ed.w;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        q.push(node(dis[v], v));
      }
    }
  }
}

void run() {
    int n,m,s;
    cin>> n >> m >>s;
    for (int i = 0; i < m; i++){
        int u,v,w;
        cin>> u >> v >> w;
        e[u].push_back(edge(v, w));
    }
    dijkstra(n,s);
    for (int i = 1; i <= n; i++){
        cout<< dis[i] << " ";
    }

}

int main() {
#if defined(__APPLE__) || defined(__WIN32__)
    freopen("./slyar.in", "r+", stdin);
    freopen("./slyar.out", "w+", stdout);
#endif
    run();
}
