#include <iostream>
#include <string>
using namespace std; 

string readText()
{
    string text;
    cout << "Enter a Text (less than a 100 characters):\n";
    /*cin.ignore();*/
    cin >> ws;
    getline(cin, text);

    while (text.length() > 100)
    {
        cout << "Enter a Text less than a 100 characters:\n";
        getline(cin, text);

    }
    return text;
}

void railFenceEncrypt()
{
    // Read the input text message
    string message = readText();

    // Process the message to remove spaces and convert to uppercase
    string msg = "";
    string encryptedMessage = "";
    for (int i = 0; i < message.length(); i++)
    {
        message[i] = toupper(message[i]);
        if (message[i] != ' ')
        {
            msg += message[i];
        }
    }

    // Initialize the cipher matrix with spaces
    char cipherMatrix[3][100];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            cipherMatrix[i][j] = ' ';
        }
    }

    // Mark the positions in the matrix where characters will be placed
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < msg.length(); j++)
        {
            cipherMatrix[i][j] = '.';
        }
    }

    // Populate the matrix with the message in Rail-Fence order
    int increment = 1;
    int row = 0, col = 0;
    while (col < msg.length())
    {
        cipherMatrix[row][col] = msg[col];
        if (row + increment < 0 || row + increment > 2)
        {
            increment *= -1;
        }
        row += increment;
        col++;
    }

    // Display the Rail-Fence representation
    cout << "Rail-Fence Representation :\n\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < msg.length(); j++)
        {
            if (cipherMatrix[i][j] != '.')
                encryptedMessage += cipherMatrix[i][j];
            cout << cipherMatrix[i][j] << ' ';
        }
        cout << "\n";
    }

    // Display the encrypted message
    cout << "\nEncrypted Message is : " << encryptedMessage << endl;
}


void railFenceDecrypt()
{
    // Read the input text message
    string message = readText();

    // Convert the message to uppercase
    for (int i = 0; i < message.length(); i++)
    {
        message[i] = toupper(message[i]);
    }

    // Initialize the decipher matrix with spaces
    char decipherMatrix[3][100];
    string decryptedText = "";

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            decipherMatrix[i][j] = ' ';
        }
    }

    // Mark the positions in the matrix where characters will be placed
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < message.length(); j++)
        {
            decipherMatrix[i][j] = '.';
        }
    }

    // Populate the matrix with '*' to represent the Rail-Fence order
    int increment = 1;
    int row = 0, col = 0;

    while (col < message.length())
    {
        decipherMatrix[row][col] = '*';
        if (row + increment < 0 || row + increment > 2)
        {
            increment *= -1;
        }
        row += increment;
        col++;
    }

    // Replace '*' with characters from the encrypted message
    int counter = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < message.length(); j++)
        {
            if (decipherMatrix[i][j] == '*')
            {
                decipherMatrix[i][j] = message[counter];
                counter++;
            }
        }
        cout << "\n";
    }

    // Display the Rail-Fence representation
    cout << "Rail-Fence Representation :\n\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < message.length(); j++)
        {
            cout << decipherMatrix[i][j] << ' ';
        }
        cout << "\n";
    }

    // Re-initialize variables for reading the matrix in Rail-Fence order
    increment = 1;
    row = 0, col = 0;

    // Read the matrix in Rail-Fence order to get the decrypted message
    while (col < message.length())
    {
        decryptedText += decipherMatrix[row][col];
        if (row + increment < 0 || row + increment > 2)
        {
            increment *= -1;
        }
        row += increment;
        col++;
    }

    // Display the decrypted message
    cout << "\nDecrypted Message is : " << decryptedText << "\n\n";
}

void menu()
{
    cout << "[1] Encryption\n[2] Decryption\n";
    int choice = 0;
    cin >> choice;
    while (choice > 2 || choice < 1)
    {
        cout << "Enter a Valid Choice \n";
        cin >> choice;
    }
    if (choice == 1) {
        railFenceEncrypt();
    }
    else if (choice == 2) {
        railFenceDecrypt();
    }
    
}
int main()
{
    menu();
}

