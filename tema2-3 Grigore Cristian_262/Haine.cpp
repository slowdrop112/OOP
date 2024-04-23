#include "Haine.h"
#include "ExceptieHaineNegativa.h"
#include "ExceptieMarimeInvalida.h"

Haine::Haine(const std::string& marca, const std::string& culoare, double pret)
    : marca(marca), culoare(culoare), pret(pret) {
    if (pret < 0) {
        throw ExceptieHaineNegativa(marca);
    }
}

void Haine::afisareDetalii() const {
    std::cout << "Marca: " << marca << ", Culoare: " << culoare << ", Pret: " << pret << " RON" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Haine& haine) {
    os << haine.marca << " " << haine.culoare << " " << haine.pret;
    return os;
}

std::istream& operator>>(std::istream& is, Haine& haine) {
    is >> haine.marca >> haine.culoare >> haine.pret;
    if (haine.pret < 0) {
        throw ExceptieHaineNegativa(haine.marca);
    }
    return is;
}

Haine& Haine::operator=(const Haine& other) {
    if (this != &other) {
        marca = other.marca;
        culoare = other.culoare;
        pret = other.pret;
    }
    return *this;
}
