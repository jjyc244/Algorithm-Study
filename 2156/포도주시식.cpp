#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
 
int main() {
	int N;
	cin >> N;
	vector<int> wines(N, 0);
	vector<int> DP(N, 0);
	for (int i = 0; i < N; i++) cin >> wines[i];
	DP[0] = wines[0];
	//N == 1 이면 정답 출력후 main 함수 종료
	if (N == 1) { cout << DP[0]; return 0; }

	DP[1] = wines[0] + wines[1];
	//N == 2 이면 정답 출력후 main 함수 종료
	if (N == 2) { cout << DP[1]; return 0; }

	DP[2] = max(wines[0] + wines[2], wines[1] + wines[2]);
	//N == 3 이면 정답 출력후 main 함수 종료
	if (N == 3) { cout << max(DP[1], DP[2]); return 0; }

	DP[3] = max(wines[0] + wines[1] + wines[3], wines[0] + wines[2] + wines[3]);

	for (int i = 4; i < N; i++) {
		DP[i] = max(max(DP[i - 2] + wines[i], DP[i - 3] + wines[i - 1] + wines[i]), DP[i-4] + wines[i-1] + wines[i]);
	}
	cout << max(DP[N-2],DP[N - 1]);
}