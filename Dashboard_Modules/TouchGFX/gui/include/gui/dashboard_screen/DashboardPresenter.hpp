/*
 * File: DashboardPresenter.hpp
 *
 * Summary: This file outlines the structure of the DashboardPresenter.cpp file.
 * 			All functions and variables should be related to processing the inputs from the
 * 			model and view classes. The presenter does not directly interact with the GUI
 * 			elements or backend communications.
 */

#ifndef DASHBOARDPRESENTER_HPP
#define DASHBOARDPRESENTER_HPP

// Imports
#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class DashboardView;

class DashboardPresenter : public touchgfx::Presenter, public ModelListener {
public:
    DashboardPresenter(DashboardView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~DashboardPresenter() {};


    /*
     * Declare functions which handle specific data transfers from the model to the view.
     */

	/*
	 * virtual void batteryTempUpdated(int temp)
	 *
	 * Parameters: 		int temp - Integer representing the new temperature.
	 *
	 * Return value: N/A
	 *
	 * Description: 	The batteryTempUpdated function declaration is to be implemented in the
	 * 					DashboardPresenter.cpp file. This function acts as a middleman between the model
	 * 					and dashboard view.
	 */
    virtual void batteryTempUpdated(int temp);

private:
    DashboardPresenter();

    DashboardView& view;
};

#endif // DASHBOARDPRESENTER_HPP
