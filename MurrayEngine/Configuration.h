#ifndef _CONFIGURATION_H
#define	_CONFIGURATION_H

#include	<iostream>
#include	<fstream>
#include	<string>
#include	<map>
#include    <SDL.h>

///	<summary>
///	The Configuration class contain mapped data read from a configuration file
//	</summary>
class Configuration
{
public:
	Configuration();
	Configuration(std::string fileName);
	~Configuration();

	typedef std::map<std::string, std::string>::iterator iterator;
	typedef std::map<std::string, std::string>::const_iterator const_iterator;

	std::string		fileName;

	///	<summary>
	///	Get value of a Configuration key
	///	</summary>
	std::string		getProperty(std::string key);

	std::string		getProperty(std::string key, std::string defaultValue);
	int				getProperty(std::string key, int defaultValue);

	///	<summary>
	///	Set value of a Configuration key
	///	</summary>
	void			setProperty(std::string key, std::string value);

	///	<summary>
	///	Import Configuration from a file
	///	</summary>
	void			importConfig(std::string fileName);

	///	<summary>
	///	Export Configuration to a file
	///	</summary>
	void			exportConfig(std::string fileName, std::string keyName, std::string valueName);

	iterator		begin();
	const_iterator	begin() const;

	iterator		end();
	const_iterator	end() const;

private:
	std::map<std::string, std::string>		configurationData;
};

#endif // !_CONFIGURATION_H
