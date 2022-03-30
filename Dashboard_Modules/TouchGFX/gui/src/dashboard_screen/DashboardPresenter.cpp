/*
 * File: DashboardPresenter.cpp
 *
 * Summary: This file is the presenter for the main screen of the dashboard (the dashboard itself). The declaration of this
 * 			class can be found in the gui/include/dashboard_screen/DashboardPresenter.hpp file.
 *
 * 			TouchGFX/STM32 uses a MVP (model, view, presenter) design, the supporting files for the model and view can
 * 			be found in the gui/src folder.
 *
 * 			The presenter file of a screen interfaces between the GUI and the model. The presenter handles new data and
 * 			sets the priority of events to/from the view/model.
 */


// Imports
#include <gui/dashboard_screen/DashboardView.hpp>
#include <gui/dashboard_screen/DashboardPresenter.hpp>


DashboardPresenter::DashboardPresenter(DashboardView& v) : view(v) {

}

void DashboardPresenter::activate() {

}

void DashboardPresenter::deactivate() {

}

/*
 * void batteryTempUpdated(int temp)
 *
 * Parameters: 		int temp - Integer representing the updated battery temperature.
 *
 * Return value: N/A
 *
 * Description: 	The batteryTempUpdated function handles passing the updated battery temperature to the UI views
 * 					that require it. Any data manipulation for the views specifically should be done here.
 */
void DashboardPresenter::batteryTempUpdated(int temp){
	view.setBatteryTemp(temp);
}
