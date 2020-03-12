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

// dp�� �̿��ؼ� Ǭ ����. ���տ��� dp[i][j] = dp[i][j - 1] * (i + j) / j; �̶�� ���� ����ϱ�. 
// �Դٰ��� �ϸ鼭 ������ �̿��ؼ� Ǭ ���� ����. ����� �� ����ϱ�.
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
	
	//n�� a�� ����, m�� z�� ����.
	//����� ���� n+m C n �����ε�.
	cin >> n >> m >> k;
	dp[1][1] = 2;
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			if (i == 0 || j == 0) { //�̷��� ���°� ���ϰڱ�.
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