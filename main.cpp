#include <iostream>
#include <cmath>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;

int main() {
    string word = "KOMBINATORIKA";
    int answer = 0;

    map<char, int> letters{};

    for (char ch: word){
        if (letters.contains(ch) == 0) {
            letters.insert({ch, 1});
            continue;
        }
        letters[ch] = letters[ch] + 1;
    }

    for (auto [iKey, i]: letters)
        for (auto [jKey, j]: letters)
            for (auto [uKey, u]: letters)
                if(!(((iKey == jKey == uKey)&&(i < 3)) || ((iKey == jKey)&&(i < 2)) || ((iKey == uKey)&&(i < 2)) || ((jKey == uKey)&&(j < 2))))
                    answer++;


    for (auto [key, value]: letters){
        cout << key << " : " << value << endl;
    }

    cout << endl << "answer: " << answer << endl;

    return 0;
}