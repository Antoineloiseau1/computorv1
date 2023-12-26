#include "Term.hpp"
#include <algorithm>


Term::Term(std::string token, bool rhs) {
	token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
	isRhs = rhs;
	coefficient = atof(token.c_str());	
	exponent = token[token.length() - 1] - 48;
}

Term::~Term(void) {}


std::ostream &operator<<(std::ostream &out, Term &term) {
	out << term.coefficient << " * X^" << term.exponent;
	return out;
}
