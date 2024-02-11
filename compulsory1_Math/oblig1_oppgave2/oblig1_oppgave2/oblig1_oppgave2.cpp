#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

// Funksjonsdefinisjoner
double spiralX(double t) {
    return t * cos(t);
}

double spiralY(double t) {
    return t * sin(t);
}

double spiralZ(double t, double a) {
    return a * t;
}

int main() {
    // Åpner en fil for å skrive data
    std::ofstream fil_ut("spiral_data.txt");

    // Sjekker om filen er åpen
    if (!fil_ut.is_open()) {
        std::cerr << "Kunne ikke åpne filen." << std::endl;
        return 1;
    }

    // Skriver antall punkter
    int n = 50;  // Antall punkter
    fil_ut << "Antall punkter " << n << std::endl;

    // Genererer og skriver punktdata
    double a = 0.1;  // Konstant for å justere høyden
    for (int i = 0; i < n; ++i) {
        double t = 0.1 * i;  // Parameter
        double x = spiralX(t);
        double y = spiralY(t);
        double z = spiralZ(t, a);
        std::string farge = z >= spiralZ(t + 0.1, a) ? "blå" : "rosa";

        fil_ut << std::fixed << std::setprecision(2) << x << ", " << y << ", " << z << ", " << farge << std::endl;
    }

    // Lukker filen
    fil_ut.close();

    std::cout << "Data lagret i spiral_data.txt" << std::endl;
    return 0;
}
