#include<iostream>


class bankAccount
{
private:

	std::string name;
	int id;
	int bankBalance;

public:
	
	bankAccount(std::string Name, int Id, int bankbal)
	{
		this->name = Name;
		this->id = Id;
		this->bankBalance = bankbal;
	};


	void investment(int bankaBalance)
	{

		std::cout << "eklemek istediginiz parayi giriniz:";
		int money;
		std::cin >> money;
		bankaBalance += money;	
				std::cout << "paraniz yatirildi";
			

	};



	void drawingCash(int bankaBalance)
	{
		std::cout << "cekmek istediðiniz miktarý giriniz:";
		int cash;
		std::cin >> cash;
		bankBalance -= cash;

		bool isDrawingCAsh = false;


		while (!isDrawingCAsh)

		{
			if (bankBalance == (bankBalance - cash) && bankaBalance> 0)
			{
				std::cout << "para cekilmistir.";
				isDrawingCAsh = true;
			}
			else if (bankBalance == (bankBalance - cash) && bankBalance < 0)
				std::cout << "yaptiginiz islem gecersiz. devam etemek istiyorsanýz 1, istemiyorsaniz 2 yazýnýz";
			
			
			int isTrue ;
			std::cin >> isTrue;
			

			switch (isTrue)
			{

			case 1:
			{
				break;
			}
			case 2:
			{
				isDrawingCAsh = true;
			}
		

			}


		}


	}

	void bakiyeSorgula()

	{

		std::cout << "bakiyeniz:" << bankBalance;
	};

};




int main()
{
	

	bankAccount* bank=new bankAccount("alan yusufoglu",123455,5000);


	std::cout << "para yatýrmak isterseniz yapacaginiz tuslama:1 istemiyorsaniz:0";
	bool yesOrno;
	std::cin >> yesOrno;
	if (yesOrno)
	{
		bank->investment(5000);
		

	}
	else
	{
		std::cout << "bir sonraki isleme geciliyor....\n";
	}
	
	std::cout << "para cekmek isterseniz yapacaginiz tuslama:1 istemiyorsaniz:0";
	bool yesOrno1;
	std::cin >> yesOrno1;
	if (yesOrno1)
	{
		bank->drawingCash(50000);
	}
	else;
	{
		std::cout << "bir sonraki isleme geciliyor....\n";
	}
	std::cout << "bakiyenizi gormek isterseniz yapacaginiz tuslama:1 istemiyorsaniz:0";
	bool yesOrno2;
	std::cin >> yesOrno2;
	if (yesOrno2)
	{
		bank->bakiyeSorgula();
	}
	else;
	{
		
	}

	delete bank;

	return 0;


}