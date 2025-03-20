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

void Binary_Radix_Sort(unsigned char* A, unsigned int size) {

}

int main(int argc, const char* argv[]) {
    vector<unsigned char> A;

    if(argc < 2) return 0;

    if(!Branje_Stevil(A, argv[1])) return 0;
    else
        Binary_Radix_Sort(&A[0], A.size());

    return 0;
}