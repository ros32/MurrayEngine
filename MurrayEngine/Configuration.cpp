#include	"Configuration.h"
#include	<iostream>
#include	<string>
#include	<sstream>
#include	<map>
#include	<fstream>


Configuration::Configuration()
{

}

Configuration::Configuration(std::string fileName)
{
	//1. Kolla om pathen inneh�ller en fil.. Kanske borde ta filnamn som argument ist�llet? Hm.
	this->fileName = fileName;
	this->configurationData;

	

}

Configuration::~Configuration()
{

}


//Imports values from file and stores them in the map configurationData
void Configuration::importConfig(std::string fileName)
{
	std::ifstream file;
	file.open(fileName.c_str());

	std::string line;
	
	if (!file.is_open())
	{
		std::string errorMsg = "No file found with the name " + fileName;
		SDL_Log(errorMsg.c_str());
	}
	else{
		std::string errorMsg = "Found the file " + fileName;
		SDL_Log(errorMsg.c_str());
	}
	

	while (std::getline (file, line))
	{
		std::string tempLine = line;

		if (tempLine.empty()){
			std::string errorMsg = "Current tempLine is empty and is disregarded";
			SDL_Log(errorMsg.c_str());
			continue;
		}

		if (tempLine.find(';') != tempLine.npos){
			std::string errorMsg = "Current tempLine contains a comment and is disregarded";
			SDL_Log(errorMsg.c_str());
			continue;
		}

		size_t equalsPosition = tempLine.find('=');
		std::string key, value;

		key = tempLine.substr(0, equalsPosition);
		value = tempLine.substr(equalsPosition + 1);
	
		configurationData.insert(std::pair <std::string, std::string>(key, value));

		
	/*	
		
		-Kanske borde ha med kontroll p� formatering s� att man tar bort whitespaces 
		 mellan nyckel och v�rden om de skulle finnas d�r.

		-Eftersom vi har c_str kanske vi kan kolla efter sektioner p� nedanst�ende vis?
		 if (tempLine[0]  == '[')
	*/

	}

	std::string outString = "outString output \n";
	std::string tempString;

	for (std::map <std::string, std::string>::iterator iter = configurationData.begin(); iter != configurationData.end(); ++iter){
		tempString = outString;
		outString = tempString + iter->first + "=" + iter->second + '\n';
	}

	SDL_Log(outString.c_str());
	
	file.close();
}
/*
---In Progress!---Later Issue---
Creates a file with a specified filename and stores keys + values
Question is, should it just export whats already in the map, or should it also add information to the map
as is the current function?
*/
void Configuration::exportConfig(std::string fileName, std::string keyName, std::string valueName)
{
	std::string tempString;
	std::string lineString;

	configurationData.insert(std::pair<std::string, std::string>(keyName, valueName));
	configurationData.insert(std::pair<std::string, std::string>("ehhej", "ehneh"));
	configurationData.insert(std::pair<std::string, std::string>("Age", "666"));
	configurationData.insert(std::pair<std::string, std::string>("; Im a comment", " "));

	for (std::map <std::string, std::string>::iterator iter = configurationData.begin(); iter != configurationData.end(); ++iter)
	{

		lineString = (tempString + iter->first + "=" + iter->second + "\n");
		tempString = lineString;
	}

	std::ofstream file(fileName);

	if (file.is_open())
	{
		file << "" + lineString;
		file.close();
	}
	else
	{
		std::string msg = "A problem occured when exporting configuration, file could not open";
		SDL_Log(msg.c_str());		
	}

	
}

//Returns the value for a given key
std::string	Configuration :: getProperty(std::string keyName)
{
	std::string resultValue;	

	for (std::map <std::string, std::string>::iterator iter = configurationData.begin(); iter != configurationData.end(); ++iter){
		if (configurationData.find(keyName) != configurationData.end());
		resultValue = iter->second;
	}

	return resultValue;

}

/*
Is this ment to open an existing file and then add keys + values if they dont exist and/or change a value for a given key?

*/
void Configuration :: setProperty(std::string fileName, std::string keyName, std::string valueName)
{
	std::string tempString;
	std::string lineString;

	for (std::map <std::string, std::string>::iterator iter = configurationData.begin(); iter != configurationData.end(); ++iter)
	{
	
		//Ist�llet k�ra en koll p� om nyckeln finns och ers�tta med nytt v�rde d� kanske

		lineString = (tempString + iter->first + "=" + iter->second + "\n");
		tempString = lineString;
	}
	
	//Ska nog k�ra in inputFileStream, fr�gan �r hur man �ndrar v�rden i en befintlig fil o.O

	std::ofstream file(fileName);
	
	if (file.is_open())
	{
		file << "" + lineString;
		file.close();
	}
	else
	{
		std::string msg = "A problem occured when setting Property, file could not open";
		SDL_Log(msg.c_str());
	}
	
}

//Will check if a file with the given name already exists
bool fileExists(std::string fileName)
{
	return false;
}

