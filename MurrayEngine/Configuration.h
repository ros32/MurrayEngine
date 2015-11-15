#ifndef _CONFIGURATION_H
#define	_CONFIGURATION_H

#include	<iostream>
#include	<fstream>
#include	<string>
#include	<map>
#include    <SDL.h>

class Configuration
{
public:
	Configuration();
	Configuration(std::string fileName);
	~Configuration();

	std::string		fileName;
	std::string		getProperty(std::string key);
	void			setProperty(std::string file, std::string key, std::string value);

	void			importConfig(std::string fileName);
	void			exportConfig(std::string fileName, std::string keyName, std::string valueName);

private:

	std::map<std::string, std::string>		configurationData;
};

#endif // !_CONFIGURATION_H
