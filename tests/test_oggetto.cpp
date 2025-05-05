#include "../include/oggetto.h"
#include <cassert>
#include <iostream>

void testCostruttore() {
    Oggetto o("Pane", "Alimentari", 2);
    assert(o.getNome() == "Pane");
    assert(o.getCategoria() == "Alimentari");
    assert(o.getQuantita() == 2);
    std::cout << "✓ testCostruttore superato\n";
}

void testSetQuantita() {
    Oggetto o("Latte", "Bevande", 1);
    o.setQuantita(5);
    assert(o.getQuantita() == 5);
    o.setQuantita(-3);
    assert(o.getQuantita() == 5);
    std::cout << "✓ testSetQuantita superato\n";
}

void testDaComprare() {
    Oggetto o("Uova", "Alimentari", 6);
    assert(!o.getDaComprare());
    o.setDaComprare(true);
    assert(o.getDaComprare());
    std::cout << "✓ testDaComprare superato\n";
}

void testToString() {
    Oggetto o("Caffè", "Bevande", 3);
    o.setDaComprare(true);
    std::string expected = "Oggetto: Caffè | Categoria: Bevande | Quantità: 3 | Da Comprare: Sì\n";
    assert(o.toString() == expected);
    std::cout << "✓ testToString superato\n";
}

