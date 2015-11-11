#ifndef _CONFIGURATION_H
#define	_CONFIGURATION_H

#include	<string>
#include	<map>

class Configuration
{
public:
	Configuration();
	~Configuration();

	std::string		getProperty(std::string key);
	void			setProperty(std::string key, std::string value);

	bool			importConfig(std::string path);
	bool			exportConfig(std::string path);

private:

	std::map<std::string, std::string>		configurationData;
};

#endif // !_CONFIGURATION_H
