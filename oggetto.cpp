#include <sstream>
#include "oggetto.h"
#include <iostream>

Oggetto::Oggetto(const std::string& nome, const std::string& categoria, int quantita)
        : nome(nome), categoria(categoria), quantita(quantita) {}

std::string Oggetto::getNome() const {
    return nome;
}

std::string Oggetto::getCategoria() const {
    return categoria;
}

int Oggetto::getQuantita() const {
    return quantita;
}

void Oggetto::setQuantita(int nuovaQuantita) {
    quantita = nuovaQuantita;
}

void Oggetto::stampaOggetto() const {
    std::cout << nome << " (" << categoria << "): " << quantita << std::endl;
}

std::string Oggetto::toString() const {
    std::ostringstream oss;
    oss << nome << " (" << categoria << "): " << quantita;
    return oss.str();
}