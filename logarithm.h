/*************************
 * Class Logarithm        *
 * TNG033: Lab 2          *
 **************************/

#pragma once

#include <iostream>

#include "expression.h"

class Logarithm : public Expression {
public:

    Logarithm();

    ~Logarithm();

    Logarithm(const Expression& Exp, const double d1, const double d2, const int base);

    Logarithm& operator=(Logarithm& rhs);

    Logarithm(const Logarithm& rhs);

    Logarithm& set_base(const int x);

    // overrides
    Expression* clone() const override;

    operator std::string() const override;

    double operator()(double x) const override;


private:

    double log_base(double x, double base) const; // in funciton caculations

    double c1; 
    
    double c2;

    Expression* E;

    int b;
    
};
