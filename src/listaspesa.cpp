#include "../include/listaspesa.h"
#include <algorithm>
#include <iostream>

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
        notificaEliminazione(nomeOggetto); // Notifica gli osservatori della rimozione
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

// Notifica agli osservatori che un oggetto è stato eliminato dalla lista
void ListaSpesa::notificaEliminazione(const std::string& nomeOggetto) {
    for (auto observer : observers) {
        // Notifica ogni osservatore che l'oggetto è stato eliminato
        observer->notificaEliminazione(nomeOggetto);
    }
}