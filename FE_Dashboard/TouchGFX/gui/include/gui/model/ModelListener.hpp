#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>

class ModelListener
{
public:
    ModelListener() : model(0) {}

    virtual ~ModelListener() {}

    void bind(Model *m)
    {
        model = m;
    }

    virtual void can_Data(char *data); // also defined in ScreenPresenter.hpp

protected:
    Model *model;
};

#endif // MODELLISTENER_HPP
