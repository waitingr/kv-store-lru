#include<iostream>
#include<unordered_map>
#include<string>
#include<sstream>
#include <windows.h>

using namespace std;

int main()
{
	unordered_map<string, int> input;
	string command = "NULL", key = "NULL",line="NULL";
	int tom = 0;

	while (1)
	{
		cout << "请输入命令:"<<endl << ">>";
		getline(cin, line);
		if (line.empty()) continue;

		stringstream ss_anylysis(line);
		ss_anylysis >> command;

		if (command == "put")
		{
			ss_anylysis >> key;
			ss_anylysis >> tom;
			input[key] = tom;
		}
		else if (command == "del")
		{
			ss_anylysis >> key;
			auto it = input.find(key);
			if (it != input.end())
			{
				input.erase(key);
			}
			else
			{
				cout << "键未找到" << endl;
			}
		}
		else if (command == "get")
		{
			ss_anylysis >> key;
			auto it = input.find(key);
			if (it != input.end())
			{
				cout << it->second << endl;
			}
			else
			{
				cout << "键未找到"<<endl;
			}
		}
		else
		{
			cout << "命令输入错误，请重新输入";
			Sleep(2000);
			system("cls");
		}
	}
}