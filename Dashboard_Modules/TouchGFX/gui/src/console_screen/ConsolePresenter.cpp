#include <gui/console_screen/ConsoleView.hpp>
#include <gui/console_screen/ConsolePresenter.hpp>

ConsolePresenter::ConsolePresenter(ConsoleView &v)
    : view(v)
{
}

void ConsolePresenter::activate()
{
}

void ConsolePresenter::deactivate()
{
}

void ConsolePresenter::dataRxed()
{
    view.updateTerminal();
}