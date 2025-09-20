#include <cstdlib>
#include <iostream>
#include <limits>
#include <ctime>

using namespace std;

int faces;

int main(){
	
	cout << "Faces: ";

	while (!(cin >> faces)){
		cout << "\nInvalid integer. Try again.";
		cout << "\nFaces: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	
	srand(time(0));
	cout << "\nLanded on " << rand() % faces + 1 << '\n';
	return -1;
	
	

}
