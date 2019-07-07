#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include "modernvector.h"


int main()
{
	try {

		ModernVector<int> modVector1;
		modVector1.reserve(2);

		std::cout << "capacity " << modVector1.capacity() << std::endl;

		ModernVector<int> modVector2(2);
		std::cout << "capacity " << modVector2.capacity() << std::endl;
		std::cout << "size " << modVector2.size() << std::endl;
		// добавляєм дані
		int tmpVAr = 10;
		modVector2.push_back(tmpVAr);
		modVector2.push_back(std::move(tmpVAr));
		std::cout << "tmpVAr after move " << tmpVAr << std::endl;

		std::cout << "modVector2[0] " << modVector2[0] << std::endl;
		std::cout << "modVector2[1] " << modVector2[1] << std::endl;
		std::cout << "size " << modVector2.size() << std::endl;
		// std::cout << "modVector2[2] " << modVector2[2] << std::endl; зловим)


		ModernVector<int> modVector3(modVector2);
		std::cout << "after copy modVector2[0] " << modVector2[0] << std::endl; // після копіювання стан modVector2 зберігається

		modVector3 = std::move(modVector2);
		ModernVector<int> modVector4(std::move(modVector3));
		modVector2.push_back(4);
		modVector2.push_back(14);
		modVector2.push_back(5);
		modVector2.push_back(16);
		//std::cout << "after move assig modVector3[0] " << modVector3[0] << std::endl; // буде помилка так як елементів більше нема
		// итератор мого контейнера )
		for (ModernVector<int>::iterator it = modVector2.begin(); it != modVector2.end(); ++it) 
		{
			std::cout << *it << std::endl;
		}
		system("pause");


	}
	catch (const std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}
	return 0;
}
