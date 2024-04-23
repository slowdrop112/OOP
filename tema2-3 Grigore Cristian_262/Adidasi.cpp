#include "Adidasi.h"

Adidasi::Adidasi(const std::string& marca, const std::string& culoare, double pret, int marime)
    : Haine(marca, culoare, pret), marime(marime) {}
    double Adidasi::getPret() const {
    return pret;
}

void Adidasi::afisareDetalii() const {
    Haine::afisareDetalii();
    std::cout << "Marime adidasi: " << marime << std::endl << std::endl;
}

void Adidasi::descriereSpecifica() const {
    std::cout << "Adidasii sunt intr-o colaborare cu firma Funko.Pop." << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Adidasi& adidasi) {
    os << static_cast<const Haine&>(adidasi) << " " << adidasi.marime;
    return os;
}

std::istream& operator>>(std::istream& is, Adidasi& adidasi) {
    is >> static_cast<Haine&>(adidasi) >> adidasi.marime;
    return is;
}

Adidasi& Adidasi::operator=(const Adidasi& other) {
    if (this != &other) {
        Haine::operator=(other);
        marime = other.marime;
    }
    return *this;
}
