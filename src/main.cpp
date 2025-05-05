#include "../include/oggetto.h"
#include "../include/listaspesa.h"
#include "../include/utente.h"
#include <memory>
#include "observer.h"

int main() {
    // Creazione utenti
    Utente utente1("Ludovica");
    Utente utente2("Daniela");

    ListaSpesa* listaSpesa = new ListaSpesa();

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




