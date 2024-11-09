#include <iostream>
#include <string>
#include <random>
#include <algorithm>

using namespace std;

int random(int min, int max) {
	static random_device rd;
	static mt19937 mt(rd());
	uniform_int_distribution<> dis(min, max);

	return dis(mt);
}

class IntSave {
private:
	int* arr;						  // ���� �迭�� �����ϴ� ������
	int size;						  // main���� ��ü ����(�ʱ�ȭ ��) ����Ǵ� �迭�� �ִ� ����
	int idx			 = random(1, 10); // �迭 index�� ��
	int removeIdxCnt = 0;			  // �����ؾ� �� index ����
public:
	// IntSave Ŭ������ ������
	IntSave(int size) {
		this->size = size;
		arr = new int[size]; // ���� �迭 �Ҵ�
	}

	// �迭 ������ ����ϴ� �޼ҵ�
	void addArr() {
		// ������
		cout << "=====================" << endl;
		cout << "arr �迭 ������  : " << size << endl;
		cout << "for���� index    : " << idx << endl;
		cout << "=====================" << endl;

		for (int i = 0; i < idx; i++) {
			// �����ڿ��� �����ߴ� �迭�� �ִ� ������ ��ġ�� ��� ������ �ø���.
			if (i == size) {
				arrExpand();
			}

			// 1 ~ 100������ ���� ���� �Ҵ�ȴ�.
			arr[i] = random(1, 100);

			// ������
			cout << "arr[i]           : " << arr[i] << endl;
		}
	}

	// ȣ�� ������ �迭 ���� Ȯ���� �� �ִ� �޼ҵ�
	void printArr() {
		cout << "arr [ ";

		for (int i = 0; i < idx; i++) {
			cout << arr[i] << " ";
		}

		cout << "]" << endl;
	}

	// ���� Ȯ�� �� ȣ���ϴ� �޼ҵ�
	void arrExpand() {
		int newSize = size * 2;			// ���� 2�� Ȯ���
		int* newArr = new int[newSize];	// temp�� �迭
		
		// ���
		for (int i = 0; i < size; i++) {
			newArr[i] = arr[i];
		}

		delete[] arr;		// ������ �ִ� �迭 �޸� ����
		int temp = size;
		arr		 = newArr;  // temp�� �迭�� �ִ� ������ ���� �ִ� �迭�� �ű�
		size	 = newSize; // �� �ƶ��� ����

		cout << "*********************" << endl;
		cout << "�迭�� �� á���Ƿ� ������ 2��� Ȯ���մϴ�." << endl;
		cout << " " << endl;
		cout << "���� �迭 ������ : " << temp << endl;
		cout << "���� �迭 ������ : " << size << endl;
		cout << "*********************" << endl;
	}

	int minNum() {
		if (size == 0) return -1;
		return *min_element(arr, arr + idx);
	}

	int maxNum() {
		if (size == 0) return -1;
		return *max_element(arr, arr + idx);
	}

	int oldNum() {
		if (idx == 0) return -1;
		return arr[0];
	}

	int newNum() {
		if (idx == 0) return -1;
		return arr[idx - 1];
	}

	int avgNum() {
		int result = 0;

		for (int i = 0; i < idx; i++) {
			result += arr[i];		// �� ��
		}
		result = (result / idx);	// �� �� = �� �� / �迭 index ����
		return result;				// ��� ��
	}

	void removeArrNum(int num) {
		for (int i = 0; i < idx; i++) {
			cout << "arr[i] = " << arr[i] << " num = " << num << endl;

			if (arr[i] == num) {
				arr[i] = 0;			// �ƶ� ���� remove
				removeIdxCnt++;
				break;
			}
		}
	}

	void numRemoveTask() {
		cout << "=====================" << endl;
		int minNum = this->minNum();
		int maxNum = this->maxNum();
		int oldNum = this->oldNum();
		int newNum = this->newNum();
		int avgNum = this->avgNum();

		cout << "���� ���� ����          : " << minNum << endl;
		cout << "���� ū ����            : " << maxNum << endl;
		cout << "���� ���� ���� ����   : " << oldNum << endl;
		cout << "���� ���߿� ���� ���� : " << newNum << endl;
		cout << "�迭 ���� ���� ��� ��  : " << avgNum << endl;
		cout << "=====================" << endl;
		cout << "���ǿ� �´� �ε����� ������ �����մϴ�." << endl;
		cout << " " << endl;
		this->removeArrNum(minNum);
		this->removeArrNum(maxNum);
		this->removeArrNum(oldNum);
		this->removeArrNum(newNum);
		this->removeArrNum(avgNum);
		cout << "=====================" << endl;
	}
};

int main() {
	int size = random(1, 10);
	IntSave intSave(size);		// ��ü ����
	intSave.addArr();			// �迭 �� �ʱ�ȭ
	intSave.numRemoveTask();	// �迭 �� ����
	intSave.printArr();			// �迭 ���
}