#include "User.hpp"

User::User(): _id(counter++)
{
	cout << "Welcome User\n";
}


User::User(const User &oldUser)
{}

User& User::operator= (const User &oldUser)
{
	return (*this);
}

User::~User()
{}

void	help(void)
{
	cout << "Add <item> WHERE item is (string)" << endl;
	cout << "Show <id> || Show <null> " << endl;
	cout << "Del <id> || Del <null> || DelAll <null>" << endl;
	cout << "exit || EXIT " << endl;
}


void	User::action(vector<string> cmds)
{
	int i = 0;
	for (vector<string>::iterator cmd = cmds.begin(); cmd != cmds.end();)
	{
		if ((*cmd) == "Show")
		{
			cmd++;
			if (cmd == cmds.end())
				show();
			else
			{
				try 
				{
					int tmp = stoi(*cmd);
					if (tmp >= 0)
						show(tmp);
				}
				catch (...) {}
			}
		}

		if ((*cmd) == "Add" && cmd != cmds.end())
		{
			cmd++;
			add(*cmd);
		}

		if ((*cmd) == "DelAll")
		{
			cmd++;
			if (cmd == cmds.end())
				delAll();
		}
		if ((*cmd) == "Del")
		{
			cmd++;
			if (cmd == cmds.end())
			{
				del();
			}
			else
			{
				try 
				{
					int tmp = stoi(*cmd);
					if (tmp >= 0)
						del(tmp);
				}
				catch (...) {}
			}
		}

		if ((*cmd) == "Help")
			help();
		break;
	}

}

void	User::testLoop(void) //gameplay loop. will exist outside user later
{

	while (1)
	{
		string 			line;
		getline(cin, line);
		
		if (line.length() == 0)
			continue;
		if (line == "exit" || line == "EXIT")
			break;
		if (line == "1")
			show();
	}

}

void	User::loop(void)
{
	while (1)
	{
		string 			line;
		getline(cin, line);
		
		if (line.length() == 0)
			continue;
		if (line == "exit" || line == "EXIT")
			break;

		stringstream	split(line);
		vector<string>	cmds;

		string			ptr;
		while (split >> ptr)
			cmds.push_back(ptr);
		
		action(cmds); 
	}
}
