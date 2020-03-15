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
//이 문제는 필수불가결하게 왔던 곳으로 돌아갈 수 밖에 없다. 2x2 짜리 sc / c#을 생각하면 됨. 고로 하나 먹은다음엔 방문을 다르게 해줘야 한다.
//또한 전에 무슨 방향을 사용했는지 넘겨주면 편할듯. 큐에서 세번째인자를 방향으로 하기로 함. 
//visit 두개로는 안될듯. 두 개에 따라 다른 값을 넣어줘야함. 

//지금 방식으로는 못품. 이 문제는 다시 돌아가는 것도 고려해줘야함. 
//사소한 것을 놓쳐서 힘들었던 문제. 방향에 대해서 확실하지 않지만, 다시 돌아가야 한다는 것을 잘못 생각해줘서 오래 걸렸다. 저렇게 4방향에 대한 검사가 필요함.
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