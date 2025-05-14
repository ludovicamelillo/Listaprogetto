#ifndef UTENTE_H
#define UTENTE_H
#include "observer.h"
#include <string>
#include "listaspesa.h"
#include <memory>
#include "observer.h"

class Utente : public Observer {
private:
    std::string nome;
    ListaSpesa* listaSeguita;


public:
    explicit Utente(const std::string& nome);

    void smettiDiSeguire();
    void aggiorna() override;
    ~Utente() override;
    void seguiLista(ListaSpesa *lista);
    void aggiornaCont() const;
    void setListaSpesa(ListaSpesa* lista);
};

#endif // UTENTE_H
