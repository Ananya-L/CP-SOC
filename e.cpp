#include <iostream>
#include <map>
using namespace std;

long long testCases, numElements, numQueries, elemX, elemY;

int main() {
    cin >> testCases;
    while (testCases--) {
        cin >> numElements >> numQueries;
        map<int, int> firstOccurrence, lastOccurrence;
        for (int i = 1; i <= numElements; i++) {
            cin >> elemX;
            if (firstOccurrence[elemX] == 0) {
                firstOccurrence[elemX] = i;
            }
            lastOccurrence[elemX] = i;
        }
        
        for (int i = 0; i < numQueries; i++) {
            cin >> elemX >> elemY;
            if (firstOccurrence[elemX] != 0 && firstOccurrence[elemY] != 0 && lastOccurrence[elemY] >= firstOccurrence[elemX]) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}
