#include <iostream>
#include <vector>
#include "Term.hpp"
#include "utils.hpp"
#include <math.h>

std::vector<Term>	compute_reduced_form(std::vector<Term> &terms) {
	std::vector<Term>::iterator	it;
	std::vector<Term>::iterator	tmp;

	print_vector(terms);	
	for(it = terms.begin(); it != terms.end(); it++)
	{
		tmp = it + 1;
		while(tmp != terms.end())
		{
			while(tmp != terms.end() && (*tmp).isRhs != true)
				tmp++;
			if(tmp != terms.end() && (*tmp).exponent == (*it).exponent) {
				(*it).coefficient += ((*tmp).coefficient *= -1);
				terms.erase(tmp);
			}
			else
				tmp++;
		}
	}
	for(it = terms.begin(); it != terms.end(); it++)
	{
		if((*it).isRhs == true)
		{
			(*it).coefficient *= -1;
			(*it).isRhs = false;
		}
	}
	return (terms);
}

void	print_reduced_form(std::vector<Term> &terms)
{
	std::vector<Term>::iterator it;

	std::cout << "Reduced form: ";
	for(it = terms.begin(); it != terms.end(); it++)
	{
		if(it != terms.begin() && (*it).coefficient >= 0)
			std::cout << " + " << (*it).coefficient << " * X^" << (*it).exponent;
		if(it == terms.begin() && (*it).coefficient >= 0)
			std::cout << (*it).coefficient << " * X^" << (*it).exponent;
		if(it == terms.begin() && (*it).coefficient < 0)
			std::cout << "- " << ((*it).coefficient * -1) << " * X^" << (*it).exponent;
		if(it != terms.begin() && (*it).coefficient < 0)
			std::cout << " - " << ((*it).coefficient * -1) << " * X^" << (*it).exponent;
	}
	std::cout << " = 0\n";
}
		 
void	determinate_degree(std::vector<Term> &terms) {
	std::vector<Term>::iterator	it;
	int degree = 0;

	for(it = terms.begin(); it != terms.end(); it++)
	{
		if ((*it).exponent > degree)
			degree = (*it).exponent;
	}
	if(degree > 2) {
		std::cout << "The polynomial degree is strictly greater than 2, I can't solve\n";
		exit(0);
	}
	else
		std::cout << "Polynomial degree: " << degree << std::endl;
}

void	compute_discriminant(std::vector<Term> &terms) {
	float a = 0, b = 0, c = 0;
	float discriminant;

	std::vector<Term>::iterator	it;
	for(it = terms.begin(); it != terms.end(); it++)
	{
		switch ((*it).exponent) { 

		case 0:
			c = (*it).coefficient;
			break;
		case 1:
			b = (*it).coefficient;
			break;
		case 2:
			a = (*it).coefficient;
			break;
		}
	}
	if(a != 0)
	{
		discriminant = (b * b) - (4 * a * c);
		if(discriminant > 0) {
			std::cout << "Discriminant is strictly positive, the two solutions are:\n";
			std::cout << ((b * -1) - sqrt(discriminant)) / (2 *a) << std::endl;
			std::cout << ((b * -1) + sqrt(discriminant)) / (2 *a) << std::endl;
		}
		else if(discriminant == 0)
			std::cout << "The solution is:\n" << (b * -1) / (2 *a) << std::endl;
		else
		{
			std::cout << "The two solutions are not real numbers, I can't solve\n";
			exit(1);
		}
	}
	else
	{
		if(b != 0)
			std::cout << "The solution is: \n" << (c / b) * - 1 << std::endl;
		else
			std::cout << "Each Real Number is a solution\n";
	}
}

	
			

