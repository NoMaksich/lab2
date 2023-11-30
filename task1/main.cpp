#include <iostream>
#include "modAlphaCipher.h"
#include <locale>
#include <clocale>
#include <cwctype>
#include <cctype>
using namespace std;
void check(const wstring& Text, const wstring& key, const bool destructCipherText=false)
{
    try {
        setlocale(LC_ALL, "ru_RU.UTF-8");
        wstring cipherText;
        wstring decryptedText;
        modAlphaCipher cipher(key);
        cipherText = cipher.encrypt(Text);
        //if (destructCipherText) // надо "портить"?
            //cipherText.front() = tolower(cipherText.front()); // "портим"
         //decryptedText = cipher.decrypt(cipherText); // расшифровывание
        decryptedText = cipher.decrypt(cipherText);
        wcout<<"key="<<key<<endl;
        wcout<<Text<<endl;
        wcout<<cipherText<<endl;
        wcout<<decryptedText<<endl;
    } catch (const cipher_error & e) {
        cerr<<"Error: "<<e.what()<<endl;
    }
}

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "ru_RU.UTF-8");   
    check(L"МЕТАЛЬНИКОВ", L"СЕКРЕТНЫЙ",true);
    return 0;
}
