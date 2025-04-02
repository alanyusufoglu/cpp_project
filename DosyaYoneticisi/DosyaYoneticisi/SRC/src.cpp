#include<iostream>
#include<fstream>
#include<string>
#include<filesystem>


int isNum;
std::string fileName;
std::filebuf file;
std::string  islem="DOSYA EKLEME : 1,DOSYA OKUMA:2,DOSYA SÝLME:3,DOSYA ARAMA:4, cýkýs:5";

static void readFile()
{
	std::cout << "lütfen dosya adýný giriniz";
	std::cin >> fileName;
	file.open(fileName, std::ios_base::in);
	if (file.is_open())
	{
		std::istream fileStream(&file);
		std::string content((std::istreambuf_iterator<char>(fileStream)), std::istreambuf_iterator<char>());

		std::cout << "dosya içeriði\n" << content;
		file.close();

	}

	else
	{
		std::cout << "dosya acilmadi";
	}




}

static void addFile()
{
	
	std::string fileName;
	bool isValid = false;

	while (!isValid) {
		std::cout << "Eklemek istediginiz dosya adýný ve uzantisini giriniz: ";
		std::cin >> fileName;

		if (fileName.empty()) {
			std::cout << "Dosya adý boþ olamaz. Lütfen tekrar deneyin.\n";
			continue; 
		}

	
		std::ofstream file(fileName);

		if (file.is_open()) {
			std::cout << "Dosya baþarýlý bir þekilde oluþturuldu.\n";
			std::string text;
			std::cout << "Eklemek istediðiniz metni giriniz: ";
			std::cin.ignore();  
			std::getline(std::cin, text);

			file << text; 
			file.close();  
			std::cout << "Metin baþarýyla dosyaya eklendi." << std::endl;
			isValid = true;  
		}
		else {
			std::cout << "HATA! Dosya oluþturulamadý. Lütfen dosya adýný ve yolunu kontrol edin.\n";
		}
	}
		
		
	

  }


static void removeFile()
{

	std::cout << "silmek istediginiz dosya adini giriniz:";
	std::cin >> fileName;

	
	if (std::filesystem::remove(fileName)) {
		std::cout << "Dosya silindi: " << fileName << std::endl;
	}
	else {
		std::cout << "Dosya silinemedi!" << std::endl;
	}



	

}


static void searchFile()
{
	std::string directoryPath;
	std::cout << "Arama yapmak istediginiz klasörün yolunu giriniz: ";
	std::cin >> directoryPath;

	if (!std::filesystem::exists(directoryPath))
	{
		std::cout << "Hata: Klasör bulunamadý!" << std::endl;
		return;
	}

	for (const auto& entry : std::filesystem::directory_iterator(directoryPath))
	{
		std::cout << "Bulunan dosya: " << entry.path().filename() << std::endl;
	}
	


}

static void fileManager()
{
	std::cout << "Dosya yoneticisi baslatildi\n";

	bool isContiune = true;

		while(isContiune)

		{

			std::cout << "yapmak istediginiz islemi seciniz:" << islem;
			std::cin >> isNum;
			switch (isNum)
			{
	         case 1:

				 addFile();
				break;

			case 2:
				readFile();
				
				break;

			case 3:
				
				removeFile();
				break;
			case 4:
				searchFile();
				
				break;

			case 5:
				isContiune = false;
				break;
			}
		};
}

int main()
{

	fileManager();

	
	return 0;
}