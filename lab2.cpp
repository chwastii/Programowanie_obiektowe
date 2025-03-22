
#include <iostream>
#include <vector>

using namespace std;

double accumulator = 0; // Akumulator

void Wyswietl_menu() {
    cout << "\nKalkulator - wybierz operacje:" << endl;
    cout << "1. Dodawanie (+)" << endl;
    cout << "2. Odejmowanie (-)" << endl;
    cout << "3. Mnozenie (*)" << endl;
    cout << "4. Dzielenie (/)" << endl;
    cout << "5. Modulo (%)" << endl;
    cout << "6. Reset akumulatora" << endl;
    cout << "7. Konwersja systemów liczbowych" << endl;
    cout << "0. Wyjscie" << endl;
}

// Funkcja konwersji liczby z systemu dziesiętnego do systemu o podstawie <= 10
void Konwersja_systemu() {
    int liczba, podstawa;
    cout << "Podaj liczbe w systemie dziesietnym: ";
    cin >> liczba;
    cout << "Podaj system docelowy (2-10): ";
    cin >> podstawa;

    if (podstawa < 2 || podstawa > 10) {
        cout << "Bledna podstawa systemu! Wybierz z zakresu 2-10." << endl;
        return;
    }

    vector<int> wynik; // Przechowywanie cyfr liczby w nowym systemie
    int temp = liczba;

    while (temp > 0) {
        wynik.push_back(temp % podstawa);
        temp /= podstawa;
    }

    cout << "Liczba " << liczba << " w systemie o podstawie " << podstawa << " to: ";
    for (int i = wynik.size() - 1; i >= 0; i--) {
        cout << wynik[i];
    }
    cout << endl;
}

void Wybor_menu() {
    int wybor;
    double a, b;
    char useAcc;

    while (true) {
        Wyswietl_menu();
        cout << "Wybierz operacje: ";
        cin >> wybor;

        if (cin.fail()) { // Obsługa błędnych danych wejściowych
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Bledne dane! Wprowadz liczbe." << endl;
            continue;
        }

        if (wybor == 0) { // Wyjście z programu
            cout << "Koniec programu." << endl;
            break;
        }

        if (wybor == 6) { // Reset akumulatora
            accumulator = 0;
            cout << "Akumulator zostal zresetowany." << endl;
            continue;
        }

        if (wybor == 7) { // Konwersja systemów liczbowych
            Konwersja_systemu();
            continue;
        }

        // Zapytanie użytkownika, czy chce użyć akumulatora
        cout << "Czy chcesz uzyc akumulatora? (t/n): ";
        cin >> useAcc;

        if (useAcc == 't') {
            a = accumulator;
            cout << "Pierwsza liczba (akumulator): " << a << endl;
        }
        else {
            cout << "Podaj a: ";
            cin >> a;
        }

        cout << "Podaj b: ";
        cin >> b;

        switch (wybor) {
        case 1: // Dodawanie
            accumulator = a + b;
            break;
        case 2: // Odejmowanie
            accumulator = a - b;
            break;
        case 3: // Mnożenie
            accumulator = a * b;
            break;
        case 4: // Dzielenie
            if (b == 0) {
                cout << "Nie mozna dzielic przez 0!" << endl;
                continue;
            }
            accumulator = a / b;
            break;
        case 5: // Modulo (tylko dla liczb całkowitych)
            if ((int)b == 0) {
                cout << "Nie mozna dzielic przez 0!" << endl;
                continue;
            }
            accumulator = static_cast<int>(a) % static_cast<int>(b);
            break;
        default:
            cout << "Nie ma takiej opcji!" << endl;
            continue;
        }

        cout << "Wynik: " << accumulator << endl;
    }
}

int main() {
    Wybor_menu();
    return 0;
}
