#include "../include/Span.hpp"

/*================================= ITERATOR =================================*/
/*=============================== Constructors ===============================*/

Span::iterator::iterator(){
}

Span::iterator::iterator(std::vector<int>::iterator src) : _value(src){
}

Span::iterator::iterator(const Span &src){
	*this = src;
}

Span::iterator::~iterator(){
}

/*================================ Overloads =================================*/

Span::iterator& Span::iterator::operator=(const Span::iterator &src)
{
	_value = src._value;
	return (*this);
}

int Span::iterator::operator*( void ){
    return (*_value);
}

bool	Span::iterator::operator==(const Span::iterator &target) const{
	return (_value == target._value);
}

bool	Span::iterator::operator!=(const Span::iterator &target) const{
	return (_value != target._value);
}

Span::iterator&	Span::iterator::operator++( void ){
	_value++;
	return (*this);
}

Span::iterator&	Span::iterator::operator--( void ){
	_value--;
	return (*this);
}


/*=================================== SPAN ===================================*/
/*=============================== Constructors ===============================*/

Span::Span() : _size(0){
}

Span::Span(unsigned int N) : _container(N), _size(0){
}

Span::Span(const Span &src){
	*this = src;
}

Span::~Span(){
}

/*================================ Overloads =================================*/

Span& Span::operator=(const Span &src)
{
	_size = src._size;
	_container = src._container;
	_containerSorted = src._containerSorted;
	return (*this);
}

/*================================= Methods ==================================*/

void	Span::addNumber(int element)
{
	if (_size >= _container.size())
		throw (FullSpan());

	_container[_size] = element;
	_size++;

	_containerSorted = _container;
	std::sort(_containerSorted.begin(), _containerSorted.end());
}

int	Span::shortestSpan( void )
{
	if (_container.empty())
		throw (EmptySpan());
	else if (_size == 1)
		return (*_container.begin());

	int	distance;
	int result = *std::max_element(_containerSorted.begin(), _containerSorted.end());

	std::vector<int>::iterator it1 = _containerSorted.begin();
	for (std::vector<int>::iterator it2 = it1 + 1; it2 != _containerSorted.end(); it1++, it2++)
	{
		distance = *it2 - *it1;
		if (distance < result)
			result = distance;
	}
	return (result);
}

int	Span::longestSpan( void )
{
	if (_container.empty())
		throw (EmptySpan());
	else if (_size == 1)
		return (*_container.begin());

	return (*(_containerSorted.end() - 1) - *_containerSorted.begin());
}

/*================================ Iterators =================================*/

Span::iterator	Span::begin( void ){
	return (Span::iterator(_container.begin()));
}

Span::iterator	Span::end( void ){
	return (Span::iterator(_container.end()));
}