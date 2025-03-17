

#include <iostream>


using namespace std;
double accumulator = 0;
void Wyswietl_menu() {
	cout << "Kalulator - wybierz operacje :" << endl;
	cout << "1. Dodawanie(+)" << endl;
	cout << "2. Odejmowanie(-)" << endl;
	cout << "3. Mnozenie(*)" << endl;
	cout << "4. Dzielenie(/)" << endl;
	cout << "5. Modulo(%)" << endl;
	cout << "6. Reset akumulatora" << endl;
	cout << "0. Wyjscie" << endl;

}
void Wybor_menu() {
	int wybor;
	cout << "Wybierz operacje: ";
	cin >> wybor;
	switch (wybor) {
	case 1:
	{
		double a, b;
		char useAcc;
		cout << "Czy chcesz uzyc akumulatora? (t/n): ";
		cin >> useAcc;
		if (useAcc == 't') {
			a = accumulator;
			cout << "Pierwsza liczba(akumulator);" << a << endl;

		}
		else {
			cout << "Podaj a: ";
			cin >> a;
		}
			cout << "Podaj b: ";
			cin >> b;
			accumulator = a + b;
			cout << "Wynik: " << accumulator << endl;
			break;

		}
	case 2:
	{
		double a, b;
		cout << "Podaj a: ";
		cin >> a;
		cout << "Podaj b: ";
		cin >> b;
		cout << "Wynik: " << a - b << endl;
		break;
	}
	case 3:
	{
		double a, b;
		cout << "Podaj a: ";
		cin >> a;
		cout << "Podaj b: ";
		cin >> b;
		cout << "Wynik: " << a * b << endl;
		break;
	}
	case 4:
	{
		double a, b;
		cout << "Podaj a: ";
		cin >> a;
		cout << "Podaj b: ";
		cin >> b;
		if (b == 0) {
			cout << "Nie mozna dzielic przez 0" << endl;
		}
		else {
			cout << "Wynik: " << a / b << endl;
		}
		break;
	}
	case 5:
	{
		double a, b;
		cout << "Podaj a: ";
		cin >> a;
		cout << "Podaj b: ";
		cin >> b;
		if ((int)b != 0) {
			cout << "Wynik: " << (int)a % (int)b << endl;
		}
		else {
			cout << "Nie mozna dzielic przez 0" << endl;
			break;
		}
	case 0:
	{
		cout << "Koniec programu" << endl;
		break;
	}
	default:
	{
		cout << "Nie ma takiej opcji" << endl;
		break;
	}
	}
	}
	}

int main() {
	Wyswietl_menu();
	Wybor_menu();
	return 0;
}