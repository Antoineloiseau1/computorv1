#include "Term.hpp"

Term::Term(std::string token, bool rhs) {
	isRhs = rhs;
	coefficient = atof(token.c_str());
	exponent = token[token.length() - 1] - 48;
}

Term::~Term(void) {}

std::ostream &operator<<(std::ostream &out, Term &term) {
	out << term.coefficient << "x" << term.exponent;
	return out;
}
