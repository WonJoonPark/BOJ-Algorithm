#include<iostream>
using namespace std;
class VectorbyPark {
public:
	     int sz;
		 int* VectorArr=new int[64];
		 int Vsize;
	VectorbyPark() {
		Vsize = 0; sz = 64;
	}
	~VectorbyPark(){}
	bool empty() {
		if (Vsize == 0) { return true; }
		else return false;
	}
	void set(int i, int x) {
		if ((i + 1) > Vsize) { cout << "肋给等 立辟" << '\n'; }
		else {
			VectorArr[i] = x;
		}
	}
	int at(int i) {
		if (i + 1 > Vsize) { cout << "肋给等 立辟" << '\n'; }
		return VectorArr[i];
	}
	int size() {
		return Vsize;
	}
	void insert(int i, int x) {
		if ((i + 1) % sz == 0) {
			int *tmp = new int[sz];
			for (int i = 0; i < sz; i++) {
				tmp[i] = VectorArr[i];
			}
			delete[] VectorArr;
			sz *= 2;
			int *VectorArr = new int[sz];
			for (int i = 0; i < sz / 2; i++) {
				VectorArr[i] = tmp[i];
			}
			delete[] tmp;
			VectorArr[i] = x;
			Vsize++;
		}
		else {
			Vsize++;
			for (int j = Vsize-1; j >= i; j--) {
				VectorArr[j] = VectorArr[j-1];
			}
			VectorArr[i] = x;
		}
	}
	void push_back(int x) {
		if ((Vsize) > sz ) {
			int *tmp = new int[sz];
			for (int i = 0; i < sz; i++) {
				tmp[i] = VectorArr[i];
			}
			delete[] VectorArr;
			sz *= 2;
			int *VectorArr = new int[sz];
			for (int i = 0; i < sz / 2; i++) {
				VectorArr[i] = tmp[i];
			}
			delete[] tmp;
			VectorArr[Vsize] = x;
			Vsize++;
		}
		else {
			VectorArr[Vsize] = x;
			Vsize++;
		}
	}
	void erase(int i) {
		for (int j = i; j < Vsize-1; j++) {
			VectorArr[j] = VectorArr[j + 1];
		}
		Vsize--;
	}
};

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	VectorbyPark obj;
	obj.push_back(1); //index 0
	obj.push_back(2); //index 1
	obj.push_back(3); //index 2
	for (int i = 0; i < obj.Vsize; i++) {
		cout << obj.VectorArr[i] << '\n';
	}
	obj.insert(1, 100);
	cout<<"\n\n";
	for (int i = 0; i < obj.Vsize; i++) {
		cout << obj.VectorArr[i] << '\n';
	}
	obj.erase(1);
	cout << "\n\n";
	for (int i = 0; i < obj.Vsize; i++) {
		cout << obj.VectorArr[i] << '\n';
	}

	cout << "\n\n";
	VectorbyPark obj2;
	for (int i = 0; i < 64; i++) {
		obj2.push_back(i);
	}
	obj2.push_back(64);
	for (int i = 0; i < obj2.Vsize; i++) {
		cout << obj2.VectorArr[i] << '\n';
	}
	return 0;
}