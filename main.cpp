#include "family.h"

void help();
char upper(char&);
void commandLine(Family&);

////////////////operations
void improveTree(Family&);
void addMember(Family&);
void dismissPart(Family&);
void changeMemberName(Family&);
void printFamily(Family&);
////////////////operations

int main(){
	help();
	string ancestorName;
	cout << "First, establish a family tree!\n";
	cout << "Enter ancestor's name: ";
	cin >> ancestorName;
	cout << "The family's ancestor is: " << ancestorName << "\n\n";
	Family family;
	family.ancestor = new Person(1, ancestorName, NULL);
	commandLine(family);
	return 0;
}

char upper(char& ch){
	if(ch >= 'a' && ch <= 'z'){
		ch += ('Z' - 'z');
		return ch;
	}
	return ch;
}

void help(){
	cout << "--------------------------------------------\n"
		<< "    Family Tree Management System ver0.1\n"
		<< "--------------------------------------------\n"
		<< "    Please Choose the Operation:\n"
		<< "    A --- Improve the tree\n"
		<< "    B --- Add Family Member\n"
		<< "    C --- Dismiss Part of the family\n"
		<< "    D --- Change member's name\n"
		<< "    E --- Print a part\n"
		<< "    Q --- Quit the System\n"
		<< "--------------------------------------------\n";
}


void commandLine(Family& family){
	char order = 0;
	cout << "Enter your operation:\n>";
	cin >> order;
	upper(order);
	while(order != 'Q'){
		switch(order){
			case 'A':
				improveTree(family);
				break;
			case 'B':
				addMember(family);
				break;
			case 'C':
				dismissPart(family);
				break;
			case 'D':
				changeMemberName(family);
				break;
			case 'E':
				printFamily(family);
				break;
			case 'Q':
				break;
			default:
				cout << "Wrong order, try again.\n";
		}
		cout << "\nEnter your operation:\n>";
		cin >> order;
		upper(order);
	}
	cout << "Bye.\n";
}


void improveTree(Family& family){
	while(true){
		string name;
		Person* father;
		cout << "Enter one's name to establish his/her family: ";
		cin >> name;
		father = family.ancestor->search(name);
		if(father == NULL){
			cout << "No such people in this family, try again.\n";
			continue;
		}else{
			father->setSons();
			cout << father->getName() << "'s first generation sons are: ";
			father->printSons();
			cout << endl;
			break;
		}

	}
}//improveTree



void addMember(Family& family){
	while(true){
		string name;
		Person* father;
		cout << "Enter one's name to add son/daughter to him: ";
		cin >> name;
		father = family.ancestor->search(name);
		if(father == NULL){
			cout << "No such people in this family, try again.\n";
			continue;
		}else{
			family.addMember(name);
			cout << father->getName() << "'s first generation sons are: ";
			father->printSons();
			cout << endl;
			break;
		}
	}
}//addMember

void dismissPart(Family& family){
	while(true){
		string name;
		cout << "Enter one's name to dissmiss the family: ";
		cin >> name;
		if(family.ancestor->search(name) == NULL){
			cout << "No such people in this family, try again.\n";
			continue;
		}else{
			family.deleteFamily(name);
			cout << endl;
			break;
		}
	}
}//dissmissPart

void changeMemberName(Family& family){
	while(true){
		string name;
		cout << "Enter one's name to change: ";
		cin >> name;
		if(family.ancestor->search(name) == NULL){
			cout << "No such people in this family, try again.\n";
			continue;
		}else{
			family.changeName(name);
			cout << endl;
			break;
		}
	}
}//changeMemberName


void printFamily(Family& family){
	while(true){
		string name;
		Person* father;
		cout << "Enter one's name to see his/her family: ";
		cin >> name;
		father = family.ancestor->search(name);
		if(father == NULL){
			cout << "No such people in this family, try again.\n";
			continue;
		}else{
			cout << "Name: " << father->getName() << endl;
			if(father->father != NULL)
				cout << "Father: " << father->father->getName() << endl;
			cout << "Sons: ";
			father->printSons();
			cout << "\n\n";
			break;
		}
	}
}//printFamily
