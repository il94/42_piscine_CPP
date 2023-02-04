#ifndef ARRAY
#define ARRAY

#include <iostream>

template< typename T >
class Array
{
	public :

	class ArrayException : public std::exception
	{
		public :
		virtual const char* what( void ) const throw() = 0;
	};
	class IndexTooHigh : public ArrayException
	{
		public :
		virtual const char* what( void ) const throw() { return ("[Exception] Index too high"); }
	};
	class IndexNegative : public ArrayException
	{
		public :
		virtual const char* what( void ) const throw() { return ("[Exception] Negative index"); }
	};


	/* Constructors */
	Array(){
		std::cout << "[Array] Default constructor called." << std::endl;
		_array = NULL;
		_sizeArray = 0;
		std::cout << "Table of " << _sizeArray << " elements created." << std::endl;
	}

	Array(unsigned int n)
	{
		std::cout << "[Array] Parameters constructor called." << std::endl;
		_array = new T[n];
		_sizeArray = n;
		for (int i = 0; i < _sizeArray; i++)
			_array[i] = 0;
		std::cout << "Table of " << _sizeArray << " elements created." << std::endl;
	}

	Array(const Array& src)
	{
		std::cout << "[Array] Copy constructor called." << std::endl;
		_array = new T[src._sizeArray];
		*this = src;
		std::cout << "Table of " << _sizeArray << " elements copied." << std::endl;
	}

	~Array()
	{
		std::cout << "[Array] Default destructor called." << std::endl;
		delete [] _array;
	}

	/* Overloads */
	Array&	operator=(const Array& src)
	{
		_sizeArray = src._sizeArray;
		for (int i = 0; i < _sizeArray; i++)
			_array[i] = src._array[i];
		return (*this);
	}

	T&	operator[](int index)
	{
		if (index < 0)
			throw (IndexNegative());
		else if (index >= _sizeArray)
			throw (IndexTooHigh());
		return (_array[index]);
	}

	/* Accessors */
	int	size( void ){
		return (_sizeArray);
	}


	private :

	/* Attributes */
	T*	_array;
	int	_sizeArray;

};

#endif