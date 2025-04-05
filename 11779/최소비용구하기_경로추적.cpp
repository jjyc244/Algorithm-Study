#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

int main() {
	// N = 도시 개수, M = 버스 개수
	int N, M;
	cin >> N >> M;

	// 비용 배열
	vector<vector<int>> costs(N, vector<int>(N, -1));

	for (int i = 0; i < M; i++) {
		int start_num, end_num, cost;
		cin >> start_num >> end_num >> cost;
		// 아직 해당 경로에 cost가 주어지지 않은 경우(cost == -1인 경우) -> 바로 cost 대입
		if (costs[start_num - 1][end_num - 1] == -1) costs[start_num - 1][end_num - 1] = cost;
		// 해당 경로에 cost가 있다면 더 저렴한 cost로 대입
		else if (costs[start_num - 1][end_num - 1] > cost) costs[start_num - 1][end_num - 1] = cost;
	}

	int start, end;
	cin >> start >> end;

	// Memory : i번째 도시로가기 위해 들러야하는 이전 도시 넘버
	vector<int> Memory(N, -1);

	// 탐색을 위한 큐 생성
	queue<int> q;

	// q에 출발지에서 갈 수 있는 도시들 push
	for (int i = 0; i < N; i++) {
		if (costs[start - 1][i] != -1) {
			Memory[i] = start;
			q.push(i);
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		// 큐에서 꺼낸 도시에서 갈 수 있는 도시들 탐색
		for (int i = 0; i < N; i++) {
			if (costs[cur][i] != -1) {
				// Memory[i]가 -1인 경우 -> Memory[i]에 cost 대입
				if (costs[start - 1][i] == -1) {
					costs[start - 1][i] = costs[start - 1][cur] + costs[cur][i];
					Memory[i] = i + 1;
					q.push(i);
				}
				// Memory[i]가 -1이 아닌 경우 -> 더 저렴한 cost로 대입
				else if (costs[start - 1][i] > costs[start - 1][cur] + costs[cur][i]) {
					costs[start - 1][i] = costs[start - 1][cur] + costs[cur][i];
					Memory[i] = cur + 1;
					q.push(i);
				}
			}
		}
	}

	stack<int> path;
	path.push(end);
	int p = end;
	while (p != start) {
		p = Memory[p - 1];
		path.push(p);
	}

	cout << costs[start - 1][end - 1] << endl;
	cout << path.size() << endl;
	while (!path.empty()) {
		cout << path.top() << " ";
		path.pop();
	}
}