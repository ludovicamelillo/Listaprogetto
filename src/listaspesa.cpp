#include "../include/listaspesa.h"
#include <algorithm>
#include <iostream>
#include "oggetto.h"

//aggiungi un oggetto alla lista
void ListaSpesa::aggiungiOggetto(const Oggetto& oggetto) {
    if (oggetto.getNome().empty() || oggetto.getQuantita() <= 0){
        std::cout<< "[Errore] Oggetto non valido. Operazione ignorata." <<std::endl;
        return;
    }

    auto it= std::find_if(oggetti.begin(), oggetti.end(),
                          [&](const Oggetto& o) { return o.getNome() == oggetto.getNome(); });

    if (it != oggetti.end()) {
        std::cout << "[Attenzione] L'oggetto \"" << oggetto.getNome() << "\" è già presente nella lista." << std::endl;
        return;
    }

    oggetti.push_back(oggetto);
    notifica();  //notifica gli osservatori dopo aver aggiunto un oggetto
}

//Rimuovi un oggetto dalla lista
void ListaSpesa::rimuoviOggetto(const std::string& nomeOggetto) {
    //Trova e rimuovi oggetto dalla lista
    auto it = std::remove_if(oggetti.begin(), oggetti.end(),
                             [&](Oggetto& o) { return o.getNome() == nomeOggetto; });

    if (it != oggetti.end()) {
        oggetti.erase(it, oggetti.end());  // Rimuovi l'oggetto trovato
        notifica(); // Mostra la nuova lista
    } else {
        std::cout << "[Info] Nessun oggetto chiamato \"" << nomeOggetto << "\" è stato trovato nella lista." << std::endl;
    }
}


void ListaSpesa::stampaLista() const {
    std::vector<Oggetto> copia = oggetti; // Copia della lista per non modificarla

    std::sort(copia.begin(), copia.end(), [](const Oggetto& a, const Oggetto& b) {
        if (a.getCategoria() == b.getCategoria()) {
            return a.getNome() < b.getNome();
        }
        return a.getCategoria() < b.getCategoria(); // Ordina prima per categoria
    });

    for (const auto& oggetto : copia) {
        oggetto.stampaOggetto();
    }
}

void ListaSpesa::aggiungiObserver(Observer* observer) {
    observers.push_back(observer);
}

void ListaSpesa::rimuoviObserver(Observer* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void ListaSpesa::notifica() {
    for (auto observer : observers) {
        observer->aggiorna();
    }
}

// Aggiunta metodo reset
void ListaSpesa::reset() {
    oggetti.clear();  // Svuota la lista degli oggetti
    notifica();       // Notifica gli osservatori della modifica
}

//Aggiunta metodi per vedere quanti oggetti contiene e quanti oggetti da comprare
int ListaSpesa::contaOggetti() const {
    return oggetti.size();
}
int ListaSpesa::contaOggettiDaComprare() const {
    int count = 0;
    for (const auto& oggetto : oggetti) {
        if (oggetto.getDaComprare()) {
            count++;
        }
    }
    return count;
}
//cerca oggetti
std::vector<Oggetto> ListaSpesa::cercaOggetti(const std::string& sottostringa) const {
    std::vector<Oggetto> risultati;
    for (const auto& oggetto : oggetti) {
        if (oggetto.getNome().find(sottostringa) != std::string::npos) {
            risultati.push_back(oggetto);
        }
    }
    return risultati;
}

std::vector<Oggetto> ListaSpesa::listaOggettiDaComprare() const {
    std::vector<Oggetto> daComprare;
    for (const auto& oggetto : oggetti) {
        if (oggetto.getQuantita() > 0) {
            daComprare.push_back(oggetto);
        }
    }
    return daComprare;
}

const std::vector<Oggetto>& ListaSpesa::getOggetti() const {
    return oggetti;
}
