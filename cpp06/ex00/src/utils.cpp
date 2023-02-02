#include "../include/conversion.h"

bool    decimalIsZero(std::string& value)
{
	char c = '1';

	if (static_cast<int>(value.find('.')) == -1)
		return (true);
	while (c <= '9')
	{
		if (static_cast<int>(value.find(c, static_cast<int>(value.find('.')))) != -1)
			return (false);
		c++;
	}
	return (true);
}