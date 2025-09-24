#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <limits>

using namespace std;

void read_tasks(){
	ifstream file("tasks.txt");
	
	string task;
	int number = 1;
	cout << "Tasks" << endl;	
	
	while(getline(file, task)){
		cout << '(' << number << ") " <<  task << endl;
		number++;

	}

	file.close();
	}

void new_task(){
	string task;
	cout << "New task: ";
	getline(cin, task);
		
	ofstream file("tasks.txt", ios::app);
	
	file << task << endl;
	
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	
	file.close();

	}

void delete_task(){
	vector<string> tasks;
	int number;
	
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
	
	while(getline(file, task)){
		tasks.push_back(task); 
	}
	
	tasks.erase(tasks.begin() + (number - 1));

	file.close();
	
	ofstream file2("tasks.txt");

	file2.close();

	ofstream file3("tasks.txt", ios::app);
	for (int x = 0; x < tasks.size(); x++){
		file3 << tasks[x] << endl;	
	
	}

	file3.close();
	}

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
	while(!(cin >> user)){
		cout << "\nInvalid operator. Type 'h' for help." << endl;
		cout << "User: ";
	
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	}
	
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << endl;

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

		case 'h':
			cout << "'n' - New task" << endl;
			cout << "'d' = Delete task" << endl;
			cout << "'r' - Read tasks" << endl;
			cout << "'h' - Get help" << endl;
			cout << "'q' - Quit program" << endl;

			break;
		
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
