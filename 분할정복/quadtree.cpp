#include <bits/stdc++.h>
using namespace std;


string reverse(string::iterator& it) {
    char head = *(it++);
    if(head == 'w' || head == 'b')
        return string(1, head);
    string upperLeft = reverse(it);
    string upperRight = reverse(it);
    string lowerLeft = reverse(it);
    string lowerRight = reverse(it);
    return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}


int main() {
    int TC; cin >> TC;
    for(int t = 0; t < TC; t++) {
        string qt;
        cin >> qt;
        auto it = qt.begin();
        cout << reverse(it) << endl;
    }
}