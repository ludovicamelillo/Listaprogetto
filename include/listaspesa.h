#ifndef LISTASPESA_H
#define LISTASPESA_H
#include <vector>
#include <string>
#include "oggetto.h"
#include "observer.h"

class ListaSpesa {
private:
    std::vector<Oggetto> oggetti;
    std::vector<Observer*> observers;

public:
    void aggiungiOggetto(const Oggetto& oggetto);
    void rimuoviOggetto(const std::string& nomeOggetto);
    void stampaLista() const;

    void aggiungiObserver(Observer* observer);
    void rimuoviObserver(Observer* observer);
    void notifica();
    void reset();
    int contaOggetti() const;
    int contaOggettiDaComprare() const;
    Oggetto* cercaOggetto(const std::string& nome) const;
    std::vector<Oggetto> listaOggettiDaComprare() const;

};


#endif // LISTASPESA_H
