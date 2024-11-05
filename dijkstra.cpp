#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

typedef long long ll;

const ll INF = numeric_limits<ll>::max();

vector<ll> djikstra(const vector<vector<pair<int, int>>>& g, int start) {
    int n = g.size();
    vector<ll> distance(n, INF);
    distance[start] = 0;

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.emplace(0, start);

    while (!pq.empty()) {
        ll dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (dist > distance[node]) continue;

        for (const auto& edge : g[node]) {
            int v = edge.first;
            int weight = edge.second;

            if (distance[node] + weight < distance[v]) {
                distance[v] = distance[node] + weight;
                pq.emplace(distance[v], v);
            }
        }
    }

    return distance;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
  
    vector<vector<pair<int, int>>> g(n);

    for(int i=0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a -= 1;
        b -= 1;

        g[a].emplace_back(b, w);
        g[b].emplace_back(a, w);
    }

    auto distances = djikstra(g, 0);

    if(distances[n-1] == INF) {
        cout << -1;
        return 0;
    }

    cout << distances[n-1];

    return 0;
}

/*
3 4
2 3 1
1 3 7
2 1 5
output: 4=
 */
