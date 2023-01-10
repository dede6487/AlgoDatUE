#pragma once

// This project was built with reference to a project I did in a previous lecture,
// I have mostly reused the structure and partial functions.
// Despite this, all of the functions were still implemented by me.

#include<string>
#include<list> //using the STL linked list "list"
#include"Monom.h"

using namespace std;

//******************************************************************
// class "DistPoly"
// 
// vars ... names of the variables
// monoms ... LinkeList of Monoms
// 
//******************************************************************

class DistPoly
{
private:
	string vars;
	list<Monom> monoms; 
	int am; 

	//gives back the position in which the monom with the exponents exps should be inserted
	int sort(int exps, int j);

	//helper function to get monom at position j
	Monom get(list<Monom> _list, int j) {
		list<Monom>::iterator it = _list.begin();
		for (int i = 0; i < j; i++) {
			++it;
		}
		return *it;
	}

public:

	//constructor
	DistPoly(string vars);

	//copy constructor, copy assignment operator, destructor
	DistPoly(DistPoly& p);
	DistPoly& operator=(DistPoly& p);
	~DistPoly();

	//adds monomials to a polynomial
	DistPoly& add(int coeff, int exps);

	//adds polynomials to polynomials
	DistPoly& add(DistPoly& p);

	//prints a polynomial
	void println();
};

