#include <iostream>
#include <string>
#include <cmath>
#include <math.h>


using namespace std; 

bool all_digits(const  string &str)
{
	return str.find_first_not_of("0123456789") ==  string::npos;
}

bool all_lowercase(const  string &str)
{
	return str.find_first_not_of("abcdefghijklmnopqrstuvwxyz") ==  string::npos;
}

bool all_uppercase(const  string &str)
{
	return str.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ") ==  string::npos;
}

bool HasDigit(string str)
{
return( any_of(str.begin(),  str.end(), :: isdigit));
}

bool HasLowerLetter(string str)
{
return( any_of(str.begin(),  str.end(), ::islower));
}

bool HasUpperLetter(string str)
{
return( any_of(str.begin(),  str.end(), ::isupper));
}

bool HasSpecialCharacters(const  string &str)
{
	return str.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789") !=  string::npos;
}



int main(int argc, char *argv[]) {
	string password;
	const int NUM = 10;
	const int ALPH = 26;
	const int SYM = 32;
	long long combinations;
	long long bits;
	int alphSize;
	
	cout << "Please enter the password: ";
	cin >> password;
if(all_digits(password)){
	combinations = pow(NUM, password.length());
	bits = floor(log2(combinations));
	cout << "There are " << combinations << " combinations" << endl;
	cout << "That is equivalent to a key of " << bits << " bits" << endl;
	return 0;
}

else if(all_lowercase(password) || all_uppercase(password)){
		combinations = pow(ALPH, password.length());
		bits = floor(log2(combinations));
		cout << "There are " << combinations << " combinations" << endl;
		cout << "That is equivalent to a key of " << bits << " bits" << endl;
		return 0;
}

else{
	if(HasDigit(password)){
		alphSize += NUM;
	}
	if(HasLowerLetter(password)){
		alphSize += ALPH;
	}
	if(HasUpperLetter(password)){
		alphSize += ALPH;
	}
	if(HasSpecialCharacters(password)){
		alphSize += SYM;
	}
	
	combinations = pow(alphSize, password.length());
	bits = floor(log2(combinations));
	cout << "There are " << combinations << " combinations" << endl;
	cout << "That is equivalent to a key of " << bits << " bits" << endl;
	return 0;
}

	
}

