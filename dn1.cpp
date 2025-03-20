#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//TODO: Funkcija za branje iz vhodne datoteke
bool Branje_Stevil(vector<unsigned char> &A, const char s[]) {
    ifstream input(s);
    unsigned char st;

    if(!input.is_open()) return false;

    while(!input.eof()){
        input >> st;
        A.push_back(st);
        while(isspace(input.peek())) input.get();
    }

    input.close();
    return true;
}

void Counting_sort_By_Bit(vector<unsigned char> &A, int BitIndex){

}

void Binary_Radix_Sort(vector<unsigned char> &A) {
    //Sortiranje od najmanjsega do najvecjega bita (LSB do MSB)
    for (int bit = 0; bit < 8; bit++){
        //Klicemo counting sort za urejanje polja
        Counting_sort_By_Bit(A, bit);
    }
}

int main(int argc, const char* argv[]) {
    vector<unsigned char> A;

    if(argc < 2) return 0;

    if(!Branje_Stevil(A, argv[1])) return 0;
    else
        Binary_Radix_Sort(A);

    return 0;
}