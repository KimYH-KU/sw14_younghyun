#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <deque>
using namespace std;
int n, m;
bool visit[1001][1001][2]; //0�� ���� �μ�����, 1�� ���� �Ⱥμ�����
int map[1001][1001];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
bool flag = false;
int cnt[1001][1001];
int answer = 987654321;
queue <pair<int, pair<int, int>>> q; //��ǥ�� �� �湮 ����
void bfs() {
	q.push(make_pair(1, make_pair(0, 0)));
	visit[0][0][1] = true;
	while (!q.empty()) {
		int y = q.front().second.first;
		int x = q.front().second.second;
		int wall = q.front().first;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (!(nx < 0 || ny < 0 || nx >= m || ny >= n)) {
				if (nx == (m - 1) && ny == (n - 1)) {
					cnt[ny][nx] = cnt[y][x] + 1;
					flag = true;
					answer = min(answer, cnt[ny][nx]);
				
					//���� ����.
				}
				//���� �ν� �� �ֳ� ���� ���ο� ���� ����.
				if (wall) {
					if (visit[ny][nx][wall] == false && map[ny][nx] == 0) { //���ΰ� �ִµ� 0�̸�.
						visit[ny][nx][wall] = true;
						cnt[ny][nx] = cnt[y][x] + 1;
						q.push(make_pair(wall, make_pair(ny, nx)));
					}
					else if (visit[ny][nx][wall] == false && map[ny][nx] == 1) { //���ΰ� �ִµ� 1�̸�,
						visit[ny][nx][wall] = true;
						cnt[ny][nx] = cnt[y][x] + 1;
						q.push(make_pair(wall-1, make_pair(ny, nx)));
					}
				}
				else { //�ɷ��� �� �� �� ���.
					if (visit[ny][nx][wall] == false && map[ny][nx] == 0) {
						visit[ny][nx][wall] = true;
						cnt[ny][nx] = cnt[y][x] + 1;
						q.push(make_pair(wall, make_pair(ny, nx)));
					}
				}
			}
		}
	}
	

}
int main() {
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	if (n == m && m == 1) {
		cout << 0 << '\n';
		return 0;
	}
	bfs();
	if (flag)
		cout << answer+1 << '\n';
	else
		cout << -1 << '\n';
	return 0;
}