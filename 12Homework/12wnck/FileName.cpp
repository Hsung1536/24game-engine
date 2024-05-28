#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int main()
{
    int count = 0;
    // ���� �ð��� ���� �ð����� ����
    chrono::steady_clock::time_point start = chrono::steady_clock::now();

    while (count < 100)
    {
        // count ���� �� ���
        count++;
        cout << count << "   current time: " << chrono::duration_cast<chrono::seconds>(chrono::steady_clock::now() - start).count() << " seconds since start" << endl;

        // ���� ���� �ð����� ���
        this_thread::sleep_until(start + chrono::seconds(count));
    }

    return 0;
}
