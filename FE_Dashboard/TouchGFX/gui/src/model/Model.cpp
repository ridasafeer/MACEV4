#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#ifndef SIMULATOR
#include "main.h"
#include "cmsis_os2.h"
#include <cstring>
extern "C"
{
    extern osMessageQueueId_t canQueueHandle;
    canData_t *canData_r;
}
#endif

Model::Model() : modelListener(0)
{
}

void Model::tick()
{

#ifndef SIMULATOR
    if (osMessageQueueGetCount(canQueueHandle) > 0)
    {
        if (osMessageQueueGet(canQueueHandle, &canData_r, 0, 0) == osOK)
        {
            strncpy(RData, canData_r->Data, canData_r->size);
            modelListener->can_Data(RData);
        }
    }

    strncpy(RData, stringTest, sizeof(stringTest));

#endif
}
