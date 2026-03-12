#ifndef RUNSESSION_H
#define RUNSESSION_H

#include "Interfaces.h"
#include "Implementations.h"

class RunSession {
public:
    RunSession(IInputGenerator* input, IScoringRule* score, IRewardRule* reward);
    void StartRun(); // Kontrol utama loop [cite: 196]

private:
    // Urutan fase (Invariant) [cite: 184]
    void GenerateInputPhase();
    void ComputeScorePhase();
    void ComputeRewardPhase();
    void UpdateMoneyPhase();
    void ShopPhase();
    void AdvanceRound();

    IInputGenerator* inputGen;
    IScoringRule* scoring;
    IRewardRule* rewardRule;
    ShopSystem shop;

    int totalMoney;
    int currentRound;
    int currentBaseScore;
    TurnInput currentInput;
};

#endif