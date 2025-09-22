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
int nw_octec1, nw_octet2, nw_octet3, nw_octet4;
string nw_octet1_b, nw_octet2_b, nw_octet3_b, nw_octet4_b;
list<int*> mask_octets[4];
int mask_octet1, mask_octet2, mask_octet3, mask_octet4;
string mask_octet1_b, mask_octet2_b, mask_octet3_b, mask_octet4_b;
int total_hosts, usable_hosts, host_bits;

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
	int number = 0;
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

// network_address_calculator function calculates the network address.
string network_address_calculator(){
	return "Invalid";
	}


// mask_calculator function calculates the network mask.
string mask_calculator(int msk){
	
	string binary = "00000000000000000000000000000000";


	for (int x = 0; x < msk; x++) {
		binary[x] = '1';

	}
	
	mask_octet1_b = binary.substr(0, 8);
	mask_octet2_b = binary.substr(8, 8);
	mask_octet3_b = binary.substr(16, 8);
	mask_octet4_b = binary.substr(24, 8);
	
	mask_octet1 = binary_to_int(mask_octet1_b);
	mask_octet2 = binary_to_int(mask_octet2_b);
	mask_octet3 = binary_to_int(mask_octet3_b);
	mask_octet4 = binary_to_int(mask_octet4_b);

	return binary;
	
}

// host_bits_calculator function calculates the host bits.
int host_bits_calculator(string msk1, string msk2, string msk3, string msk4){

	int bits = 0;

	for (int x = 0; x < 8; x++){
		if (msk1[x] == '0'){
			bits++;
		}

	}

	for (int x = 0; x < 8; x++){
		if (msk2[x] == '0'){
			bits++;
		}

	}

	for (int x = 0; x < 8; x++){
		if (msk3[x] == '0'){
			bits++;
		}

	}

	for (int x = 0; x < 8; x++){
		if (msk4[x] == '0'){
			bits++;
		}



	}

	return bits;

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
		octet2_b = int_to_binary(octet2);
		octet3_b = int_to_binary(octet3);
		octet4_b = int_to_binary(octet4);

		mask_octet1 = binary_to_int(mask_octet1_b);
		mask_octet2 = binary_to_int(mask_octet2_b);
		mask_octet3 = binary_to_int(mask_octet3_b);
		mask_octet4 = binary_to_int(mask_octet4_b);

		string a = mask_calculator(mask);	
	
		host_bits = host_bits_calculator(mask_octet1_b, mask_octet2_b, mask_octet3_b, mask_octet4_b);
		usable_hosts = pow(2, host_bits) - 2;
		total_hosts = pow(2, host_bits);

		cout << "\nIP Address: " << octet1 << '.' << octet2 << '.' << octet3 << '.' << octet4;
		cout << "\nNetwork Address: ";
		cout << "\nUsable Host IP Range: ";
		cout << "\nBroadcast Address: ";
		cout << "\nTotal Number of Hosts: " << total_hosts;
		cout << "\nNumber of Usable Hosts: " << usable_hosts;
		cout << "\nSubnet Mask: " << mask_octet1 << '.' << mask_octet2 << '.' << mask_octet3 << '.' << mask_octet4;
		cout << "\nWildcard Mask: ";
		cout << "\nBinary Subnet Mask: " << mask_octet1_b << '.' << mask_octet2_b << '.' << mask_octet3_b << '.' << mask_octet4_b;
		cout << "\nIP Class: ";
		cout << "\nCIDR Notation: /" << mask;
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
		cout << '\n';	
		
	}	
