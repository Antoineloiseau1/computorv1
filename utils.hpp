#ifndef UTILS_HPP
# define UTILS_HPP

#include <vector>
#include <iostream>

bool	is_sign(char c);

template <typename T>
void	print_vector(std::vector<T> v) {
	typename std::vector<T>::iterator	it;

	std::cout << "{";
	for(it = v.begin(); it != v.end(); it++) {
		std::cout << *it;
		if (it + 1 != v.end())
			std::cout << ", ";
	}
	std::cout << "}\n";
}

#endif
