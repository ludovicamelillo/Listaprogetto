#include "../include/oggetto.h"
#include <cassert>
#include <iostream>
#include <gtest/gtest.h>

TEST(OggettoTest, CostruttoreValido) {
Oggetto o("Pane", "Alimentari", 3, false);
EXPECT_EQ(o.getNome(), "Pane");
EXPECT_EQ(o.getCategoria(), "Alimentari");
EXPECT_EQ(o.getQuantita(), 3);
}

TEST(OggettoTest, CostruttoreQuantitaNegativa) {
    Oggetto o("Latte", "Latticini", -2, true);
    EXPECT_EQ(o.getQuantita(), 0); // quantità impostata a 0 in caso di valore negativo
}

TEST(OggettoTest, DaComprareGetterSetter) {
    Oggetto o("Uova", "Alimentari", 6, false);
    EXPECT_FALSE(o.getDaComprare());
    o.setDaComprare(true);
    EXPECT_TRUE(o.getDaComprare());
}

TEST(OggettoTest, ToStringTest) {
    Oggetto o("Caffè", "Bevande", 3, false);
    o.setDaComprare(true);
    std::string expected = "Oggetto: Caffè | Categoria: Bevande | Quantità: 3 | Da Comprare: Sì\n";
    EXPECT_EQ(o.toString(), expected);
}

TEST(OggettoTest, SetQuantitaValida) {
    Oggetto o("Uova", "Alimentari", 6, true);
    o.setQuantita(4);
    EXPECT_EQ(o.getQuantita(), 4);
}

TEST(OggettoTest, SetQuantitaNegativa) {
    Oggetto o("Burro", "Latticini", 2, true);
    o.setQuantita(-3);
    EXPECT_EQ(o.getQuantita(), 2);
}
