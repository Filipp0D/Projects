#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using ll = long long;
const ll INF = (ll)1e18;	// "infinito" pratico


// n: nodi, m: archi
// su arco u, v: nodi, w: peso
// sorgente: src, destinazione: target
// vector<vector<pair<int, int>>> rappresentazione del grafo con indice 
// - adj[u]: nodo considerato, 
// - adj[u][v, w]: vettori di coppie di nodoaccanto e peso arco che li collega

// Output: distanza e nodi predecessori, input: #nodi, grafo, sorgente
pair<vector<ll>, vector<int>> dijkstra(int n, const vector<vector<pair<int, int>>>& adj, int src) {
	// init vars da restitutire
	vector<ll> dist(n, INF);	// vettore di n valori tutti settati a INF
	vector<int> prev(n, -1); // nodi predecessori tutti settati a -1 (non ancora verificati)
	dist[src] = 0;

	// min-heap: coda di priorità con minimo in cima
	// Forma base priority_queue:
	// template <
	//		class T,                           // 1️⃣ tipo degli elementi contenuti
	//		class Container = vector<T>,       // 2️⃣ struttura dati usata per contenerli
	//		class Compare = less<T>            // 3️⃣ criterio di confronto (ordine)
	// > class priority_queue;
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	pq.push({ 0, src }); // inserisce coppia distanza-nodo di partenza

	while (!pq.empty()) {
		auto [d, u] = pq.top();		// prendo elt a distanza minima (primo della lista)	
		pq.pop();					// tolgo elt che sto per processare dalla lista

		if (d != dist[u]) continue;

		for (auto [v, w] : adj[u]) {
			// relaxation condition -> se v nodo "nuovo" dist[v] sarà inf, 
			// se nodo "noto" dist[v] maggiore => modo nuovo più veloce per arrivarci, 
			// se nodo "noto" dist[v] minore, strada ottimale gà c'è e scartiamo
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				prev[v] = u;
				pq.push({ dist[v], v });
			}
		}
	}
	return { dist, prev };
}

	// ricostruisce percorso da target a src
	// Output: sequenza nodi, input: src, target, prev
vector<int> reconstruct_path(int src, int target, vector<int>& prev) {
	vector<int> path;
	int cur = target;
	while (cur != -1) {
		path.push_back(cur);
		if (cur == src) break;
		cur = prev[cur];
	}
	if (path.empty() || path.back() != src) {};		// target non raggiungibile
	reverse(path.begin(), path.end());
	return path;
}






using ll = long long;
ll INF = (ll)1e18;

pair<vector<ll>, vector<int>> Dijkstra(vector<vector<pair<int, int>>> graph, int src, int n) {
	vector<ll> dist(n, INF);
	vector<int> prev(n, -1);
	priority_queue<pair<ll, int>, vector<pair<ll,int>>, greater<pair<ll,int>>> prio_q;
	
	dist[src] = 0;
	prio_q.push({ dist[src], src });

	while (!prio_q.empty()) {
		auto [d, u] = prio_q.top();
		prio_q.pop();

		for (auto& [v, w] : graph[u]) {
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				prev[v] = u;
				prio_q.push({dist[v], v});
			}
		}
	}

	return { dist, prev };
}

vector<int> reconstructPath(vector<int> prev, int target, int src) {
	vector<int> path;
		int cur = target;
		int i = 0;
	while (cur != -1) {
		path.push_back(cur);
		if (cur == src) break;
		cur = prev[cur];
	}

	if (path.empty() || path.back() != src) {};
	reverse(path.begin(), path.end());

	return path;


}



int main() {



	return 0;
}