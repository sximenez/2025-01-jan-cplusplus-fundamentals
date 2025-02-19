#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <tuple>
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;

#pragma region Multidimensional arrays ----------------------------------------

static int multidimensional_arrays() {
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

int messange_sender() {
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

#pragma region Operators

void operators() {
	vector<int> list = { 4, 1, 3, 2 };

	sort(list.begin(), list.end()); // Defaults to less<int>() or ascending.
	for (int value : list) {
		cout << value << endl;
	}

	cout << endl;

	sort(list.begin(), list.end(), greater<int>()); // Descending.
	for (int value : list) {
		cout << value << endl;
	}

	cout << endl << endl;

	int sum = accumulate(list.begin(), list.end(), 0); // Defaults to plus<int>() or sum.
	cout << sum << endl;

	cout << endl;

	/*for (int i = 0; i < list.size(); i++) {
		cout << list[i] << endl;
	}*/

	/*for (int value : list) {
		cout << value << endl;
	}*/

	//cout << sum;
}

#pragma endregion

#pragma region Basic function

int max_of_four(int a, int b, int c, int d) {
	return max({ a, b, c, d });
}

int basic_function() {
	string input = "3 4 5 6";
	stringstream cin(input);

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int ans = max_of_four(a, b, c, d);
	printf("%d", ans);

	return 0;
}

#pragma endregion

#pragma region Attribute parser

int main() {
	//string input = "4 3\n<tag1 value = \"HelloWorld\">\n<tag2 name = \"Name1\" value = \"ahaha\">\n</tag2>\n</tag1>\ntag1.tag2~name\ntag1~name\ntag1~value";
	//string input = "10 10\n<a value = \"GoodVal\">\n<b value = \"BadVal\" size = \"10\">\n</b>\n<c height = \"auto\">\n<d size = \"3\">\n<e strength = \"2\">\n</e>\n</d>\n</c>\n</a>\na~value\nb~value\na.b~size\na.b~value\na.b.c~height\na.c~height\na.d.e~strength\na.c.d.e~strength\nd~sze\na.c.d~size";
	//string input = "6 4\n<a>\n<b name = \"tag_one\">\n<c name = \"tag_two\" value = \"val_907\">\n</c>\n</b>\n</a>\na.b~name\na.b.c~value\na.b.c~src\na.b.c.d~name";
	string input = "16 14\n<tag1 v1 = \"123\" v2 = \"43.4\" v3 = \"hello\">\n</tag1>\n<tag2 v4 = \"v2\" name = \"Tag2\">\n<tag3 v1 = \"Hello\" v2 = \"World!\">\n</tag3>\n<tag4 v1 = \"Hello\" v2 = \"Universe!\">\n</tag4>\n</tag2>\n<tag5>\n<tag7 new_val = \"New\">\n</tag7>\n</tag5>\n<tag6>\n<tag8 intval = \"34\" floatval = \"9.845\">\n</tag8>\n</tag6>\ntag1~v1\ntag1~v2\ntag1~v3\ntag4~v2\ntag2.tag4~v1\ntag2.tag4~v2\ntag2.tag3~v2\ntag5.tag7~new_val\ntag5~new_val\ntag7~new_val\ntag6.tag8~intval\ntag6.tag8~floatval\ntag6.tag8~val\ntag8~intval";
	stringstream cin(input);

	int n;
	int q;
	cin >> n >> q;

	unordered_map<string, string> dictionary;
	string line;
	const char OPENING_TAG = '<';
	const char CLOSING_TAG = '>';
	const char BACKSLASH = '/';
	const char QUOTE = '"';
	string root;

	for (int i = 0; i < n; i++) {
		string key;
		string value;

		while (cin >> line) {
			if (line[1] == BACKSLASH) {
				string tag = line.substr(2, line.length() - 3); // Recover the tag.

				if (tag == root) {
					root.clear(); // Clear if same.
				}
				else {
					size_t pos = root.find(tag);
					if (pos != string::npos) {
						root = root.substr(0, pos - 1); // Update if different.
					}
				}

				break;
			}
			else if (line[0] == OPENING_TAG) {
				size_t pos = line.find(CLOSING_TAG);
				string tag;

				if (pos != string::npos) { 
					tag = line.substr(1, pos - 1); // If closing tag, remove.
				}
				else {
					tag = line.substr(1);
				}

				if (!root.empty()) {
					root += "."; // If root is not empty, add dot.
				}
				root += tag;

				if (pos != string::npos) {
					break;
				}

				continue;
			}
			else if (line[0] == QUOTE) {
				value = line.substr(1);
				size_t pos = value.find(CLOSING_TAG);

				if (pos != string::npos) {
					value = value.substr(0, pos - 1); // If closing tag, remove.
				}
				else {
					value = value.substr(0, value.length() - 1);
				}

				dictionary[key] = value;

				if (pos != string::npos) {
					break;
				}
			}
			else if (line[0] != '=') {
				key = root + "~" + line;
				dictionary[key] = "";
			}
		}
	}

	vector<string> queries;
	for (int i = 0; i < q; i++) {
		cin >> line;
		queries.push_back(line);
	}

	for (string query : queries) {
		if (dictionary[query] != "") {
			cout << dictionary[query] << endl;
		}
		else {
			cout << "Not Found!" << endl;
		}
	}

	return 0;
}

#pragma endregion
