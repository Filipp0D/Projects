#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int main() {

	// VECTOR
	cout << "VECTOR" << endl;
	vector<string> animalVec = {"Lion", "Eagle", "Shark", "Bee", "Frog"};
	for (string k : animalVec) {		// for-each loop
		cout << k << endl;
	}
	cout << animalVec[2] << endl;
	cout << animalVec.at(2) << endl;

	// Get the first element
	cout << animalVec.front() << endl;

	// Get the last element
	cout << animalVec.back() << endl;

	animalVec[3] = "Ant";
	animalVec.push_back("Monkey");		// add element at the end
	animalVec.pop_back();				// remove element from the end
	cout << animalVec.size() << endl;
	cout << animalVec.empty() << endl;	// 1 if the vector is empty

	// LIST
	cout << "LIST" << endl;
	list<string> animalList = { "Lion", "Eagle", "Shark", "Bee", "Frog" };
	for (string k : animalList) {		// for-each loop
		cout << k << endl;
	}

	// Get the first element
	cout << animalList.front() << endl;

	// Get the last element
	cout << animalList.back() << endl;

	animalList.push_back("Monkey");		// add element at the end
	animalList.push_front("Tiger");		// add element at the beginning
	animalList.pop_back();				// remove element from the end
	animalList.pop_front();				// remove element from the beginning
	cout << animalList.size() << endl;
	cout << animalList.empty() << endl;	// 1 if the list is empty

	// STACK -> LastInFirstOut
	cout << "STACK" << endl;
	stack<string> animalStack;		// not adding elements as for vectors or lists
	animalStack.push("Lion");
	animalStack.push("Eagle");
	animalStack.push("Shark");
	animalStack.push("Bee");
	animalStack.push("Frog");
	cout << animalStack.top() << endl;		// top elt, LAST in
	animalStack.top() = "Monkey";
	cout << animalStack.top() << endl;
	animalStack.pop();
	cout << animalStack.top() << endl;

	cout << animalStack.size() << endl;
	cout << animalStack.empty() << endl;	// 1 if the stack is empty


	// QUEUE -> FirstInFirstOut
	cout << "QUEUE" << endl;
	queue<string> animalQueue;		// not adding elements as for vectors or lists
	animalQueue.push("Lion");
	animalQueue.push("Eagle");
	animalQueue.push("Shark");
	animalQueue.push("Bee");
	animalQueue.push("Frog");
	cout << animalQueue.front() << endl;
	cout << animalQueue.back() << endl;
	animalQueue.pop();						// pop the first in
	cout << animalQueue.front() << endl;		

	cout << animalStack.size() << endl;
	cout << animalStack.empty() << endl;	// 1 if the stack is empty

	// DEQUE
	cout << "DEQUE" << endl;
	deque<string> animalDeq = { "Lion", "Eagle", "Shark", "Bee", "Frog" };
	for (string k : animalDeq) {		// for-each loop
		cout << k << endl;
	}
	cout << animalDeq[2] << endl;
	cout << animalDeq.at(2) << endl;

	animalDeq.push_front("Monkey");
	animalDeq.push_back("Tiger");

	cout << animalDeq.front() << endl;		// Get the first element
	cout << animalDeq.back() << endl;		// Get the last element

	animalDeq[3] = "Ant";
	animalDeq.pop_front();
	animalDeq.pop_back();					// remove element from the end
	cout << animalDeq.size() << endl;
	cout << animalDeq.empty() << endl;		// 1 if the deque is empty


	// SET -> sorted automatically in ascending order alphabetically or numerically
	cout << "SET" << endl;
	set<string> animalSet = { "Lion", "Eagle", "Shark", "Bee", "Frog" };
	for (string animal : animalSet) {
		cout << animal;
	}
	cout << "\n";
	// sort in descending order
	set<int, greater<int>> num = { 1, 7, 4, 6, 9, 3, 7, 0 };		// double elts are ingored
	for (int number : num) {
		cout << number;
	}
	cout << "\n";
	num.insert(5);	// add new elt
	num.erase(7);	// remove elt
	num.clear();	// remove all elts

	cout << num.size() << endl;
	cout << num.empty() << endl;


	// MAP
	cout << "MAP" << endl;
	map<string, int> people = { {"Leonardo",32}, {"Emma", 25}, {"Cesare", 2}, { "Giorgia", 67 }};
	cout << people["Leonardo"] << endl;
	cout << people.at("Emma") << endl;		// usually prefered since it throws an error message if the elt doesn't exist
	people["Cesare"] = 4;
	people.at("Giorgia") = 91;				// safer to use .at()

	people.insert({ "Amelia", 44 });		// no equal elts are allowed, the 1st one added is kept
	people.erase("Amelia");

	cout << people.size() << endl;
	cout << people.empty() << endl;
	cout << people.count("Giorgia") << endl;	// verifies the presence of an elt

	for (auto i : people) {									// auto->automatically detect the datatype
		cout << i.first << " is: " << i.second << endl;		// first->key, second->value
	}

	people.clear();							// remove all elts
	map<string, int, greater<string>> people2 = { {"John", 56}, {"Phil", 32}, {"Jane", 23} };		// sorted alphatically in ascending order
	for (auto j : people2) {
		cout << j.first << " is: " << j.second << endl;
	}



	// ITERATORS
	cout << "----- ITERATORS -----" << endl;
	// iterating is techncal term for looping, iterator means iterate through data structures pointing at them
	// iterators also called pointers in that they point to elts in the data structure rather than returning values from them
	
	// create a vector iterator
	vector<string>::iterator it;
	for (it = animalVec.begin(); it != animalVec.end(); ++it) {
		cout << *it << endl;
	}

	// NOTE: - when you need to just read elts for-each loop is more simple and clearer
	//		 - when you need to add, modify, remove elts, iterate in reverse, skip elts, iterators would be a better solution

	// alternative usign auto keyword
	for (auto it = animalVec.begin(); it != animalVec.end(); ) {		
		cout << *it << endl;
		if (*it == "Ant") {
			it = animalVec.erase(it);	// erase-> remove an elt and return an iterator that points to the next elt
		}
		else {
			++it;
		}
	}

	for (const string& animal : animalVec) {
		cout << animal << endl;
	}
	///	NOTE: the following example shows how to use a range-based loop with reference in order to access directly the elts in the container
	//		  - range-based loop with reference(&) -> reading, changing existing values in the container, not for add/remove elts (too unpredictable)
	//												  no copies and memory saving
	//		  - range-based loop with const reference (const &) -> only reading elts, compute them, use them in a non-destructive way
	//															   no copies and memory saving
	//		  - iterator loop -> direct access to the container securely, but boilerplate
	vector<int> numbers = { 1, 2, 3, 4, 5 };

	for (auto& num : numbers) {  // Passaggio per riferimento
		num *= 2;  // Modifica ogni elemento del contenitore
	}

	for (const auto& num : numbers) {
		std::cout << num << " ";  // Output: 2 4 6 8 10
	}
	cout << "/n";
	///
	// NOTE: if working with primitive types the use of (&) or (const &) is often useless since:
	//			- primitives are fast to copy
	//			- memory usage is negligible


	// iterate in reverse order
	for (auto it = animalVec.rbegin(); it != animalVec.rend(); ++it) {
		cout << *it << endl;
	}


	// same goes for ather data structures that support iterators except for stacks and queues
	for (auto it = people2.begin(); it != people2.end(); ++it) {
		cout << it->first << it->second << endl;
	}

	
	// ALGORITHMS
	// iterators works with some algorithms functions (<algorithm> library) such as sort(), find()

	// sort() -> takes iterators typically returned by begin(), start iterator, and end(), end iterator, as pars
	sort(animalVec.begin(), animalVec.end());
	sort(animalVec.rbegin(), animalVec.rend());
	
	// find() -> 
	auto iter = find(animalVec.begin(), animalVec.end(), "Shark");
	cout << *iter << endl;
	
	// upper_bound()
	auto itUB = upper_bound(num.begin(), num.end(), 5);
	// check if the iterator is valid
	if (itUB != num.end()) {
		cout << "The first number greater than 5 is: " << *itUB << endl;
	}
	else {
		cout << "No number greater than 5 was found in the vector." << endl;
	}
	
	// lower_bound()
	auto itLB = lower_bound(num.begin(), num.end(), 7);
	// check if the iterator is valid
	if (itLB != num.end()) {
		cout << "The first number greater than 5 is: " << *itLB << endl;
	}
	else {
		cout << "No number greater than 5 was found in the vector." << endl;
	}
	// min_element()
	auto itMinElt = min_element(num.begin(), num.end());
	if (itMinElt != num.end()) {
		cout << "The first number greater than 5 is: " << *itMinElt << endl;
	}
	else {
		cout << "No number greater than 5 was found in the vector." << endl;
	}
	// max_element()
	auto itMaxElt = max_element(num.begin(), num.end());
	if (itMaxElt != num.end()) {
		cout << "The first number greater than 5 is: " << *itMaxElt << endl;
	}
	else {
		cout << "No number greater than 5 was found in the vector." << endl;
	}
	
	// copy elts
	vector<int> copyNum(7);
	copy(numbers.begin(), numbers.end(), copyNum.begin());
	for (const int& number : copyNum) {
		cout << number << endl;
	}

	// fill all the elts in a container with a value
	vector<int> value(5);
	fill(value.begin(), value.end(), 3);
	for (const int& number : value) {
		cout << number << endl;
	}

	// Random number each time the program runs
	srand(time(0));

	// Random number
	int randomNumber = rand() % 101;		// get random number between 0 and 100
	cout << randomNumber << endl;


	return 0;

}