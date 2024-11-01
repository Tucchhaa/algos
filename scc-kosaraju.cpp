#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int n, m;

vector<vector<int>> g, inv_g;
vector<bool> vis;
vector<int> order;

void dfs1(int v) {
    vis[v] = true;

    for(auto &to : g[v]) {
        if(!vis[to])
            dfs1(to);
    }

    order.push_back(v);
}

void dfs2(int v, vector<int>& component) {
    component.push_back(v);
    vis[v] = true;

    for(auto& to: inv_g[v]) {
        if(!vis[to])
            dfs2(to, component);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    g.resize(n);
    inv_g.resize(n);
    vis.resize(n);

    for(int i=0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        a -= 1; b-= 1;

        g[a].push_back(b);
        inv_g[b].push_back(a);
    }

    for(int i=0; i < n; i++) {
        if(!vis[i])
            dfs1(i);
    }

    fill(vis.begin(), vis.end(), false);
    reverse(order.begin(), order.end())
    vector<vector<int>> scc;

    for(auto& v: order) {
        if(!vis[v]) {
            vector<int> component;
            dfs2(v, component);
            scc.push_back(component);
        }
    }

    for(auto& component: scc) {
        cout << "component: ";
        for(auto v: component) {
            cout << v << " ";
        }
        cout << "\n";
    }

    return 0;
}

/*
5 7
1 3
2 4
3 5
1 4
4 2
5 2
5 1

output: 0 4 and 1 2 3
 */
