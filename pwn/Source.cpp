#include <iostream>

using namespace std;

int getlen(char s[]) {
	int len=0;
	while (s[len] != '\0')
		len++;

	return len;
}

int main() {
	freopen("input.txt", "r", stdin);
	char input[100];
	cin >> input;
	cout << "secrect:   " << input << endl;

	if (!memcmp(input, "KhongGiongTrenServer", getlen(input)))
		cout << "Khong giong" << endl;
	else
		cout << "giong" << endl;

	system("pause");
}