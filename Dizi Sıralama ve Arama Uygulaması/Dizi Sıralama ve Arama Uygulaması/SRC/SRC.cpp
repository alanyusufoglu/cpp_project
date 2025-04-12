#include<iostream>
#include<array>

 class sorting
{
public:
	static const char* bubbleSort(std::array<int, 25>& ar)
	{
		bool swap = false;
		int size = sizeof(ar) / sizeof(ar[1]);

		do
		{
			swap = false;
			for (int i = 1; i < size; i++)
			{
				if (ar[i - 1] > ar[i])
				{
					int temp = ar[i];
					ar[i] = ar[i - 1];
					ar[i - 1] = temp;
				}

			}
			swap = true;
		} while (swap);
	}
	const char* selectionSort(std::array<int, 25>& ar)
	{

		for (int i = 0; i <= std::size(ar); i++)
		{
			int min = i;
			for (int j = i+1; j < std::size(ar); j++)
			{
				if(ar[j] < ar[min])
				min = j;

			};
			int temp = ar[i];
			ar[i] = ar[min];
			ar[i] = temp;
		};



	}


	const char* insertionSort(std::array<int,25>& ar)

	{
		for (int i = 1; i < std::size(ar); i++) {
			int value = ar[i];
			int j = i - 1;
			while (j >= 0 && ar[j] > value) {
				ar[j + 1] = ar[j];
				j = j - 1;
			}
			ar[j + 1] = value;
		}
		

	};

};

class searching
{
public:
	const char* binarySearch(std::array<int, 25>& ar, int& num1)
	{

		int left = 0;
		int right = std::size(ar) - 1;

		while (left <= right) {
			int mid = (left + right) / 2;
			if (ar[mid] == num1) {
				std::cout << ar[mid];
			}
			else if (ar[mid] < num1) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		};
		
	};


	const char* lineerSearch(std::array<int, 25>& ar, int& num1)
	{
		for (int i = 0; i < std::size(ar); i++) {
			if (ar[i] == num1)
			{
				std::cout << ar[i];
			}
		}

	};




};







int main()
{
	sorting* srt;
	searching* search;


	std::array<int, 25> ar;

	std::cout << "dizi elemanlarýný ekleyiniz";
	for (int i = 0; i <= 25; i++)
	{
		std::cin >> i;

	};

	

	std::cout << "yapmak istediginiz islem:";
	std::cout << " bubble sort:1",
		"insertion sort:2\n",
		"selection sort:3\n",
		"linear search:4\n";
	"binay search:5\n";

	int selec;

	std::cin >> selec;

	switch (selec)
	{
	case 1:
	{
		printf(srt->bubbleSort(ar));
		break;
	}
	case 2:
	{
		printf(srt->insertionSort(ar));
		break;
	}
	case 3:
	{
		printf(srt->selectionSort(ar));
		break;
	}

	case 4:
	{
		std::cout << "araamak istediginiz degeri giriniz:";
		int num;
		std::cin >> num;
		std::cout << "\n";
		search->lineerSearch(ar, num);
		break;
	}

	case 5:
	{
		std::cout << "araamak istediginiz degeri giriniz:";
		int num2;
		std::cin >> num2;
		std::cout << "\n";
		search->binarySearch(ar, num2);

		break;
	}

	default:
		std::cout << "var olmayan bir islem sectiniz!!!!!!!!!!!!!";

	}



};