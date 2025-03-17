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
    temp.hiz =temp.hiz+ ivme * deltaT;
    temp.konum =temp.konum + hiz * deltaT; 
    return temp;
}



class rocket : public cisim
{
public:
    double p_oran;
	vector p_hiz;
    rocket(double, vector, vector, vector, double);
    rocket() = default;
    void print();
    rocket update(double, double);
};

rocket::rocket(double kutleVal, vector konumVal, vector hizVal, vector p_hiz_val, double p_oran_val)
: cisim(kutleVal, konumVal, hizVal), p_hiz(p_hiz_val), p_oran(p_oran_val) {}



int main()
{
    rocket r1(150, vector(400,0), vector(0,0.2), vector(5,0), 0.1);
 
 	std::cout<<r1.k;


    return 0;
}