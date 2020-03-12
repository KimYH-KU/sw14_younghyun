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

// �߰��� ã��. �켱 ���� ť�� ó������غ� ����. ���̵� ���ø��� ���� �߿��ϴٴ� ���� ����. ���� ��������.
// ���������� �⺻ ���̰�. ������������ ����Ҷ��� ���� ���� ¥�� ��.
// �� �ִ����� ��������. �ּ����� �켱������ �ǹ��Ѵ�.(���⼭�� �̸� �ݴ�� ��..)

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
	//MinQ�� �߰������� ū ���� ������������ 
	//MaxQ�� ���� ���� ������������ ����
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (MaxQ.empty()) { //ó���� ������ �����ʿ�.
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