#include<iostream>
using namespace std;
const int MAX_SIZE = 20;
class StackbyPark {
private:
	int top; //개수check
	int data[MAX_SIZE];

public:
	StackbyPark() { top = -1; } //생성자
	~StackbyPark() {} //소멸자

	bool iS_empty() {
		if (top == -1) return true;
		else { return false; }}
	bool full() {
		if (top == MAX_SIZE - 1) return true;
		else { return false; }}
	void push(int e) {
		if (full()) { cout << "스택이 가득 찼습니다" << '\n'; }
		data[++top] = e;}// 요소를 스택에 삽입
	int pop() {
		if (iS_empty()) { cout << "스택이 비어있습니다" << '\n'; }
		return data[top--]; }
	int peek() {
		if (iS_empty()) { cout << "스택이 비어있습니다" << '\n'; }
		return data[top];}//요소를 확인만 하는것이므로 감소는 없음
	int size() {
		return top + 1;}
};
int main() {
	StackbyPark daeeung;
	if (daeeung.iS_empty() == true) { cout << "스택이 비었습니다" << '\n'; }
	daeeung.push(3);
	int x = daeeung.peek();
	cout << x << '\n';
	cout << daeeung.size() << '\n';
	return 0;
}