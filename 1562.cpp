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

//���� ��ܼ��� �����Ǵ� ����. ��Ʈ����ũ�� ���� ���� �˾ұ⿡ ���� �ذ��� �� �־���.
//�ٸ�, ��ȭ���� Ȯ���ϰ� ����� ������ Ǯ��.
//������ ������ ����� ������ += ��� Ǯ� ������� ��.

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int a;
	cin >> a;

	//0���� 9�� �� ����ߴ��� �˻簡 �ʿ���. 
	for (int i = 1; i <= 9; i++) {
		d[0][i][1 << i] = 1;
	}
	//�� ���ڸ� ����־������� �ش� ó�� ������ �ʿ���. 
	//�׸��� ���߿� ������� 1<<10�� ���� ���ָ� �ɵ�. ��Ȯ���� 1<<10 -1.
	//or�� ���ָ� �ɵ�(��Ʈ����ŷ).

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
				{ // 0�� �ƴ� ���.
					d[i][j][temp] = (d[i][j][temp] + d[i - 1][j - 1][k]) % M;
					d[i][j][temp] = (d[i][j][temp] + d[i - 1][j + 1][k]) % M;
				}



			}
		}
	}
	//��ȭ���� �� ����� �״����� ���� ������ ��.
	ll answer = 0;
	for (int i = 0; i < 10; i++) {
		answer = (answer + d[a - 1][i][(1 << 10) - 1]) % M;
	}

	cout << answer << '\n';


	return 0;
}