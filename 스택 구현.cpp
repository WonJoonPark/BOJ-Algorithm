#include<iostream>
using namespace std;
const int MAX_SIZE = 20;
class StackbyPark {
private:
	int top; //����check
	int data[MAX_SIZE];

public:
	StackbyPark() { top = -1; } //������
	~StackbyPark() {} //�Ҹ���

	bool iS_empty() {
		if (top == -1) return true;
		else { return false; }}
	bool full() {
		if (top == MAX_SIZE - 1) return true;
		else { return false; }}
	void push(int e) {
		if (full()) { cout << "������ ���� á���ϴ�" << '\n'; }
		data[++top] = e;}// ��Ҹ� ���ÿ� ����
	int pop() {
		if (iS_empty()) { cout << "������ ����ֽ��ϴ�" << '\n'; }
		return data[top--]; }
	int peek() {
		if (iS_empty()) { cout << "������ ����ֽ��ϴ�" << '\n'; }
		return data[top];}//��Ҹ� Ȯ�θ� �ϴ°��̹Ƿ� ���Ҵ� ����
	int size() {
		return top + 1;}
};
int main() {
	StackbyPark daeeung;
	if (daeeung.iS_empty() == true) { cout << "������ ������ϴ�" << '\n'; }
	daeeung.push(3);
	int x = daeeung.peek();
	cout << x << '\n';
	cout << daeeung.size() << '\n';
	return 0;
}