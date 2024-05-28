#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int main()
{
    int count = 0;
    // 현재 시간을 시작 시간으로 설정
    chrono::steady_clock::time_point start = chrono::steady_clock::now();

    while (count < 100)
    {
        // count 증가 및 출력
        count++;
        cout << count << "   current time: " << chrono::duration_cast<chrono::seconds>(chrono::steady_clock::now() - start).count() << " seconds since start" << endl;

        // 다음 실행 시간까지 대기
        this_thread::sleep_until(start + chrono::seconds(count));
    }

    return 0;
}
