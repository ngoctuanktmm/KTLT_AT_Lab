////#include <iostream>
////#include <string>
////
////using namespace std;
////
////const int ELEMENT = 10;
////
////// Cơ chế an toàn.
////int isNumber(int num) {
////	if (0 <= num&&num <= INT_MAX)
////		return 1;
////	return 0;
////}
////
////
////void inputNames(string names[], int e) {
////	for (int i = 0; i < e; i++) {
////		cout << "Name # " << i + 1 << ": ";
////		cin >> names[i]; // Lỗi 1
////	}
////}
////
////int getPick() {
////	int x;
////	cout << "Pick the perfect name: ";
////	cin >> x; // Lỗi 2
////
////
////	// fix
////	do {
////		cout << "Pick the perfect name: ";
////		cin >> x; 
////
////		if (cin.fail()) {
////			cin.clear();
////			cin.ignore(1000, '\n');
////		}
////
////	} while (!isNumber(x));
////	
////}
////
////string outputName(int n, string outputName[], int e) {
////	return outputName[n - 1];
////}
////
////int main() {
////	int pick;
////	string names[ELEMENT];
////	inputNames(names, ELEMENT);
////
////	pick = getPick();
////	string oName = outputName(pick, names, ELEMENT);
////	cout << "You chose name:  " << oName << endl;
////
////	return 0;
////}
////
//
//
//
//
//
//
#include <iostream>
#include <string>
#include <regex>
#include <stdlib.h>
#include <math.h>

#define MAX_INT 0xFFFFFFFF

using namespace std;

const regex REGEX_FLOAT("[+]?[0-9]+[.]?[0-9]*");
const regex REGEX_INT("[0-9][0-9]*");

double toFloat(string str) {
	int i = 0, count = 0;
	double left = 0, right = 0, KQ = 0;
	if (str[i] == '+') {
		i += 1;
		while (str[i] != '.') {
			left = left * 10 + str[i]-48;
			i++;
		}
		i++;
		while (str[i] != '\0') {
			right = right * 10 + str[i] - 48;
			i++;
			count++;
		}

		for (int i = 0; i < count; i++) {
			right = right / 10;
		}

		KQ = left + right;
	}
	else {
		if (str[i] == '.') {
			i++;
			while (str[i] != '\0') {
				right = right * 10 + str[i] - 48;
				i++;
				count++;
			}

			for (int i = 0; i < count; i++) {
				right = right / 10;
			}

			KQ = left + right;
		}
		else {
			while (str[i] != '.') {
				left = left * 10 + str[i] - 48;
				i++;
				if (str[i] == '\0')
					return left;
			}
			i++;
			while (str[i] != '\0') {
				right = right * 10 + str[i] - 48;
				i++;
				count++;
			}

			for (int i = 0; i < count; i++) {
				right = right / 10;
			}

			KQ = left + right;
		}
	}

	return KQ;
}

int convertStringToInt(string str) {
	int i;
	int result = str[0] - 48;
	for (i = 1; i < str.length(); i++) {
		result = result * 10 + str[i] - 48;
	}

	return result;
}

void showWarring() {
	cout << "=====================================================" << endl;
	cout << "==                     WARNING                     ==" << endl;
	cout << "=====>     Vui long nhap dung dinh dang!!!     <=====" << endl;
	cout << "==                                                 ==" << endl;
	cout << "=====================================================" << endl << endl;
}

bool checkGia(string giaMua) {
	if (giaMua[0] == '.') {
		giaMua = "0" + giaMua;
	}

	if (regex_match(giaMua, REGEX_FLOAT)) {
		return true;
	}
	else {
		showWarring();
		return false;
	}
}

bool checkSoLuong(string soLuong) {
	if (regex_match(soLuong, REGEX_INT) && soLuong.length() < 11) {
		if (convertStringToInt(soLuong) <= MAX_INT&&convertStringToInt(soLuong) >= 1)
			return true;
		else {
			showWarring();
			return false;
		}
	}
	else {
		showWarring();
		return false;
	}
}

void showKQ(double gia, int soLuong) {
	cout << endl<<endl<<"=====================================================" << endl;
	cout << "                   KET QUA DAU THAU                  " << endl;
	cout << " - Gia ma ban dau thau:   " << gia << endl;
	cout << " - So luong ma ban mua:   " << soLuong << endl;
}

void program_2() {

	// Nhập giá mua.
	string strGiaMua;
	double dGiaMua;
	do {
		cout << "\nNhap vao gia mua:   ";
		getline(cin, strGiaMua);
	} while (!checkGia(strGiaMua));

	dGiaMua = toFloat(strGiaMua);

	// Nhập số lượng cần mua.
	string strSoLuong;
	int soLuong;
	do {
		cout << "\nNhap vao so luong mua:   ";
		getline(cin, strSoLuong);
	} while (!checkSoLuong(strSoLuong));

	soLuong = convertStringToInt(strSoLuong);
	showKQ(dGiaMua, soLuong);
}

int main() {
	program_2();

	return 0;
}


