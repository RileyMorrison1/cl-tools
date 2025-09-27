#include <iostream>
#include <limits>
#include <cmath>
#include <list>

using namespace std;

// clear_input function clears the current input stream.
void clear_input(){
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

int main(){
	float num1, num2, answer;
	bool running = true;
	bool validation, found;
	char op;
	char operators[] = {'+', '-', '*', '/', '%', '=', '^'};
	
	while (running){
		validation = false;
		
		// Asks for input and validates it, to see if it is an integer.
		cout << endl << "Number 1: ";
		while (!(cin >> num1)){
			cout << endl << "Invalid Number. Try again." << endl;
			cout << "Number 1: ";
			clear_input();

		}

		clear_input();

		// Asks for input and validates it, to see if it is a valid operator.
		while (!validation){

		cout << endl << "Operator: ";
			while (!(cin >> op)){
			
				cout << endl << "Invalid Operator. Try again." << endl;
				cout << "Operator: ";
				clear_input();

		}
			switch (op){
				// If 'h' is inputted, information about operators is outputted.
				case 'h':
					cout << endl << "Operators" << endl;
					cout << "\'+\' - Addition" << endl;
					cout << "\'-\' - Subtraction" << endl;
					cout << "\'*\' - Multiplication" << endl;
					cout << "\'/\' - Division" << endl;
					cout << "\'%\' - Mudulo" << endl;
					cout << "\'=\' - Equals" << endl;
					cout << "\'^\' - Exponent" << endl;
					cout << "\'h\' - Help" << endl;
					cout << "\'q\' - Quit" << endl;
					break;

				// If 'q' is inputted, the application is terminated.
				case 'q':
					running = false;
					cout << endl;
					return -1;


				default:
					found = false;
					for (int x = 0; x < 7; x++){
						if (op == operators[x]){
							found = true;
							break;
						}
					}
		
					if (found){
						validation = true;
						break;
					} 
					else{
						cout << endl << "Invalid Operator. Try again.";
					}
			}

		}
		
		cout << endl << "Number 2: ";
		while (!(cin >> num2)){

			cout << endl << "Invalid Number. Try again.";
			cout << endl << "Number 2: ";
			clear_input();

		}

		clear_input();

		cout << endl;

		// Calculates the operation done on num1 and num2 based on the operator.
		switch (op){
			case '+':
				answer = num1 + num2;
				break;

			case '-':
				answer = num1 - num2;
				break;

			case '*':
				answer = num1 * num2;
				break;

			case '/':
				answer = num1 / num2;
				break;

			case '%':
				answer = int(num1) % int(num2);
				break;

			case '^':
				answer = pow(num1, num2);
				break;

		}
		
		// Outputs the answer.
		if (op == '='){
			if (num1 == num2) {
				cout << num1 << " == " << num2 << endl;
			}
			else{
				cout << num1 << " != " << num2 << endl;
			}
		}
		else{
			cout << num1 << ' ' << op << ' ' << num2 << " = " << answer << endl;
		}		
	}
}
