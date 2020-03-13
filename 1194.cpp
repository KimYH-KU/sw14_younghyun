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
	bool operator()(pair<int, int> a, pair<int, int> b) { //a가 하단값.
		return a.first > b.first;
	}
};
priority_queue<p, vector<p>, func> pq; //테스트용으로 만들어봄.

queue<p> q;

//이 문제는 키의 여부도 큐에 넣어줘야 하기 때문에 큐플을 써보도록 하자.
//비트마스크 꼭 복습하기. |은 or, &은 and, 그리고 1 << a는 1을 a만큼 왼쪽으로 shift하라는 뜻.
bool bfs(int a, int b, int c) {
	q.push({ a,b,c });
	visit[a][b][c] = true;
	while (!q.empty()) {
		int y, x, ke;
		tie(y, x, ke) = q.front(); // 이렇게 쓸 수 있는거 알아두기.
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
				if (room[ny][nx] >= 'a' && room[ny][nx] <= 'f' && visit[ny][nx][ke] == false) { //열쇠방인데 안갔을 경우.
					int nk = ke | (1 << (int(room[ny][nx] - 'a')));
					visit[ny][nx][ke] = true;
					walk[ny][nx] = walk[y][x] + 1;
					q.push({ ny, nx, nk });
				}
				else if (room[ny][nx] >= 'A' && room[ny][nx] <= 'F' && visit[ny][nx][ke] == false) { //문일때.
					int flag = ke & (1 << (int(room[ny][nx] - 'A')));
						if (flag) // 열쇠가 있다면,
						{
							visit[ny][nx][ke] = true;
							walk[ny][nx] = walk[y][x] + 1;
							q.push({ ny, nx, ke });
						}
				}
				else { //.이나 0같이 출발점일때.
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