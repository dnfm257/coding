#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, R, cnt;
vector<int> seq;
vector<vector<int>> graph;
vector<bool> visited;

void DFS(int st){
	visited[st] = true;

	seq[st] = ++cnt;

	for (int i = 0; i < graph[st].size(); i++) {
		int nxt = graph[st][i];

		if (!visited[nxt]) {
			DFS(nxt);
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> R;

	seq.resize(N + 1);
	graph.resize(N + 1);
	visited.resize(N + 1);

	int u, v;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		graph[u].emplace_back(v);
		graph[v].emplace_back(u);
	}
	
	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	DFS(R);

	for(int i = 1; i <= N; i++){
		cout << seq[i] << "\n";
	}
}