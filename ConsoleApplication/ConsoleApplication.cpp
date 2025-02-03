#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <tuple>
using namespace std;

#pragma region Multidimensional arrays ----------------------------------------

static int multidimensionalArrays() {
	string input = "2 2\n3 1 5 4\n5 1 2 8 9 3\n0 1\n1 3";
	istringstream cin(input);

	int arrays;
	int queries;

	cin >> arrays >> queries;
	vector<vector<int>> arrayOfArrays;

	for (int i = 0; i < arrays; i++) {
		int arraySize;
		cin >> arraySize;
		vector<int> innerArray;

		for (int j = 0; j < arraySize; j++) {
			int innerValue;
			cin >> innerValue;
			innerArray.push_back(innerValue);
		}
		arrayOfArrays.push_back(innerArray);
	}

	for (int i = 0; i < queries; i++) {
		int targetArray;
		int targetIndex;
		cin >> targetArray >> targetIndex;

		int result = arrayOfArrays[targetArray][targetIndex];
		cout << result << endl;
	}

	return 0;
}

#pragma endregion

#pragma region Method overloading ---------------------------------------------

class Person {
public:
	Person(const string& first_name, const string& last_name) : first_name_(first_name), last_name_(last_name) {}
	const string& get_first_name() const {
		return first_name_;
	}
	const string& get_last_name() const {
		return last_name_;
	}
private:
	string first_name_;
	string last_name_;
};

ostream& operator<<(ostream& os, const Person& person) {
	os << "first_name=" << person.get_first_name() << ",last_name=" << person.get_last_name();
	return os;
}

static int methodOverloading() {
	string input = "hello world";
	istringstream cin(input);

	string first_name, last_name;
	cin >> first_name >> last_name;
	auto p = Person(first_name, last_name);
	cout << p.get_first_name() << endl;
	cout << p << endl;
	return 0;
}

#pragma endregion

#pragma region Debugging ------------------------------------------------------

class Message {
public:
	// Initialization list.
	Message(const string& text, int index) : stored_text_(text), index_(index) {}

	// Getter function.
	// Returns a reference to a stored string (not a copy).
	// const after the invocator () means that the function does not modify the object.
	const string& get_text() const {
		return stored_text_;
	}

	// Getter function.
	// Returns a copy of internal member index_.
	int get_index() const {
		return index_;
	}

	bool operator<(const Message& next) const {
		return index_ < next.index_;
	}

private:
	string stored_text_;
	int index_;
};

class MessageFactory {
public:
	// Members can be initialized inline using the invocator.
	MessageFactory() : current_index_(0) {}

	Message create_message(const string& text) {
		return Message(text, current_index_++);
	}

private:
	int current_index_;
};

class Recipient {
public:
	Recipient() {}
	void receive(const Message& msg) {
		messages_.push_back(msg);
	}
	void print_messages() {
		fix_order();
		for (auto& msg : messages_) {
			cout << msg.get_text() << endl;
		}
		messages_.clear();
	}
private:
	void fix_order() {
		sort(messages_.begin(), messages_.end());
	}
	vector<Message> messages_;
};

class Network {
public:
	static void send_messages(vector<Message> messages, Recipient& recipient) {
		// simulates the unpredictable network, where sent messages might arrive in unspecified order
		random_shuffle(messages.begin(), messages.end());
		for (auto msg : messages) {
			recipient.receive(msg);
		}
	}
};

int messangeSender() {
	string input = "Alex\nHello Monique!\nWhat'up?\nNot much :(";
	istringstream cin(input);

	MessageFactory message_factory;
	Recipient recipient;
	vector<Message> messages;
	string text;
	while (getline(cin, text)) {
		Message message = message_factory.create_message(text);
		messages.push_back(message);
	}
	Network::send_messages(messages, recipient);
	recipient.print_messages();

	return 0;
}

#pragma endregion

#pragma region Operator overloading

void main() {
	vector<int> list = { 4, 1, 3, 2 };
	sort(list.begin(), list.end());

	for (int i = 0; i < list.size(); i++) {
		cout << list[i] << endl;
	}

	/*for (int value : list) {
		cout << value << endl;
	}*/
}

#pragma endregion
