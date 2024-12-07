/*************************
 * Class Expression       *
 * TNG033: Lab 2          *
 **************************/

#pragma once

#include <iostream>

constexpr double Epsilon = 1.0e-5;

class Expression {
public:

	Expression& operator=(const Expression&) = delete;

	// Destructor
	virtual ~Expression() {
		--count_expressions;
	}

	// ADD OTHER MEMBER FUNCTIONS
	virtual double operator()(double x) const = 0;

	bool isRoot(double x) const;

	friend std::ostream& operator<<(std::ostream& os, const Expression& e) {
		os << std::string{e};  // dynamic binding
		return os;
	}

	// Return number of existing instances of class Expression
	// Used only for debug purposes
	static std::size_t get_count_expressions();

	virtual Expression* clone() const = 0;

	virtual operator std::string() const = 0;


protected:
	// Default constructor
	Expression() {
		++count_expressions;
	}

	// Copy constructor
	Expression(const Expression&) {
		++count_expressions;
	}

	// total number of existing expressions -- only to help to detect bugs in the code
	static std::size_t count_expressions;
	// Your code cannot manipulate this variable


};

