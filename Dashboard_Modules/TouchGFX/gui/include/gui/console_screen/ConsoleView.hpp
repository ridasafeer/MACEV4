#ifndef CONSOLEVIEW_HPP
#define CONSOLEVIEW_HPP

#include <gui_generated/console_screen/ConsoleViewBase.hpp>
#include <gui/console_screen/ConsolePresenter.hpp>

class ConsoleView : public ConsoleViewBase
{
public:
    ConsoleView();
    virtual ~ConsoleView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    // user code begin
    virtual void updateTerminal();

protected:
};

#endif // CONSOLEVIEW_HPP
