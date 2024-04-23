#ifndef ADIDASI_H
#define ADIDASI_H

#include "Haine.h"

class Adidasi : public Haine {
private:
    int marime;

public:
    Adidasi(const std::string& marca, const std::string& culoare, double pret, int marime);
         double getPret() const override;

    void afisareDetalii() const override;
    void descriereSpecifica() const override;


    friend std::ostream& operator<<(std::ostream& os, const Adidasi& adidasi);
    friend std::istream& operator>>(std::istream& is, Adidasi& adidasi);
    Adidasi& operator=(const Adidasi& other);
};

#endif
