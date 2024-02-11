
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

// Funksjonsdefinisjon
double funksjon(double x, double y) {
    return x * x + y * y;
}

int main() {
    // Åpner en fil for å skrive data
    std::ofstream file("en_funksjon_av_to_variable_data.txt");

    // Sjekker om filen er åpen
    if (!file.is_open()) {
        std::cerr << "Kunne ikke åpne filen." << std::endl;
        return 1;
    }

    // Antall punkter og oppdeling
    int n = 5;  // Antall punkter i hver retning
    double delta = 0.5;  // Avstand mellom punktene

    // Skriver antall punkter
    file <<"Antall linjer " << n * n << std::endl;

    // Genererer og skriver punktdata
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            double x = i * delta;
            double y = j * delta;
            double z = funksjon(x, y);
            std::string farge = "0.0 1.0 0.0";  // RGB-farge, her grønn
            double u = static_cast<double>(i) / (n - 1);  // UV-koordinat
            double v = static_cast<double>(j) / (n - 1);

            file << std::fixed << std::setprecision(2) << x << " " << y << " " << z << " " << farge << " " << u << " " << v << std::endl;
        }
    }

    // Lukker filen
    file.close();

    std::cout << "Data lagret i funksjon_data.txt" << std::endl;
    return 0;
}
