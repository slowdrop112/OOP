#ifndef PANTALONI_H
#define PANTALONI_H

#include "Haine.h"

class Pantaloni : public Haine {
private:
    std::string stil;

public:
    Pantaloni(const std::string& marca, const std::string& culoare, double pret, const std::string& stil);
         double getPret() const override;

    void afisareDetalii() const override;
    void descriereSpecifica() const override;

    friend std::ostream& operator<<(std::ostream& os, const Pantaloni& pantaloni);
    friend std::istream& operator>>(std::istream& is, Pantaloni& pantaloni);
    Pantaloni& operator=(const Pantaloni& other);
};

#endif
