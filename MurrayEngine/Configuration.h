#ifndef _CONFIGURATION_H
#define	_CONFIGURATION_H

#include	<iostream>
#include	<fstream>
#include	<string>
#include	<map>
#ifdef _WIN32
#include <SDL.h>
#elif __linux__
#include <SDL2/SDL.h>
#endif
#include	<sstream>


///	<summary>
///	The Configuration stores key and value pairs that can be read from and written to file.
///	Configuration (.cfg) files uses a similiar syntax to INI-files.
///	</summary>
class Configuration
{
public:

	///	<summary>
	///	Create an empty Configuration object. 
	///	</summary>
	Configuration();

	///	<summary>
	///	Create a Configuration from the specified file.
	///	</summary>
	Configuration(std::string fileName);

	~Configuration();

	//	Typedef iterators for simplification
	typedef std::map<std::string, std::string>::iterator iterator;
	typedef std::map<std::string, std::string>::const_iterator const_iterator;

	///	<summary>
	///	Get value of a Configuration key. Returns an empty string if value is not found.
	///	</summary>
	std::string		getProperty(std::string key);

	///	<summary>
	///	Get value of a Configuration key, or return defaultValue if key is not found.
	///	</summary>
	std::string		getProperty(std::string key, std::string defaultValue);

	///	<summary>
	///	Get value of a Configuration key and try to parse as int. Return defaultValue
	///	either if key is not found or parsing failed
	///	</summary>
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
	void			exportConfig(std::string fileName);

	//	Iterators

	//	We need the iterators begin() and end() to be able to use for(auto key : configuration) on the Configuration object.
	iterator		begin();
	const_iterator	begin() const;

	iterator		end();
	const_iterator	end() const;

private:

	//	map<string, string> where data is stored
	std::map<std::string, std::string>		configurationData;

	//	Name of imported file
	std::string		fileName;

};

#endif // !_CONFIGURATION_H
