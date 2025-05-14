#ifndef OGGETTO_H
#define OGGETTO_H
#include <string>

class Oggetto {
private:
    std::string nome;
    std::string categoria;
    int quantita;
    bool daComprare;

public:
    Oggetto(const std::string& nome, const std::string& categoria, int quantita, bool daComprare=true);

    std::string getNome() const;
    std::string getCategoria() const;
    int getQuantita() const;
    void stampaOggetto() const;
    std::string toString() const;
    void setQuantita(int nuovaQuantita);
    bool getDaComprare() const;
    void setDaComprare(bool);
};

#endif // OGGETTO_H
