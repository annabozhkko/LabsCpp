#include "consoleView.h"

void ConsoleView::showGame(int *field1, int *field2) {
    cout << "   ";
    for(int i = 0; i < 10; ++i)
        cout << (char)('a' + i) << ' ';
    cout << "  ";
    for(int i = 0; i < 10; ++i)
        cout << (char)('a' + i) << ' ';
    cout << '\n';
    for(int i = 0; i < 10; ++i) {
        cout << i + 1 << ' ';
        if (i < 9)
            cout << ' ';
        for (int j = 0; j < 10; ++j) {
            if (field1[i * 10 + j] == EMPTY)
                cout << "  ";
            if (field1[i * 10 + j] == MISS)
                cout << ". ";
            if (field1[i * 10 + j] == SHIP)
                cout << "# ";
            if (field1[i * 10 + j] == HITSHIP)
                cout << "x ";
        }
        cout << "  ";
        for (int j = 0; j < 10; ++j) {
            if (field2[i * 10 + j] == EMPTY)
                cout << "  ";
            if (field2[i * 10 + j] == MISS)
                cout << ". ";
            if (field2[i * 10 + j] == SHIP)
                cout << "  ";
            if (field2[i * 10 + j] == HITSHIP)
                cout << "x ";
        }
        cout << '\n';
    }
    cout << '\n';
}
