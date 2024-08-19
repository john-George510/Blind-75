#include <map>
#include <iostream>
#include <typeinfo>
#include <set>
#include <utility>
#include <unordered_set>
#include <stack>

using namespace std;

int main(){
	map<pair<float,int>,int> m;
	m[{1,2}] = 1;
	m[{2,3}] = 2;
	// m[] = 2;
	// m[2] = 3;

	// Get the type of map
	using MapType = decltype(m);
	cout << "Type of it: " << typeid(MapType).name() << endl;

	set<float> s;
	s.insert(1);
	s.insert(2);
	s.insert(3);

	stack<int> st;
	st.push(1);
	st.push(2);

	//get type of stack
	using StackType = decltype(st);

	// Print the type of it
	cout << "Type of it: " << typeid(StackType).name() << endl;

	unordered_set<int> us;
	us.insert(1);
	us.insert(2);

	// Get the type of unordered set
	using UnorderedSetType = decltype(us);
	cout << "Type of it: " << typeid(UnorderedSetType).name() << endl;

	// Get the type of unordered set iterator
	using UnorderedSetIteratorType = decltype(us.begin());
	cout << "Type of iterator: " << typeid(UnorderedSetIteratorType).name() << endl;


	// Find an element in the map
	auto it1 = s.find(1);

	// Get the type of it
	using IteratorType1 = decltype(it1);

	// Print the type of it
	cout << "Type of it: " << typeid(IteratorType1).name() << endl;

	auto it = m.find({1,2});
    
	// Get the type of it
	using IteratorType = decltype(it);
	
	// Print the type of it
	cout << "Type of it: " << typeid(IteratorType).name() << endl;

	// if(it != m.end()){
	// 	cout << it->first << " " << it->second << endl;
	// }

	// for(auto it : m){
	// 	cout << it.first << " " << it.second << endl;
	// }
	return 0;
}