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
    uint8_t* getRData() {
        return RData;
    }
    uint8_t RData[257];

protected:
    ModelListener *modelListener;
};

#endif // MODEL_HPP
