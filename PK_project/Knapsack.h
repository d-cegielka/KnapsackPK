#include <vector>
#include <iostream>
#include <string>
#include <mpirxx.h>
#include <bitset>
#ifndef Knapsack_H

#define Knapsack_H

using namespace std;

class Knapsack
{
public:

	Knapsack();

	~Knapsack();

	System::String^ EncryptMessage(System::String^ plainText, int backpackSize);

	System::String^ DecryptMessage();

	System::String^ EncryptFileF(System::String^ plainFilePath, System::String^ cryptFilePath, int backpackSize);

	System::String^ Knapsack::DecryptFileF(System::String^ cryptFilePath, System::String^ plainFilePath);

	void GenerateKey(int backpackSize);

	System::String^ GetPublicKey();

	System::String^ GetPrivateKey();

	System::String^ SaveLoadPublicKey(System::String^ Path, bool option);

	System::String^ SaveLoadPrivateKey(System::String^ Path, bool option);

	System::String^ SaveLoadM(System::String^ Path, bool option);

	System::String^ SaveLoadN(System::String^ Path, bool option);

	System::String^ GetM();

	System::String^ GetN();

	vector<mpz_class> publicKey;

	vector<string> cryptogram;

private:
	mpz_class NWD(mpz_class a, mpz_class b);
	vector <mpz_class> privateKey;
	mpz_class sumPK = 0;
	mpz_class M;
	mpz_class N; 
	System::String^ IntVectorToString(vector<mpz_class> vector);
	System::String^ Knapsack::Ascii2Bin(System::String^ mess);
	System::String^ Knapsack::Bin2Ascii(System::String^ mess);
	mpz_class Knapsack::EuclideanExtNWD(mpz_class a, mpz_class b, mpz_class* x, mpz_class* y);
	bool VectorSaveFile(vector<string> vector, string pathToSave);
	bool VectorIntSaveFile(vector<mpz_class> vector, string pathToSave);
	bool FiletoVector(vector<string>& vector, string pathFile);
	bool FiletoIntVector(vector<mpz_class>& vector, string pathFile);
};


#endif //Knapsack_H

