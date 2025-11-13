#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Output: void (print nodi in ordine di visita), input: nodo partenza, grafo
void bfs(int src, vector<vector<int>>& graph) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;

    visited[src] = true;
    q.push(src);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << endl;

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]){
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }

}

int main()
{
    std::cout << "Hello World!\n";
}

