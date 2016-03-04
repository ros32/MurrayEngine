#include	"Configuration.h"

//	Set iterator and const_iterator to be iterators of std::map
typedef std::map<std::string, std::string>::iterator iterator;
typedef std::map<std::string, std::string>::const_iterator const_iterator;


Configuration::Configuration()
{

}


Configuration::Configuration(std::string fileName)
{
	this->fileName = fileName;
	this->configurationData;
	this->importConfig(fileName);

	

}

Configuration::~Configuration()
{
	this->configurationData.clear();
}


//Imports values from file and stores them in the map configurationData
void Configuration::importConfig(std::string fileName)
{
	std::ifstream file;
	file.open(fileName.c_str(), std::ios::in|std::ios::out);

	std::string line;
	
	if (file.fail())
	{
		std::string errorMsg = "No file found with the name " + fileName;
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, errorMsg.c_str());
	}
	else
	{
		std::string errorMsg = "Found the file " + fileName;
		SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, errorMsg.c_str());
	}
	

	while (std::getline (file, line))
	{
		std::string tempLine = line;

		if (tempLine.empty())
		{
			std::string errorMsg = "Ignoring empty line";
			SDL_LogVerbose(SDL_LOG_CATEGORY_APPLICATION, errorMsg.c_str());
			continue;
		}

		if (tempLine.find(';') != tempLine.npos)
		{
			std::string errorMsg = "Ignoring comment";
			SDL_LogVerbose(SDL_LOG_CATEGORY_APPLICATION, errorMsg.c_str());
			continue;
		}

		size_t equalsPosition = tempLine.find('=');
		std::string key, value;

		key = tempLine.substr(0, equalsPosition);
		value = tempLine.substr(equalsPosition + 1);
	
		configurationData.insert(std::pair <std::string, std::string>(key, value));
	/*	
		-Eftersom vi har c_str kanske vi kan kolla efter sektioner p� nedanst�ende vis?
		 if (tempLine[0]  == '[')
	*/

	}

	// Prints the imported data in SDL_Log for testing purpose
	std::string outString = "Imported Values: \n";
	std::string tempString;

	for (std::map <std::string, std::string>::iterator iter = configurationData.begin(); iter != configurationData.end(); ++iter)
	{
		tempString = outString;
		outString = tempString + iter->first + "=" + iter->second + '\n';
	}

	SDL_LogVerbose(SDL_LOG_CATEGORY_APPLICATION, outString.c_str());
	
	file.close();
	file.clear();
}

//Creates a file with a specified filename and stores keys + values
//Should perhaps check if file exists before writing, and then replace it
void Configuration::exportConfig(std::string fileName)
{
	std::string tempString;
	std::string lineString;

	// TODO: Cleanup debug code

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
		std::string msg = "Error exporting configuration, could not open file";
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, msg.c_str());		
	}

	
}

std::string Configuration::getProperty(std::string key)
{
	iterator iterator;
	iterator = this->configurationData.find(key);

	if (iterator != this->configurationData.end())
		return iterator->second;
	else
		return "";
}

std::string Configuration::getProperty(std::string key, std::string defaultValue)
{
	std::string output = this->getProperty(key);
	if (output == "")
	{
		std::string errorMessage = "A value for key \"" + key + "\" does not exist! Using default value: (string) \"" + defaultValue + "\".";
		SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, errorMessage.c_str());
		return defaultValue;
	}
	else
		return output;
}

int	Configuration::getProperty(std::string key, int defaultValue)
{
	std::string output = this->getProperty(key);
	int returnValue;
	try
	{
		returnValue = std::stoi(output);
	}
	catch (std::exception e)
	{
		std::string errorMessage = "A value for key \"" + key + "\" does not exist! Using default value: (int) \"" + std::to_string(defaultValue) + "\".";
		SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, errorMessage.c_str());
		return defaultValue;
	}

	return returnValue;
}
	
void Configuration::setProperty(std::string key, std::string value)
{
	this->configurationData.insert(std::map<std::string, std::string>::value_type(key, value));
}



iterator Configuration::begin()
{
	return this->configurationData.begin();
}

const_iterator Configuration::begin() const
{
	return this->configurationData.begin();
}

iterator Configuration::end()
{
	return this->configurationData.end();
}

const_iterator Configuration::end() const
{
	return this->configurationData.end();
}