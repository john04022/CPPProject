#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <chrono>  // Für system_clock

enum class Farbe {
    Rot, Gruen, Blau, Gelb, Magenta, Cyan
};


class Spieler {
private:

public:
    std::string Name;
    Farbe farbe;
    int id;
    bool isAI;
    int score;
    // Automatische Zuweisungn von id noch unklar !!!
    Spieler(Farbe farbe, const std::string& name) : Name(name), farbe(farbe), id(generiereZufaelligeID()), isAI(false), score(0) {}

    void setName(const std::string& name) { Name = name; }
    const std::string& getName() const { return Name; }

    void setFarbe(Farbe f) { farbe = f; }
    Farbe getFarbe() const { return farbe; }

    void setId(int i) { id = i; }
    int getId() const { return id; }

    void setScore(int s) { score = s; }
    int getScore() const { return score; }

    // Zufällige ID, die im Konstruktor des Spielers erstellt wird
    static int generiereZufaelligeID() {
        static std::mt19937 generator(std::chrono::system_clock::now().time_since_epoch().count()); // Zufallsgenerator
        static std::uniform_int_distribution<int> distribution(1, 10000);
        return distribution(generator);
    }

};

class Feld {
private:

public:
    int anzahl;
    Spieler* owner;

    Feld() : anzahl(0), owner(nullptr) {}

    Feld(int anzahl = 0, Spieler* owner = nullptr)
    : anzahl(anzahl), owner(owner) {}

    void hinzufuegen() { anzahl++; }
    
    const Feld& getFeld() const {
    return *this; // Gibt eine konstante Referenz auf das aktuelle Objekt zurück
    }

    void setAnzahl(int num) { anzahl = num; }
    int getAnzahl() { return anzahl; }

    void setOwner(Spieler* spieler) { owner = spieler; }
    Spieler* getOwner() const { return owner; }
};

