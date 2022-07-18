#include <iostream>

void encrypt_caesar (int count , std::string& text){

    for (int i(0); text.length() > i ; i++)
    {
        if ( (text[i]>='A') && (text[i]<='Z') )
        {
            if ( count >= 0 ) text[i]=( 65+ ( text[i]-65+count ) % 26 ) ;
            else text[i]=( 90-  ( 90-text[i]-count ) % 26 ) ;

        }
        else if ( (text[i]>='a') && (text[i]<='z') )
        {
             if ( count >= 0 ) text[i]=( 97+ ( text[i]-97+count ) % 26 ) ;
             else text[i]=( 122-  ( 122-text[i]-count ) % 26 ) ;

        }
    }
}

void  decrypt_caesar(int count , std::string& text){
     encrypt_caesar((-1)*count,text);
}


int main() {

    int count;
    std::string text;

    std::cout << "The program encrypts data using the \"Caesar cipher\"." << std::endl;
    std::cout << "Enter the text: ";
    std::getline (std::cin,text);
    std::cout << "Enter the offset: ";
    std::cin >> count;
    encrypt_caesar(count,text);
    std::cout << "Encryption: " << text << std::endl;
    decrypt_caesar(count,text);
    std::cout << "Decryption: " << text << std::endl;
    return 0;
}
