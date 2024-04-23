#ifndef EXCEPTIE_HAINE_NEGATIVA_H
#define EXCEPTIE_HAINE_NEGATIVA_H

#include <stdexcept>
#include <string>

class ExceptieHaineNegativa : public std::exception {
private:
    std::string mesaj;

public:
    explicit ExceptieHaineNegativa(const std::string& numeHaina)
        : mesaj("Eroare: " + numeHaina + " are un pret negativ.") {}

    const char* what() const noexcept override {
        return mesaj.c_str();
    }
};

#endif

