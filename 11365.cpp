#include<iostream>
#include<string.h>
using namespace std;

int main() {
	while (1) {
		char arrs[500] = {};
		scanf("%[^\n]", &arrs);
		if (!strcmp(arrs, "END")) break;
		int size = 0;
		for (int i = 0; i < 500; i++) {
			if (arrs[i] == NULL) break;
			size++;
		}
		for (int i = size - 1; i >= 0; i--) {
			printf("%c", arrs[i]);
		}
		printf("\n");
		getchar();
	}
	return 0;
}