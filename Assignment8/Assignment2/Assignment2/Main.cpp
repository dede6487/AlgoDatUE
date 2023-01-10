#include"DistPoly.h"
#include<string>

int main() {
	string vars = "x";
	DistPoly p(vars);
	p.add(3, 1).add(5, 2).add(7, 1);

	DistPoly q(vars);
	q.add(11, 1).add(-3, 2).add(2, 0);

	// print p and q
	p.println();
	q.println();

	// set p to p+2*q and print it

	DistPoly r = p;
	r.add(q).add(q);
	p = r;
	p.println();

	return 0;
}