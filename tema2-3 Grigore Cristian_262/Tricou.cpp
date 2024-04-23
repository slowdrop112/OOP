#include "Tricou.h"

Tricou::Tricou(const std::string& marca, const std::string& culoare, double pret, const std::string& material)
    : Haine(marca, culoare, pret), material(material) {}

double Tricou::getPret() const {
    return pret;
}

void Tricou::afisareDetalii() const {
    Haine::afisareDetalii();
    std::cout << "Material: " << material << std::endl << std::endl;
}

void Tricou::descriereSpecifica() const {
    std::cout << "Tricoul este de tip heavyweight." << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Tricou& tricou) {
    os << static_cast<const Haine&>(tricou) << " " << tricou.material;
    return os;
}

std::istream& operator>>(std::istream& is, Tricou& tricou) {
    is >> static_cast<Haine&>(tricou) >> tricou.material;
    return is;
}

Tricou& Tricou::operator=(const Tricou& other) {
    if (this != &other) {
        Haine::operator=(other);
        material = other.material;
    }
    return *this;
}
