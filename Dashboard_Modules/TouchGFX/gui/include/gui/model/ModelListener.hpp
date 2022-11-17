/*
 * File: ModelListener.hpp
 *
 * Summary: This file defines the functions that the screen presenters can use to interact with the data
 * 			provided by the TouchGFX model. Functions should be declared as empty and overridden by each
 * 			presenter that needs to use them.
 */

#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

// Imports
#include <gui/model/Model.hpp>

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}

    virtual void dataRxed() {}

    void bind(Model* m)
    {
        model = m;
    }


    /*
     * Functions to notify presenters of updated data from the model.
     * Need to be overridden by the presenter implementations that require it.
     */
    virtual void batteryTempUpdated(int temp){}
protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
