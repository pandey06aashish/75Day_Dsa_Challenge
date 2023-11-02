// Q1.Reverse String...

#include <iostream>
#include <string>
using namespace std;
int main() {
   string str = "Hello, World!";
    int length = str.length();

    for (int i = length - 1; i >= 0; i--) {
        cout << str[i];
    }

    return 0;
}



// Q2.Check Palindrome String...

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isPalindrome(const string& str) {
    string reversedStr = str;
    reverse(reversedStr.begin(), reversedStr.end());
    return str == reversedStr;
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    if (isPalindrome(str)) {
        cout << str << " is a palindrome." << endl;
    } else {
        cout << str << " is not a palindrome." << endl;
    }

    return 0;
}
