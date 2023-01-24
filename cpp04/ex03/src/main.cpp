#include "../include/MateriaCure.hpp"
#include "../include/MateriaIce.hpp"
#include "../include/MateriaSource.hpp"
#include "../include/Character.hpp"

// int main()
// {
// 	I_MateriaSource* src = new MateriaSource();
// 	src->learnMateria(new MateriaIce());
// 	src->learnMateria(new MateriaCure());
// 	I_Character* me = new Character("me");
// 	A_Materia* tmp;
// 	tmp = src->createMateria("MateriaIce");
// 	me->equip(tmp);
// 	tmp = src->createMateria("MateriaCure");
// 	me->equip(tmp);
// 	I_Character* bob = new Character("bob");
// 	me->use(0, *bob);
// 	me->use(1, *bob);
// 	delete bob;
// 	delete me;
// 	delete src;
// 	return 0;
// }

int main( void )
{
	I_MateriaSource*	src = new MateriaSource();
	std::cout << std::endl;

	src->learnMateria(new MateriaIce());
	std::cout << std::endl;

	src->learnMateria(new MateriaCure());
	std::cout << std::endl;

	I_Character*	me = new Character("me");
	std::cout << std::endl;

	A_Materia* tmp;
	(void)tmp;
	std::cout << std::endl;

	delete me;
	std::cout << std::endl;

	delete src;
}