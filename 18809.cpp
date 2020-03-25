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
//vector<pair<int, int>> v; // 배양액을 뿌릴 수 있는 땅의 수.
//typedef tuple<int, int, int> p;
//struct func {
//	bool operator()(p a, p b) { //a가 하단값.
//	/*	int a_x, a_y, a_z;
//		tie(a_x, a_y, a_z) = a;
//		int b_x, b_y, b_z;
//		tie(b_x, b_y, b_z) = a;
//		return a_z > b_z;*/
//		return get<2>(a) > get<2>(b);
//	}
//};
//priority_queue<p, vector<p>, func> q; //테스트용으로 만들어봄.
//int answer;
//int real_answer;
//int bfs() {
//	answer = 0;
//	while (!q.empty()) {
//		int y, x, time;
//		tie(y, x, time) = q.top(); //time은 이제 시간
//		q.pop();
//		for (int i = 0; i < 4; i++) {
//			int ny = y + dy[i];
//			int nx = x + dx[i];
//			if (ny < 0 || nx < 0 || ny > n - 1 || nx > m - 1 || !copy_room[ny][nx])
//				continue;
//			//g는 3, r은 4가 들어와있는상황. 
//			if (copy_room[y][x] == 3) {
//				//내가 3인데, 가려는 곳이 4가 아니면,
//				if (copy_room[ny][nx] != 4) {
//					if (q_visit[ny][nx] == false) {
//						q_visit[ny][nx] = true;
//						copy_room[ny][nx] = 3;
//						q.push({ ny, nx, time + 1 });
//						room_time[ny][nx] = time + 1;
//					}
//				}
//				else { //4면.
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
//				else { //4면.
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
//	//여기가 잘못되었다.
//	//g+r만큼만 돌도록 해야함. 
//	if (cnt == g) {
//		memcpy(copy_room, room, sizeof(room));
//		memset(q_visit, 0, sizeof(q_visit));
//		for (int i = 0; i < v.size(); i++) {
//			if (visit2[i]) { //true인 경우만 선택받음. g는 3, r은 4
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
//	//0은 호수, 1은 뿌릴 수 없는 땅, 2는 배양액을 뿌릴 수 있는 땅.
//	//땅의 개수는 R+G개 이상, 10개 이하
//	//경우의 수가 생각보다 많지 않아서 전부 다 해줘서 꽃의 개수를 구하는 식으로 해줘야 할듯.
//
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cin >> room[i][j];
//			if (room[i][j] == 2) {
//				v.push_back({ i, j });
//			}
//		}
//	}
//	//g나 r을 기준으로 조합의 개수를 구해줌.
//
//	//dfs를 두번 해줘야 할 거 같음. 전체에서 g+r만큼 한 번, 거기서 g 고르는거 한 번.
//	dfs(0, 0);
//	cout << real_answer << '\n';
//	return 0;
//}