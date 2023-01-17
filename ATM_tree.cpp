#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>


class ATM_Node
{
public:
	ATM_Node(std::string cl, std::string un, std::string pw, int64_t acc_num, int64_t acc_bal, int64_t ph_num,
	         int64_t ph_bal)
		: client(cl),
		  username(un),
		  password(pw),
		  account_number(acc_num),
		  account_balance(acc_bal),
		  phone_number(ph_num),
		  phone_balance(ph_bal)
	{
	}

	std::string client, username, password;
	int64_t account_number, account_balance, phone_number, phone_balance;

	ATM_Node* Left = nullptr;
	ATM_Node* Right = nullptr;
};

class ATM_Tree
{
public:
	ATM_Tree()
		: Root(0)
	{
	}

	void Manager()
	{
		std::string username;
		std::cout <<
			"1 to open the client list\n 2 - add new client\n3 - delete client\n4 - Edit the client data\nESC to exit\n";
	point1:
		switch (_getch())
		{
		case '1': PrintTree(Root);
			goto point1;
		case '2': AddUser();
			goto point1;
		case '3': std::cout << "Please, enter the username whose data you want to delete\n";
			DeleteUser(Root, username);
			goto point1;
		case '4': std::cout << "Please, enter the username whose data you want to change\n";
			Editor(Root, username);
			goto point1;
		case 27: return;
		default: goto point1;
		}
	}

	void Client(std::string un, std::string pw)
	{
		char y = 'N';
		ATM_Node* node = GetUserNode(un, pw);
		if (node->username != un || node->password != pw)
		{
			std::cout << "Wrong login/password\n";
			return;
		}
		std::cout << "Hello " << node->client << " what you want to do?\n";
		while (y == 'N')
		{
			std::cout << "1 - Check your balance\n2 - Send money\n3 - Pay for communication\nEsc - Exit\n";
			switch (_getch())
			{
			case '1': ShowBalance(node);
				break;
			case '2': MoneyTransfer(node);
				break;
			case '3': PhoneFee(node);
				break;
			case '27': break;
			}
			std::cout << "Do you want to exit?\nY/N\n";
			std::cin >> y;
		}
	}


	void Insert(std::string cl, std::string un, std::string pw, int64_t acc_num, int64_t acc_bal, int64_t ph_num,
	            int64_t ph_bal)
	{
		ATM_Node** cur = &Root;
		while (*cur)
		{
			ATM_Node& node = **cur;
			if (acc_num < node.account_number)
			{
				cur = &node.Left;
			}
			else
			{
				cur = &node.Right;
			}
		}
		*cur = new ATM_Node(cl, un, pw, acc_num, acc_bal, ph_num, ph_bal);
	}

private:
	ATM_Node* Root;

	void ShowBalance(ATM_Node*& node)
	{
		if (node)
			std::cout << "Your account balance is " << node->account_balance << '\n' << "Your phone balance is " << node
				->phone_balance << "\n\n\n";
	}

	void MoneyTransfer(ATM_Node*& node)
	{
		ATM_Node* node1 = nullptr;
		int64_t summa, account_number;
		std::cout << "Enter the recipient's account\n";
		std::cin >> account_number;
		std::cout << "Enter the transfer amount\n";
		std::cin >> summa;
		node1 = MoneyTransferNode(node, account_number);
		if (node->account_balance >= summa)
		{
			node->account_balance = node->account_balance - summa;
			node1->account_balance = node1->account_balance + summa;
		}
		else
			std::cout << "Not enough money\n";
		return;
	}

	void PhoneFee(ATM_Node*& node)
	{
		std::cout <<
			"1 - Recharge your phone balance\n2 - Recharge from your account balance\n3 - Recharge from your phone balance\nEsc-exit\n";
		switch (_getch())
		{
		case '1': OwnPhoneBalance(node);
			break;
		case '2': FromAccountBalance(node);
			break;
		case '3': FromPhoneBalance(node);
			break;
		case '27': break;
		}
		return;
	}

	void OwnPhoneBalance(ATM_Node*& node)
	{
		int64_t summa;
		std::cout << "Enter the transfer amount\n";
		std::cin >> summa;
		node->account_balance = node->account_balance - summa;
		node->phone_balance = node->phone_balance + summa;
	}

	void FromAccountBalance(ATM_Node*& node)
	{
		ATM_Node* node1 = Root;
		int64_t summa;
		int64_t phone_number;
		std::cout << "Enter the transfer amount\n";
		std::cin >> summa;
		std::cout << "Enter the recipient's phone number\n";
		std::cin >> phone_number;

		node1 = FromAccountBalanceNode(node1, phone_number);
		node->account_balance = node->account_balance - summa;
		node1->phone_balance = node1->phone_balance + summa;
	}

	void FromPhoneBalance(ATM_Node*& node)
	{
		ATM_Node* node1 = Root;
		int64_t summa;
		int64_t phone_number;
		std::cout << "Enter the transfer amount\n";
		std::cin >> summa;
		std::cout << "Enter the recipient's phone number\n";
		std::cin >> phone_number;

		node1 = FromAccountBalanceNode(node1, phone_number);
		node->account_balance = node->phone_balance - summa;
		node1->phone_balance = node1->phone_balance + summa;
	}


	ATM_Node* FromAccountBalanceNode(ATM_Node*& node, int64_t phone_number)
	{
		if (node)
		{
			if (phone_number != node->phone_number)
			{
				FromAccountBalanceNode(node->Left, phone_number);
				FromAccountBalanceNode(node->Right, phone_number);
			}
			else
				return (node);
		}
	}

	ATM_Node* MoneyTransferNode(ATM_Node*& node, int64_t account_number)
	{
		ATM_Node** cur = &Root;
		while (*cur)
		{
			ATM_Node& node = **cur;
			if (account_number != node.account_number)
			{
				cur = &node.Left;
				cur = &node.Right;
			}
			else
			{
				return (*cur);
				break;
			}
		}
	}

	ATM_Node* GetUserNode(std::string un, std::string pw)
	{
		ATM_Node** cur = &Root;
		while (*cur)
		{
			ATM_Node& node = **cur;
			if (un != node.username || pw != node.password)
			{
				cur = &node.Left;
				cur = &node.Right;
			}
			else
			{
				return (*cur);
				break;
			}
		}
	}

	static void PrintTree(ATM_Node*& node)
	{
		if (node)
		{
			PrintTree(node->Left);
			std::cout << node->client << " " << node->username << " " << node->password << " " << node->account_number
				<< " " << node->account_balance << " " << node->phone_number << " " << node->phone_balance << "\n";
			PrintTree(node->Right);
		}
	}

	void AddUser()
	{
		std::string client, username, password;
		int64_t account_number, account_balance, phone_number, phone_balance;
		std::cin >> client >> username >> password >> account_number >> account_balance >> phone_number >>
			phone_balance;
		std::cout << "vvedite";
		ATM_Node** place = &Root;
		while (*place)
		{
			ATM_Node& node = **place;
			if (account_number < node.account_number)
			{
				place = &node.Left;
			}
			else
			{
				place = &node.Right;
			}
		}
		*place = new ATM_Node(client, username, password, account_number, account_balance, phone_number, phone_balance);
	}

	static void DeleteUser(ATM_Node*& node, std::string un)
	{
		if (node)
		{
			DeleteUser(node->Left, un);
			DeleteUser(node->Right, un);
			if (node->username == un)
			{
				ATM_Node* help = node;
				if (help->Right == NULL)
					node = help->Left;
				else if (help->Left == NULL)
					node = help->Right;
				else
					MoveNodeToLeaf(help->Left, help);
				delete help;
			}
		}
	}

	static void MoveNodeToLeaf(ATM_Node*& R, ATM_Node*& R1)
	{
		if (R->Right)
			MoveNodeToLeaf(R->Right, R1);
		else
		{
			R1->client = R->client;
			R1->username = R->username;
			R1->password = R->password;
			R1->account_number = R->account_number;
			R1->account_balance = R->account_balance;
			R1->phone_number = R->phone_number;
			R1->phone_balance = R->phone_balance;
			R1 = R;
			R = R->Left;
		}
	}

	void Editor(ATM_Node*& node, std::string un)
	{
		std::string new_string_data;
		int64_t new_int_data;
		if (node)
		{
			Editor(node->Left, un);
			Editor(node->Right, un);
			if (node->username == un)
			{
				std::cout <<
					"1 to change client name\n2 - username\n3 - password\n4 - account number\n5 - account balance\n6 - phone number\n7 - phone balane\nESC - go back\n";
			point2:
				switch (_getch())
				{
				case '1': std::cout << "Old client name: " << node->client << "\nPlease, enter the new client name: ";
					std::cin >> new_string_data;
					node->client = new_string_data;
					new_string_data.clear();
					goto point2;
				case '2': std::cout << "Old username: " << node->username << "\nPlease, enter the new username: ";
					std::cin >> new_string_data;
					node->username = new_string_data;
					new_string_data.clear();
					goto point2;
				case '3': std::cout << "Old password data: " << node->password << "\nPlease, enter the new password: ";
					std::cin >> new_string_data;
					node->password = new_string_data;
					new_string_data.clear();
					goto point2;
				case '4': std::cout << "Old account number: " << node->account_number <<
						"\nPlease, enter the new account number: ";
					std::cin >> new_int_data;
					node->account_number = new_int_data;
					new_int_data = NULL;
					goto point2;
				case '5': std::cout << "Current balance: " << node->account_balance <<
						"\nPlease, enter the new balance: ";
					std::cin >> new_int_data;
					node->account_balance = new_int_data;
					new_int_data = NULL;
					goto point2;
				case '6': std::cout << "Old phone number: " << node->phone_number <<
						"\nPlease, enter the new phone number: ";
					std::cin >> new_int_data;
					node->phone_number = new_int_data;
					new_int_data = NULL;
					goto point2;
				case '7': std::cout << "Current phone balance: " << node->phone_balance <<
						"\nPlease, enter the new phone balance: ";
					std::cin >> new_int_data;
					node->phone_balance = new_int_data;
					new_int_data = NULL;
					goto point2;
				case 27: Manager();
				default: goto point2;
				}
			}
		}
	}
};


void main()
{
	char Ans = 'Y';
	int k = 0, k1 = 0;
	std::string filename = "testcur.txt", cl, un, pw;
	int64_t acc_num, acc_bal, ph_num, ph_bal;
	std::string manager_username = "admin";
	std::string manager_password = "0000";
	std::string username, password;
	ATM_Tree call;

	if (k1 == 0)
	{
		//std::getline(std::cin, filename);
		std::ifstream input(filename);
		system("cls");

		if (input.is_open())
		{
			while (!input.eof())
			{
				input >> cl >> un >> pw >> acc_num >> acc_bal >> ph_num >> ph_bal;
				call.Insert(cl, un, pw, acc_num, acc_bal, ph_num, ph_bal);
			}
		}
		else
			std::cout << "Warning! Input file is damaged/does not exist\n";
		k1 = k1 + 1;
	}

	std::cout << "ATM_Core v0.1\n\n";
	while (Ans == 'Y')
	{
		k = k + 1;
		if (k > 1)
		{
			std::cout << "Do you want to continue working with the ATM?\nY/N\n";
			std::cin >> Ans;
			if (Ans != 'Y')
				exit(0);
		}
		std::cout << "Please, enter the username:\n";
		std::cin >> username;
		std::cout << "Please, enter the password:\n";
		std::cin >> password;
		if (username == manager_username && password == manager_password)
			call.Manager();
		else
		{
			call.Client(username, password);
		}
	}
}
