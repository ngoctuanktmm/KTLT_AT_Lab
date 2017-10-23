//#include <iostream>
////#include <cstddef>
//
//using namespace std;
//
//
//// Program 1
//
//void Program_1() {
//	long money;
//	short rate;
//
//	cout << "How much money can put in back account?  ";
//	cin >> money;
//	cout << "What is the interest rate? (e.g., for 10% enter 10)";
//	cin >> rate;
//
//	float InterestRate = static_cast<float>(rate) / 100;
//	cout << InterestRate << endl;
//
//	cout << "Year\tGrowth\tNew blance" << endl;
//
//	for (size_t i = 1; i <= 10; i++) {
//		long increae = static_cast<long>(money*InterestRate);
//		long newmoney = money + increae;
//
//		cout << i << "\t" << increae << "\t" << newmoney << endl;
//		money = newmoney;
//	}
//
//	cout << "Total " << money << endl;
//}
//
//
//
//// Program_2
//void Program_2() {
//	short money;
//	short rate;
//
//	cout << "How much money can put in back account?  ";
//	cin >> money;
//	cout << "What is the interest rate? (e.g., for 10% enter 10)";
//	cin >> rate;
//
//	float InterestRate = static_cast<float>(rate) / 100;
//	cout << InterestRate << endl;
//
//	cout << "Year\tGrowth\tNew blance" << endl;
//
//	for (size_t i = 1; i <= 10; i++) {
//		short increae = static_cast<short>(money*InterestRate);
//		short newmoney = money + increae;
//
//		cout << i << "\t" << increae << "\t" << newmoney << endl;
//		money = newmoney;
//	}
//
//	cout << "Total " << money << endl;
//}
//
//int main() {
//	
//	Program_1();
//
//
//	return 0;
//}




// Program 3

#include<iostream>
#include<stdint.h>
#include<cstdint>

using namespace std;

int* convertToBinary(int n) {
	int KQ[32], i = 0, j;
	int old_n = n;
	while (n > 0) {
		KQ[i] = n % 2; 
		i++;
		n /= 2;
	}
	cout << old_n << " =  ";
	for (j = i - 1; j >= 0; j--)
		cout << KQ[j];

	cout << endl;

	return KQ;
}

int mul_is_safe(uint32_t a, uint32_t b) {
	if (b > UINT32_MAX / a)
		return 0;
	return 1;
}

void showWarring() {
	cout << endl << "overflow warning" << endl;
}


uint32_t POW(uint32_t a, uint32_t b){
	uint32_t KQ = 1;
	int i;
	if (b == 0)
		return KQ;
	else {
		for (i = 1; i <= b; i++) {
			if (mul_is_safe(KQ, b))
				KQ *= a;
			else {
				showWarring();
				return 0;
			}
		}
	}

	return KQ;
}

int XOR(int a, int b) {
	int mult = 1;
	int res = 0;
	int i1, i2;

	for (int i = 0; i < 32; i++) {
		i1 = a % 2;
		i2 = b % 2;
		
		if (i1 != i2)
			res += mult;

		a /= 2;
		b /= 2;

		mult *= 2;
	}

	return res;
}



int main() {

	freopen("input.txt", "r", stdin);

	uint32_t x, y;
	//int *a = (int*)calloc(20, sizeof(int));
	//int *b = (int*)calloc(20, sizeof(int));
	cin >> x >> y;

	convertToBinary(x);
	convertToBinary(y);

	cout << x << " XOR " << y << " = " << XOR(x, y) << endl;
	convertToBinary(XOR(x, y));

	if (POW(x, y) != 0)
		cout << x << "^" << y << " = " << POW(x, y);

	return 0;
}

