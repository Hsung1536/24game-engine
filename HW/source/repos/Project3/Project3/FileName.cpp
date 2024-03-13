#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

class StockGame {
private:
    double stockPrice;

public:
    StockGame(double initialPrice = 100) : stockPrice(initialPrice) {}

    void updateStockPrice() {
        // 가격을 -5%에서 5%까지 랜덤하게 조정
        double percentageChange = ((rand() % 11) - 5) / 100.0;
        stockPrice *= (1 + percentageChange);
    }

    void runGame(int numMinutes = 10) {
        for (int minute = 1; minute <= numMinutes; ++minute) {
            std::cout << "Minute " << minute << ": Stock Price - " << stockPrice << std::endl;
            updateStockPrice();
            std::this_thread::sleep_for(std::chrono::minutes(1)); // 1분 대기
        }
    }
};

int main() {
    // 랜덤 시드 설정
    std::srand(std::time(0));

    StockGame game;
    game.runGame();

    return 0;
}