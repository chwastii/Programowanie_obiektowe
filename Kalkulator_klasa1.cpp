#include <iostream>
#include <vector>

using namespace std;

class Kalkulator {
private:
    double accumulator; // Akumulator

public:
    // Konstruktor klasy, inicjalizuje akumulator na 0
    Kalkulator() : accumulator(0) {}

    // Funkcja wyświetlająca menu
    void Wyswietl_menu() const {
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
    void Konwersja_systemu() const {
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

    // Metoda dodawania
    void Dodaj(double a, double b) {
        accumulator = a + b;
    }

    // Metoda odejmowania
    void Odejmij(double a, double b) {
        accumulator = a - b;
    }

    // Metoda mnożenia
    void Pomnoz(double a, double b) {
        accumulator = a * b;
    }

    // Metoda dzielenia
    void Podziel(double a, double b) {
        if (b == 0) {
            cout << "Nie mozna dzielic przez 0!" << endl;
            return;
        }
        accumulator = a / b;
    }

    // Metoda modulo
    void Modulo(double a, double b) {
        if ((int)b == 0) {
            cout << "Nie mozna dzielic przez 0!" << endl;
            return;
        }
        accumulator = static_cast<int>(a) % static_cast<int>(b);
    }

    // Funkcja do przeprowadzenia operacji na liczbach
    void Operacje() {
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
                SetAccumulator(0); // Resetujemy akumulator
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
                a = GetAccumulator(); // Pobieramy wartość akumulatora
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
                Dodaj(a, b);
                break;
            case 2: // Odejmowanie
                Odejmij(a, b);
                break;
            case 3: // Mnożenie
                Pomnoz(a, b);
                break;
            case 4: // Dzielenie
                Podziel(a, b);
                break;
            case 5: // Modulo (tylko dla liczb całkowitych)
                Modulo(a, b);
                break;
            default:
                cout << "Nie ma takiej opcji!" << endl;
                continue;
            }

            cout << "Wynik: " << GetAccumulator() << endl; // Wyświetlamy wartość akumulatora
        }
    }

    // Getter - zwraca aktualną wartość akumulatora
    double GetAccumulator() const {
        return accumulator;
    }

    // Setter - ustawia wartość akumulatora
    void SetAccumulator(double value) {
        accumulator = value;
    }
};

int main() {
    Kalkulator kalk; // Tworzymy obiekt kalkulatora

    // Testowanie klasy Kalkulator
    cout << "Testowanie kalkulatora:" << endl;

    // Dodawanie
    kalk.Dodaj(5, 3);
    cout << "Dodawanie 5 + 3 = " << kalk.GetAccumulator() << endl;

    // Odejmowanie
    kalk.Odejmij(10, 4);
    cout << "Odejmowanie 10 - 4 = " << kalk.GetAccumulator() << endl;

    // Mnożenie
    kalk.Pomnoz(2, 6);
    cout << "Mnożenie 2 * 6 = " << kalk.GetAccumulator() << endl;

    // Dzielenie
    kalk.Podziel(20, 4);
    cout << "Dzielenie 20 / 4 = " << kalk.GetAccumulator() << endl;

    // Modulo
    kalk.Modulo(10, 3);
    cout << "Modulo 10 % 3 = " << kalk.GetAccumulator() << endl;

    // Resetowanie akumulatora
    kalk.SetAccumulator(50);
    cout << "Akumulator ustawiony na 50: " << kalk.GetAccumulator() << endl;
    kalk.SetAccumulator(0);
    cout << "Akumulator po resecie: " << kalk.GetAccumulator() << endl;

    // Testowanie konwersji systemów liczbowych
    kalk.Konwersja_systemu(); // Testowanie konwersji dla dowolnej liczby

    // Uruchamiamy operacje z menu
    kalk.Operacje();

    return 0;
}
