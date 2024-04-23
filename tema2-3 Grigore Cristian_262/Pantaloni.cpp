#include "Pantaloni.h"

Pantaloni::Pantaloni(const std::string& marca, const std::string& culoare, double pret, const std::string& stil)
    : Haine(marca, culoare, pret), stil(stil) {}

double Pantaloni::getPret() const {
    return pret;
}

void Pantaloni::afisareDetalii() const {
    Haine::afisareDetalii();
    std::cout << "Stil pantaloni: " << stil << std::endl << std::endl;
}

void Pantaloni::descriereSpecifica() const {
    std::cout << "Pantaloni evazati cu dungi de vopsea si print." << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Pantaloni& pantaloni) {
    os << static_cast<const Haine&>(pantaloni) << " " << pantaloni.stil;
    return os;
}

std::istream& operator>>(std::istream& is, Pantaloni& pantaloni) {
    is >> static_cast<Haine&>(pantaloni) >> pantaloni.stil;
    return is;
}

Pantaloni& Pantaloni::operator=(const Pantaloni& other) {
    if (this != &other) {
        Haine::operator=(other);
        stil = other.stil;
    }
    return *this;
}
