#include <iostream>
#include <string>
#include <cctype>
#include <limits>
#include <list>
#include <cmath>

using namespace std;
bool validation, mistake;
char network_class;
int length, mask, octet1, octet2, octet3, octet4, current_octet;
string address, octet1_s, octet2_s, octet3_s, octet4_s;
string octet1_b, octet2_b, octet3_b, octet4_b;
list<int*> octets = {&octet1, &octet2, &octet3, &octet4};

// class_validation function checks if a character is a valid network class and returns either true or false.
bool class_validation(char class_type){
	switch (class_type) {
		case 'A':
			return true;

		case 'B':
			return true;

		case 'C':
			return true;

		case 'a':
			return true;

		default:
			return false;
	}
}

// int_to_binary function converts an integer to binary and returns a binary string.
string int_to_binary(int number){
	string binary = "";
	int remainder;
	cout << "\n" << number;
	while (number >= 1){
		remainder = number % 2;
		number /= 2;
		binary = to_string(remainder) + binary;
	}
	while (binary.size() < 8){
		binary = "0" + binary;
	}
	return binary;

	}

// binary_to_int function converts binary to an integer and returns an integer.
int binary_to_int(string binary){
	int number;
	int length = binary.size();
	int exponent = 0;
	for (int x = length - 1; x >= 0; x--){
		if (binary[x] == '1'){
		number += pow(2, exponent);
		}

		exponent++;
	}

	return number;
	}

// AND_operation function does a binary AND operation between two bytes.
string AND_operation(string binary1, string binary2){
	string binary = "";
	for (int x = 0; x < 8; x++){
		if ((binary1[x] - '0') && (binary[x] - '0')){
			binary += '1';	
		}
		else {
			binary += '0';
		}


	}
		return binary;
	}


int main(){

	// Validates a user inputted network class.
	validation = false;
	while (!validation){
	cout << "Network Class: ";
	while (!(cin >> network_class)){
		cout << "\nInvalid Class. Enter 'h' for help.";
		cout << "\nNetwork Class: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
	if (class_validation(network_class)){
		validation = true;
	}

	}
	
	// Validates a user inputted subnet mask.
	cout << "\nSubnet Mask: ";

	while (!(cin >> mask)){
		cout << "\nInvalid mask. Try again.";
		cout << "\nSubnet Mask: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}	
	

	// Validates a user inputted IPv4 address.
	validation = false;
	while (!validation){
		cout << "\nIP Address: ";
		cin >> address;
		length = address.size();
		current_octet = 1;
	        octet1_s = "";
		octet2_s = "";
		octet3_s = "";
		octet4_s = "";	
		mistake = false;
		for (int x = 0; x < length; x++){
			if (isdigit(address[x])) {
				
				switch (current_octet){
					case 1:
						octet1_s += address[x];
						break;

					case 2:
						octet2_s += address[x];
						break;
	
					case 3:
						octet3_s += address[x];
						break;

					case 4:
						octet4_s += address[x];
						break;
				}
			}
			else if (address[x] == '.') {
				current_octet++;
				if (current_octet > 4){
					mistake = true;
					break;
				}

			}
			
			else {
				mistake = true;
				break;
	
			}
		}
		if (current_octet != 4){
			mistake = true;

		}
		
		else if (!mistake){
			octet1 = stoi(octet1_s);
			octet2 = stoi(octet2_s);
			octet3 = stoi(octet3_s);
			octet4 = stoi(octet4_s);
			
			for (int *x : octets) {
				if ((*x < 0) || (*x > 255)){
					mistake = true;
				}
			}
			if (!mistake) {
				validation = true;
			}
		}
		if (mistake) {
			cout << "\nInvalid IP Address";
		}
		}

		octet1_b = "";
		octet2_b = "";
		octet3_b = "";
		octet4_b = "";
		
		octet1_b = int_to_binary(octet1);
		octet1 = binary_to_int(octet1_b);

		cout << "\nOctet1 = " << octet1_s;
		cout << "\nOctet2 = " << octet2_s;
		cout << "\nOctet3 = " << octet3_s;
		cout << "\nOctet4 = " << octet4_s;
		cout << "\n" << octet1_b;
		cout << "\n" << octet1;			
		
			
	
		cout << "\nIP Address: ";
		cout << "\nNetwork Address: ";
		cout << "\nUsable Host IP Range: ";
		cout << "\nBroadcast Address: ";
		cout << "\nTotal Number of Hosts: ";
		cout << "\nNumber of Usable Hosts: ";
		cout << "\nSubnet Mask: ";
		cout << "\nWildcard Mask: ";
		cout << "\nBinary Subnet Mask: ";
		cout << "\nIP Class: ";
		cout << "\nCIDR Notation: ";
		cout << "\nIP Type: ";
		cout << "\n";
		cout << "\nShort: ";
		cout << "\nBinary ID: ";
		cout << "\nInteger ID: ";
		cout << "\nHex ID: ";
		cout << "\nin-addr.arpa: ";
		cout << "\nIPv4 Mapped Address: ";
		cout << "\n6to4 Prefix: ";

		cout << "\n";
		cout << "\nAll of the Possible /" << mask << " Networks for ";
	
		
	}	
