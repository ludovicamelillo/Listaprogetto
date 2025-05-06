#include "gtest/gtest.h"
#include "Utente.h"

TEST(UtenteTest, CostruttoreTest) {
    Utente u("Ludovica");
    SUCCEED();
}

TEST(UtenteTest, SeguiListaTest) {
    Utente u("Ludovica");
    ListaSpesa lista;
    u.seguiLista(&lista);
    u.aggiorna();
    SUCCEED();
}

TEST(UtenteTest, SmettiDiSeguireTest) {
    Utente u("Ludovica");
    ListaSpesa lista;
    u.seguiLista(&lista);
    u.smettiDiSeguire();
    SUCCEED();
}
