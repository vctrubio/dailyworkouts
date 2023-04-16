#ifndef CLASSROOM_HPP
#define CLASSROOM_HPP

#include "Headers.hpp"
using namespace std;

struct student
{
	string	name;
	int		age;
	string	comment;
};



class Classroom
{
	list<student*>	front;	
public:
	Classroom();
	Classroom(const Classroom &oldClassroom);
	Classroom& operator= (const Classroom &oldClassroom);
	~Classroom();

	void	add(string, int, string);
	void	print(void);
};

#endif
