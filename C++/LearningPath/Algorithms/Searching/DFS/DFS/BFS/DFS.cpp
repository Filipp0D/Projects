#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int src, vector<vector<int>>& graph) {
    vector<bool> visited(graph.size(), false);

    dfsUtil(src, graph, visited);

}

// Output: void (print ordine di visita), input: nodo src, grafo
void dfsUtil(int node, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;

    cout << node << endl;
    
    for (int neighbour : graph[node]) {
        if (!visited[neighbour]) {
            dfsUtil(neighbour, graph, visited);
        }
    }

}

// no recursive
void dfsNoRecursive(int node, vector<vector<int>> graph) {
    stack<int> nodesStack;
    vector<bool> visited(graph.size(), false);
    nodesStack.push(node);
    while (!nodesStack.empty()) {
        int node = nodesStack.top();

        if (!visited[node]) {
            cout << node << endl;
            visited[node] = true;
            nodesStack.push(node);


            // aggiunge allo stack tutti gli elementi del nodo e li porta a visited in true se non lo sono, 
            // poi ricomincia dalla cima dello stack
            for (auto it = graph[node].rbegin(); it != graph[node].rend(); ++it) {
                int neighbor = it->first;
                if (!visited[neighbor]) {
                    nodesStack.push(neighbor);
                }
            }
        }
    }

}

int main()
{
    std::cout << "Hello World!\n";
}

