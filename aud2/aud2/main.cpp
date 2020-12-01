#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <random>  
#include <ctime> 

int main()
{
	int rand_number, mod2 = 0, mod3 = 0, mod4 = 0, mod5 = 0, mod6 = 0, mod7 = 0, mod8 = 0, mod9 = 0;
	//rand
	srand(4541);
	int mil = 1000000;
	for (int i = 0; i < mil; i++)
	{
		rand_number = rand();
		if (rand_number % 2 == 0)
			mod2++;
		if (rand_number % 3 == 0)
			mod3++;
		if (rand_number % 4 == 0)
			mod4++;
		if (rand_number % 5 == 0)
			mod5++;
		if (rand_number % 6 == 0)
			mod6++;
		if (rand_number % 7 == 0)
			mod7++;
		if (rand_number % 8 == 0)
			mod8++;
		if (rand_number % 9 == 0)
			mod9++;
	}
	std::cout << "for rand (percentage):" << std::endl << "mod 2=" << ((mod2 * 100.0) / mil) << std::endl << "mod 3=" << ((mod3 * 100.0) / mil) << std::endl << "mod 4=" << ((mod4 * 100.0) / mil) << std::endl << "mod 5=" << ((mod5 * 100.0) / mil) << std::endl;
	std::cout << "mod 6=" << ((mod6 * 100.0) / mil) << std::endl << "mod 7=" << ((mod7 * 100.0) / mil) << std::endl << "mod 8=" << ((mod8 * 100.0) / mil) << std::endl << "mod 9=" << ((mod9 * 100.0) / mil) << std::endl << std::endl;
	mod2 = 0, mod3 = 0, mod4 = 0, mod5 = 0, mod6 = 0, mod7 = 0, mod8 = 0, mod9 = 0;
	//std::mt19937
	std::mt19937 gen(time(0));
	for (int i = 0; i < mil; i++)
	{
		rand_number = gen();
		if (rand_number % 2 == 0)
			mod2++;
		if (rand_number % 3 == 0)
			mod3++;
		if (rand_number % 4 == 0)
			mod4++;
		if (rand_number % 5 == 0)
			mod5++;
		if (rand_number % 6 == 0)
			mod6++;
		if (rand_number % 7 == 0)
			mod7++;
		if (rand_number % 8 == 0)
			mod8++;
		if (rand_number % 9 == 0)
			mod9++;
	}
	std::cout << "for mt19937 (percentage):" << std::endl << "mod 2=" << ((mod2 * 100.0) / mil) << std::endl << "mod 3=" << ((mod3 * 100.0) / mil) << std::endl << "mod 4=" << ((mod4 * 100.0) / mil) << std::endl << "mod 5=" << ((mod5 * 100.0) / mil) << std::endl;
	std::cout << "mod 6=" << ((mod6 * 100.0) / mil) << std::endl << "mod 7=" << ((mod7 * 100.0) / mil) << std::endl << "mod 8=" << ((mod8 * 100.0) / mil) << std::endl << "mod 9=" << ((mod9 * 100.0) / mil) << std::endl << std::endl;
	//uniform_int_distribution
	mod2 = 0, mod3 = 0, mod4 = 0, mod5 = 0, mod6 = 0, mod7 = 0, mod8 = 0, mod9 = 0;
	std::uniform_int_distribution<> distrib(0, 100);
	for (int i = 0; i < mil; i++)
	{
		rand_number = distrib(gen);
		if (rand_number % 2 == 0)
			mod2++;
		if (rand_number % 3 == 0)
			mod3++;
		if (rand_number % 4 == 0)
			mod4++;
		if (rand_number % 5 == 0)
			mod5++;
		if (rand_number % 6 == 0)
			mod6++;
		if (rand_number % 7 == 0)
			mod7++;
		if (rand_number % 8 == 0)
			mod8++;
		if (rand_number % 9 == 0)
			mod9++;
	}
	std::cout << "for uniform_int_distribution (percentage):" << std::endl << "mod 2=" << ((mod2 * 100.0) / mil) << std::endl << "mod 3=" << ((mod3 * 100.0) / mil) << std::endl << "mod 4=" << ((mod4 * 100.0) / mil) << std::endl << "mod 5=" << ((mod5 * 100.0) / mil) << std::endl;
	std::cout << "mod 6=" << ((mod6 * 100.0) / mil) << std::endl << "mod 7=" << ((mod7 * 100.0) / mil) << std::endl << "mod 8=" << ((mod8 * 100.0) / mil) << std::endl << "mod 9=" << ((mod9 * 100.0) / mil) << std::endl << std::endl;
	return 0;
}