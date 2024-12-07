/*********************************************************
 * Class Logarithm member functions implementation        *
 * TNG033: Lab 2                                          *
 **********************************************************/

#include "logarithm.h"
#include "polynomial.h"
#include <vector>

#include <cmath>

// overrides

double Logarithm::operator()(double x) const {

	double d = 0;
	double evaluateE = log_base(E->operator()(x), b);

	d += x * c1;
	d += x * c1;
	d += evaluateE;

	return d;
}

Expression* Logarithm::clone() const {
	return new Logarithm(*this);
}

Logarithm::operator std::string() const {

	std::string EStr = E->operator std::string();

	std::cout << c2 << "\n\n\n";

	std::string result = std::format("{:.2f} + {:.2f} * Log_{}( {} )", c1, c2, b, EStr);

	if (c2 < 0) { 
		std::string s = std::format("{:.2f} - {:.2f} * Log_{}( {} )", c1, abs(c2), b, EStr);
		return s;
	}

	return result;
}

//std::string formatted_str = std::format("My name is {} and my number is {}", name,num);

// other

double Logarithm::log_base(double x, double base) const {
	return std::log(x) / std::log(base);
}

Logarithm::Logarithm() {
	b = 2;
	c1 = 0;
	c2 = 1;
	E = new Polynomial(std::vector<double> { 0, 1 });
}

Logarithm::~Logarithm() {
	delete E;
}

Logarithm::Logarithm(const Expression& Exp, const double d1, const double d2, const int base) {
	c1 = d1;
	c2 = d2;
	b = base;
	E = Exp.clone();
}

Logarithm::Logarithm(const Logarithm& rhs) {
	c1 = rhs.c1;
	c2 = rhs.c2;
	b = rhs.b;
	E = rhs.E->clone();
}

Logarithm& Logarithm::operator=(Logarithm& rhs) {


	delete E;

	c1 = rhs.c1;
	c2 = rhs.c2;
	b = rhs.b;
	E = rhs.E->clone();
	return *this;
}

Logarithm& Logarithm::set_base(const int x) {
	b = x;
	return *this;
}




// ADD implementation of the member functions for class Logarithm