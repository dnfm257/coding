#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int V, E;
long long ans;
vector<pair<int, int>> tree[10001];
bool visited[10001];

void prim() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
	pq.push(make_pair(0, 1));

	while (!pq.empty()) {
		int cost = pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (!visited[now]) {
			visited[now] = true;
			ans += cost;

			for (int i = 0; i < tree[now].size(); i++) {
				int nxt = tree[now][i].second;
				int nt_cost = tree[now][i].first;

				if (!visited[nxt])
					pq.push(make_pair(nt_cost, nxt));

			}
		}
	}
}

int main() {
	cin >> V >> E;

	int a, b, c;
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		tree[a].push_back({ c, b });
		tree[b].push_back({ c, a });
	}

	prim();

	cout << ans << "\n";
}