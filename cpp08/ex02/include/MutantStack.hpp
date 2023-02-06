#ifndef MUTANTSTACK
#define MUTANTSTACK

#include <iostream>
#include <stack>
#include <algorithm>

template <typename T>
void	printElement(T i){
	std::cout << "[" << i << "] ";
}

template <typename T>
class MutantStack : public std::stack<T>
{
	public :

	class iterator
	{
		public:

		/* Constructors */
		iterator(){
		}

		iterator(typename std::deque<T>::iterator src) : _value(src){
		}

		iterator(iterator const& src) : _value(src._value){
		}

		~iterator(){
		}


		/* Overloads */
		iterator&	operator=(const iterator& src){
			_value = src._value;
			return (*this);
		}
		
		T 		operator*( void ){
			return (*_value);
		}

		iterator	operator+(const int &factor) const
		{
			iterator	result = *this;

			result._value += factor;
			return (result);
		}

		iterator	operator-(const int &factor) const
		{
			iterator	result = *this;

			result._value -= factor;
			return (result);
		}


		bool		operator==(const iterator& target) const{
			return (_value == target._value);
		}
		bool		operator!=(const iterator& target) const{
			return (_value != target._value);
		}

		iterator& 	operator++( void ){
			_value++;
			return (*this);
		}
		iterator& 	operator--( void ){
			_value--;
			return (*this);
		}

		private:
		
		/* Attributes */
		typename std::deque<T>::iterator	_value;

	};

	/* Constructors */
	MutantStack() : std::stack<T>(){
	}

	MutantStack(const MutantStack& src) : std::stack<T>(src){
		*this = src;
	}

	~MutantStack(){
	}


	/* Overloads */
	using std::stack<T>::operator=;

	/* Iterators */
	MutantStack::iterator	begin( void ){
		return (iterator(this->c.begin()));
	}

	MutantStack::iterator	end( void ){
		return (iterator(this->c.end()));
	}	
};

#endif