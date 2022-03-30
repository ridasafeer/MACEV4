/*
 * File: DashboardView.hpp
 *
 * Summary: This file outlines the structure of the DashboardView.cpp file (and dashboard view class).
 * 			All functions and variables should be directly tied to GUI elements, any processing or data
 * 			communication is handled by the presenter and model respectively.
 */

#ifndef DASHBOARDVIEW_HPP
#define DASHBOARDVIEW_HPP

#include <gui_generated/dashboard_screen/DashboardViewBase.hpp>
#include <gui/dashboard_screen/DashboardPresenter.hpp>
#include <gui/containers/ProgressWrapper.hpp> // Added reference to ProgressWrapper class

class DashboardView : public DashboardViewBase {
public:
    DashboardView();
    virtual ~DashboardView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    // Function to call each tick ** To be removed ***
    virtual void handleTickEvent();

    /*
     * Setter methods for UI elements. These functions are to be used by the presenter
     * when updated data is passed from the model.
     */

	/*
	 * void setBatteryTemp(int val)
	 *
	 * Parameters: 		int temp - Integer representing the updated battery temperature.
	 *
	 * Return value: N/A
	 *
	 * Description: 	The setBatteryTemp function declaration is to be implemented in the
	 * 					DashboardView.cpp file. This function acts directly access the UI elements
	 * 					and updates them according to the value passed by the presenter.
	 */
    virtual void setBatteryTemp(int temp);

private:
    // Declare private instance variables (pointers)
    ProgressWrapper *batterySOC, *batteryTemp;

protected:
};

#endif // DASHBOARDVIEW_HPP
