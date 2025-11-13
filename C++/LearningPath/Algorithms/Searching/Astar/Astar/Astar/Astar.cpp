#include <iostream>
#include <vector>
#include <queue>


using ll = long long;
const ll INF = 1e18;


// Output: coppia di vettori distanza da src e nodi predecessori, input: #nodi, grafo, src, target, vettore euristico
pair<vector<ll>, vector<int>> a_star(
    int n,
    vector<vector<pair<int, int>>>& graph,
    int src,
    int target,
    vector<ll>& h
) {
    vector<ll> realCost(n, INF);
    vector<ll> totalCost(n, INF);
    vector<int> prev(n, -1);

    realCost[src] = 0;
    totalCost[src] = h[src];
    
    priority_queue <pair<ll,int>, vector<pair<ll,int>, greater<pair<ll,int>>> prio_q;

    prio_q.push({ totalCost[src], src });

    while (!prio_q.empty()) {
        auto& [totalCost_curr, u] = prio_q.top();
        prio_q.pop();

        if (u == target) break;

        for (auto& [v, w] : graph) {
            if (realCost[v] > realCost[u] + w) {
                realCost[v] = realCost[u] + w;
                totalCost[v] = realCost[v] + h[v];
                prev[v] = u;

                prio_q.push({ totalCost[v], v });
            }
        }
    }
    return { realCost, prev };
}

vector<int> reconstruct_path(vector<int>& prev, int src, int target) {
    vector<int> path;
    int cur = target;
    while (cur != -1) {
        path.push_back(cur);
        cur = prev[cur];
    }
    reverse(path.begin(), path.end());

    return path;

// posso anche scriverlo come:
//   for (int cur = goal; cur != -1; cur = prev[cur])
//        path.push_back(cur);
}


int main()
{
    std::cout << "Hello World!\n";
}

