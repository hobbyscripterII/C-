#include <iostream>	// ����� Ŭ����
#include <string>	// string Ŭ����(�⺻ Ÿ���� �ƴϱ� ������ ���� x ������ ������ �Ѵ�)

using namespace std;

int total = 0;

int ForTest(int idx) {
	for (int i = 0; i < idx; i++) {
		cout << "i     = " << i << endl;
		total += i;
		cout << "total = " << total << endl;
		cout << " " << endl;
	}

	return total;
}

//int main() {
//	int result = ForTest(10);
//	
//	cout << "ForTest�� ��� ���� " << result << "�Դϴ�." << endl;
//}