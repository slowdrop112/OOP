#include "Geaca.h"

Geaca::Geaca(const std::string& marca, const std::string& culoare, double pret, const std::string& tipGeaca)
    : Haine(marca, culoare, pret), tipGeaca(tipGeaca) {}
    double Geaca::getPret() const {
    return pret;
}


void Geaca::afisareDetalii() const {
    Haine::afisareDetalii();
    std::cout << "Tip geaca: " << tipGeaca << std::endl << std::endl;
}

void Geaca::descriereSpecifica() const {
    std::cout << "Geaca are vatelina, ce rezista la temperaturi joase." << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Geaca& geaca) {
    os << static_cast<const Haine&>(geaca) << " " << geaca.tipGeaca;
    return os;
}

std::istream& operator>>(std::istream& is, Geaca& geaca) {
    is >> static_cast<Haine&>(geaca) >> geaca.tipGeaca;
    return is;
}

Geaca& Geaca::operator=(const Geaca& other) {
    if (this != &other) {
        Haine::operator=(other);
        tipGeaca = other.tipGeaca;
    }
    return *this;
}
