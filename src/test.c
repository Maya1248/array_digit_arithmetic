#include <stdio.h>

void ADD(int a[], int b[], int res[]) {
	int tmp = 0, carry = 0;

	for (int i=0; i<4; i++) {
		tmp = a[i] + b[i] + carry;

		if (tmp > 9) {
			carry = 1;
			tmp = tmp % 10;
		} else {
			carry = 0;
		}

		res[i] = tmp;
	}

	if (carry == 1) {
		res[5] = 1;
	} else {
		res[5] = 0;
	}
}

int main() { // 4321 + 9876 = 14197
	int a[4] = {1,2,3,4};
	int b[4] = {6,7,8,9};

	int res[5];

	ADD(a, b, res);
	
	int flag = 0;
	for (int i=5; i>=0; i--) {
		if (res[i] == 0 && flag == 0) {
			
			flag = 1;
		} else {
			printf("%d", res[i]);
		}
	}
	printf("\n");
	
	return 0;
}
