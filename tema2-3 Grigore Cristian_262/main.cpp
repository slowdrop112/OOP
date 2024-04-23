#include "Tricou.h"
#include "Geaca.h"
#include "Pantaloni.h"
#include "Adidasi.h"
#include "ExceptieHaineNegativa.h"
#include "ExceptieMarimeInvalida.h"
#include "ContainerHaine.h"
#include <iostream>
#include <memory>
#include <vector>

template<typename T>
void afisareHaine(const std::vector<std::unique_ptr<T>>& haine) {
    for (const auto& item : haine) {
        item->descriereSpecifica();
        item->afisareDetalii();
    }
}

template<typename T>
double calculMediePret(const std::vector<std::unique_ptr<T>>& haine) {
    double sumaPreturi = 0.0;

    for (const auto& item : haine) {
        sumaPreturi += item->getPret();
    }

    return haine.empty() ? 0.0 : sumaPreturi / haine.size();
}

int main() {
    std::vector<std::unique_ptr<Haine>> haine;

    haine.push_back(std::make_unique<Tricou>("Nike", "Rosu", 89.99, "Bumbac"));
    haine.push_back(std::make_unique<Geaca>("Adidas", "Negru", 259.99, "Iarna"));
    haine.push_back(std::make_unique<Pantaloni>("Levi's", "Albastru", 179.99, "Slim Fit"));
    haine.push_back(std::make_unique<Adidasi>("Puma", "Verde", 269.99, 42));



    // Exemplu de polimorfism
    for (const auto& item : haine) {
        item->descriereSpecifica();
        item->afisareDetalii();
    }

    // Testare pentru pret negativ
        std::cout<<"-------------------------------------"<<std::endl;
    try {
        Adidasi adidasiPretNegativ("Puma", "Verde", -69.99, 42);  // Pretul negativ, arunca ExceptieHaineNegativa
    } catch (const ExceptieHaineNegativa& e) {
        std::cerr << "Exceptie: " << e.what() << std::endl;
    }
        std::cout<<"-------------------------------------"<<std::endl;
     std::vector<std::unique_ptr<Pantaloni>> pantaloni;

    pantaloni.push_back(std::make_unique<Pantaloni>("Wanted Collection", "Negru", 179.99, "Loose fit"));
    pantaloni.push_back(std::make_unique<Pantaloni>("Zara", "Negru", 59.99, "Regular Fit"));

    // Utilizare funcție template pentru Pantaloni
    afisareHaine(pantaloni);

     std::vector<std::unique_ptr<Tricou>> tricouri;

tricouri.push_back(std::make_unique<Tricou>("Gucci", "Rosu", 599.99, "Bumbac"));
tricouri.push_back(std::make_unique<Tricou>("H&M", "Alb", 39.99, "Poliester"));

    // Utilizare funcție template pentru Tricouri
    afisareHaine(tricouri);


    haine.push_back(std::make_unique<Tricou>("Broken Planet", "Maro", 259.99, "Bumbac"));
    haine.push_back(std::make_unique<Geaca>("Tommy Hilfiger", "Negru&Alb", 699.99, "Iarna"));
    haine.push_back(std::make_unique<Pantaloni>("Adidas", "Albastru", 179.99, "Slim Fit"));
    haine.push_back(std::make_unique<Adidasi>("Yeezy", "Alb", 869.99, 42));

    // Utilizare funcție template
    double mediaPreturilor = calculMediePret(haine);

    std::cout << "Media preturilor hainelor: " << mediaPreturilor << " RON" << std::endl;

     // Utilizare ContainerHaine pentru Tricouri
    ContainerHaine<Tricou> containerTricouri;
    std::cout<<"-------------------------------------"<<std::endl;
    containerTricouri.adaugaHaina(std::make_unique<Tricou>("Ralph Lauren", "Albastru", 249.99, "Bumbac"));
    containerTricouri.adaugaHaina(std::make_unique<Tricou>("POLO", "Gri", 239.99, "Poliester"));

    // Afisare detalii si calcul medie preturi
    containerTricouri.afiseazaDetalii();
    std::cout << "Media preturilor tricourilor: " << containerTricouri.calculMediePret() << " RON" << std::endl;

    // Utilizare ContainerHaine pentru Pantaloni

    ContainerHaine<Pantaloni> containerPantaloni;
    std::cout<<"-------------------------------------"<<std::endl;
    containerPantaloni.adaugaHaina(std::make_unique<Pantaloni>("Zara", "Gri", 79.99, "Regular Fit"));
    containerPantaloni.adaugaHaina(std::make_unique<Pantaloni>("Zara", "Negru", 59.99, "Baggy"));

    // Afisare detalii si calcul medie preturi
    containerPantaloni.afiseazaDetalii();
    std::cout << "Media preturilor pantalonilor: " << containerPantaloni.calculMediePret() << " RON" << std::endl;

    ContainerHaine<Adidasi> containerAdidasi;
    std::cout<<"-------------------------------------"<<std::endl;
    containerAdidasi.adaugaHaina(std::make_unique<Adidasi>("Off-White", "Baby Blue", 1579.99, 44));
    containerAdidasi.adaugaHaina(std::make_unique<Adidasi>("Rick Owens", "Negru", 1959.99, 44));

    // Afisare detalii si calcul medie preturi
    containerAdidasi.afiseazaDetalii();
    std::cout << "Media preturilor pantalonilor: " << containerAdidasi.calculMediePret() << " RON" << std::endl;
    std::cout<<"-------------------------------------"<<std::endl;







    return 0;
}
