// Program_1
#include <iostream>
#include <stdlib.h>

using namespace std;

int n, m;
int a[20], b[20], c[40];

void p1() {
	int i;
	cout << "- Cau 1:" << endl;
	do {
		cout << " - Nhap gia tri cua n:   ";
		cin >> n;
	} while (10 > n || n > 20);

	for (i = 0; i < n; i++) {
		a[i] = rand() % 500 + 10;
		b[i] = rand() % 500 + 10;
	}
}

void p2(int *a, int n) {
	int i;
	for (i = 0; i < n; i++)
		cout << "\t" << a[i];
	cout << endl;
}

void p3() {
	int i, j = -1;
	int temp[40];
	for (i = 0; i <= n; ) {
		if (a[i] % 2 == 0) {
			j++;
			c[j] = a[i];
		}
		if (b[i] % 2 != 0) {
			j++;
			c[j] = b[i];
		}
		i++;
	}


	m = j;
}

int mul_is_safe(uint32_t a, uint32_t b) {
	if (b > INT_MAX / a)
		return 0;
	return 1;
}

void showWarring() {
	cout << endl << " => Integer overflow" << endl;
}

void p4() {
	int i;
	long int KQ = 1;
	for (i = 0; i < m; i++) {
		if (mul_is_safe(c[i], KQ))
			KQ *= c[i];
		else {
			showWarring();
			return;
		}
	}

	cout << " - Tich cac phan tu cua mang C:   " << KQ << endl;
}

int main() {
	p1();

	cout << " - Mang A:   " << endl;
	p2(a, n);
	cout << " - Mang B:   " << endl;
	p2(b, n);

	p3();

	cout << " - Mang C:   " << endl;
	p2(c, m);
	
	p4();

	system("pause");
	//return 0;

}

//////
//////
//////
//////
//////
//////
//////
//////
//////// Program_2
//////#include <iostream>
//////
//////using namespace std;
//////
//////char S1[1000], S2[1000];
//////
//////int getlen(char *s) {
//////	int len = 0;
//////	while (s[len] != '\0')
//////		len++;
//////	return len;
//////}
//////
//////int check(char *S2) {
//////	int len = getlen(S2);
//////	int i;
//////
//////	for (i = 0; i < len; i++) {
//////		if (S2[i] - 48 < 0 || S2[i] - 48 > 9) {
//////			cout << endl << "Input Validation" << endl;
//////			return 0;
//////		}
//////	}
//////	return 1;
//////}
//////
//////void p1() {
//////	do {
//////		cout << " - Nhap gia chuoi S2:   ";
//////		cin >> S2;
//////	} while (!check(S2));
//////}
//////
//////void p2(char *S1) {
//////	int i, len;
//////	int flag = 0;
//////	len = getlen(S1);
//////	for (i = 0; i < len; i++) {
//////		if (S1[i] - 48 >= 0 && S1[i] - 48 <= 9)
//////			flag += 1;
//////	}
//////
//////	if (flag > 0)
//////		cout << " - Trong chuoi S1 co chu so!" << endl;
//////	else
//////		cout << " - Trong chuoi S1 khong co chu so!" << endl;
//////}
//////
//////void p3(char *S3) {
//////	int i, len;
//////	int flag = 0;
//////	len = getlen(S2);
//////	if (len == 10) {
//////		if (S2[0] - 48 == 0 && S2[1] - 48 == 9 && S2[0] - 48 == 0) {
//////			for (i = 3; i < len; i++) {
//////				if (S2[i] - 48 >= 0 && S2[i] - 48 <= 9)
//////					flag += 1;
//////			}
//////		}
//////		else {
//////			flag = 0;
//////		}
//////	}
//////
//////	if (flag > 0)
//////		cout << " - Day la sdt mang Mobifone" << endl;
//////	else
//////		cout << " - Day khong la sdt mang Mobifone" << endl;
//////}
//////
//////int check_str(char*s1, char*s2, int len) {
//////	int i;
//////	for (i = 0; i < len; i++) {
//////		if (s1[i] != s2[i])
//////			return 0;
//////	}
//////
//////	return 1;
//////}
//////
//////int p4(const char *str, char *sub)
//////{
//////	const char *p = str;
//////	int len = strlen(sub);
//////	while (*p != NULL)
//////	{
//////		if (strlen(p) >= len)
//////		{
//////			if (strncmp(p, sub, strlen(sub)) == 0)
//////			{
//////				return (p - str);
//////			}
//////		}
//////		else
//////		{
//////			break;
//////		}
//////		p++;
//////	}
//////	return -1;
//////}
//////
//////char* p5(char *s1, char *s2) {
//////	cout << " - S1 + S2 = ";
//////	int len_s1 = getlen(s1);
//////	int len_s2 = getlen(s2);
//////
//////	int len = len_s1 + len_s2;
//////	char *C = (char*)calloc(len + 1, sizeof(char));
//////	
//////	for (int i = 0; i < len; i++) {
//////		if (i < len_s1) // đang còn hân tử trong s1
//////			C[i] = s1[i];
//////		else // Mang s1 đã hết phần tử
//////			C[i] = s2[i - len_s1];
//////	}
//////
//////	for (int i = 0; i < len; i++)
//////		cout << C[i];
//////
//////	cout << endl;
//////
//////	return C;
//////}
//////
//////void p6(char *str_add) {
//////	//char str_add[100];
//////	char after;
//////	/*cout << " - Nhap chuoi S4:   ";
//////	cin >> str_add;*/
//////	cout << "\n - after:   ";
//////	cin >> after;
//////
//////	cout << " => ";
//////
//////	int len_s4 = getlen(str_add);
//////	int len_buff = getlen("Buffer_Overflow");
//////
//////	int len = len_s4 + len_buff;
//////
//////	//char *s5 = (char*)calloc(len + 1, sizeof(char));
//////	for (int i = 0; i < len_s4; i++) {
//////		if (str_add[i] != after)
//////			cout << str_add[i];
//////		else{
//////			cout << after << "Buffer_Overflow";
//////		}
//////	}
//////
//////}
//////
//////int main() {
//////
//////	cout << " - Nhap chuoi S1:   ";
//////	cin >> S1;
//////
//////	p1();
//////
//////	cout << "\n============ KET QUA ============\n";
//////
//////	p2(S1);
//////
//////	p3(S2);
//////
//////	if (p4(S1, S2) != -1)
//////		cout << " - S2 la tap con cua S1" << endl;
//////	else
//////		cout << " - S2 khong la tap con cua S1" << endl;
//////
//////	char* C = (char*)calloc(1000, sizeof(char));
//////	C = p5(S1, S2);
//////
//////	p6(C);
//////	
//////	return 0;
//////}
////
////
////
////
