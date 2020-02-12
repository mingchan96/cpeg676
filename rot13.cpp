#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string decode(int key, string encoded_message){

    //decode the message
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    string decoded_message;
    string letter;

    for (int i = 0; i < encoded_message.length() + 1; i++){
        if(encoded_message[i] == '-' || encoded_message[i] == ' ' || encoded_message[i] == '\0'){
            int index = ( stoi(letter) - 1 + key) % 26;
            decoded_message += alpha[index];
            if (encoded_message[i] == ' ') decoded_message += " ";
            letter = "";
        }
        else{
            letter += encoded_message[i];
        }
    }
    cout << encoded_message << endl;
    cout << decoded_message << endl;

    return decoded_message + "\n";
}

int main(void){
    string line;
    ifstream input_file("input.txt");
    string encoded_message;
    string decoded_message;

    //read the encoded message
    if (input_file.is_open()){
        while(getline(input_file, line)){
            decoded_message += decode(13, line);
        }
        input_file.close();
    }
    else{
        cout << "File cannot be opened" << endl;
    }

    ofstream output_file;
    output_file.open("output.txt");
    output_file << decoded_message;
    output_file.close();

    return 0;
}