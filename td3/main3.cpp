/*

Exercice III: QUEUE & STACK

Vous disposez d’une variable de type ‘string’. Implémentez la fonction isPalindrome qui retourne true si la chaîne est un
palindrome et false sinon.
    Un palindrome signifie qu’il se lit de la même manière de gauche à droite et de droite à gauche, formant ainsi un mot ou
une phrase symétrique. Par exemple, les mots "radar" et "été" sont des palindromes.
*/

#include <iostream>
#include <queue>
#include <stack>
#include <cctype>

using namespace std;

bool isPalindrome(const string& input) {
    queue<char> characters;
    stack<char> reversedCharacters;

    for (char character : input) {
        characters.push(character);
        reversedCharacters.push(character);
    }

    while (!characters.empty()) {
        if (characters.front() != reversedCharacters.top()) {
            return false;
        }

        characters.pop();
        reversedCharacters.pop();
    }

    return true;
}

int main() {
    cout <<boolalpha;
    
    cout<< "Is 'racecar' a palindrome? " 
        << isPalindrome("racecar") << endl;

    cout<< "Is 'hello' a palindrome? "
        << isPalindrome("hello") << endl;
}