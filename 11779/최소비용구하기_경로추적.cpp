#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
	// N = ���� ����, M = ���� ����
	int N, M;
	cin >> N >> M;

	// ��� �迭
	vector<vector<int>> costs(N, vector<int>(N, -1));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int start_num, end_num, cost;
			cin >> start_num >> end_num >> cost;
			// ���� �ش� ��ο� cost�� �־����� ���� ���(cost == -1�� ���) -> �ٷ� cost ����
			if (costs[start_num - 1][end_num - 1] == -1) costs[start_num - 1][end_num - 1] = cost;
			// �ش� ��ο� cost�� �ִٸ� �� ������ cost�� ����
			else if(costs[start_num - 1][end_num - 1] > cost) costs[start_num - 1][end_num - 1] = cost;
		}
	}

	int start, end;
	cin >> start >> end;

	vector<int> Memory(N, -1);

	// Ž���� ���� ť ����
	queue<int> q;

	// q�� ��������� �� �� �ִ� ���õ� push
	for (int i = 0; i < N; i++) {
		if(costs[start-1][i] != -1) q.push()
	}

}