#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <deque>
#include <functional>
using namespace std;

priority_queue<int, vector<int>, greater<int>> MaxQ;
priority_queue<int> MinQ;

// 중간값 찾기. 우선 순위 큐를 처음사용해본 문제. 아이디어를 떠올리는 것이 중요하다는 것을 느낌. 좋은 문제였다.
// 내림차순이 기본 값이고. 오름차순으로 사용할때는 위와 같이 짜줄 것.
// 즉 최대힙이 내림차순. 최소힙이 우선차순을 의미한다.(여기서는 이름 반대로 씀..)

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int temp;

	int n;
	cin >> n;
	if (n == 1) {
		cin >> temp;
		cout << temp;
		return 0;
	}
	//MinQ는 중간값보다 큰 값을 내림차순으로 
	//MaxQ는 작은 값을 오름차순으로 저장
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (MaxQ.empty()) { //처음은 무조건 오른쪽에.
			MaxQ.push(temp);
			cout << temp << '\n';
		}
		else {
			if (temp >= MaxQ.top())
				MaxQ.push(temp);
			else
				MinQ.push(temp);

			if (MaxQ.size() >= MinQ.size() + 2) {
				MinQ.push(MaxQ.top());
				MaxQ.pop();
			}
			else if (MinQ.size() >= MaxQ.size() + 1) {
				MaxQ.push(MinQ.top());
				MinQ.pop();
			}
			if (MinQ.size() == MaxQ.size())
				cout << MinQ.top() << '\n';
			else
				cout << MaxQ.top() << '\n';
		}

			

		
	}
	return 0;
}