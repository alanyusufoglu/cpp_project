#include<iostream>


static int newDeleteDiziYonetimi(int ar1[], int& index)
{
	 ar1 = new int[index];
	std::cout << "diziniz oluturuldu.\n";


	std::cout << "dizi elemanlarýný giriniz:";
	for (int i = 0; i < index; i++)
	{
		std::cin >> ar1[i];  // Dizinin her elemanýný kullanýcýdan al
	}
	std::cout << "dinamik bellek ile olsturdugunuz dizi:" << *ar1;


	int sum=0;
	for (int i = 0; i < index; i++)
	{
		sum += ar1[i];
	};
	int mid = sum / index;
	std::cout << "olusturdugunuz dizinin ortalamasý:" << mid;
	
	
	return mid;
	delete[] ar1;
};


static int mallocFreeDiziYonetimi(int ar2[], int& index2)
{

	 ar2 = (int*)malloc(index2 * sizeof(int));
	std::cout << "dizniz oluturuldu.\n";

	std::cout << "dizi elemanlarýný giriniz:";
	for (int i = 0; i < index2; i++) {
		std::cin >> ar2[i];  // Dizinin her elemanýný kullanýcýdan al

	}
	std::cout << "dusuk bellek olusturma yontemi  ile olsturdugunuz dizi:" << *ar2;



	int sum = 0;
	for (int i = 0; i < index2; i++)
	{
		sum += ar2[i];
	};
	int mid = sum / index2;
	std::cout << "olusturdugunuz dizinin ortalamasý:" << mid;



	return mid;
	free(ar2);

};



int main()
{

	std::cout << "hangi yontem ile bellek yontemiyle dizi olusturmak istersiniz\n";
		std::cout<<"dinamik bellek yöntemi : 1\n";
		std::cout<<"dusuk bellek yontemi:2\n";
	
	int mode;
	std::cin >> mode;
	switch (mode)
	{
	case 1:
	{
		std::cout << "lutfen bir dizi index giriniz";
		int i;
		std::cin >> i;
		
		int* ar1 = nullptr;
		newDeleteDiziYonetimi(ar1, i);
		break;
	}
	case 2:
	{
		std::cout << "lutfen bir dizi index giriniz";
		int i1;
		std::cin >> i1;
		
		int* ar2 =nullptr;
		mallocFreeDiziYonetimi(ar2, i1);
		break;
		
	}
	default:
		std::cout << "gecersiz islem!!!!!!!!!!!!!!!";
		break;
	}

	return 0;


}