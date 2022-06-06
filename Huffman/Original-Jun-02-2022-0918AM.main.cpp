#include <iostream>
#include <conio.h>
#include <list>
using namespace std;
struct User {
	string name;
	string password;
	User() {
		name = "";
		password = "";
	}
	User(string name, string password) {
		this->name = name;
		this->password = password;
	}
};
class HashTable {
private:
	static const int initial_size = 11;
	list<User> table[initial_size];
	int size = initial_size; // or ca n be cal led as buckets
		int entries = 0; // the to talent  add ed into the ha sh table
public:
	bool is_empty() const {
		int sum = 0;
		for (int i = 0; i < size; i++) {
			sum += table[i].size();
		}
		return sum == 0;
	}
	// hash table will be considered full if its 70% filled
	bool is_full() const {
		int percent = (int)floor(((double)entries / (double)size) * (double)100);
		return percent >= 70;
	}
	int hash_function(string str) {
		int hash = 0;
		for (int i = 0; i < str.size(); i++) {
			hash += str[i] * 2 ^ (i + 1);
		}
		return hash % size;
	}
	bool insert(const User& user) {
		int hash = hash_function(user.name);
		auto& cell = table[hash];
		for (auto it = cell.begin(); it != cell.end(); it++) {
			// user wit h the same name already exists , break and re turn
			if (it->name == user.name) {
				return false;
			}
		}
		// user doe s not exist and so add him
		cell.push_back(user);
		entries++;
		return true;
	}
	bool remove(string username) {
		int hash = hash_function(username);
		auto& cell = table[hash];
		for (auto it = cell.begin(); it != cell.end(); it++) {
			// user found
			if (it->name == username) {
				it = cell.erase(it);
				return true;
			}
		}
		return false;
	}
	bool retrieve(string username, User&user) {
		int hash = hash_function(username);
		auto& cell = table[hash];
		for (auto it = cell.begin(); it != cell.end(); it++) {
			// user found
			if (it->name == username) {
				user = *it;
				return true;
			}
		}
		return false;
	}
	void clear() {
		// first clear all the cells in t he table
		for (int i = 0; i < size; i++) {
			table[i].clear();
		}
		entries = 0; // table cleared, so no entries
	}
	void show_structure() {
		for (int i = 0; i < size; i++) {
			auto& cell = table[i];
			if (cell.size() == 0) {
				continue;
			}
			cout << "[Index: " << i << "]" << endl;
			for (auto it = cell.begin(); it != cell.end(); it++) {
				cout << "- User: " << it->name << endl;
				cout << " Password: " << it->password << endl;
			}
		}
	}
};
class Website {
private:
	HashTable table;
public:
	void signup(string username, string password) {
		if (!table.insert(User(username, password))) {
			cout << "User: "<< username << " is already registered " << endl;
			return;
		}
		cout << "User: "<< username << " registered successfully" << endl;
	}
	void login(string username, string password) {
		User user;
		if (!table.retrieve(username, user)) {
			cout << "User: " << username << " is not registered" << endl;
			return;
		}
		if (user.password != password) {
			cout << "Unable to login. Invalid password provided for User: " << username << endl;
			return;
		}
		cout << "User: " << username << " logged in successfully" << endl;
	}
	void display() {
		if (table.is_empty()) {
			cout << "No registered users to display" << endl;
			return;
		}
		cout << "Registered users: " << endl;
		table.show_structure();
	}
	HashTable& get_hash_table() {
		return table;
	}
};
int main() {
	Website site;
	cout << "Operation 1 - ";
	site.login("user1", ""); // operation 1
		cout << "Operation 2 - ";
	site.signup("user1 ", "user 1"); // operation 2
	cout << "Operation 3 - ";
	site.login("user1", "user1 "); // operation 3
	cout << "Operation 4 - ";
	site.login("user1", "check "); // operation 4
	cout << "Operation 5 - ";
	site.signup("user1 ", "hell o"); // operation 5
	cout << "Operation 6 - ";
	site.signup("user2 ", "user 2"); // operation 6
	cout << "Operation 7 - ";
	site.login("user2", "user2 "); // operation 7
	cout << "Operation 8 - ";
	site.display(); // operation 8
	_getch();
	return 0;
}