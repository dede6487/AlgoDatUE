#include"DistPoly.h"
#include<iostream>
#include<list>
#include<iterator>

using namespace std;

//******************************************************************
// Method "add(itn coeff, int* exps)"
// 
// is a member function of the class "DistPoly" and adds the monomial
// given by its coefficient and its exponent to the current polynomial
// 
// coeff ... ceofficient of the monomial that will be added
// exps ... exponents of the monomial that will be added
//******************************************************************

DistPoly& DistPoly::add(int coeff, int exps) {
    if (coeff !=0) {
        Monom* n = new Monom;
        (*n).coeff = coeff;
        (*n).exps = exps;
        for (int j = 0; j <= this->am; j++) {
            int k = 1;
            //checks where to insert/add the polynomial
            k = sort(exps, j);
            if (k == 0) {
                if ((*(monoms.begin())).coeff += coeff == 0) { //should first change the value, then check if 0
                    monoms.pop_front();
                    am--;
                }
                break;
            }

            else if (k == -1) {
                list<Monom>::iterator it = monoms.begin();
                for (int i = 0; i < j - 1; i++) {
                    it++;
                }
                monoms.insert(it, *n);
                am++;
                break;
            }
            else {
                monoms.push_back(*n);
                am++;
            }
        }
    }
    return *this;
}

//******************************************************************
// Method "add(DistPoly& p)"
// 
// is a member function of the class "DistPoly" and adds one 
// polynomial to the polynomial.
// 
// p ... polynomial that should be added
//******************************************************************

DistPoly& DistPoly::add(DistPoly& p) {
	if (this->vars != p.vars) {
		cout << "Error: the variables of two added polynomials do not match";
		throw 1;
	}
    if (p.am != 0) {
        for (int i = 0; i <= p.am; i++){
            this->add(get(p.monoms, i).coeff, get(p.monoms, i).exps);
        }
    }
    return *this;
}

//******************************************************************
// Method "sort"
// 
// is a private member function of DistPoly used in the add method to determine
// the correct place in which the new monomial should be added.
// 
// It takes the exponents of a monomial and gives back:
// 
// -> 0 if the given exponents match the exponents of this polynomial.
// -> 1 if the given exponents need to be inserted after this polynomial.
// -> -1 if the given exponents need to be inserted before this polynomial.
// 
// exps ... exponents to be sorted in
// j ... the number of the monomial it should check against in the 
// monomial array of the polynomial
//******************************************************************

int DistPoly::sort(int exps, int j) {
	if (get(monoms, j).exps > exps) {
		return 1;
	}
	else if (get(monoms, j).exps < exps) {
		return -1;
	}
    return 0;
}

//******************************************************************
// Method "println()"
// it prints out the given polynomial.
//******************************************************************

void DistPoly::println() {
    if (am==0) {
        cout << "0" << endl;
    }
    else {
        for (int i = 0; i < am; i++) {
            Monom temp = get(monoms, i);
            if (temp.coeff != 0) {
                cout << temp.coeff;
				if (temp.exps == 1) {
					cout << this->vars;
				}
				else if (temp.exps != 0) {
					cout << this->vars;
					cout << "^" << temp.exps;
				}
                if (i < am && temp.coeff > 0) {
                    cout << "+";
                }
            }
        }
        cout << "\n";
    }
}

DistPoly::DistPoly(string vars) {
    this->vars = vars;
    this->am = 0;
}

DistPoly::DistPoly(DistPoly& p) {
    this->vars = p.vars;
    this->am = p.am;
   this->monoms = p.monoms; //these assignments produced errors I was not able to fix in time
}

DistPoly& DistPoly::operator=(DistPoly& p) {
    this->vars = p.vars;
    this->am = p.am;
   this->monoms = p.monoms; //these assignments produced errors I was not able to fix in time

    return *this;
}

DistPoly::~DistPoly() {

}
