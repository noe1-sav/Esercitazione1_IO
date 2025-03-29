#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
int main()
{
	std::ifstream file("data.txt"); //Apre il file
	if (!file) //Controlla se il file è stato aperto correttamente
	{
		std::cerr << "Non è stato possibile aprire il file" << std::endl;
		return 1; //Esce con codice di errore
	}
		//scrivere nel file
	std::ofstream outputFile("result.txt");
	if (!outputFile) 
	{
		std::cerr << "Non è stato possibile aprire il file" << std::endl;
		return 1;
	}		

	outputFile << std::setprecision(16) << std::scientific;
	std::string tmp;
	while (std::getline(file,tmp)){ //legge una riga del file
	  std::cout << "Stringa letta:" << tmp << std::endl; //la stampa
	//Devo mappare i punti da [-1,2]
	  double val = std::stod(tmp); //stod trasforma una stringa in double
	  if (val >= -1.0 && val <= 2.0){
		std::cout << "il valore" << val << "è compreso" << std::endl;
		outputFile << val << std::endl;
	} else  {
		std::cout << "il valore" << val << "non è compreso" << std::endl;
	}
	}	
	
	file.close();
	outputFile.close();
	
	
	   return 0;
}
   
