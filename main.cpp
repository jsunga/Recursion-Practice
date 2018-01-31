#include <iostream>
#include <string>

using namespace std;

//Problem 1
bool isPalindrome(const string& input) {
	if(input.size() == 1) //when string is only one letter then return true
		return true;
	if(input.size() == 2) { //when string is size 2 then for it to be a palindrome, first letter must be the same as the second letter
		return input[0] == input[1];
	} else { //compare first letter to last letter then remove front letter and last letter and repeat function
	return (input[0] == input[input.size()-1]) && isPalindrome(input.substr(1, input.size()-2)); 
	}
}

//Problem 2
int digitSum(int input) {
	if (input > 0) {
    	int lsb = input % 10; //takes the LSB of the input
    	return lsb + digitSum(input / 10); //adds the LSB to the remaining bits in each call
   }
   return 0;
}

//Problem 3
int waysToClimb(int numStairs) {
/*
one can reach the nth stair from either (n-1)th stair or from
(n-2)th stair. then the number of ways to climb n stairs is
ways(n-1) + ways(n-2).
*/
	if (numStairs <= 3) {
		return numStairs;
	} else {
		return waysToClimb(numStairs - 1) + waysToClimb(numStairs - 2);
	}
}



int main() {
	cout << "*****Testing Functions*****" << endl << endl;
	
	//Problem 1
	cout << "Problem 1" << endl << endl;
	cout << "Enter a string: ";
	string s;
	cin >> s;
	if(isPalindrome(s)) {
		cout << s << " is a palindrome" << endl << endl;
	} else {
		cout << s << " is not a palindrome" << endl << endl;
	}
	
	//Problem 2
	cout << "Problem 2" << endl << endl;
	cout << "Integers		Sum" << endl;
	cout << "123" << "			" << digitSum(123) << endl;
	cout << "1234" << "			" << digitSum(1234) << endl;
	cout << "12345" << "			" << digitSum(12345) << endl;
	cout << "123456" << "			" << digitSum(123456) << endl;
	cout << "1234567" << "			" << digitSum(1234567) << endl;
	cout << "12345678" << "		" << digitSum(12345678) << endl;
	cout << "123456789" << "		" << digitSum(123456789) << endl << endl; 
	
	//Problem 3
	cout << "Problem 3" << endl << endl;
	cout << "Number of stairs	Total ways to climb" << endl;
	int x = 1;
	while (x != 11) {
		cout << x << "			" << waysToClimb(x) << endl;
		x++;
	}
	return 0;	
}
