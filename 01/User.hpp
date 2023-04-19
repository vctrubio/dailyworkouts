#ifndef USER_HPP
#define USER_HPP

#include "Headers.hpp"
#include "Kart.hpp"
#include "Wallet.hpp"

class Kart;
class Wallet;


class User : public Kart
{
	static int		counter;
	unsigned int	_id;
	Wallet			*wallet;

public:
	User();
	User(const User &oldUser);
	User& operator= (const User &oldUser);
	~User();

	void	testLoop(void);
	void	loop(void);
	void	action(vector<string>);
};


#endif
