#ifndef _ACTION_H
#define _ACTION_H

///-------------------------------------------------------------------------------------------------
/// <summary>	The Action interface depicts Actions that can be launched by the user (from the keyboard)
/// 			or the AI (from the AI interface implementations). Each Action is parameterized in the
/// 			constructor and is performed by using execute().
/// 			
/// 			A progress system exist for actions that should take more than one tick to perform. </summary>
///
/// <remarks>	Rosen, 2016-02-28. </remarks>
///-------------------------------------------------------------------------------------------------
class Action{

public:

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Default constructor. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///-------------------------------------------------------------------------------------------------
	Action();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Destructor. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///-------------------------------------------------------------------------------------------------
	virtual ~Action();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Executes this object. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///-------------------------------------------------------------------------------------------------
	virtual void execute() = 0;

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Query if this object is completed. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <returns>	true if completed, false if not. </returns>
	///-------------------------------------------------------------------------------------------------
	bool	isCompleted() const;

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets the progress. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <returns>	The progress. </returns>
	///-------------------------------------------------------------------------------------------------
	double	getProgress() = delete;

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Sets the progress. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <param name="progress">	The progress. </param>
	///-------------------------------------------------------------------------------------------------
	void	setProgress(double progress);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Updates the progress described by progress. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <param name="progress">	The progress. </param>
	///-------------------------------------------------------------------------------------------------
	void	updateProgress(double progress);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Copies this object. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <returns>	null if it fails, else an Action*. </returns>
	///-------------------------------------------------------------------------------------------------
	virtual Action*	copy() = 0;


private:

	/// <summary>	The progress. </summary>
	double progress;

};

 #endif // !_ACTION_H