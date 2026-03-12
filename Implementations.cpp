#include "Implementations.h"
#include <iostream>
#include <cstdlib>

TurnInput RandomInputGenerator::Generate() {
    return { (std::rand() % 10) + 1 };
}

int BasicScoring::ComputeScore(TurnInput input) {
    return input.value * 10; 
}

int CustomReward::ComputeReward(int baseScore) {
    // Implementasi Modifikasi 2: Reward tidak sama dengan base score [cite: 241]
    return baseScore + 5; 
}

void ShopSystem::ShowShop() {
    std::cout << "[SHOP] offered: Upgrade cost 5" << std::endl;
    std::cout << "[SHOP] skipped" << std::endl;
}