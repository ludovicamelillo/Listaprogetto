#ifndef UTENTE_H
#define UTENTE_H

#include <string>
#include "listaspesa.h"
#include <memory>

// Classe Utente (Observer)
class Utente : public IObserver {
private:
    std::string nome;
    std::shared_ptr<ListaSpesa> listaSeguita;

public:
    explicit Utente(const std::string& nome);

    void seguiLista(const std::shared_ptr<ListaSpesa>& lista);
    void smettiDiSeguire();
    void aggiorna() override;
    void notificaEliminazione(const std::string& nomeOggetto) override;  // Nuovo metodo per la notifica di eliminazione
    ~Utente() override;

};

#endif // UTENTE_H
