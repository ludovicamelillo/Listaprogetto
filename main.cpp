#include "oggetto.h"
#include "listaspesa.h"
#include "utente.h"
#include <memory>

int main() {
    // Creazione utenti
    Utente utente1("Ludovica");
    Utente utente2("Daniela");

    // Creazione lista della spesa condivisa con shared_pyt
    auto listaSpesa = std::make_shared<ListaSpesa>();


    //Gli utenti seguono la stessa lista
    utente1.seguiLista(listaSpesa);
    utente2.seguiLista(listaSpesa);


    // Aggiunta oggetti alla lista
    listaSpesa->aggiungiOggetto(Oggetto("Mele", "Frutta", 5));
    listaSpesa->aggiungiOggetto(Oggetto("Latte", "Latticini", 2));

    // Rimuovere un oggetto
    listaSpesa->rimuoviOggetto("Mele");

    return 0;
}




