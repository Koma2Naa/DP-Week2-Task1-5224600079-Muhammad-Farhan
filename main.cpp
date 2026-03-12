#include "RunSession.h"
#include "Implementations.h"
#include <ctime>
#include <cstdlib>

int main() {
    std::srand(static_cast<unsigned int>(std::time(0)));

    // Inisialisasi komponen konkret
    RandomInputGenerator input;
    BasicScoring scoring;
    CustomReward reward;

    // RunSession dipanggil tanpa modifikasi internal [cite: 237, 245]
    RunSession run(&input, &scoring, &reward);
    run.StartRun();

    return 0;
}