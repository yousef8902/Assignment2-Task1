#include <iostream>
#include <cctype>
#include <string>
using namespace std;
// This function takes the message from the user and check if it's valid message or not 
string message(string user_need) {
	string new_message = "";
	while (true) {
		// user message
		cout << "Please enter the message you want to "<< user_need <<" : ";
		string user_message;
		// use getline to read the entire line including spaces
		getline(cin, user_message);
		// remove spaces and numbers from user_message 
		for (char a : user_message) {
			if (isalpha(a)) {
				//  convert all letters to small letters
				a = char(tolower(a));
				new_message += a;
			}
			else {
				continue;
			}
		}
		//  check if user_message has no letters at all
		if (new_message.length() == 0) {
			cout << "Inalid input your message must have english letters" << endl;
			continue;
		}
		else {
			break;
		}
	}
	// return the message after we checked it's valid
	return new_message;
}

int value_of_the_key() {
	int key;
	while (true) {
		// Asking user if he wants to use default value for key or he wants to use his own  key value  
		cout << "The default key value is 3." << endl;
		cout << "Do you want to use default key value?" << endl;
		cout << "1) Yes" << endl;
		cout << "2) No, I will enter the key value that i want to" << endl;
		cout << "Please enter your choice between 1-2: ";
		string user_choice;
		getline(cin, user_choice);
		// delete unnecessary spaces if user inputs them
		string user_choice1 = "";
		for (char a : user_choice) {
			if (a == ' ') {
				continue;
			}
			else {
				user_choice1 += a;
			}
		}
		// check if user input consists only of digits
		bool valid_input = true;
		for (char a : user_choice1) {
			if (!isdigit(a))
			{
				valid_input = false;
				break;
			}
		}
		// if user input doesn't consist only of digits  
		if (!valid_input) {
			cout << "Invalid input. Please only choose numbers" << endl;
			continue;
		}
		// convert user choice to integer after we cheked it only consists of digits
		int choice = stoi(user_choice1);
		// using the default key value if user chooses to use it 
		if (choice == 1) {
			key = 3;
			break;
		}
		// taling key value from the user if he wants to use his own key value after checking it's valid
		else if (choice == 2) {
			while (true) {
				cout << "Please enter a positive key value you want to use: ";
				string key_value;
				// use getline to read the entire line including spaces
				getline(cin, key_value);
				// delete unnecessary spaces if user inputs them
				string key_value1 = "";
				for (char a : key_value) {
					if (a == ' ') {
						continue;
					}
					else {
						key_value1 += a;
					}
				}
				// check if user input consists only of digits
				bool valid_input = true;
				for (char a : key_value1) {
					if (!isdigit(a))
					{
						valid_input = false;
						break;
					}
				}
				// if user input doesn't consist only of digits  
				if (!valid_input) {
					cout << "Invalid input. Please only enter choose numbers" << endl;
					continue;
				}
				// convert user choice to integer after chekeing it only consists of digits 
				int chosen_value = stoi(key_value1);
				if (chosen_value > 0) {
					key = chosen_value;
					break;
				}
				else {
					cout << "invalid Choice." << endl;
					continue;
				}
			}
			break;
		}
		else {
			cout << "Invalid Choice"<< endl;
			continue;
		}

	}
	return key;
}
void railFence_cipher(){
	// Putting user message is a variable after checkeing it's valid
	string message_letters = message("cipher");
	// puting user choice for key value in a variable after checkeing it's valid
	int rows = value_of_the_key();
	int columns = message_letters.length();
	string ciphered_messsage = "";
	// if user chosses the key value equals 1
	if (rows == 1) {
		for (int m = 0; m < columns; m++) {
			cout << message_letters[m] << " ";
		}
		cout << endl;
		cout << "The ciphred messsage is: " << message_letters << endl;
		
	}
	// if user chooses key value greater than 1
	else {
		// make 2d array using pointers because rows and columns of the cipher is diffreent according to 
		// number of letters in user message and key value
		char** arr = new(char* [rows]);
		for (int i = 0; i < rows; i++) {
			arr[i] = new(char[columns]);
		}
		// make all elements in the 2d array is '.' at first   
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				arr[i][j] = '.';
			}
		}
		// puting the letters of the message in the 2d array in a zigzag shape
		// this variable represent index of the row 
		int i = 0;
		// this variable represents if i go down in the zigzag shape  
		bool isDown = true;
		for (int k = 0; k < columns; k++) {
			if (i == 0) {
				isDown = true;
			}
			// when i = last endex in the 2d array is down becom false and then i go up in the zigzag shape
			else if (i == rows - 1) {
				isDown = false;
			}
			arr[i][k] = message_letters[k];
			if (isDown) {
				i++;
			}
			else {
				i--;
			}
		}
		// printing the 2d array after we add usermessage's letters to it 
		for (int k = 0; k < rows; k++) {
			for (int l = 0; l < columns; l++) {
				cout << arr[k][l] << " ";
			}
			cout << endl;
		}
		// cipher the message by putting the letters  starting from  first row till last one 
		for (int k = 0; k < rows; k++) {
			for (int l = 0; l < columns; l++) {
				if (arr[k][l] != '.') {
					ciphered_messsage += arr[k][l];
				}
			}
		}
		cout << "The ciphered message is : " << ciphered_messsage << endl;
		// delete the 2d pointer array after we used it to free memory allocation 
		for (int i = 0; i < rows; i++) {
			delete[] arr[i];
		}
		delete[]arr;
	}

}
void railFence_decipher() {
	// Putting user message is a variable after checkeing it's valid
	string message_letters = message("decipher");
	// puting user choice for key value in a variable after checkeing it's valid
	int rows = value_of_the_key();
	int columns = message_letters.length();
	string deciphered_message = "";
	// if user chosses the key value equals 1
	if (rows == 1) {
		for (int m = 0; m < columns; m++) {
			cout << message_letters[m] << " ";
		}
		cout << endl;
		cout << "The decrypted message is: " << message_letters << endl;
		
	}
	// if user chooses key value greater than 1
	else {
		// make 2d array using pointers because rows and columns of the decipher is diffreent according to 
		// number of letters in user message and key value
		char** arr = new(char* [rows]);
		for (int i = 0; i < rows; i++) {
			arr[i] = new(char[columns]);
		}
		// make all elements in the 2d array is '.' at first 
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				arr[i][j] = '.';
			}
		}
		// this variable represent index of the row
		int i = 0;
		// this variable represents if i go down in the zigzag shape 
		bool isDown = true;
		for (int k = 0; k < columns; k++) {
			if (i == 0) {
				isDown = true;
			}
			// when i = last endex in the 2d array is down becom false and then i go up in the zigzag shape
			else if (i == rows - 1) {
				isDown = false;
			}
			// putting '#' in the elments in the zigzag shape in the 2d array
			arr[i][k] = '#';
			if (isDown) {
				i++;
			}
			else {
				i--;
			}
		}
		// this vaiable represent index of the letter in user message'letters
		int j = 0;
		for (int k = 0; k < rows; k++) {
			for (int l = 0; l < columns; l++) {
				if (arr[k][l] != '.') {
					// changing '#' with message letters starting from fisrt row to last one  
					arr[k][l] = message_letters[j];
					j++;
				}
			}
		}
		//printing the 2d array after we add usermessage's letters to it 
		for (int k = 0; k < rows; k++) {
			for (int l = 0; l < columns; l++) {
				cout << arr[k][l] << " ";
			}
			cout << endl;
		}
		// decipher the message by reading the letters from the zigzag shape 
		i = 0;
		isDown = true;
		for (int k = 0; k < columns; k++) {
			if (i == 0) {
				isDown = true;
			}
			else if (i == rows - 1) {
				isDown = false;
			}
			deciphered_message += arr[i][k];
			if (isDown) {
				i++;
			}
			else {
				i--;
			}
		}
		cout << "The deciphered message is: " << deciphered_message << endl;
		// delete the 2d pointer array after we used it to free memory allocation 
		for (int i = 0; i < rows; i++) {
			delete[] arr[i];
		}
		delete[] arr;
	}
}
int main() {
	while (true) {
		cout << "------------------------------------------------------------------" << endl;
		cout << "Ahln ya user ya habibi." << endl;
		cout << "This program encrypt and decrypt messages using Rail-Fence technique" << endl;
		cout << "1) Cipher a message" << endl;
		cout << "2) Decipher a message" << endl;
		cout << "3) EXIT" << endl;
		cout << "PLease enter your choice between 1-3: ";
		string program_choice;
		getline(cin, program_choice);
		// delete unnecessary spaces if user inputs them
		string program_choice1 = "";
		for (char a : program_choice) {
			if (a == ' ') {
				continue;
			}
			else {
				program_choice1 += a;
			}
		}
		bool valid_input = true;
		for (char a : program_choice1) {
			if (!isdigit(a))
			{
				valid_input = false;
				break;
			}
		}
		// if user input doesn't consist only of digits  
		if (!valid_input) {
			cout << "Invalid input. Please only choose numbers" << endl;
			continue;
		}
		// convert user choice to integer after we cheked it only consists of digits
		int choice2 = stoi(program_choice1);
		if (choice2 == 1) {
			railFence_cipher();
			continue;
		}
		else if (choice2 == 2) {
			railFence_decipher();
			continue;
		}
		else if (choice2 == 3) {
			break;
		}
		else {
			cout << "Invalid Choice" << endl;
		}
	}
	return 0;
}