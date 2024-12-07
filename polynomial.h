/*************************
 * Class Polynomial       *
 * TNG033: Lab 2          *
 **************************/

#pragma once

#include <iostream>
#include <vector>

#include "expression.h"

class Polynomial : public Expression {
public:

	//overrides
	Expression* clone() const override;

	operator std::string() const override;

	double operator()(double x) const override;

	//other funcs
	Polynomial();

	Polynomial(const std::vector<double> v);

	Polynomial(const double d);

	Polynomial(const Polynomial& p);

	Polynomial& operator=(Polynomial rhs);

	Polynomial& operator+=(Polynomial rhs);

	friend Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs);

	//friend Polynomial operator+(Polynomial lhs, const Polynomial& rhs);

	double& operator[](const int x);

	double operator[](const int i) const;

	std::vector<double> get_coeffs() const;

private:

	std::vector<double> theCoefficients;
};

/*
 * std::vector should be used to store polinomial's coefficients
 */