#include "listaspesa.h"
#include <algorithm>
#include <iostream>

void ListaSpesa::aggiungiOggetto(const Oggetto& oggetto) {
    oggetti.push_back(oggetto);
    notifica();
}

void ListaSpesa::rimuoviOggetto(const std::string& nomeOggetto) {
    oggetti.erase(std::remove_if(oggetti.begin(), oggetti.end(),
                                 [&](Oggetto& o) { return o.getNome() == nomeOggetto; }), oggetti.end());
    notifica();
}

void ListaSpesa::stampaLista() const {
    for (const auto& oggetto : oggetti) {
        oggetto.stampaOggetto();
    }
}

void ListaSpesa::aggiungiObserver(IObserver* observer) {
    observers.push_back(observer);
}

void ListaSpesa::rimuoviObserver(IObserver* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void ListaSpesa::notifica() {
    for (auto observer : observers) {
        observer->aggiorna();
    }
}