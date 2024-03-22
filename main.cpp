#include <iostream>
#include <cmath>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;

void task1() {
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


    for (auto [key, value]: letters)
        cout << key << " : " << value << endl;


    cout << endl << "answer: " << answer << endl;
}

double Recurent(double an1, double an){
    return 4*an1 - 13*an;
}

void task2(){
    double an = 1;
    double an1 = 2;
    for (int i = 2; i <= 100; i++){
        double temp = Recurent(an1, an);
        an = an1;
        an1 = temp;
    }
    cout << "a(100)" << an1 << endl; 
}

int basicClimb(int up, int right){
    if (up > 0 && right > 0) return basicClimb(up - 1, right) + basicClimb(up, right - 1);
    return 1;
}

int conditionalClimb(int up, int right){
    if (right == 0 && up != 0) return 0;
    if (up > 0 && right > 0) return conditionalClimb(up - 1, right - 1) + conditionalClimb(up, right - 1);
    return 1;
}

void task6(){
    cout << basicClimb(13,16) << endl;
    cout << conditionalClimb(13,16) << endl;
    cout << basicClimb(13,16 - 13) << endl;
}

int main(){
    int i;
    cout << "Task number: ";
    cin >> i;
    cout << endl;
    switch (i) {
        case 1 :{
            task1();
            break;
        }
        case 2:{
            task2();
            break;
        }
        case 6:{
            task6();
            break;
        }
        default:{
            cout << "wrong number" << endl;
            break;
        }
    }
    return 0;
}
