#include "family.h"

Person::Person(int num):numberOfSons(num), isNull(false){
}

Person::Person(int num, string _name):numberOfSons(num), name(_name), isNull(false){
}

Person::Person(int num, string _name, Person* dad):numberOfSons(num), name(_name), isNull(false), father(dad){
}

void Person::setName(string _name){
	name = _name;
	isNull = false;
}

void Person::setNumberOfSons(int num){
	numberOfSons = num;
}


void Person::setSons(){
	char c;
	cout << "Enter " << name << "'s sons number: ";
	cin >> numberOfSons;
	cout << "Enter " << name << "'s sons names: ";
	for(int i = 0;i < numberOfSons;++i){
		string newName;
		cin >> newName;
		sons.push_back(*(new Person(0, newName, this)));
	}
	//cout << "set successfully!\n";
}

void Person::printSons(){
	for(vector<Person>::iterator iter = sons.begin();iter != sons.end();++iter)
		cout << (*iter).getName() << ' ';
}

void Person::printTree(){
	if(isNull == false){
		cout << "Name: " << name << ", father: " << father->name << endl;
		for(vector<Person>::iterator iter = sons.begin();iter != sons.end();++iter)
			iter->printTree();
	}
	return;
}

Person* Person::search(string sName){
	Person* temp;
	if(name == sName)
		return this;
	else if(numberOfSons != 0){
		for(int i = 0;i < numberOfSons;++i){
			temp = sons[i].search(sName);
			if(temp != NULL)
				return temp;
			else
				continue;
		}
	}else
		return NULL;
}

Person::~Person(){
	sons.clear();
}


bool Family::addMember(string sName){
	Person* temp = ancestor->search(sName);
	if(temp == NULL)
		return false;
	++(temp->numberOfSons);
	cout << "Enter new member's name: ";
	string newMemberName;
	cin >> newMemberName;
	(temp->sons).push_back(*(new Person(1, newMemberName)));
	return true;
}

bool Family::deleteFamily(string sName){
	Person* temp = ancestor->search(sName);
	if(temp == NULL)
		return false;

	Person* father = temp->father;
	cout << "To delete: " << temp->getName() << endl;
	cout << temp->getName() << "'s sons: ";
	temp->printSons();
	cout << endl;

	//(temp->sons).clear();
	vector<Person>::iterator toDelete = father->sons.begin();
	for(;toDelete != father->sons.end();++toDelete){
		if((*toDelete).getName() == temp->getName()){
			father->sons.erase(toDelete);
			break;
		}
	}
	return true;
}

bool Family::changeName(string sName){
	Person* temp = ancestor->search(sName);
	if(temp == NULL)
		return false;
	cout << "Enter the name to change to: ";
	string newName, oldName;
	cin >> newName;
	oldName = temp->getName();
	temp->setName(newName);
	cout << oldName << "'s name has been changed to " << newName << endl;
	return true;
}
