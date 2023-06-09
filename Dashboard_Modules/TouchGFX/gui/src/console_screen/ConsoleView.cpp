#include <gui/console_screen/ConsoleView.hpp>
#include <cstring>

extern char dataBuffer[100];

ConsoleView::ConsoleView()
{
}

void ConsoleView::setupScreen()
{
    ConsoleViewBase::setupScreen();
}

void ConsoleView::tearDownScreen()
{
    ConsoleViewBase::tearDownScreen();
}

void ConsoleView::updateTerminal()
{
    char forrestTest[20] = "Forrest Herman Code";
    // char forrestTest2[20] = "F";
    // Unicode::snprintf(textTerminalBuffer, TEXTTERMINAL_SIZE, "Testing %d", 13);
    Unicode::strncpy(textTerminalBuffer, forrestTest, strlen(forrestTest));
    textTerminal.invalidate();
    // memset(dataBuffer, '\0', sizeof(dataBuffer));

    // This is a hack to get the scrollable container to scroll to the bottom
    // when new text is added to the text area.
    // The scrollable container is not updated when the text area is updated.
    // This is a known issue in TouchGFX 4.10.0.
    // See https://support.touchgfx.com/support/discussions/topics/11000006476
    // scrollableContainer1.moveTo(scrollableContainer1.getScrollRange());
}