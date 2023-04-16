#include "Classroom.hpp"

Classroom::Classroom()
{}

Classroom::Classroom(const Classroom &oldClassroom)
{}

Classroom& Classroom::operator= (const Classroom &oldClassroom)
{
	return (*this);
}

Classroom::~Classroom()
{}


student	createStudent(string name, int age, string comment)
{
	student rtn;

	rtn.name = name;
	rtn.age = age;
	rtn.comment = comment;
	return rtn;
}


void	Classroom::add(string name, int age, string comment)
{
	student *ptr = new student;

	ptr->name = name;
	ptr->age = age;
	ptr->comment = comment;

	front.push_back(ptr);
	cout << "Student " << name << " created.\n";
}


void	Classroom::print(void)
{
	cout << "Printing List of Student...\n";

	int j = 0;
	for (auto i : front)
	{
		cout << ++j << ": ";
		cout << "NAME: " << i->name << " AGE: " << i->age << " : " << i->comment << endl;
	}

}
