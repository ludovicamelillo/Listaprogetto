#include "utente.h"
#include <iostream>

Utente::Utente(const std::string& nome) : nome(nome), listaSeguita(nullptr) {}

void Utente::seguiLista(const std::shared_ptr<ListaSpesa>& lista) {
    listaSeguita = lista;
    listaSeguita->aggiungiObserver(this);
}

void Utente::smettiDiSeguire() {
    if (listaSeguita) {
        listaSeguita->rimuoviObserver(this);
        listaSeguita.reset();
    }
}

void Utente::aggiorna() {
    std::cout << "Utente " << nome << " ha ricevuto un aggiornamento sulla lista della spesa." << std::endl;
    if (listaSeguita) {
        listaSeguita->stampaLista();
    }
}

void Utente::notificaEliminazione(const std::string& prodotto) {
    std::cout << "**Notifica**: La " << prodotto << " è stata eliminata dalla lista della spesa." << std::endl;
}

Utente::~Utente() {
    smettiDiSeguire();
}
