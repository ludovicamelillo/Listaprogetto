#ifndef LISTASPESA_H
#define LISTASPESA_H

#include <vector>
#include <string>
#include "oggetto.h"

// Interfaccia Observer
class IObserver {
public:
    virtual void aggiorna() = 0;
    virtual ~IObserver(){};
};

// Classe ListaSpesa (Subject)
class ListaSpesa {
private:
    std::vector<Oggetto> oggetti;
    std::vector<IObserver*> observers;

public:
    void aggiungiOggetto(const Oggetto& oggetto);
    void rimuoviOggetto(const std::string& nomeOggetto);
    void stampaLista() const;

    void aggiungiObserver(IObserver* observer);
    void rimuoviObserver(IObserver* observer);
    void notifica();

};

#endif // LISTASPESA_H
