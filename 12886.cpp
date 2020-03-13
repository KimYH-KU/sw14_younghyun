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
int a, b, c;
queue<pair<int, int>> q;
vector <int> v;
bool visit[1001][1001]; //�� �κ��� �򰥸��µ�, � ��쿡�� ���� 1000�� �Ѿ�� �ʴ´�. ��� �ּҶ� �ִ밪�� üũ���ָ� ��.
int total;
void bfs() {
	sort(v.begin(), v.end());
	q.push({ v[0], v[2] });
	visit[v[0]][v[2]] = true;
	while (!q.empty()) {
		int A = q.front().first; //�ּҰ�
		int B = q.front().second; //�ִ밪.
		int C = total - (A + B); //�߰���.
		q.pop();
		if (A == B && B == C) {
			cout << 1;
			return;
		}
		int nx[3] = { A, A, C }; int ny[3] = { B, C, B };
		for (int i = 0; i < 3; i++) {
			int x = nx[i];
			int y = ny[i];
			if (x == y) //���� ���� �н�
				continue;
			int X = x * 2;
			int Y = y - x;
			int Z = total - X - Y;
			int mini = min(min(X, Y), Z);
			int maxi = max(max(X, Y), Z);
			if (visit[mini][maxi] == false) {
				visit[mini][maxi] = true;
				q.push({ mini,maxi });
			}
		}
	}
	cout << 0;
	return;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b >> c;
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	total = a + b + c;
	//������ ���ĵ� �׻� ���� ����.
	if (a == b && b == c) { //�� ���� ������ ��.
		cout << 1;
		return 0;
	}
	else if ((a + b + c) % 3) { // �� ������ �� 3�� ����� �ȵǸ� �׾ �ȵ�.
		cout << 0;
		return 0;
	}
	bfs();
	return 0;
}