#ifndef EXCEPTIE_MARIME_INVALIDA_H
#define EXCEPTIE_MARIME_INVALIDA_H

#include <stdexcept>
#include <string>

class ExceptieMarimeInvalida : public std::exception {
private:
    std::string mesaj;

public:
    explicit ExceptieMarimeInvalida(const std::string& numeHaina)
        : mesaj("Eroare: Marimea pentru " + numeHaina + " nu este valida.") {}

    const char* what() const noexcept override {
        return mesaj.c_str();
    }
};

#endif // EXCEPTIE_MARIME_INVALIDA_H
