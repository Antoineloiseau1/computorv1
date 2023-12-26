#ifndef COMPUTE_HPP
# define COMPUTE_HPP

#include <vector>
#include "Term.hpp"

std::vector<Term>       compute_reduced_form(std::vector<Term> &terms);
void                    print_reduced_form(std::vector<Term> &terms);
void					determinate_degree(std::vector<Term> &terms);
void					compute_discriminant(std::vector<Term> &terms);

#endif
