#ifndef USER_HPP
#define USER_HPP

#include "Headers.hpp"
#include "Kart.hpp"

class Kart;


class User : public Kart
{
	static int		counter;
	unsigned int	_id;
public:
	User();
	User(const User &oldUser);
	User& operator= (const User &oldUser);
	~User();

	void	loop(void);
	void	action(vector<string>);
};


#endif
