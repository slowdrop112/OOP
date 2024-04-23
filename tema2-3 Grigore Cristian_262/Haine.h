#ifndef HAINE_H
#define HAINE_H

#include <iostream>
#include <string>

class Haine {
private:
    std::string marca;
    std::string culoare;
    protected:
    double pret;

public:
    Haine(const std::string& marca, const std::string& culoare, double pret);
        virtual double getPret() const = 0;

    virtual void afisareDetalii() const;
    virtual void descriereSpecifica() const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Haine& haine);
    friend std::istream& operator>>(std::istream& is, Haine& haine);
    Haine& operator=(const Haine& other);
};

#endif
