#include<iostream>
#include<string>
#include<array>



static void Calulator()
{
	float var1, var2;
	std::cout << "iki deger giriniz:";
	std::cin >> var1 >> var2;

	std::cout <<"yapmak istediginiz islemi seciniz: \n";

	std::string islem[] = {
		"+","-","*","/"
	};

std::string selection = islem->c_str();

	std::cin >> selection;
	int changeS=0;
	(selection == "+") ? changeS = 1 : false;
	(selection == "-") ? changeS = 2 : false; 
	(selection == "*") ? changeS = 3 : false; 
	(selection == "/") ? changeS = 4 : false;
	switch (changeS)

	{
	case 1:

		std::cout << "toplam:" << var1 + var2;
		break;
	case 2:

		std::cout << "fark:" << var1 - var2;
		break;
	case 3:
		std::cout << "carpim:" << var1 * var2;
		break;
	case 4:
		std::cout << "bolum:" << var1 /var2;
		break;
	default:
		std::cout << "gecersiz bir islem girdiniz";

		break;
	}
}



int main()
{
  Calulator();
	std::cin.get();
}