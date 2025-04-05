#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

int main() {
	// N = ���� ����, M = ���� ����
	int N, M;
	cin >> N >> M;

	// ��� �迭
	vector<vector<int>> costs(N, vector<int>(N, -1));

	for (int i = 0; i < M; i++) {
		int start_num, end_num, cost;
		cin >> start_num >> end_num >> cost;
		// ���� �ش� ��ο� cost�� �־����� ���� ���(cost == -1�� ���) -> �ٷ� cost ����
		if (costs[start_num - 1][end_num - 1] == -1) costs[start_num - 1][end_num - 1] = cost;
		// �ش� ��ο� cost�� �ִٸ� �� ������ cost�� ����
		else if (costs[start_num - 1][end_num - 1] > cost) costs[start_num - 1][end_num - 1] = cost;
	}

	int start, end;
	cin >> start >> end;

	// Memory : i��° ���÷ΰ��� ���� �鷯���ϴ� ���� ���� �ѹ�
	vector<int> Memory(N, -1);

	// Ž���� ���� ť ����
	queue<int> q;

	// q�� ��������� �� �� �ִ� ���õ� push
	for (int i = 0; i < N; i++) {
		if (costs[start - 1][i] != -1) {
			Memory[i] = start;
			q.push(i);
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		// ť���� ���� ���ÿ��� �� �� �ִ� ���õ� Ž��
		for (int i = 0; i < N; i++) {
			if (costs[cur][i] != -1) {
				// Memory[i]�� -1�� ��� -> Memory[i]�� cost ����
				if (costs[start - 1][i] == -1) {
					costs[start - 1][i] = costs[start - 1][cur] + costs[cur][i];
					Memory[i] = i + 1;
					q.push(i);
				}
				// Memory[i]�� -1�� �ƴ� ��� -> �� ������ cost�� ����
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