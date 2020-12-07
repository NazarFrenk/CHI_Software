#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <thread>
#include <sstream> //wistringstream
#include <ctime> //time_t
#include <iomanip> //get_time
#include "my_funcs.h"

struct ToDoItem
{
	std::chrono::time_point<std::chrono::system_clock> timePoint;
	std::string description;
};

struct ToDoList
{
	/* you can change the signature,
	but the item should be passed as cheaper as possible (only ctor, no copy)
	also this function should be thread safe*/
	void addItem(ToDoItem item) {}

	struct NotifierGuard {
		ToDoList& list;
		template<typename F>
		NotifierGuard(ToDoList& list_, F callback)
			: list{ list_ } {
			list.setCallbackNotifier(callback);
		}
		~NotifierGuard() {
			list.detachCallBack();
		}
	};

private:
	/* this function should be thread safe */
	template<typename F>
	void setCallbackNotifier(F callback) {}
	void detachCallBack() {}
};

enum Options {
	Option_Invalid,
	view,
	add,
	quit,
	enter
};

Options resolveOption(std::string input) {
	if (input == "1") return view;
	if (input == "2") return add;
	if (input == "3") return quit;
	if (input == "\0") return enter;
	return Option_Invalid;
}

void myThread() 
{
	//notify functions
};

int main(int argc, char* argv[])
{
	std::string file_name = "TasksList.txt"; //file which consists user's tasks
	bool active = true;
	std::string input;

	ToDoList List; //main list with items

	//TODO - try to read and convert file lines to ToDoItems

	std::thread t(myThread);

	welcome();

	do
	{
		getline(std::cin, input); //read user's command

		switch (resolveOption(input))
		{
		case view: {
			//TODO - show List
			break;
		}
		case add: {
			//create new item
			ToDoItem item;
			//description and date from user input
			std::string description;
			std::string date;
			std::cout << "Describe your task:" << std::endl;
			std::cin >> description;
			std::cout << "Enter target date:" << std::endl;
			//TODO - convertion date
			std::cin >> date;
			//set item description
			item.description = description;
			//add item to list
			List.addItem(item);
			std::ofstream ofs(file_name, std::ofstream::app);
			//TODO - add item to file
			ofs.close();
			std::cout<<"Success!"<<std::endl;
			break;
		}
		case quit: {
			active = false;
			break;
		}
		case enter: {
			//
			break;
		}
		// handles Option_Invalid and any other missing/unmapped cases
		default: {
			std::cout << "Command '" << input << "' doesn't exist" << std::endl;
			break;
		}
		}

	} while (active);

	t.detach();

	return 0;
}