//#include <iostream>
//#include <string>
//
//using namespace std;
//
//const int inputSize = 10;
//
//string inputString();
//void copyStrs(string, char[]);
//void subStrs(char[], char[]);
//void getStrs(int, int, char[], char[]);
//
///*Sử lý an toàn*/
//int getLen(char *str) {
//	int i = 0;
//	while (str[i] != '\0')
//		i++;
//
//	return i;
//}
//void getStrs_s(int start, int end, char strs[], char newStrs[]) {
//	int len = end - start + 1;
//	if (len < inputSize) {
//		int i = 0;
//
//		for (i = 0; i < len - 1; i++) {
//			newStrs[i] = strs[start + i];
//		}
//		newStrs[i] = '\0';
//	}
//	else {
//		cout << "===== ERROR!!! =====\n";
//		return;
//	}
//}
//
//
//int main() {
//	char strs[inputSize];
//	char sub[inputSize];
//
//	char *_strs = (char*)calloc(inputSize + 1, sizeof(char));
//	char *_sub = (char*)calloc(inputSize + 1, sizeof(char));
//
//	string s1 = inputString();
//	if (s1.length() <= inputSize) {
//		copyStrs(s1, _strs);
//		subStrs(_strs, _sub);
//
//		cout << "sub string:   " << _sub << endl;
//		system("pause");
//	}
//	else {
//		cout << "===== WARNING !!! =====\n";
//		system("pause");
//	}
//	/*copyStrs(s1, strs);
//	subStrs(strs, sub);*/
//
//	/*copyStrs_s(s1, _strs);
//	subStrs(_sub, sub);
//
//	cout << "sub string:   " << sub << endl;*/
//
//	return 0;
//
//}
//
//string inputString() {
//	//cout << "Type a string:   ";
//	//string s;
//	//getline(cin, s);
//	///* Lỗi 1 - getline không kiểm tra độ dài chuỗi, chỉ khi kết thúc dòng mới dừng lại
//	//có thể gặp shellcode...
//	//*/
//
//	string s;
//
//	do {
//		cout << "Type a string:   ";
//		string s;
//		getline(cin, s);
//	} while (s.length() <= inputSize);
//
//	return s;
//}
//
//void copyStrs(string s, char strs[]) {
//	int i = 0;
//	for (i = 0; i < s.length(); i++) {
//		strs[i] = s.at(i);
//	}
//
//	strs[i] = '\0';
//
//	/* Lỗi 2 - Khi xuất hiện lỗi 1, thì chuỗi s được truyền vào hàm copyStrs
//		s.length() có thể lớn hơn kích thước tối đa mà mảng strs[] khai báo.
//		do đó có thể xuất hiện lỗi tại hàm này.
//	*/
//}
//
//void subStrs(char strs[], char newStrs[]) {
//	int start;
//	int end;
//
//	do {
//		cout << "Starting point:  ";
//		cin >> start;
//
//		cout << "Ending point:  ";
//		cin >> end;
//		cout << endl;
//	} while (!(0 <= start && end < getLen(strs)));
//
//	getStrs(start, end, strs, newStrs);
//		
//}
//
//void getStrs(int start, int end, char strs[], char newStrs[]) {
//	int len = end - start + 1;
//	int i = 0;
//
//	for (i = 0; i<len - 1; i++) {
//		newStrs[i] = strs[start + i];
//	}
//
//	newStrs[i] = '\0';
//
//	/* Lỗi 3 - Khi xuất hiện lỗi 1 && 2, thì chuỗi strs được truyền vào hàm subStrs
//		'len' có thể lớn hơn kích thước tối đa mà mảng newStrs[] khai báo.
//		do đó có thể xuất hiện lỗi tại hàm này.
//	*/
//}







/*===== program 2 */
#include <iostream>
#include <string.h>

using namespace std;

void print(int *arr, int len) {
	int i;
	for (i = 0; i < len; i++)
		cout << "\t" << arr[i];

	cout << endl;
}

void copy_arr(int *arr1, int *arr2, int len) {
	for (int i = 0; i < len; i++)
		arr2[i] = arr1[i];
}

void XuLy(int *nguon, int *dich, int len_nguon, int len_dich, int start, int end, int local) {
	int len_add = end - start + 1;
	int i, j;
	int len = len_dich + len_add;

	int *temp = (int*)calloc(len + 1, sizeof(int));

	for (i = 0; i < local + len_add; i++) {
		// Nhan pha tu truoc local
		if (i < local)
			temp[i] = dich[i];
		else { // Nhan cac phan tu tu tu mang nguon
			for (j = 0; j < len_add; j++) {
				temp[i] = nguon[start + j];
				i++;
			}
		}

		// Xong vòng lặp for này thì toàn bộ phần tử của mang đích trước local + mang nguồn cần copy đã vào mảng temp
	}

	// i=7;
	j = i - 1;

	// Nem phần còn lại vào mảng temp.
	// vị trí 'local' đến cuối mảng đích.
	for (i = local; i < len_dich; i++) {
		temp[j] = dich[i];
		j++;
	}



	// In cac pha tu trong mang vua tao duoc
	for (i = 0; i < len; i++)
		cout << "\t" << temp[i];

	
}

int main() {
	freopen("input.txt", "r", stdin);

	/*
		Bộ dữ liệu đầu vào:
			+ dòng đầu tiên gồm 2 số nguyên n, m;
			+ 2 dòng tiếp theo lần lượt là n, m số nguyên biểu diễn giá trị của mảng s1 & s2;
			+ dòng cuối cùng là 3 số nguyên. Lần lượt là start, end, local
		Bộ dữ liệu đầu vào đảm bảo điều kiện đề bài.
	*/

	int n, m;	// n, m lần lượt là số phần tử của s1, s2;
	int start, end, viTri, KQ;
	int i;
	cin >> n >> m;
	int *s1 = (int*)calloc(n, sizeof(int));
	//int *s2 = (int*)calloc(m, sizeof(int));
	int s2[101];

	// Input
	for (i = 0; i < n; i++)
		cin >> s1[i];
	for (i = 0; i < m; i++)
		cin >> s2[i];

	cin >> start >> end >> viTri;
	cout << " - Mang s1:   " << endl;
	print(s1, n);


	/*KQ = program_2(s1, n, start, end, s2, m, viTri);
	cout << " - Mang sau khi copy:   " << endl;
	print(s2, m);
	cout << "\n => So phan tu duoc phep copy:   " << KQ << endl;*/

	cout << " - Mang S2:  " << endl;
	for (i = 0; i < m; i++)
		cout << "\t" << s2[i];
	cout << endl;

	// len = 3
	// s0 s1 s2
	// len = 5

	XuLy(s1, s2, n, m, start, end, viTri);


	return 0;
}
