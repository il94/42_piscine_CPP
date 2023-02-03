#include "../include/type.h"

Base*	generate( void )
{
	int		randomNumber = (rand() % 3);

	if (randomNumber == 0)
	{
		std::cout << "A object will be generate" << std::endl;
		return (new A);
	}
	else if (randomNumber == 1)
	{
		std::cout << "B object will be generate" << std::endl;
		return (new B);
	}
	else
	{
		std::cout << "C object will be generate" << std::endl;
		return (new C);
	}
}

void	identify(Base* p)
{
	try
	{
		if (not p)
			throw (std::exception());
		try
		{
			if (not dynamic_cast<A*>(p))
				throw (std::exception());
			std::cout << "Object type is : [A]" << std::endl;
		}
		catch (std::exception&)
		{
			try
			{
				if (not dynamic_cast<B*>(p))
					throw (std::exception());
				std::cout << "Object type is : [B]" << std::endl;
			}
			catch (std::exception&)
			{
				try
				{
					if (not dynamic_cast<C*>(p))
						throw (std::exception());
					std::cout << "Object type is : [C]" << std::endl;
				}
				catch (std::exception&){
					std::cout << "Object type is : [NULL]" << std::endl;
				}
			}
		}
	}
	catch (std::exception&){
		std::cout << "Object type is : [NULL]" << std::endl;
	}
}

void	identify(Base& p)
{
	try
	{
		if (not dynamic_cast<A*>(&p))
			throw (std::exception());
		std::cout << "Object type is : [A]" << std::endl;
	}
	catch (std::exception&)
	{
		try
		{
			if (not dynamic_cast<B*>(&p))
				throw (std::exception());
			std::cout << "Object type is : [B]" << std::endl;
		}
		catch (std::exception&)
		{
			try
			{
				if (not dynamic_cast<C*>(&p))
					throw (std::exception());
				std::cout << "Object type is : [C]" << std::endl;
			}
			catch (std::exception&)
			{
				std::cout << "Object type is : [NULL]" << std::endl;
			}
		}
	}
}