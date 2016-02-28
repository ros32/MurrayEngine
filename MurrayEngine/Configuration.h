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
/// <summary>	A configuration. </summary>
///
/// <remarks>	Rosen, 2016-02-28. </remarks>
///-------------------------------------------------------------------------------------------------
class Configuration
{
public:

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Default constructor. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///-------------------------------------------------------------------------------------------------
	Configuration();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Constructor. </summary>
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
	/// <summary>	Gets a property. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <param name="key">	The key. </param>
	///
	/// <returns>	The property. </returns>
	///-------------------------------------------------------------------------------------------------
	std::string		getProperty(std::string key);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets a property. </summary>
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
	/// <summary>	Gets a property. </summary>
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
	/// <summary>	Import configuration. </summary>
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
	/// <summary>	Gets the begin. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <returns>	An iterator. </returns>
	///-------------------------------------------------------------------------------------------------
	iterator		begin();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets the begin. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <returns>	A const_iterator. </returns>
	///-------------------------------------------------------------------------------------------------
	const_iterator	begin() const;

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets the end. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <returns>	An iterator. </returns>
	///-------------------------------------------------------------------------------------------------
	iterator		end();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets the end. </summary>
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
