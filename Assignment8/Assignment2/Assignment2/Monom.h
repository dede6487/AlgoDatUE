#pragma once

//class monom for the distpoly class

class Monom
{
public:
    int coeff;
    int exps;

    //constructors
    Monom() {
        this->coeff = 0;
        this->exps = 0;
    }
    Monom(int coeff, int exps, int n) {
        this->coeff = coeff;
        this->exps = exps;
    }

    //copy constructor, copy assignment operator, destructor
    Monom& operator=(Monom& m) {
        this->coeff = m.coeff;
        this->exps = exps;
        return *this;
    }

    //destructor
    ~Monom() {

    }
};
