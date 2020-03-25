#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 401

int n, k, s;
int room[MAX][MAX];
//vector <int> v[401];
//bool visit[401];
// 이문제를 기존 dfs로 풀어보려 하였으나, dfs에서 시간복잡도는 노드 + 엣지인데, 여긴 쿼리가 50000까지 가능하므로, 5만의 제곱인 25억이라 시간 초과 발생.
// 따라서, 플로이드 와샬 알고리즘을 이용해 보도록 해보겠음.
// 강의는 동빈나님 강의 참조. 그니까 전체 노드에를 기준으로 최단거리를 갱신한다는 알고리즘 같음. 
// 이 강의를 듣고 다익스트라도 들어봐야겠음. 

// 이문제를 처음 풀때는 벡터로 풀려 했는데(dfs)를 이용하려 했으니, 맵에 저장해둘 부분이 필요해서.(없으면 0 으로 하기도 용이하므로.)
// 이차원 배열로 풀도록 함.

//bool search(int s_index, int f_index) {
//	for (int i = 0; i < v[s_index].size(); i++) {
//		if (v[s_index][i] == f_index)
//			return true;
//		if (v[v[s_index][i]].size() && !visit[v[s_index][i]]) { //있으면 다음 노드로 ㄱ ㄱ 
//			visit[v[s_index][i]] = true;
//			search(v[s_index][i], f_index);
//		}
//	}
//	return false;
//}

void floydWarshall() {
	for (int c = 1; c <= n; c++) { //중간 노드
		for (int i = 1; i <= n; i++) { //처음 노드
			for (int j = 1; j <= n; j++) { //끝 노드
				if (!room[i][j]) { //업뎃이 안된, 0인 사건들에 대해서.
					//if (room[i][j] > room[i][c] + room[c][n]) { //처음과 끝이 중간을 거친 값보다 더 크다면,
					//	room[i][j] = room[i][c] + room[c][n]; // 여긴 근데 지금 0, -1, 1뿐임. 
					//}
					// 고로 위처럼 써주는게 아니라 다른 방식으로 사용.
					// 그니까, 중간점을 기준으로 확인을 하면서 i와 j를 통해 업뎃한다고 생각하면 됨.
					if (room[i][c] == 1 && room[c][j] == 1) room[i][j] = 1; //시작이 중간보다 나중에 일어났고, 중간이 끝보다 나중이라면, 시작이 끝보다 나중에 일어남.
					else if (room[i][c] == -1 && room[c][j] == -1) room[i][j] = -1; //이건 반대.

				}
				
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;

	int t1, t2;

	for (int i = 0; i < k; i++) {
		cin >> t1 >> t2;
		room[t1][t2] = -1;
		room[t2][t1] = 1; //역은 편의를 위해 -1 넣어줌.
	}
	floydWarshall();
	cin >> s;
	for (int i = 0; i < k; i++) {
		cin >> t1 >> t2;
		cout << room[t1][t2] << '\n';
	}

	//그럼 연결이 되어있으면 1, 역이면 -1, 없으면 0인 상태.

	//for (int i = 0; i < k; i++) {
	//	int t1, t2;
	//	cin >> t1 >> t2; //앞에 있는 사건이 뒤보다 먼저.
	//	v[t1].push_back(t2);
	//}
	//for (int i = 1; i <= n; i++) {
	//	if(v[i].size())
	//		sort(v[i].begin(), v[i].end());
	//}
	//cin >> s;
	//for (int i = 0; i < s; i++) {
	//	int t1, t2;
	//	cin >> t1 >> t2;
	//	//앞에서 한번 서치
	//	//거꾸로 서치
	//	//둘다 없으면 0 출력
	//	memset(visit, 0, sizeof(visit));
	//	if (search(t1, t2)) {
	//		cout << -1 << '\n';
	//		continue;
	//	}
	//	memset(visit, 0, sizeof(visit));
	//	if (search(t2, t1)) {
	//		cout << 1 << '\n';
	//		continue;
	//	}
	//	cout << 0 << '\n';
	//}
	return 0;
}