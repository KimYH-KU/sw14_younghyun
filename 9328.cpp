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
char room[110][110];
bool visit[110][110];
typedef tuple<int, int, int> p;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
int answer = 0;
bool key_room[26];
queue<p> q;
vector <pair<int, int>> v[26];
// �� ������ ���� �������� ���ڸ� Ǯ�� �ٷ� ����.
// ����ó�� visit�� �̿��� ���� ����. (���� ������ 26�̶� ����� ���� 2^26)
// visit�� �ϳ��� ����, ��� �ش� ���踦 ������ ���� �����ִ� ������ �����غ���, �׸��� ������ Ž�� ������ �ϴ°���.
// ���� ��������. �̷��� �󸶳� ������������ �߿����� �ʴٸ�, Ư�� �������� Ž���� ������ �� �ֵ��� �ϴ� ���̵� �߿��ߴ� ����.
void bfs() {
	q.push({ 0,0,0 });
	visit[0][0] = true;
	while (!q.empty()) {
		int y, x, ke;
		tie(y, x, ke) = q.front(); // �̷��� �� �� �ִ°� �˾Ƶα�.
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && nx >= 0 && ny <= n+1 && nx <= m+1) {
				if (room[ny][nx] == '*')
					continue;
				if (room[ny][nx] == '$' && visit[ny][nx] == false) { //�������.
					visit[ny][nx] = true;
					room[ny][nx] = '0';
					answer++;
					q.push({ ny, nx, ke });
				}
				else if (room[ny][nx] >= 'a' && room[ny][nx] <= 'z' && visit[ny][nx] == false) { //������ε� �Ȱ��� ���.
					key_room[int(room[ny][nx] - 'a')] = true;
					visit[ny][nx] = true;
					q.push({ ny, nx, ke });
					if (v[room[ny][nx] - 'a'].size()) { //�ʿ� �ִ� ���̶��. ���Ⱑ Ʋ�ȴ�. �湮�ߴ� ���� �־����� �ߴµ�.
						for (int j = 0; j < v[room[ny][nx] - 'a'].size(); j++) {
							int dy = v[room[ny][nx] - 'a'][j].first;
							int dx = v[room[ny][nx] - 'a'][j].second;
							if (visit[dy][dx] == false) {
								visit[dy][dx] = true;
								room[dy][dx] = '0';
								q.push({ dy, dx, ke });
							}
						}
					}
					room[ny][nx] = '0';
					
					
				}
				else if (room[ny][nx] >= 'A' && room[ny][nx] <= 'Z' && visit[ny][nx]== false) { //���϶�.
					if (key_room[int(room[ny][nx] - 'A')]) { //���谡 �ִٸ�,
						room[ny][nx] = '0';
						visit[ny][nx] = true;
						q.push({ ny, nx, ke });
					}
					else {
						v[int(room[ny][nx] - 'A')].push_back({ ny, nx });
					}
				}
				else { //.�̳� 0���� ������϶�.
					if (visit[ny][nx] == false) {
						visit[ny][nx] = true;
						q.push({ ny, nx, ke });
					}
				}

			}
		}
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		answer = 0;
		memset(room, 0, sizeof(room));
		memset(visit, 0, sizeof(visit));
		memset(key_room, 0, sizeof(key_room));
		for (int i = 0; i < 26; i++) {
			v[i].clear();
		}
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> room[i][j];
				
			}
		}
		string s;
		cin >> s;
		if (s != "0") {
			for (int i = 0; i < s.size(); i++) {
				char temp = s[i];
				
				key_room[(int(temp- 'a'))] = true;
			}
		}
		bfs();
		cout << answer << '\n';
	}
	

}