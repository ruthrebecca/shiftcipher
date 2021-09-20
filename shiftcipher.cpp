/*
Nama      : Ruth Rebecca Ovelin
NPM       : 140810190054
Kelas     : A
Deskripsi : Program Enkripsi dan Dekripsi Shift Cipher
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{

    char message[100], ch;
    int i, key;
    bool isLoop = true;
    char x;

    while (isLoop == true)
    {
        printf("Enter a message to encrypt: ");
        gets(message);
        printf("Enter key: ");
        scanf("%d", &key);

        // Enkripsi
        for (i = 0; message[i] != '\0'; ++i)
        {
            ch = message[i];
            if (ch >= 'a' && ch <= 'z')
            {
                ch = ch + key;
                if (ch > 'z')
                {
                    ch = ch - 'z' + 'a' - 1;
                }
                message[i] = ch;
            }
            else if (ch >= 'A' && ch <= 'Z')
            {
                ch = ch + key;
                if (ch > 'Z')
                {
                    ch = ch - 'Z' + 'A' - 1;
                }
                message[i] = ch;
            }
        }
        printf("Encrypted message: %s", message);

        // Dekripsi
        for (i = 0; message[i] != '\0'; ++i)
        {
            ch = message[i];
            if (ch >= 'a' && ch <= 'z')
            {
                ch = ch - key;
                if (ch < 'a')
                {
                    ch = ch + 'z' - 'a' + 1;
                }
                message[i] = ch;
            }
            else if (ch >= 'A' && ch <= 'Z')
            {
                ch = ch - key;
                if (ch < 'A')
                {
                    ch = ch + 'Z' - 'A' + 1;
                }
                message[i] = ch;
            }
        }
        printf("\nDecrypted message: %s", message);

        do
        {
            cout << "\n\nApakah ingin di ulang? (Y/N): ";
            cin >> x;
            cin.ignore();
            if (x == 'Y' || x == 'y')
            {
                isLoop = true;
            }
            if (x == 'N' || x == 'n')
            {
                isLoop = false;
            }

        } while (x != 'y' && x != 'Y' && x != 'n' && x != 'N');
    }
}