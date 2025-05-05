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
        listaSeguita->stampaLista();
    }
}

Utente::~Utente() {
    smettiDiSeguire();
}
