#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <deque>
#include <tuple>
using namespace std;
int n, m;
char room[51][51];
bool visit[51][51][(1 << 2)][5];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
typedef tuple<int, int, int, int, int> t;
int ans;
queue <t> q;
//�� ������ �ʼ��Ұ����ϰ� �Դ� ������ ���ư� �� �ۿ� ����. 2x2 ¥�� sc / c#�� �����ϸ� ��. ��� �ϳ� ���������� �湮�� �ٸ��� ����� �Ѵ�.
//���� ���� ���� ������ ����ߴ��� �Ѱ��ָ� ���ҵ�. ť���� ����°���ڸ� �������� �ϱ�� ��. 
//visit �ΰ��δ� �ȵɵ�. �� ���� ���� �ٸ� ���� �־������. 

//���� ������δ� ��ǰ. �� ������ �ٽ� ���ư��� �͵� ����������. 
//����� ���� ���ļ� ������� ����. ���⿡ ���ؼ� Ȯ������ ������, �ٽ� ���ư��� �Ѵٴ� ���� �߸� �������༭ ���� �ɷȴ�. ������ 4���⿡ ���� �˻簡 �ʿ���.
bool bfs(int a, int b) {
	q.push({ a,b,4, 0, 0 });
	visit[a][b][0][4] = true;
	bool flag = false;
	while (!q.empty()) {
		int y, x, dir, num, cnt;
		tie(y, x, dir, num, cnt) = q.front();
		q.pop();
		if (num == 3) {
			ans = cnt;
			return true;
		}
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny > n - 1 || nx > m - 1 || visit[ny][nx][num][i] || room[ny][nx] == '#' || dir == i)
				continue;
			int temp = num;
			if (room[ny][nx] == 'C') {
				temp |= (1 << 0);
			}
			else if (room[ny][nx] == 'D') {
				temp |= (1 << 1);

			}
			visit[ny][nx][temp][i] = true;
			q.push({ ny, nx, i, temp, cnt + 1 });
		}
	}
	return false;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	int s_y;
	int s_x;
	int c_y, c_x;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> room[i][j];
			if (room[i][j] == 'S') {
				room[i][j] = '.';
				s_y = i;
				s_x = j;
			}
			else if (room[i][j] == 'C') {
				c_y = i;
				c_x = j;
			}
		}
	}
	room[c_y][c_x] = 'D';
	if (bfs(s_y, s_x))
		cout << ans << '\n';
	else
		cout << -1 << '\n';
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << answer[i][j][2] << ' ';
		}
		cout << '\n';
	}*/
	return 0;
}