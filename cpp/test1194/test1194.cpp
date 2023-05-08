#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct dot {
	int x;
	int y;
	int cnt;
	char key;
};

int N, M;
char field[51][51];
bool visited[51][51];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void BFS(pair<int, int> st) {
	queue<dot> q;
	q.push({ st.first, st.second, 0, (char)NULL });
	visited[st.first][st.second] = true;

	while (!q.empty()) {
		dot now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			dot nt = now;
			nt.cnt += 1;

			if (!visited[nt.x][nt.y]) {
				visited[nt.x][nt.y] = true;
				q.push(nt);
			}
		}
	}

	cout << "-1\n";
}

int main() {
	cin >> N >> M;

	pair<int, int> st;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> field[i][j];

			if (field[i][j] == '0')
				st = { i, j };
		}
	}

	BFS(st);
}