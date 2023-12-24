#include <iostream>
#include <vector>
#include "parser.hpp"
#include "compute.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2) {
		std::cerr << "usage: computer <polynomial_equation>\n";
		exit(1);
	}
	std::vector<Term *> terms = parse(argv[1]);
	terms = compute_reduced_form(terms);
	determinate_degree(terms);
	compute_discriminant(terms);
	return 0;
}
