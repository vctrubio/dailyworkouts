#ifndef BANK_HPP
#define BANK_HPP

#include "Headers.hpp"

class Bank
{
public:
	Bank();
	Bank(const Bank &oldBank);
	Bank& operator= (const Bank &oldBank);
	~Bank();
};

#endif
