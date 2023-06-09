#ifndef DRIVINGSCREENPRESENTER_HPP
#define DRIVINGSCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class DrivingScreenView;

class DrivingScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    DrivingScreenPresenter(DrivingScreenView& v);

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

    virtual ~DrivingScreenPresenter() {};

private:
    DrivingScreenPresenter();

    DrivingScreenView& view;
};

#endif // DRIVINGSCREENPRESENTER_HPP
