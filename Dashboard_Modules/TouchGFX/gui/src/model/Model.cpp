/*
 * File: Model.cpp
 *
 * Summary: This file is the model for the TouchGFX GUI interface. The declaration of this
 * 			class can be found in the gui/include/model/Model.hpp file.
 *
 * 			TouchGFX/STM32 uses a MVP (model, view, presenter) design, the supporting files for the views and presenters
 * 			can be found in the gui/src folder.
 *
 * 			The model file interacts directly with the backend communication channels and controls the data processing
 * 			for the GUI. The listener functions used in this file can be found in ModelListener.hpp, which declares the
 * 			functions to be implemented by the presenters if they want to handle each particular dataset sent by the model.
 */

// Imports
#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

extern int isDataTerminal;

// Temporary variable for testing
int count_model = 0;

Model::Model() : modelListener(0) {

}

void Model::tick() {

	// Temporary - for testing only
	// Increment count if less than 100, reset to 0 when >= 100
	count_model = count_model < 100 ? count_model + 1 : 0;

	// On each tick, update the battery temperature with the count
	modelListener->batteryTempUpdated(count_model);

//	if (isDataTerminal == 1)
//	{
//		modelListener->dataRxed();
//		isDataTerminal = 0;
//	}
}
