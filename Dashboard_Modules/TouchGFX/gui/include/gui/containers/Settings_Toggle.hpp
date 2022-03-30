#ifndef SETTINGS_TOGGLE_HPP
#define SETTINGS_TOGGLE_HPP

#include <gui_generated/containers/Settings_ToggleBase.hpp>

class Settings_Toggle : public Settings_ToggleBase
{
public:
    Settings_Toggle();
    virtual ~Settings_Toggle() {}

    virtual void initialize();
protected:
};

#endif // SETTINGS_TOGGLE_HPP
