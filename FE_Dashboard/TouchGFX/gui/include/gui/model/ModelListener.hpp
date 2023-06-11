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

    //virtual void can_Data(char *data) {}; // also defined insScreenPresenter.hpp
    //virtual void can_Data(char* data) {}; // also defined insScreenPresenter.hpp
    virtual void can_Data(char* data) {};

    //any method functions to use on our screens is defined in modelListener class because the Presenter class is derived from the model listener
    // vs. Model, that just controls ./....?

protected:
    Model *model;
};

#endif // MODELLISTENER_HPP
