#ifndef GEACA_H
#define GEACA_H

#include "Haine.h"

class Geaca : public Haine {
private:
    std::string tipGeaca;

public:
    Geaca(const std::string& marca, const std::string& culoare, double pret, const std::string& tipGeaca);
         double getPret() const override;

    void afisareDetalii() const override;
    void descriereSpecifica() const override;

    friend std::ostream& operator<<(std::ostream& os, const Geaca& geaca);
    friend std::istream& operator>>(std::istream& is, Geaca& geaca);
    Geaca& operator=(const Geaca& other);
};

#endif
