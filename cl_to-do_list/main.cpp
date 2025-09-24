#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <limits>

using namespace std;

// read_tasks function outputs all of the tasks in the list.
void read_tasks(){
	ifstream file("tasks.txt");
	
	string task;
	int number = 1;
	cout << "Tasks" << endl;	
	
	// Goes through each tasks and outputs it.
	while(getline(file, task)){
		cout << '(' << number << ") " <<  task << endl;
		number++;

	}

	file.close();
	}

// new_task function creates a new task.
void new_task(){
	string task;

	// Asks for input for new task.
	cout << "New task: ";
	getline(cin, task);
		
	ofstream file("tasks.txt", ios::app);
	
	// Appends a new task to the end of the list.
	file << task << endl;
	
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	
	file.close();

	}

// delete_task function deletes a specified task.
void delete_task(){
	vector<string> tasks;
	int number;
	
	// Asks for task number and validates it.
	cout << "Delete task: ";
	while(!(cin >> number)){
		cout << "Invalid task" << endl;
		
		cout << "Delete task: ";

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	ifstream file("tasks.txt");
	
	string task;
	
	// Goes through each task and appends it to a vector.
	while(getline(file, task)){
		tasks.push_back(task); 
	}
	
	// Deletes the specified task from the vector.
	tasks.erase(tasks.begin() + (number - 1));

	file.close();
	
	// Clears the text file.
	ofstream file2("tasks.txt");

	file2.close();

	// Adds tasks back to the text file.
	ofstream file3("tasks.txt", ios::app);
	for (int x = 0; x < tasks.size(); x++){
		file3 << tasks[x] << endl;	
	
	}

	file3.close();
	}

// clear_tasks function deletes all of the tasks.
void clear_tasks(){
	ofstream file("tasks.txt");
	file.close();

	}


int main(){
	char user;
	bool running, validation;

	read_tasks();
	cout << endl;

	while(!validation){
	cout << "User: ";

	// Asks for input and validates the input.
	while(!(cin >> user)){
		cout << "\nInvalid operator. Type 'h' for help." << endl;
		cout << "User: ";
	
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	}
	
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << endl;

	// Checks if the input is a valid operator.
	switch(user){
		case 'n':
			new_task();
			break;

		case 'd':
			delete_task();
			break;

		case 'r':
			read_tasks();
			break;
		
		case 'c':
			clear_tasks();
			break;

		// Outputs help information.
		case 'h':
			cout << "'n' - New task" << endl;
			cout << "'d' = Delete task" << endl;
			cout << "'r' - Read tasks" << endl;
			cout << "'h' - Get help" << endl;
			cout << "'q' - Quit program" << endl;
			break;
		
		// Quits the program.
		case 'q':
			validation = true;
			running = false;
			break;

		default:
			cout << "Invalid operator. Type 'h' for help." << endl;
			break;
	}

	cout << endl;


	}
	
	return -1;

}
