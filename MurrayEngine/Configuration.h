#ifndef _CONFIGURATION_H
#define	_CONFIGURATION_H

#include	<sstream>
#include	<iostream>
#include	<fstream>
#include	<string>
#include	<map>
#ifdef _WIN32
#include <SDL.h>
#elif __linux__
#include <SDL2/SDL.h>
#endif

///-------------------------------------------------------------------------------------------------
/// <summary>	The Configuration class is very similar to the Properties class in Java,
/// 			in that it contains a map of keys and values that can be loaded from
/// 			a file.</summary>
///
/// <remarks>	Rosen, 2016-02-28. </remarks>
///-------------------------------------------------------------------------------------------------
class Configuration
{
public:

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Create an empty Configuration object. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///-------------------------------------------------------------------------------------------------
	Configuration();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Create a Configuration object by importing a .cfg file.
	/// 			
	/// 			Files used by the Configuration class has the extension .cfg and follows
	/// 			(somewhat) the INI-file syntax, in that KEY=VALUE and whitespace is not
	/// 			allowed.
	///
	/// 			All .cfg files must use \n line breaks to be compatible with both Windows
	/// 			and UNIX. Using \r\n line breaks in UNIX will cause unexpected behavior.</summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <param name="fileName">	Filename of the file. </param>
	///-------------------------------------------------------------------------------------------------
	Configuration(std::string fileName);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Destructor. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///-------------------------------------------------------------------------------------------------
	~Configuration();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Defines an alias representing the iterator. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///-------------------------------------------------------------------------------------------------
	typedef std::map<std::string, std::string>::iterator iterator;

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Defines an alias representing the constant iterator. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///-------------------------------------------------------------------------------------------------
	typedef std::map<std::string, std::string>::const_iterator const_iterator;

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Get a string value from a key, or return an empty string. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <param name="key">	The key. </param>
	///
	/// <returns>	The property. </returns>
	///-------------------------------------------------------------------------------------------------
	std::string		getProperty(std::string key);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Get a string value from a key, or return the provided string defaultValue  </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <param name="key">		   	The key. </param>
	/// <param name="defaultValue">	The default value. </param>
	///
	/// <returns>	The property. </returns>
	///-------------------------------------------------------------------------------------------------
	std::string		getProperty(std::string key, std::string defaultValue);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Interpret a property value from a key into an int, or return the provided
	/// 			int defaultValue. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <param name="key">		   	The key. </param>
	/// <param name="defaultValue">	The default value. </param>
	///
	/// <returns>	The property. </returns>
	///-------------------------------------------------------------------------------------------------
	int				getProperty(std::string key, int defaultValue);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Sets a property. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <param name="key">  	The key. </param>
	/// <param name="value">	The value. </param>
	///-------------------------------------------------------------------------------------------------
	void			setProperty(std::string key, std::string value);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Import configuration.
	/// 			
	/// 			Files used by the Configuration class has the extension .cfg and follows
	/// 			(somewhat) the INI-file syntax, in that KEY=VALUE and whitespace is not
	/// 			allowed.
	///
	/// 			All .cfg files must use \n line breaks to be compatible with both Windows
	/// 			and UNIX. Using \r\n line breaks in UNIX will cause unexpected behavior.</summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <param name="fileName">	Filename of the file. </param>
	///-------------------------------------------------------------------------------------------------
	void			importConfig(std::string fileName);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Export configuration. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <param name="fileName">	Filename of the file. </param>
	///-------------------------------------------------------------------------------------------------
	void			exportConfig(std::string fileName);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	The begin() iterator. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <returns>	An iterator. </returns>
	///-------------------------------------------------------------------------------------------------
	iterator		begin();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	The constant begin() iterator. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <returns>	A const_iterator. </returns>
	///-------------------------------------------------------------------------------------------------
	const_iterator	begin() const;

	///-------------------------------------------------------------------------------------------------
	/// <summary>	The end() iterator. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <returns>	An iterator. </returns>
	///-------------------------------------------------------------------------------------------------
	iterator		end();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	The constant end() iterator. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <returns>	A const_iterator. </returns>
	///-------------------------------------------------------------------------------------------------
	const_iterator	end() const;

private:

	/// <summary>	Information describing the configuration. </summary>
	std::map<std::string, std::string>		configurationData;

	/// <summary>	Filename of the file. </summary>
	std::string								fileName;

};

#endif // !_CONFIGURATION_H
