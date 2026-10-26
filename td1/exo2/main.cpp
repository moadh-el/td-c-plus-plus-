#include <iostream>
#include <cmath>

class Complex2D {
private:
    double reel;
    double imaginaire;

public:

    Complex2D() : reel(0.0), imaginaire(0.0) {}


    Complex2D(double r, double i) : reel(r), imaginaire(i) {}


    Complex2D(double val) : reel(val), imaginaire(val) {}


    Complex2D(const Complex2D& autre) : reel(autre.reel), imaginaire(autre.imaginaire) {}


    void setReel(double r) { reel = r; }
    void setImaginaire(double i) { imaginaire = i; }


    double getReel() const { return reel; }
    double getImaginaire() const { return imaginaire; }


    Complex2D operator+(const Complex2D& c) const {
        return Complex2D(reel + c.reel, imaginaire + c.imaginaire);
    }

    Complex2D operator-(const Complex2D& c) const {
        return Complex2D(reel - c.reel, imaginaire - c.imaginaire);
    }


    Complex2D operator*(const Complex2D& c) const {
        return Complex2D(reel * c.reel - imaginaire * c.imaginaire,
                         reel * c.imaginaire + imaginaire * c.reel);
    }


    Complex2D operator/(const Complex2D& c) const {
        double denom = c.reel * c.reel + c.imaginaire * c.imaginaire;
        return Complex2D((reel * c.reel + imaginaire * c.imaginaire) / denom,
                         (imaginaire * c.reel - reel * c.imaginaire) / denom);
    }


    bool operator<(const Complex2D& c) const {
        double mod1 = std::sqrt(reel * reel + imaginaire * imaginaire);
        double mod2 = std::sqrt(c.reel * c.reel + c.imaginaire * c.imaginaire);
        return mod1 < mod2;
    }


    bool operator>(const Complex2D& c) const {
        double mod1 = std::sqrt(reel * reel + imaginaire * imaginaire);
        double mod2 = std::sqrt(c.reel * c.reel + c.imaginaire * c.imaginaire);
        return mod1 > mod2;
    }
};
