#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <deque>
typedef long long ll;
using namespace std;
int n, m;
ll k;
ll dp[102][102];
string answer;

// dp를 이용해서 푼 문제. 조합에서 dp[i][j] = dp[i][j - 1] * (i + j) / j; 이라는 점을 기억하기. 
// 왔다갔다 하면서 개수를 이용해서 푼 좋은 문제. 방식은 꼭 기억하기.
void sear(int y, int x, ll num) {
	if (y == 0) {
		for (int i = 0; i < x; i++) {
			answer += 'z';
		}
		return;
	}
	if (x == 0) {
		for (int i = 0; i < y; i++) {
			answer += 'a';
		}
		return;
	}
	if (dp[y - 1][x] >= num) {
		answer += 'a';
		sear(y - 1, x, num);
	}
	else {
		answer += 'z';
		sear(y, x-1, num - dp[y - 1][x]);
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	//n은 a의 개수, m은 z의 개수.
	//경우의 수는 n+m C n 가지인데.
	cin >> n >> m >> k;
	dp[1][1] = 2;
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			if (i == 0 || j == 0) { //이렇게 쓰는게 편하겠군.
				dp[i][j] = 1;
				continue;
			}
			dp[i][j] = dp[i][j - 1] * (i + j) / j;
			if (dp[i][j] > 1000000000)
				dp[i][j] = 1000000000;
		}
	}
	if (dp[n][m] < k) {
		cout << -1 << '\n';
		return 0;
	}
	sear(n, m, k);
	cout << answer << '\n';
}