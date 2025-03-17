#include <iostream>

const double deltaT = 0.01;


class vector
{
 public:
    double x, y;
    vector() = default;
    vector(double, double);
    
    vector operator+(const vector& other) const {
        return vector(x + other.x, y + other.y);
    }

    vector operator-(const vector& other) const {
        return vector(x - other.x, y - other.y);
    }

    vector operator*(double scalar) const {
        return vector(x * scalar, y * scalar);
    }

    vector operator/(double scalar) const {
        return vector(x / scalar, y / scalar);
    }
};

vector::vector(double xVal, double yVal)
{
    x = xVal;
    y = yVal;
}


class cisim
{
public:
    double kutle;
    vector hiz;
    vector konum;
    cisim(double,vector,vector);
    cisim() = default;
    virtual cisim update(vector);
};

cisim::cisim(double kutleVal, vector konumVal, vector hizVal)
{
    kutle = kutleVal;
    konum = konumVal;
    hiz = hizVal;
}

cisim cisim::update(vector bileskeKuvvet)
{
    cisim temp;
    vector ivme = bileskeKuvvet / kutle;
    temp.hiz = hiz + ivme * deltaT;
    temp.konum = konum + hiz * deltaT; 
    return temp;
}



class rocket : public cisim
{
public:
    double p_kutle;
	vector p_hiz;
    rocket(double, vector, vector, vector, double);
    rocket() = default;
    void print();
    rocket update(double, double);
};

rocket::rocket(double kutleVal, vector konumVal, vector hizVal, vector p_hiz_val, double p_kutle_val)
: cisim(kutleVal, konumVal, hizVal), p_hiz(p_hiz_val), p_kutle(p_kutle_val) {}

rocket rocket::update(vector bileskeKuvvet)
{
    rocket temp;
    temp.kutle = kutle - (p_kutle * deltaT);
    vector ivme = bileskeKuvvet / temp.kutle;
    temp.hiz = hiz + ivme * deltaT;
    temp.konum = konum + hiz * deltaT;  
    return temp;
}


class hesapla
{
    vector kuvvetHesapla();
    vector bileskeKuvvetHesapla();
}