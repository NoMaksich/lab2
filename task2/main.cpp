#include <iostream>
#include "shifr.h"

void check(const std::wstring& Text, const int key) {
    try {
        std::wstring cipherText;
        std::wstring decryptedText;
        Shifr cipher(key);
        cipherText = cipher.encrypt(Text);
        decryptedText = cipher.decrypt(cipherText);
        std::wcout << L"key=" << key << std::endl;
        std::wcout << Text << std::endl;
        std::wcout << cipherText << std::endl;
        std::wcout << decryptedText << std::endl;
    } catch (const cipher_error & e) {
        std::wcerr << L"Error: " << e.what() << std::endl;
    }
}

int main() {
	setlocale(LC_ALL, "ru_RU.UTF-8");
    int columns;
    std::wcout << L"Enter the number of columns in the table: ";
    std::wcin >> columns;
    std::wcin.ignore();
    
    std::wstring text;
    std::wcout << L"Enter the encryption text: ";
    getline(std::wcin, text);
    check(text, columns);
    return 0;
}
