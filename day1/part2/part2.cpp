#include <iostream>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string rotation;
    long long curr = 50;
    long long count = 0;

    while (getline(cin, rotation)) {
        char dir = rotation[0];
        long long dist = stoll(rotation.substr(1));

        long long firstHit;

        if (dir == 'R') {
            firstHit = (100 - curr) % 100;
        } else {
            firstHit = curr % 100;
        }

        if (firstHit == 0) firstHit = 100;

        if (firstHit <= dist) {
            count += 1 + (dist - firstHit) / 100;
        }
        if (dir == 'R')
            curr = (curr + dist) % 100;
        else
            curr = (curr - dist % 100 + 100) % 100;
    }

    cout << count << "\n";
    return 0;
}
