/*
 * File: ProgressWrapper.cpp
 *
 * Summary: This file contains the implementation of the ProgressWrapper class (defined in ProgressWrapper.hpp).
 * 			The wrapper allows for more granular control over TouchGFX generated box progress bars and reduces
 * 			repetitive code. Specifically, this class sets the bar parameters and updates the colouring based
 * 			off of the passed input data.
 */

// Imports
#include <gui/containers/ProgressWrapper.hpp>
#include <touchgfx/Color.hpp>

/*
 * Constructor:
 *
 * Parameters:		touchgfx::BoxProgress *progress_bar - The address of the generated TouchGFX progress bar is will be manipulated
 * 					progressConfig config - The configuration struct used to set the progress bar parameters. The definition can be found in the class header file.
 */
ProgressWrapper::ProgressWrapper(touchgfx::BoxProgress *progress_bar, progessConfig config) {

	// Store passed data to instance variables
	this->bar = progress_bar;

	// Unpack configuration into instance variables
	this->maxValue = config.maxValue;
	this->minValue = config.minValue;
	this->minColour = config.minColour;
	this->maxColour = config.maxColour;

	// Set progress bar parameters from config
	bar->setRange(config.minValue, config.maxValue);

}


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
void ProgressWrapper::setValue(int val){

	// Check if provided value is in acceptable range, ignore if not
	if (val < minValue || val > maxValue)
		return;

	// Update bar value
	bar->setValue(val);

	// Compute red, green, and blue values for new progress bar value
	// This shifts the "hex" colour code so that the 8 relevant bits are passed to the computeColour function
	int red = computeColour((minColour >> 16) & 0xFF, (maxColour >> 16) & 0xFF, val);
	int green = computeColour((minColour >> 8) & 0xFF, (maxColour >> 8) & 0xFF, val);
	int blue = computeColour(minColour & 0xFF, maxColour & 0xFF, val);

	bar->setColor(touchgfx::Color::getColorFrom24BitRGB(red, green, blue)); // Send updated colour data to bar

	bar->invalidate(); // Re-draw progress bar
}

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
int ProgressWrapper::computeColour(int startColour, int endColour, int progress){

	// Linear equation, treat startColour as the y intercept and find value at current progress
	return startColour + (endColour - startColour)/(maxValue - minValue) * progress;

}

