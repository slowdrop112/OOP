#ifndef TRICOU_H
#define TRICOU_H

#include "Haine.h"
#include <memory>

class Tricou : public Haine {
private:
    std::string material;

public:
    Tricou(const std::string& marca, const std::string& culoare, double pret, const std::string& material);
         double getPret() const override;

    void afisareDetalii() const override;
    void descriereSpecifica() const override;


    friend std::ostream& operator<<(std::ostream& os, const Tricou& tricou);
    friend std::istream& operator>>(std::istream& is, Tricou& tricou);
    Tricou& operator=(const Tricou& other);
};

#endif
