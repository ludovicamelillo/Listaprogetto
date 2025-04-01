#ifndef UTENTE_H
#define UTENTE_H

#include <string>
#include "listaspesa.h"

// Classe Utente (Observer)
class Utente : public IObserver {
private:
    std::string nome;
    ListaSpesa* listaSeguita;

public:
    explicit Utente(const std::string& nome);

    void seguiLista(ListaSpesa* lista);
    void smettiDiSeguire();
    void aggiorna() override;
    void notificaEliminazione(const std::string& nomeOggetto) override;  // Nuovo metodo per la notifica di eliminazione
    ~Utente() override;

};

#endif // UTENTE_H
