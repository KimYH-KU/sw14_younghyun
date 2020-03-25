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
// �̹����� ���� dfs�� Ǯ��� �Ͽ�����, dfs���� �ð����⵵�� ��� + �����ε�, ���� ������ 50000���� �����ϹǷ�, 5���� ������ 25���̶� �ð� �ʰ� �߻�.
// ����, �÷��̵� �ͼ� �˰����� �̿��� ������ �غ�����.
// ���Ǵ� ���󳪴� ���� ����. �״ϱ� ��ü ��忡�� �������� �ִܰŸ��� �����Ѵٴ� �˰��� ����. 
// �� ���Ǹ� ��� ���ͽ�Ʈ�� �����߰���. 

// �̹����� ó�� Ǯ���� ���ͷ� Ǯ�� �ߴµ�(dfs)�� �̿��Ϸ� ������, �ʿ� �����ص� �κ��� �ʿ��ؼ�.(������ 0 ���� �ϱ⵵ �����ϹǷ�.)
// ������ �迭�� Ǯ���� ��.

//bool search(int s_index, int f_index) {
//	for (int i = 0; i < v[s_index].size(); i++) {
//		if (v[s_index][i] == f_index)
//			return true;
//		if (v[v[s_index][i]].size() && !visit[v[s_index][i]]) { //������ ���� ���� �� �� 
//			visit[v[s_index][i]] = true;
//			search(v[s_index][i], f_index);
//		}
//	}
//	return false;
//}

void floydWarshall() {
	for (int c = 1; c <= n; c++) { //�߰� ���
		for (int i = 1; i <= n; i++) { //ó�� ���
			for (int j = 1; j <= n; j++) { //�� ���
				if (!room[i][j]) { //������ �ȵ�, 0�� ��ǵ鿡 ���ؼ�.
					//if (room[i][j] > room[i][c] + room[c][n]) { //ó���� ���� �߰��� ��ģ ������ �� ũ�ٸ�,
					//	room[i][j] = room[i][c] + room[c][n]; // ���� �ٵ� ���� 0, -1, 1����. 
					//}
					// ��� ��ó�� ���ִ°� �ƴ϶� �ٸ� ������� ���.
					// �״ϱ�, �߰����� �������� Ȯ���� �ϸ鼭 i�� j�� ���� �����Ѵٰ� �����ϸ� ��.
					if (room[i][c] == 1 && room[c][j] == 1) room[i][j] = 1; //������ �߰����� ���߿� �Ͼ��, �߰��� ������ �����̶��, ������ ������ ���߿� �Ͼ.
					else if (room[i][c] == -1 && room[c][j] == -1) room[i][j] = -1; //�̰� �ݴ�.

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
		room[t2][t1] = 1; //���� ���Ǹ� ���� -1 �־���.
	}
	floydWarshall();
	cin >> s;
	for (int i = 0; i < k; i++) {
		cin >> t1 >> t2;
		cout << room[t1][t2] << '\n';
	}

	//�׷� ������ �Ǿ������� 1, ���̸� -1, ������ 0�� ����.

	//for (int i = 0; i < k; i++) {
	//	int t1, t2;
	//	cin >> t1 >> t2; //�տ� �ִ� ����� �ں��� ����.
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
	//	//�տ��� �ѹ� ��ġ
	//	//�Ųٷ� ��ġ
	//	//�Ѵ� ������ 0 ���
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