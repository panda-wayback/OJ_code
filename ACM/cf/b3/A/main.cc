#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> PII;


PII getIndex(string indexStr) {
    int y = indexStr[0] - 'a';
    int x = indexStr[1] - '0';

    return make_pair(x, y);
}

/**
 这样写可以让代码变得更加精简
 */
string checkX(PII &startIndex, PII &endIndex) {
    if (startIndex.second < endIndex.second) {
        startIndex.second += 1;
        return "R";
    }

    if (startIndex.second > endIndex.second) {
        startIndex.second -= 1;
        return "L";
    }

    if (startIndex.second == endIndex.second) {
        return string();
    }
}

string checkY(PII &startIndex, PII &endIndex) {
    if (startIndex.first < endIndex.first) {
        startIndex.first += 1;
        return "U";
    }

    if (startIndex.first > endIndex.first) {
        startIndex.first -= 1;
        return "D";
    }

    if (startIndex.first == endIndex.first) {
        return string();
    }
}

vector<string> tag;

void recursion(PII &startIndex, PII &endIndex) {
    //cout<<startIndex.first << ' '<<startIndex.second << ' '<<endIndex.first << ' '<<endIndex.second <<endl;
    if (startIndex == endIndex) {
        cout << tag.size() << endl;
        for (auto tem :tag) {
            cout << tem << endl;
        }
        tag.clear();
        return;
    }
    tag.push_back(checkX(startIndex, endIndex) + checkY(startIndex, endIndex));
    recursion(startIndex, endIndex);

}

void run() {
    string startStr, endStr;
    cin >> startStr >> endStr;

    PII startIndex = getIndex(startStr);
    PII endIndex = getIndex(endStr);

    recursion(startIndex, endIndex);

}

int main() {

    freopen("./slyar.in", "r+", stdin);
    freopen("./slyar.out", "w+", stdout);
    run();
}
