#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string rotation;
    int curr = 50;     
    int count = 0;    

    while (getline(cin, rotation)) {
        char dir = rotation[0];
        int dist = stoi(rotation.substr(1));

        if (dir == 'R') {
            curr += dist;
        } else { 
            curr -= dist;
        }

        curr = ((curr % 100) + 100) % 100;

        if (curr == 0) {
            count++;
        }
    }
    cout << count << "\n";

    return 0;
}
