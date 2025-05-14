#include "../include/utente.h"
#include <iostream>

Utente::Utente(const std::string& nome) : nome(nome), listaSeguita(nullptr) {}

void Utente::seguiLista(ListaSpesa* lista) {
    listaSeguita = lista;
    listaSeguita->aggiungiObserver(this);
}

void Utente::smettiDiSeguire() {
    if (listaSeguita) {
        listaSeguita->rimuoviObserver(this);
        listaSeguita= nullptr;
    }
}

void Utente::aggiorna() {
    std::cout << "Utente " << nome << " ha ricevuto un aggiornamento sulla lista della spesa." << std::endl;
    if (listaSeguita) {
       aggiornaCont();
    }
}

void Utente::aggiornaCont() const {
    if (listaSeguita) {
        listaSeguita->stampaLista();  // Chiama il metodo per stampare la lista aggiornata
    } else {
        std::cout << "Nessuna lista seguita!" << std::endl;
    }
}

void Utente::setListaSpesa(ListaSpesa* lista) {
    listaSeguita = lista;
    listaSeguita->aggiungiObserver(this);
}

Utente::~Utente() {
    smettiDiSeguire();
}
