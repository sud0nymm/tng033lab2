/*********************************************************
 * Class Polynomial member functions implementation       *
 * TNG033: Lab 2                                          *
 **********************************************************/

#include "polynomial.h"


Polynomial::Polynomial() {}

Polynomial::Polynomial(const std::vector<double> v) : theCoefficients{ v } {}

Polynomial::Polynomial(const double d) {
	const std::vector<double> v = { d };
	theCoefficients = v;
}

Polynomial::Polynomial(const Polynomial& p) {
	theCoefficients = p.get_coeffs();
}

std::vector<double> Polynomial::get_coeffs() const {
	return theCoefficients;
}

Polynomial& Polynomial::operator=(Polynomial rhs) {
	theCoefficients = rhs.get_coeffs();
	return *this;
}

Polynomial& Polynomial::operator+=(Polynomial rhs) {

	if (theCoefficients.size() < rhs.get_coeffs().size()) {
		theCoefficients.resize(rhs.get_coeffs().size(), 0);
	}
	
	for (int i = 0; i < rhs.get_coeffs().size(); ++i) { // possible hazard
		theCoefficients[i] = theCoefficients[i] + rhs.get_coeffs()[i];
	}

	return *this;
}

Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs) {

	Polynomial result{lhs};
	result += rhs;
	return result;
}

/*
Polynomial operator+(Polynomial lhs, const Polynomial& rhs) {

	lhs += rhs;
	return lhs;
}*/

double& Polynomial::operator[](const int x) {
	return theCoefficients[x];
}

double Polynomial::operator[](const int x) const {
	return theCoefficients[x];
}




// overrides 
double Polynomial::operator()(double x) const {
	double d = 0;

	for (int i = 0; i < theCoefficients.size(); i++) {
		d += theCoefficients[i] * pow(x, i);
	}
	return d;
}

Expression* Polynomial::clone() const {
	return new Polynomial(*this);
}

Polynomial::operator std::string() const {
	std::string result;
	result += std::format("{:.2f}", theCoefficients[0]);
	for (int i = 1; i < theCoefficients.size(); i++) {
		if (theCoefficients[i] < 0) {
			result += std::format(" - {:.2f} * X^{}", -theCoefficients[i], i);
		}
		else {
			result += std::format(" + {:.2f} * X^{}", theCoefficients[i], i);
		}
	}
	return result;
}





// ADD implementation of the member functions for class Polynomial