#ifndef WALLET_HPP
#define WALLET_HPP

#include "Headers.hpp"

class Wallet
{
	int	_balance;
public:
	Wallet(int i): _balance(i){};
	Wallet(const Wallet &oldWallet);
	Wallet& operator= (const Wallet &oldWallet);
	~Wallet();

	int		balance(){return _balance;};
	void	deposit(int i) {_balance += i;};
	void	transaction(int i){_balance -= i;};
};

/* to implement
 * transaction ->when checkout of kart, check balance, add balance -> deposut
 *
*/

#endif
