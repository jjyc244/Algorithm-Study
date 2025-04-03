#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
	// N = 도시 개수, M = 버스 개수
	int N, M;
	cin >> N >> M;

	// 비용 배열
	vector<vector<int>> costs(N, vector<int>(N, -1));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int start_num, end_num, cost;
			cin >> start_num >> end_num >> cost;
			// 아직 해당 경로에 cost가 주어지지 않은 경우(cost == -1인 경우) -> 바로 cost 대입
			if (costs[start_num - 1][end_num - 1] == -1) costs[start_num - 1][end_num - 1] = cost;
			// 해당 경로에 cost가 있다면 더 저렴한 cost로 대입
			else if(costs[start_num - 1][end_num - 1] > cost) costs[start_num - 1][end_num - 1] = cost;
		}
	}

	int start, end;
	cin >> start >> end;

	vector<int> Memory(N, -1);

	// 탐색을 위한 큐 생성
	queue<int> q;

	// q에 출발지에서 갈 수 있는 도시들 push
	for (int i = 0; i < N; i++) {
		if(costs[start-1][i] != -1) q.push()
	}

}