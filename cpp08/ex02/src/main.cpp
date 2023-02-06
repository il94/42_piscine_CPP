#include "../include/MutantStack.hpp"

// int main( void )
// {
// 	MutantStack<int> mstack;

// 	mstack.push(5);
// 	mstack.push(17);

// 	std::cout << mstack.top() << std::endl;

// 	mstack.pop();

// 	std::cout << mstack.size() << std::endl;

// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	//[...]
// 	mstack.push(0);

// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();

// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 		std::cout << *it << std::endl;
// 		++it;
// 	}
// 	std::stack<int> s(mstack);
// 	return 0;
// }

int main( void )
{
	MutantStack<int> myStack;
	myStack.push(0); printElement(myStack.top());
	myStack.push(10); printElement(myStack.top());
	myStack.push(50); printElement(myStack.top());
	myStack.push(150); printElement(myStack.top());
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << std::endl;

	std::cout << "My Incredible Stack top is : " << myStack.top() << std::endl;
	std::cout << std::endl;

	MutantStack<int> myCopyStack(myStack);

	std::cout << "My Awesome Copy Stack top is : " << myCopyStack.top() << std::endl;
	std::cout << "[Pop -> new]" << std::endl;
	myCopyStack.pop();
	std::cout << "My Awesome Copy Stack top is : " << myCopyStack.top() << std::endl;

	std::cout << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << std::endl;

	std::cout << "My Fabulous Stack (displayed by my fantastic iterators) is : ";
	std::for_each(myStack.begin(), myStack.end(), printElement<int>);
	std::cout << std::endl;	

	std::stack<int> original(myStack);
	std::cout << "std::stack top is : " << original.top() << std::endl;

	std::cout << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << std::endl;

	MutantStack<std::string> myStringStack;

	myStringStack.push("Ca");
	myStringStack.push("marche");
	myStringStack.push("aussi");
	myStringStack.push("avec");
	myStringStack.push("des");
	myStringStack.push("strings");
	myStringStack.push("!!!");

	std::for_each(myStringStack.begin(), myStringStack.end(), printElement<std::string>);
	std::cout << std::endl;

	for (MutantStack<std::string>::iterator it = myStringStack.begin(); it != myStringStack.end(); ++it)
	{
		if (it == myStringStack.begin() or it == myStringStack.begin() + 1 or it == myStringStack.end() - 1)
			printElement<std::string>(*it);
	}
	std::cout << std::endl;

	return (0);
}

// #include <list>
// int main( void )
// {
// 	std::list<int> myStack;
// 	myStack.push_back(0); printElement(myStack.back());
// 	myStack.push_back(10); printElement(myStack.back());
// 	myStack.push_back(50); printElement(myStack.back());
// 	myStack.push_back(150); printElement(myStack.back());
// 	std::cout << std::endl;

// 	std::cout << std::endl;
// 	std::cout << "===================================" << std::endl;
// 	std::cout << std::endl;

// 	std::cout << "My Incredible Stack top is : " << myStack.back() << std::endl;
// 	std::cout << std::endl;

// 	std::list<int> myCopyStack(myStack);

// 	std::cout << "My Awesome Copy Stack top is : " << myCopyStack.back() << std::endl;
// 	std::cout << "[Pop -> new]" << std::endl;
// 	myCopyStack.pop_back();
// 	std::cout << "My Awesome Copy Stack top is : " << myCopyStack.back() << std::endl;

// 	std::cout << std::endl;
// 	std::cout << "===================================" << std::endl;
// 	std::cout << std::endl;


// 	std::cout << "My Fabulous Stack is : ";
// 	for (std::list<int>::iterator it = myStack.begin(); it != myStack.end(); ++it)
// 		printElement(*it);
// 	std::cout << std::endl;


// 	std::list<int> original(myStack);
// 	std::cout << "std::stack back is : " << original.back() << std::endl;

// 	return 0;
// }