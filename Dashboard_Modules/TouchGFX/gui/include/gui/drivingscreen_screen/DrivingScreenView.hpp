#ifndef DRIVINGSCREENVIEW_HPP
#define DRIVINGSCREENVIEW_HPP

#include <gui_generated/drivingscreen_screen/DrivingScreenViewBase.hpp>
#include <gui/drivingscreen_screen/DrivingScreenPresenter.hpp>

class DrivingScreenView : public DrivingScreenViewBase
{
public:
    DrivingScreenView();
    virtual ~DrivingScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // DRIVINGSCREENVIEW_HPP
