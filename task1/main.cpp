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
        //if (destructCipherText) // Ð½Ð°Ð´Ð¾ "Ð¿Ð¾ÑÑÐ¸ÑÑ"?
            //cipherText.front() = tolower(cipherText.front()); // "Ð¿Ð¾ÑÑÐ¸Ð¼"
         //decryptedText = cipher.decrypt(cipherText); // ÑÐ°ÑÑÐ¸ÑÑÐ¾Ð²ÑÐ²Ð°Ð½Ð¸Ðµ
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
    check(L"ÐÐÐ¢ÐÐÐ¬ÐÐÐÐÐ", L"Ð¡ÐÐÐ ÐÐ¢ÐÐ«Ð",true);
    return 0;
}
