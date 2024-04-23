// ContainerHaine.h
#ifndef CONTAINER_HAINE_H
#define CONTAINER_HAINE_H

#include <vector>
#include <memory>

template <typename T>
class ContainerHaine {
private:
    std::vector<std::unique_ptr<T>> haine;

public:
    void adaugaHaina(std::unique_ptr<T> haina) {
        haine.push_back(std::move(haina));
    }

    void afiseazaDetalii() const {
        for (const auto& item : haine) {
            item->descriereSpecifica();
            item->afisareDetalii();
        }
    }

    double calculMediePret() const {
        double sumaPreturi = 0.0;

        for (const auto& item : haine) {
            sumaPreturi += item->getPret();
        }

        return haine.empty() ? 0.0 : sumaPreturi / haine.size();
    }
};

#endif

