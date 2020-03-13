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
typedef long long ll;
using namespace std;
int n, m;
char room[51][51];
int walk[51][51];
bool visit[51][51][(1<<6)];
typedef tuple<int, int, int> p;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
int answer = 987654321;
struct func {
	bool operator()(pair<int, int> a, pair<int, int> b) { //a�� �ϴܰ�.
		return a.first > b.first;
	}
};
priority_queue<p, vector<p>, func> pq; //�׽�Ʈ������ ����.

queue<p> q;

//�� ������ Ű�� ���ε� ť�� �־���� �ϱ� ������ ť���� �Ẹ���� ����.
//��Ʈ����ũ �� �����ϱ�. |�� or, &�� and, �׸��� 1 << a�� 1�� a��ŭ �������� shift�϶�� ��.
bool bfs(int a, int b, int c) {
	q.push({ a,b,c });
	visit[a][b][c] = true;
	while (!q.empty()) {
		int y, x, ke;
		tie(y, x, ke) = q.front(); // �̷��� �� �� �ִ°� �˾Ƶα�.
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && nx >= 0 && ny < n && nx < m) {
				if (room[ny][nx] == '#')
					continue;
				if (room[ny][nx] == '1') {
					walk[ny][nx] = walk[y][x] + 1;
					answer = walk[ny][nx];
					return true;
				}
				if (room[ny][nx] >= 'a' && room[ny][nx] <= 'f' && visit[ny][nx][ke] == false) { //������ε� �Ȱ��� ���.
					int nk = ke | (1 << (int(room[ny][nx] - 'a')));
					visit[ny][nx][ke] = true;
					walk[ny][nx] = walk[y][x] + 1;
					q.push({ ny, nx, nk });
				}
				else if (room[ny][nx] >= 'A' && room[ny][nx] <= 'F' && visit[ny][nx][ke] == false) { //���϶�.
					int flag = ke & (1 << (int(room[ny][nx] - 'A')));
						if (flag) // ���谡 �ִٸ�,
						{
							visit[ny][nx][ke] = true;
							walk[ny][nx] = walk[y][x] + 1;
							q.push({ ny, nx, ke });
						}
				}
				else { //.�̳� 0���� ������϶�.
					if (visit[ny][nx][ke] == false) {
						visit[ny][nx][ke] = true;
						walk[ny][nx] = walk[y][x] + 1;
						q.push({ ny, nx, ke });
					}
				}

			}
		}
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	int start_y, start_x;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> room[i][j];
			if (room[i][j] == '0') {
				start_y = i; start_x = j;
			}
		}
	}
	if (bfs(start_y, start_x, 0)) 
		cout << answer;
	else
		cout << -1 << '\n';

}