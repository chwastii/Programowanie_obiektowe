// Zajęcia1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
using namespace std;
void Z1a(unsigned int n) {
	for (unsigned int i = 0; i < n; i++) {
		cout << i % 10;
	}
	cout << endl;
}
void Z1b(unsigned int n) {
	for (unsigned int i = 0; i < n; i++) {
		cout << i % 2;
	}
	cout << endl;
}
void Z1d(unsigned int n) {
	for (unsigned int i = 0; i < n *4; i++) {
		cout << i % 4;
	}
	cout << endl;
}
void Z1e(unsigned int n) {
	for (unsigned int i = 0; i < n*10 ; i++) {
		cout << i % 10;
	}
	cout << "0123";
	cout << endl;
}
void Z2d(unsigned int n) {
	for (unsigned int i = 0; i < n; i++) {
		for (unsigned int j = n; j > i; j--) {
			cout << j;
		}
		cout << endl;
	}
}
void Z2b(unsigned int n) {
	for (unsigned int i = 1; i <=n; i++) {
		for (unsigned int j = 1;j <= i; j++) {
			cout << j;
		}
		cout << endl;
	}
	
}
void Z2a(unsigned int n) {
	for (unsigned int i = 1; i <= n; i++) {
		for (unsigned int j = n; j >= 1 ; j--) {
			cout << j;
		}
		cout << endl;
	}
}
void Z3(unsigned int n) {
	int suma = 0;
	for (unsigned int i = 1; i < n; i += 2) {
		suma += i;
	}
	cout << suma << endl;
}
void Z4(int a, int b) {
	int licznik = 0;
	int start = (b - 1) / 9 * 9;

	for (int i = start; i > a; i -= 9) {
		cout << i << " ";
		licznik++;
	}

	cout << "\nLiczba wielokrotności 9 w przedziale (" << a << ", " << b << ") wynosi: " << licznik << endl;
}
	bool czy_doskonala(unsigned int n){
		int suma = 0;
		for (int i = 1; i < n; i++) {
			if (n % i == 0) {
				suma += i;
			}
		}
		return suma == n;
	}
	

int main() {
	unsigned int n;
	//int suma = 0;
	cout << "podaj n" << endl;
	cin >> n;
	//int a, b;
	//cout << "Podaj liczby a i b (a ≤ b): ";
	//cin >> a >> b;

	Z1d(n);
	//if (czy_doskonala(n)) {
		//cout << n << " jest liczba doskonala!" << endl;
	//}
	//else {
		//cout << n << " nie jest liczba doskonala." << endl;
	//}
	return 0;
} 