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
typedef long long ll;
#define M 1000000000;

ll d[101][10][1 << 10];

//쉬운 계단수와 연동되는 문제. 비트마스크를 쓰는 것을 알았기에 쉽게 해결할 수 있었음.
//다만, 점화식을 확실하게 세우고 문제를 풀기.
//나눗셈 연산을 사용할 때에는 += 대신 풀어서 사용해줄 것.

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int a;
	cin >> a;

	//0부터 9를 다 사용했는지 검사가 필요함. 
	for (int i = 1; i <= 9; i++) {
		d[0][i][1 << i] = 1;
	}
	//각 숫자를 집어넣어줬을때 해당 처리 구문이 필요함. 
	//그리고 나중에 결과값은 1<<10의 값만 해주면 될듯. 정확히는 1<<10 -1.
	//or로 해주면 될듯(비트마스킹).

	for (int i = 1; i <= a; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 1; k < (1 << 10); k++) {
				int temp = k;
				temp |= (1 << (j));

				/*cout << d[i][j][k] << ',' << i << ',' <<k << '\n';*/
				if (!j) {
					//d[i][j][temp] += d[i-1][j+1][k] % MAX;
					d[i][j][temp] = (d[i][j][temp] + d[i - 1][j + 1][k]) % M;

				}
				else if (j == 9) {
					d[i][j][temp] = (d[i][j][temp] + d[i - 1][j - 1][k]) % M;
				}
				else
				{ // 0이 아닌 경우.
					d[i][j][temp] = (d[i][j][temp] + d[i - 1][j - 1][k]) % M;
					d[i][j][temp] = (d[i][j][temp] + d[i - 1][j + 1][k]) % M;
				}



			}
		}
	}
	//점화식을 꼭 세우고 그다음에 식을 세워줄 것.
	ll answer = 0;
	for (int i = 0; i < 10; i++) {
		answer = (answer + d[a - 1][i][(1 << 10) - 1]) % M;
	}

	cout << answer << '\n';


	return 0;
}