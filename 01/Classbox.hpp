#ifndef CLASSBOX_HPP
#define CLASSBOX_HPP

#include "Headers.hpp"

template<typename T>
struct listNode
{
	T	ptr;
	listNode	*next;
	listNode(T x): ptr(x), next(nullptr) {}

};


class Classbox
{
public:
	Classbox();
	Classbox(const Classbox &oldClassbox);
	Classbox& operator= (const Classbox &oldClassbox);
	~Classbox();
};

#endif
