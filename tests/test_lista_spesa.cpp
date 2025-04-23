#include <gtest/gtest.h>
#include "listaspesa.h"
#include "oggetto.h"

TEST(ListaSpesaTest, AggiungiOggettoTest) {
    ListaSpesa lista;
    Oggetto mela("Mele", "Frutta", 5);
    lista.aggiungiOggetto(mela);

    // Verifica che l'oggetto sia stato aggiunto alla lista
    ASSERT_EQ(1, lista.getOggetti().size());  // Verifica che ci sia 1 oggetto
    ASSERT_EQ("Mele", lista.getOggetti()[0].getNome());  // Verifica che l'oggetto sia "Mele"
}

TEST(ListaSpesaTest, RimuoviOggettoTest) {
    ListaSpesa lista;
    Oggetto mela("Mele", "Frutta", 5);
    lista.aggiungiOggetto(mela);

    // Rimuovi oggetto
    lista.rimuoviOggetto("Mele");

    // Verifica che l'oggetto sia stato rimosso
    ASSERT_EQ(0, lista.getOggetti().size());  // Verifica che la lista sia vuota
}

TEST(ListaSpesaTest, RimuoviOggettoNonPresenteTest) {
    ListaSpesa lista;
    Oggetto pane("Pane", "Forno", 2);
    lista.aggiungiOggetto(pane);

    // Provo a rimuovere un oggetto che non c'è
    lista.rimuoviOggetto("Mandarino");

    // La lista deve avere ancora un solo oggetto
    ASSERT_EQ(1, lista.getOggetti().size());
    ASSERT_EQ("Pane", lista.getOggetti()[0].getNome());
}

