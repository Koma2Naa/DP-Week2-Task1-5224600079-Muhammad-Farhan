#ifndef INTERFACES_H
#define INTERFACES_H

struct TurnInput {
    int value;
};

class IInputGenerator {
public:
    virtual ~IInputGenerator() {}
    virtual TurnInput Generate() = 0;
};

class IScoringRule {
public:
    virtual ~IScoringRule() {}
    virtual int ComputeScore(TurnInput input) = 0;
};

class IRewardRule {
public:
    virtual ~IRewardRule() {}
    virtual int ComputeReward(int baseScore) = 0;
};

#endif