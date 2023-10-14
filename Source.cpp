//Chad Huntebrinker
//CS 303
//Problem #3

#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main() {
	stack<int> origStack, temp;
	int stackPosition, data, i;
	char userInput;
	vector<int> vector;

	do {
		i = 0;

		//The menu for what the user wants to do with the stack
		cout << "If you want to insert integer into a stack regularly, enter R." << endl;
		cout << "If you want to insert integer at a certain point, enter P." << endl;
		cout << "If you want to quit, enter Q." << endl;
		cin >> userInput;
		userInput = toupper(userInput);

		//If the user entered 'R' or 'P', then the user will enter in what integer number he wants to enter in.
		//If the user entered 'P', then the user will enter where he/she wants to put the number in the stack
		//starting with 0.  If it is 'R', it uses the 'push' command as usual.
		if (userInput == 'R' || userInput == 'P') {
			cout << "Please enter your integer: ";
			cin >> data;
			if (userInput == 'P') {
				cout << "Please enter the position you want to insert your integer (starts at 0): ";
				cin >> stackPosition;

				//The program puts all the data before the desired position in a different stack and then
				//deletes it from the original stack. If it is at the desired position, the program
				//puts the user's number in the stack at that spot. i is the position the original
				//stack is at currently.
				do {
					if (i == stackPosition) {
						temp.push(data);
					}
					else {
						temp.push(origStack.top());
						origStack.pop();
					}
					++i;
				} while (!origStack.empty());

				//This loop returns the stacks data to the original position and stack.
				do {
					origStack.push(temp.top());
					temp.pop();
				} while (!temp.empty());

			}
			else {
				origStack.push(data);
			}
		}

		//This loop outputs the stack, puts the top element in a vector, and then deletes the top element.
		cout << "Stack: ";
		do {
			cout << origStack.top() << " ";
			vector.push_back(origStack.top());
			origStack.pop();
		} while (!origStack.empty());

		//i is now the largest position
		i = vector.size() - 1;
		
		//This loop returns the data from the vector back to the original stack.
		do {
			origStack.push(vector.at(i));
			--i;
		} while (i != -1);
		vector.clear();

		cout << endl << endl;
	} while (userInput != 'Q');

	return 0;
}
