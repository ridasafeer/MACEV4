#ifndef MODEL_HPP
#define MODEL_HPP

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener *listener)
    {
        modelListener = listener;
    }

    void tick();
    char* getRData() {
        return RData;
    }
    char RData[257];

protected:
    ModelListener *modelListener;
};

#endif // MODEL_HPP
