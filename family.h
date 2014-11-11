#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Person{
	friend class Family;
	private:
		string name;
		int numberOfSons;
	public:
		Person* father;
		vector<Person> sons;
		bool isNull;
		Person():isNull(true), numberOfSons(0){}
		Person(int);
		Person(int, string);
		Person(int, string, Person*);
		~Person();
		void setName(string);
		void setNumberOfSons(int);
		int getNumberOfSons(){return numberOfSons;}
		void setSons();
		void printSons();
		void printTree();
		string getName(){return name;}
		Person* search(string);
};

class Family{
	public:
		Person* ancestor;
		bool addMember(string);
		bool deleteFamily(string);
		bool changeName(string);
};
