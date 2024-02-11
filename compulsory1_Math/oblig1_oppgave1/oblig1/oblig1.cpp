#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

// Funksjonsdefinisjoner
double f(double x) {
    return x * x;
}

double df(double x) {
    return 2 * x;
}

int main() {
    // Definerer intervaller og oppløsning
    double a = -5, b = 5;
    int n = 10;
    double h = (b - a) / n;

    // Åpner en fil for å skrive data
    std::ofstream ut_fil("vertex_data.txt");

    // Sjekker om filen er åpen
    if (!ut_fil.is_open()) {
        std::cerr << "Kan ikke åpne fil." << std::endl;
        return 1;
    }

    // Skriver antall punkter
    ut_fil << "Antall punkter " << (n + 1) << std::endl;

    // Beregner og skriver punktdata
    for (int i = 0; i <= n; ++i) {
        double x = a + i * h;
        double fx = f(x);
        double dfx = df(x);
        std::string color = dfx > 0 ? "pink" : "blue";

        ut_fil << std::fixed << std::setprecision(2) << x << ", " << fx << ", " << color << std::endl;
    }

    // Lukker filen
    ut_fil.close();

    std::cout << "Data er lagret i vertex_data.txt" << std::endl;
    return 0;
}
