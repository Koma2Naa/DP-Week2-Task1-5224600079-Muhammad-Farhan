#ifndef IMPLEMENTATIONS_H
#define IMPLEMENTATIONS_H

#include "Interfaces.h"

// Modifikasi 1: Random Input Generator [cite: 235]
class RandomInputGenerator : public IInputGenerator {
public:
    TurnInput Generate() override;
};

class BasicScoring : public IScoringRule {
public:
    int ComputeScore(TurnInput input) override;
};

// Modifikasi 2: Custom Reward Logic [cite: 240]
class CustomReward : public IRewardRule {
public:
    int ComputeReward(int baseScore) override;
};

class ShopSystem {
public:
    void ShowShop();
};

#endif