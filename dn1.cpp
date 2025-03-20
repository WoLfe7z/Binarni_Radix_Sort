#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//TODO: Funkcija za branje iz vhodne datoteke
bool Branje_Stevil(vector<unsigned char> &A, const char s[]) {
    ifstream input(s);
    int st;

    if(!input.is_open()) return false;

    while(!input.eof()){
        input >> st;
        A.push_back(static_cast<unsigned char>(st));
        while(isspace(input.peek())) input.get();
    }

    input.close();
    return true;
}

//TODO: Funckija za izpis stevil v izhodno datoteko
void Izpis_Stevil(vector<unsigned char> &A){
    ofstream output("out.txt");
    if(!output) return;

    for(unsigned int i = 0; i < A.size(); i++){
        output << static_cast<int>(A[i]) << ' ';
    }

    output.close();
}

void Counting_sort_By_Bit(vector<unsigned char> &A, vector<unsigned char> &B, int k){
    vector<int> C(2, 0);

    //1.korak: C[(A[i] >> k) & 1]++
    for (unsigned int i = 0; i < A.size(); i++) {
        C[(A[i] >> k) & 1]++;
    }

    //2.Korak: Prefix sum
    C[1] += C[0];

    //3.Korak: B[--C[(A[i] >> k) & 1]] = A[i]   -   Razvrscanje (Od zadnjega proti prvemu za stabilnost)
    for (int i = A.size() - 1; i >= 0; i--){
        B[--C[(A[i] >> k) & 1]] = A[i];
    }

    //4.Korak: Zamenjava polj
    swap(A, B);
}

void Binary_Radix_Sort(vector<unsigned char> &A) {
    vector<unsigned char> B(A.size());

    //Sortiranje od najmanjsega do najvecjega bita (LSB do MSB)
    for (int k = 0; k < 8; k++){
        //Klicemo counting sort za urejanje polja
        Counting_sort_By_Bit(A, B, k);
    }
}

int main(int argc, const char* argv[]) {
    vector<unsigned char> A;

    if(argc < 2) return 0;

    if(!Branje_Stevil(A, argv[1])) return 0;
    else
        Binary_Radix_Sort(A);

    Izpis_Stevil(A);

    return 0;
}