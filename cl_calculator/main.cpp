#include <iostream>
#include <limits>
using namespace std;
int main(){
	float num1, num2, answer;
	bool running = true;
	bool validation;
	char op;
	while (running){
		validation = false;
		
		cout << "\nNumber 1: ";
		while (!(cin >> num1)){
			cout << "\nInvalid Number. Try again.";
			cout << "\nNumber 1: ";
			cin.clear();
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');

		}

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		while (!validation){

		cout << "\nOperator: ";
			while (!(cin >> op)){
			
				cout << "\nInvalid Operator. Try again.";
				cout << "\nOperator: ";
				cin.clear();
				cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		}
			switch (op){
				case '+':
					validation = true;
					break;
				
				case '-':
					validation = true;
					break;

				case '*':
					validation = true;
					break;

				case '/':
					validation = true;
					break;

				case '%':
					validation = true;
					break;
				
				case '=':
					validation = true;
					break;

				case 'h':
					cout << "Operators\n";
					cout << "\'+\' - Addition\n";
					cout << "\'-\' - Subtraction\n";
					cout << "\'*\' - Multiplication\n";
					cout << "\'/\' - Division\n";
					cout << "\'%\' - Mudulo\n";
					cout << "\'=\' - Equals\n";
					cout << "\'h\' - Help\n";
					cout << "\'q\' - Quit\n";
					break;

				case 'q':
					running = false;
					
					break;

				default:
					cout << "\nInvalid Operator. Try again.";
			}

			if (!running){
				break;
			}



		}
		if (!running){
			break;
		}
		std::cout << "\nNumber 2: ";
		while (!(cin >> num2)){

			cout << "\nInvalid Number. Try again.";
			cout << "\nNumber 2: ";
			cin.clear();
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		}

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\n";
		switch (op){
			case '+':
				answer = num1 + num2;
				cout << num1 << " + " << num2 << " = "  << answer << "\n";
				break;

			case '-':
				answer = num1 - num2;
				cout << num1 << " - " << num2 << " = " << answer << "\n";
				break;

			case '*':
				answer = num1 * num2;
				cout << num1 << " * " << num2 << " = " << answer << "\n";
				break;

			case '/':
				answer = num1 / num2;
				cout << num1 << " / " << num2 << " = " << answer << "\n";
				break;

			case '%':
				answer = int(num1) % int(num2);
				cout << num1 << " % " << num2 << " = " << answer << "\n";
				break;

			case '=':
				if (num1 == num2){
					cout << num1 << " == " << num2 << "\n";
					break;
				}
				else {
					cout << num1 << " != " << num2 << "\n";
					break;


                                      }
		}

		
	}
}
