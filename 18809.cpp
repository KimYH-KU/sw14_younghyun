//#include <iostream>
//#include <string>
//#include <cstring>
//#include <cmath>
//#include <stack>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <deque>
//#include <tuple>
//using namespace std;
//int n, m, g, r;
//int room[51][51];
//int copy_room[51][51];
//int room_time[51][51];
//int arr[10];
//int visit[10];
//int visit2[10];
//bool q_visit[51][51];
//int dx[4] = { 0, 1, 0, -1 };
//int dy[4] = { -1, 0, 1, 0 };
//vector<pair<int, int>> v; // ������ �Ѹ� �� �ִ� ���� ��.
//typedef tuple<int, int, int> p;
//struct func {
//	bool operator()(p a, p b) { //a�� �ϴܰ�.
//	/*	int a_x, a_y, a_z;
//		tie(a_x, a_y, a_z) = a;
//		int b_x, b_y, b_z;
//		tie(b_x, b_y, b_z) = a;
//		return a_z > b_z;*/
//		return get<2>(a) > get<2>(b);
//	}
//};
//priority_queue<p, vector<p>, func> q; //�׽�Ʈ������ ����.
//int answer;
//int real_answer;
//int bfs() {
//	answer = 0;
//	while (!q.empty()) {
//		int y, x, time;
//		tie(y, x, time) = q.top(); //time�� ���� �ð�
//		q.pop();
//		for (int i = 0; i < 4; i++) {
//			int ny = y + dy[i];
//			int nx = x + dx[i];
//			if (ny < 0 || nx < 0 || ny > n - 1 || nx > m - 1 || !copy_room[ny][nx])
//				continue;
//			//g�� 3, r�� 4�� �����ִ»�Ȳ. 
//			if (copy_room[y][x] == 3) {
//				//���� 3�ε�, ������ ���� 4�� �ƴϸ�,
//				if (copy_room[ny][nx] != 4) {
//					if (q_visit[ny][nx] == false) {
//						q_visit[ny][nx] = true;
//						copy_room[ny][nx] = 3;
//						q.push({ ny, nx, time + 1 });
//						room_time[ny][nx] = time + 1;
//					}
//				}
//				else { //4��.
//					if (time + 1 == room_time[ny][nx])
//						answer++;
//				}
//			}
//			else if (copy_room[y][x] == 4) {
//				if (copy_room[ny][nx] != 3) {
//					if (q_visit[ny][nx] == false) {
//						q_visit[ny][nx] = true;
//						copy_room[ny][nx] = 4;
//						q.push({ ny, nx, time + 1 });
//						room_time[ny][nx] = time + 1;
//					}
//				}
//				else { //4��.
//					if (time + 1 == room_time[ny][nx])
//						answer++;
//				}
//			}
//
//		}
//	}
//	return answer;
//}
//void dfs2(int idx, int cnt) {
//	//���Ⱑ �߸��Ǿ���.
//	//g+r��ŭ�� ������ �ؾ���. 
//	if (cnt == g) {
//		memcpy(copy_room, room, sizeof(room));
//		memset(q_visit, 0, sizeof(q_visit));
//		for (int i = 0; i < v.size(); i++) {
//			if (visit2[i]) { //true�� ��츸 ���ù���. g�� 3, r�� 4
//				int y = v[i].first;
//				int x = v[i].second;
//				if (visit2[i] == 2) {
//					copy_room[y][x] = 3;
//					q_visit[y][x] = true;
//					q.push({ y, x, 0 });
//				}
//				else {
//					copy_room[y][x] = 4;
//					q_visit[y][x] = true;
//					q.push({ y, x, 0 });
//				}
//			}
//		}
//		//cout << real_answer << '\n';
//		real_answer = max(bfs(), real_answer);
//		return;
//	}
//
//	for (int i = idx; i < v.size(); i++) {
//		if (visit[i]) {
//			if (visit2[i] == 2)
//				continue;
//			visit2[i] = 2;
//			dfs2(i + 1, cnt + 1);
//			visit2[i] = 1;
//		}
//	}
//}
//void dfs(int idx, int cnt) {
//	if (cnt == g + r) {
//		for (int i = 0; i < v.size(); i++) {
//			if (visit[i])
//				visit2[i] = 1;
//		}
//		dfs2(0, 0);
//		memset(visit2, 0, sizeof(visit2));
//		return;
//	}
//	for (int i = idx; i < v.size(); i++) {
//		if (visit[i])
//			continue;
//		visit[i] = true;
//		dfs(i + 1, cnt + 1);
//		visit[i] = false;
//
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	cin >> n >> m >> g >> r;
//	//0�� ȣ��, 1�� �Ѹ� �� ���� ��, 2�� ������ �Ѹ� �� �ִ� ��.
//	//���� ������ R+G�� �̻�, 10�� ����
//	//����� ���� �������� ���� �ʾƼ� ���� �� ���༭ ���� ������ ���ϴ� ������ ����� �ҵ�.
//
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cin >> room[i][j];
//			if (room[i][j] == 2) {
//				v.push_back({ i, j });
//			}
//		}
//	}
//	//g�� r�� �������� ������ ������ ������.
//
//	//dfs�� �ι� ����� �� �� ����. ��ü���� g+r��ŭ �� ��, �ű⼭ g ���°� �� ��.
//	dfs(0, 0);
//	cout << real_answer << '\n';
//	return 0;
//}