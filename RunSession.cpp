#include "RunSession.h"
#include <iostream>

RunSession::RunSession(IInputGenerator* input, IScoringRule* score, IRewardRule* reward)
    : inputGen(input), scoring(score), rewardRule(reward), totalMoney(0), currentRound(1) {}

void RunSession::StartRun() {
    std::cout << "=== RUN START" << std::endl;
    while (currentRound <= 3) { // Tepat 3 ronde [cite: 214]
        std::cout << "Round " << currentRound << std::endl;
        GenerateInputPhase();
        ComputeScorePhase();
        ComputeRewardPhase();
        UpdateMoneyPhase();
        ShopPhase();
        AdvanceRound();
    }
    std::cout << "=== RUN END ===" << std::endl;
    std::cout << "Final money: " << totalMoney << std::endl;
}

void RunSession::GenerateInputPhase() {
    currentInput = inputGen->Generate();
    std::cout << "[PLAY] input generated: " << currentInput.value << std::endl;
}

void RunSession::ComputeScorePhase() {
    currentBaseScore = scoring->ComputeScore(currentInput);
    std::cout << "[SCORE] base score: " << currentBaseScore << std::endl;
}

void RunSession::ComputeRewardPhase() {
    int gain = rewardRule->ComputeReward(currentBaseScore);
    totalMoney += gain; // Update money hanya di fase reward [cite: 249]
    std::cout << "[REWARD] gain: " << gain << " money: " << totalMoney << std::endl;
}

void RunSession::UpdateMoneyPhase() {
    // Fase ini bisa digunakan untuk trigger visual update jika diperlukan
}

void RunSession::ShopPhase() {
    shop.ShowShop();
}

void RunSession::AdvanceRound() {
    currentRound++;
}