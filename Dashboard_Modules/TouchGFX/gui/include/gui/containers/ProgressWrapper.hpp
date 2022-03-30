/*
 * File: ProgressWrapper.hpp
 *
 * Summary: This file contains the structure of the ProgressWrapper class that is implemented in the
 * 			ProgressWrapper.cpp file.
 */

#ifndef PROGRESSWRAPPER_HPP
#define PROGRESSWRAPPER_HPP

// Imports
#include <touchgfx/containers/progress_indicators/BoxProgress.hpp>
#include <touchgfx/Color.hpp>

/*
 * Struct:
 *
 * Parameters:		int minValue - The minimum value of the progress bar
 * 					int maxValue - The maximum value of the progress bar
 * 					unsigned long minColour - The colour of the progress bar when it is at its minimum.
 * 											  This is represented by a hex colour code.
 * 					unsigned long maxColour - The colour of the progress bar when it is at its maximum.
 * 											  This is represented by a hex colour code.
 */
typedef struct progressConfig {
		int minValue = 0;
		int maxValue = 100;
		unsigned long minColour = 0xFF0000;
		unsigned long maxColour = 0x00FF00;
} progessConfig;


/*
 * Class declaration:
 *
 * Summary:	This class adds additional functionality to the TouchGFX BoxProgress elements and reduces repetitive code
 * 			within the project. This also ensures that the design and functionality is consistent across the dashboard.
 */
class ProgressWrapper {
	public:

		/*
		 * Constructor:
		 *
		 * Parameters:		touchgfx::BoxProgress *progress_bar - The address of the generated TouchGFX progress bar is will be manipulated
		 * 					progressConfig config - The configuration struct used to set the progress bar parameters. The definition can be found above.
		 */
		ProgressWrapper(touchgfx::BoxProgress *progress_bar, progessConfig config);

		virtual ~ProgressWrapper() {}

		/*
		 * void setValue(int val)
		 *
		 * Parameters: 		int val - Integer representing the value that the progress bar should be set to
		 *
		 * Return value: N/A
		 *
		 * Description: 	The setValue function updates the progress bar's value and sets it colour accordingly.
		 * 					The function also ensures that the passed value is within the bar's range and ignores it if
		 * 					it is invalid.
		 */
		void setValue(int val);


	private:
		// Private instance variable declaration
		int minValue, maxValue, minColour, maxColour;
		touchgfx::BoxProgress *bar;

		/*
		 * int computeColour(int startColour, int endColour, int progress)
		 *
		 * Parameters: 		int startColour - The intensity of the colour at the starting position of the bar (minValue)
		 * 					int endColour - The intensity of the colour at the ending position of the bar (maxValue)
		 * 					int progress - The current value of the progress bar
		 *
		 * Return value: 	int - The intensity of the current colour channel that is proporional to the current bar progress.
		 *
		 * Description: 	The computeColour function is a helper function which calculates the intensity of a colour
		 * 					based off of the current progress of the bar.
		 */
		int computeColour(int startColour, int endColour, int progress);

	protected:

};

#endif
