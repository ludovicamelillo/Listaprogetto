#include <sstream>
#include "../include/oggetto.h"
#include <iostream>

Oggetto::Oggetto(const std::string& nome, const std::string& categoria, int quantita)
        : nome(nome), categoria(categoria), quantita(quantita), daComprare(false) {
    if (quantita < 0) {
        std::cerr << "[Errore] Quantità negativa, impostata a 0.\n";
        this->quantita = 0;
    }else{
        this->quantita=quantita;
    }
}

std::string Oggetto::getNome() const {
    return nome;
}

std::string Oggetto::getCategoria() const {
    return categoria;
}

int Oggetto::getQuantita() const {
    return quantita;
}

void Oggetto::stampaOggetto() const {
    std::cout << nome << " (" << categoria << "): " << quantita << std::endl;
}

std::string Oggetto::toString() const {
    std::ostringstream oss;
    oss << "Oggetto: " << nome
        << " | Categoria: " << categoria
        << " | Quantità: " << quantita
        << " | Da Comprare: " << (daComprare ? "Sì" : "No") << "\n";
    return oss.str();
}

void Oggetto::setQuantita(int quantita) {
    if (quantita < 0) {
        this->quantita = this->quantita; // mantenere il valore attuale
    } else {
        this->quantita = quantita;
    }
}


bool Oggetto::getDaComprare() const {
    return daComprare;
}

void Oggetto::setDaComprare(bool valore) {
    daComprare = valore;
}

