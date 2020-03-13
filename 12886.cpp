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
bool visit[1001][1001]; //이 부분은 헷갈리는데, 어떤 경우에도 수가 1000을 넘어가지 않는다. 고로 최소랑 최대값만 체크해주면 됨.
int total;
void bfs() {
	sort(v.begin(), v.end());
	q.push({ v[0], v[2] });
	visit[v[0]][v[2]] = true;
	while (!q.empty()) {
		int A = q.front().first; //최소값
		int B = q.front().second; //최대값.
		int C = total - (A + B); //중간값.
		q.pop();
		if (A == B && B == C) {
			cout << 1;
			return;
		}
		int nx[3] = { A, A, C }; int ny[3] = { B, C, B };
		for (int i = 0; i < 3; i++) {
			int x = nx[i];
			int y = ny[i];
			if (x == y) //같을 경우는 패스
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
	//과정을 거쳐도 항상 합은 같음.
	if (a == b && b == c) { //세 수가 같으면 끝.
		cout << 1;
		return 0;
	}
	else if ((a + b + c) % 3) { // 다 더했을 때 3의 배수가 안되면 죽어도 안됨.
		cout << 0;
		return 0;
	}
	bfs();
	return 0;
}