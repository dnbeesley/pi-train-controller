
struct SingalCondition
{
    unsigned short motorState;
    unsigned short pointsState;
    unsigned char result;
};

struct SignalSet
{
    SingalCondition *conditions;
    unsigned int conditionCount;
    unsigned char address;
    unsigned char currentState;
    unsigned char defaultState;
};

class SignalControllerClass
{
public:
    void begin(SignalSet *signalSets, unsigned int signalSetCount);
    void updateSignalSets(unsigned short motorState, unsigned short pointsState);

private:
    unsigned char calculateNewState(SignalSet *signalSet, unsigned short motorState, unsigned short pointsState);
    bool statesMatch(unsigned short expected, unsigned short actual);
    SignalSet *signalSets;
    unsigned int signalSetCount;
};

extern SignalControllerClass SignalController;
