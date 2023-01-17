#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <conio.h>

class cell
{
public:
	cell(std::string des, int num, std::string pass, int d, int m, int y)
		: destination(des),
		  fl_num(num),
		  passenger(pass),
		  day(d),
		  month(m),
		  year(y)
	{
	}

	std::string destination;
	int fl_num, day, month, year;
	std::string passenger;

	cell* next = nullptr;
};

class list
{
public:
	list()
		: Start(0)
	{
	}

	~list()
	{
		DeleteList(Start);
	}

	void output()
	{
		if (Start)
			PrintList(Start);
		else
			std::cout << "No requests\n";
	}

	void DelSuitable(int num, std::string pass, std::string des, int d, int m, int y)
	{
		if (pass == "\n")
		{
			count = 0;
			NumberOfSuitableRequests(Start, num, d, m, y, count);
			DeleteSuitableCells(Start, num, d, m, y);
		}
		else
		{
			DeleteUnit(Start, num, pass, des, d, m, y);
		}
	}

	void Insert(std::string des, int num, std::string pass, int d, int m, int y)
	{
		cell** cur = &Start;
		count = 0;
		NumberOfExistingRequests(Start, num, d, m, y, pass, des, count);
		if (count == 0)
		{
			while (*cur)
			{
				cell& unit = **cur;
				cur = &unit.next;
			}
			*cur = new cell(des, num, pass, d, m, y);
		}
	}

private:
	static void DeleteList(cell*& unit)
	{
		while (unit)
		{
			DeleteList(unit->next);
			delete unit;
			unit = NULL;
		}
	}

	static void PrintList(cell*& unit)
	{
		if (unit)
		{
			std::cout << unit->destination << " " << unit->fl_num << " " << unit->passenger << " " << unit->day << "."
				<< unit->month << "." << unit->year << "\n";
			PrintList(unit->next);
		}
	}

	static void NumberOfSuitableRequests(cell*& unit, int num, int d, int m, int y, int& count)
	{
		if (unit)
		{
			if (num == unit->fl_num && d == unit->day && m == unit->month && y == unit->year)
				count++;
			NumberOfSuitableRequests(unit->next, num, d, m, y, count);
		}
	}

	static void NumberOfExistingRequests(cell*& unit, int num, int d, int m, int y, std::string pass, std::string des,
	                                     int& count)
	{
		if (unit)
		{
			if (pass == unit->passenger && des == unit->destination && d == unit->day && m == unit->month && y == unit->
				year)
				count++;
			NumberOfExistingRequests(unit->next, num, d, m, y, pass, des, count);
		}
	}

	void DeleteSuitableCells(cell*& unit, int num, int d, int m, int y)
	{
		while (count > 0)
		{
			if (unit)
			{
				if (num != unit->fl_num)
					DeleteSuitableCells(unit->next, num, d, m, y);
				else
				{
					cell* help = unit;
					if (unit->next == NULL)
					{
						delete unit;
						unit = NULL;
					}
					else
					{
						MoveUnitToEnd(help->next, help);
						delete help;
					}
				}
			}
			count--;
		}
	}

	static void MoveUnitToEnd(cell*& R, cell*& R1)
	{
		R1->destination = R->destination;
		R1->fl_num = R->fl_num;
		R1->passenger = R->passenger;
		R1->day = R->day;
		R1->month = R->month;
		R1->year = R->year;
		R1 = R;
		R = R->next;
	}

	static void DeleteUnit(cell*& unit, int num, std::string pass, std::string des, int d, int m, int y)
	{
		if (unit)
		{
			if (num == unit->fl_num && pass == unit->passenger && des == unit->destination && d == unit->day && m ==
				unit->month && y == unit->year)
			{
				cell* help = unit;
				MoveUnitToEnd(help->next, help);
				delete help;
			}
			else
				DeleteUnit(unit->next, num, pass, des, d, m, y);
		}
	}

	cell* Start;
	int count;
};

class Interface
{
public:
	void AddRequest(list& tree)
	{
		char c;
		std::string des, pass;
		int num, d, m, y;
		bool leap = false, long_month = false;
		std::time_t time = std::time(0);
		std::tm* now = std::localtime(&time);

		std::cout << "\nDo you want to create a request? Y/N\n";
		if (_getch() == 'y')
		{
			std::cout << "Please, enter the destination point\n";
			std::cin >> des;
			std::cout << "Please, enter the surname and inits w/o spacebar (ex: IvanovI.I.)\n";
			std::cin >> pass;
			std::cout << "Please, enter the flight date\n";
			std::cin >> d >> c >> m >> c >> y;
			num = std::rand() % 450 + 70;
			if (y >= (now->tm_year + 1900))
			{
				if (y % 4 == 0)
					leap = true;
				if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
					long_month = true;
				if (y == (now->tm_year + 1900))
				{
					if (m >= (now->tm_mon + 1) && m < 13)
					{
						if (m == 2)
						{
							if (d >= now->tm_mday && d < (28 + leap))
							{
								tree.Insert(des, num, pass, d, m, y);
							}
						}
						else
						{
							if (m == (now->tm_mon + 1))
							{
								if (d >= now->tm_mday && d < (31 + long_month))
								{
									tree.Insert(des, num, pass, d, m, y);
								}
							}
							else
							{
								if (d > 0 && d < (31 + long_month))
								{
									tree.Insert(des, num, pass, d, m, y);
								}
							}
						}
					}
				}
				else
				{
					if (m > 0 && m < 13)
					{
						if (m == 2)
						{
							if (d > 0 && d < (28 + leap))
							{
								tree.Insert(des, num, pass, d, m, y);
							}
						}
						else
						{
							if (d > 0 && d < (31 + long_month))
							{
								tree.Insert(des, num, pass, d, m, y);
							}
						}
					}
				}
			}
			system("cls");
		}
		else
			system("cls");
	}

	void DeleteRequest(list& tree)
	{
		char c;
		std::string des, pass;
		int num, d, m, y;
		std::cout << "\nDo you want to delete certain request? Y/N\n";
		if (_getch() == 'y')
		{
			std::cout << "Please, enter the destination point\n";
			std::cin >> des;
			std::cout << "Please, enter the surname and inits !w/o! spacebar (ex: IvanovI.I.)\n";
			std::cin >> pass;
			std::cout << "Please, enter the flight number\n";
			std::cin >> num;
			std::cout << "Please, enter the flight date\n";
			std::cin >> d >> c >> m >> c >> y;
			tree.DelSuitable(num, pass, des, d, m, y);
		}
		else
			system("cls");
	}

	void DeleteFlight(list& tree)
	{
		char c;
		int num, d, m, y;
		std::cout << "\nDo you want to delete certain flight? Y/N\n";
		if (_getch() == 'y')
		{
			std::cout << "Please, enter the flight number\n";
			std::cin >> num;
			std::cout << "Please, enter the flight date\n";
			std::cin >> d >> c >> m >> c >> y;
			tree.DelSuitable(num, "\n", "\n", d, m, y);
		}
		else
			system("cls");
	}

	void ClearRequests(list& tree)
	{
		std::cout << "\nDo you want to delete all requests? Y/N\n";
		if (_getch() == 'y')
		{
			tree.~list();
			system("cls");
		}
		else
			system("cls");
	}

	void ShowRequests(list& tree)
	{
		std::cout << "\nDo you want to see all requests? Y/N\n";
		if (_getch() == 'y')
		{
			tree.output();
		}
		else
			system("cls");
	}
};

int main(int argc, char** argv)
{
	std::srand(std::time(0));
	std::string filename;
	std::string des, pass;
	int num, d, m, y;
	char c;
	list tree;
	Interface call;

	std::cout << "Welcome to the request editor\n";
	if (argc < 2)
	{
		std::cout << "\nPlease, enter the input fime name (ex: in.txt)\n";
		std::getline(std::cin, filename);
	}
	else
	{
		filename = argv[1];
	}
	std::ifstream input(filename);

	if (input.is_open())
	{
		while (!input.eof())
		{
			input >> des >> num >> pass >> d >> c >> m >> c >> y;
			if (num > 70 && num < 450)
				tree.Insert(des, num, pass, d, m, y);
		}
	}
	else
		std::cout << "Warning! Input file is damaged/does not exist\n";

point:
	std::cout <<
		"Tap:\n 1 to Show all requests\n 2 to Delete all requests\n 3 to Delete flight\n 4 to Add request\n 5 to Delete request\n Esc to exit\n";
	switch (_getch())
	{
	case '1': call.ShowRequests(tree);
		goto point;
	case '2': call.ClearRequests(tree);
		goto point;
	case '3': call.DeleteFlight(tree);
		goto point;
	case '4': call.AddRequest(tree);
		goto point;
	case '5': call.DeleteRequest(tree);
		goto point;
	case 27: system("cls");
		exit(7);
	default: system("cls");
		goto point;
	}
}
