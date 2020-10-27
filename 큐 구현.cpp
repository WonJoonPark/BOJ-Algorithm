#include<iostream>
using namespace std;
const int MAX_QUEUE_SIZE=20;
class queuebyPark {
private:
	int data[MAX_QUEUE_SIZE];
	int frontindex;
	int rearindex;
	int qarrsize;
public:
	queuebyPark() {
		frontindex = 0; rearindex = -1; qarrsize = 0;
	}
	void Enqueue(int inputnum);
	void Dequeue();
	bool IsEmpty();
	int queuesize();
	int front();
	int rear();
};

bool queuebyPark::IsEmpty() {
	if (qarrsize == 0) { return true; }
	else { return false; }
}
void queuebyPark::Enqueue(int inputnum) {
	if (queuesize() == MAX_QUEUE_SIZE) {// 자료의 크기가 배열의 전체크기를 넘을경우
		cout << "error" << '\n';
		return;
	}
	rearindex = (rearindex + 1) % MAX_QUEUE_SIZE; 
	data[rearindex] = inputnum;
	qarrsize++;
	return;
}
void queuebyPark::Dequeue() {
	if (IsEmpty() == true) {
		cout << "큐가 비어있습니다" << '\n'; return;
	}
	int tmp = data[frontindex];
	frontindex = (frontindex + 1) % MAX_QUEUE_SIZE;
	qarrsize--;
}
int queuebyPark::queuesize() {
	return qarrsize;
}
int queuebyPark::front() {
	if (IsEmpty() == true) {
		cout << "큐가 비어있습니다" << '\n';
}
	else {
		return data[frontindex];
	}
}
int queuebyPark::rear() {
	if (IsEmpty() == true) {
		cout << "큐가 비어있습니다" << '\n';
	}
	else {
		return data[rearindex];
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	queuebyPark qqq1;
	qqq1.Enqueue(1);
	qqq1.Enqueue(2);
	qqq1.Enqueue(3);
	cout << qqq1.front() << '\n';
	cout << qqq1.rear() << '\n';
	qqq1.Dequeue();
	qqq1.Dequeue();
	qqq1.Dequeue();
	if (qqq1.IsEmpty()) { cout << "큐가 비었습니다" << '\n'; }
	queuebyPark qqq2;
	for (int i = 0; i < 20; i++) {
		qqq2.Enqueue(i);
	}
	qqq2.Enqueue(3);
	cout << qqq2.front() << '\n';
	cout << qqq2.rear() << '\n';


	return 0;
}