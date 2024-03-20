#include <iostream>
using namespace std;

enum ForeColour
{
    WHITE = 1,      // 흰색
    RED = 10,       // 빨강색
    BLOW = 100,     // 파랑
    YELLOW = 1000,  // 노랑
    GREEN = 10000,  // 초록색
    MAGENTA = 100000, // 마젠타색
};

int main()
{
    cout << "화면에 블록을 만드는 코드입니다." << endl;
    cout << "학번 : 202327035" << endl;
    cout << "이름 : 정회성" << endl;

    int code = 0;

    while (code != 1000000) { 
        cout << "화면에 그릴 물체코드를 입력하세요!" << endl;
        cin >> code;

        if (code == WHITE) {
            cout << "\x1b[37m" << "[]아름다운색 우왕!" << endl; 
        }
        else if (code == RED) {
            cout << "\x1b[31m" << "[]아름다운색 우왕!" << endl; 
        }
        else if (code == BLOW) {
            cout << "\x1b[34m" << "[]아름다운색 우왕!" << endl; 
        }
        else if (code == YELLOW) {
            cout << "\x1b[33m" << "[]아름다운색 우왕!" << endl; 
        }
        else if (code == GREEN) {
            cout << "\x1b[32m" << "[]아름다운색 우왕!" << endl; 
        }
        else if (code == MAGENTA) {
            cout << "\x1b[35m" << "[]아름다운색 우왕!" << endl; 
        }
        else if (code == 1000000) {
            cout << "프로그램을 종료합니다." << endl;
            break; 
        }
        else {
            cout << "유효하지 않은 물체코드입니다." << endl;
        }
    }

    return 0;
}