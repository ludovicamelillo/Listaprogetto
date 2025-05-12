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

TEST(UtenteTest, AggiornaContOutput) {
    Utente u("Ludovica");
    ListaSpesa lista;
    lista.aggiungiOggetto(Oggetto("uova","alimentari", 1));
    u.setListaSpesa(&lista);

    // Cattura std::cout
    testing::internal::CaptureStdout();
    u.aggiornaCont();  // dovrebbe stampare la lista aggiornata
    std::string output = testing::internal::GetCapturedStdout();

    // Controlla che contenga "uova" e la quantità
    ASSERT_NE(output.find("uova"), std::string::npos);
    ASSERT_NE(output.find("1"), std::string::npos);
}
