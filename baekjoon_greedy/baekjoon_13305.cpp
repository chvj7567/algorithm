#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::min;

int main() {
	// ������ ��
	int num_of_city;
	// �� ���ݰ�, ���� �� �������� ����
	long long price, min_city;
	// �� ������ ������� ���� ���� �Ÿ�
	vector<long long> city, dis;

	// ������ �� �Է�
	cin >> num_of_city;

	// �� ���� ���� �Ÿ� �Է�
	for (int i = 0; i < num_of_city - 1; i++) {
		int tmp;
		cin >> tmp;
		dis.push_back(tmp);
	}

	// �� ������ ������ �Է�
	for (int i = 0; i < num_of_city; i++) {
		int tmp;
		cin >> tmp;
		city.push_back(tmp);
	}

	// 1��° ���ÿ��� 2��° ���ñ�����
	// ������ 1��° ���ÿ��� ���� �� ������
	min_city = city[0];
	price = city[0] * dis[0];

	// ���� ������ ������� �� �� �� ������� ����
	for (int i = 1; i < city.size() - 1; i++) {
		min_city = min(min_city, city[i]);
		price += min_city * dis[i];
	}

	cout << price << endl;

	return 0;
}