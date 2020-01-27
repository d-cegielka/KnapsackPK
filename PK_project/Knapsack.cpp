// Knapsack.cpp

#include "Knapsack.h"
#include <time.h>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <msclr\marshal_cppstd.h>

using namespace std;

Knapsack::Knapsack()
{
	//throw gcnew System::NotImplementedException();
}

Knapsack::~Knapsack()
{
	//throw gcnew System::NotImplementedException();
}


void Knapsack::GenerateKey(int backpackSize)
{
	srand(time(NULL));
	sumPK = 0;
	privateKey.clear();
	publicKey.clear();
	
	//Stworzenie klucza prywatnego przy u¿yciu superrosn¹cej sekwencji 
	for (int i = 0; i < backpackSize; i++)
	{
		mpz_class randNumber = rand() % 10 + 1;
		mpz_class temp = sumPK + randNumber;
		privateKey.push_back(temp);
		sumPK += temp;
	}

	srand(time(NULL));

	// M i N
	M = rand() % 50 + sumPK;
	N = rand() % M;
	while (NWD(M, N) != 1)
	{
		N = rand() % M;
	}

	//Klucz publiczny
	for (size_t i = 0; i < privateKey.size(); i++)
	{
		publicKey.push_back((N * privateKey[i]) % M);
	}

}

System::String^ Knapsack::EncryptMessage(System::String^ plainText, int backpackSize)
{
	cryptogram.clear();
	System::String^ result = "{";
	int chunkLength = backpackSize / 8;
	for (int i = 0; i < plainText->Length; i+=chunkLength)
	{	
		System::String^ chunk;
		if(plainText->Length - i < chunkLength) chunk = plainText->Substring(i, plainText->Length-i);
		else chunk = plainText->Substring(i, chunkLength);
		System::String^ bitschunk = Ascii2Bin(chunk);

		mpz_class cryptText = 0;

		for (int j = 0; j < bitschunk->Length; j++)
		{
			if (bitschunk[j] == '1')
			{
				cryptText += publicKey[j];
			}
		}
		//System::String^ temp = gcnew System::String((cryptText.get_str()).c_str());
		cryptogram.push_back(cryptText.get_str());
		result += gcnew System::String((cryptText.get_str()).c_str()) + ",";
	}
	return result->Substring(0, result->Length - 1) + "}";
}

System::String^ Knapsack::EncryptFileF(System::String^ plainFilePath, System::String^ cryptFilePath, int backpackSize)
{
	cryptogram.clear();
	int chunkLength = backpackSize / 8;
	cli::array<unsigned char>^ plainText = System::IO::File::ReadAllBytes(plainFilePath);
	for (int i = 0; i < plainText->Length; i += chunkLength)
	{
		/*System::String^ chunk;
		if (plainText->Length - i < chunkLength) chunk = plainText->Substring(i, plainText->Length - i);
		else chunk = plainText->Substring(i, chunkLength);*/
		string bitschunk;
		for (size_t k = 0; k < chunkLength; k++)
		{
			if(i+k < plainText->Length) bitschunk += bitset<8>(plainText[i + k]).to_string();
		}
		mpz_class cryptText = 0;

		for (int j = 0; j < bitschunk.size(); j++)
		{
			if (bitschunk[j] == '1')
			{
				cryptText += publicKey[j];
			}
		}
		cryptogram.push_back(cryptText.get_str());
	}
	string PathToSave = msclr::interop::marshal_as<string>(cryptFilePath);
	if (VectorSaveFile(cryptogram, PathToSave)) return "Szyfrowanie zosta³o zakoñczone pomyœlnie! ";
	else return "Nie uda³o siê zapisaæ zaszyfrowanego pliku! ";
}

System::String^ Knapsack::DecryptMessage()
{
	System::String^ mess;
	mpz_class x, y;

	mpz_class nwd = EuclideanExtNWD(N, M, &x, &y);

	for (int i = 0; i < cryptogram.size(); i++) 
	{
		//System::String^ decryptedMess = gcnew System::String('0', privateKey.size());
		string decryptedMess(privateKey.size(), '0');

		if(nwd == 1)
		{
			mpz_class inverseN = (x + M) % M;

			mpz_class cText;
			istringstream temp(cryptogram[i]);
			temp >> cText;

			mpz_class step = (cText * inverseN) % M;

			while(step != 0) 
			{
				for (int j = 0; j < privateKey.size(); j++)
				{
					if(privateKey[j] > step)
					{
						if(j == 0)
						{
							step = 0;
							break;
						}

						decryptedMess[j - 1] = '1';
						step = step - privateKey[j - 1];
						break;
					}
					if (j == privateKey.size() - 1)
					{
						decryptedMess[j] = '1';
						step = step - privateKey[j];
						break;
					}
				
				}

			}
			mess += gcnew System::String(decryptedMess.c_str());
			
		}

	}
	
	return Bin2Ascii(mess);
}

System::String^ Knapsack::DecryptFileF(System::String^ cryptFilePath, System::String^ plainFilePath)
{
	cryptogram.clear();
	if (FiletoVector(cryptogram, msclr::interop::marshal_as<string>(cryptFilePath))== false) return "Nie uda³o siê wczytaæ pliku!";
	System::String^ mess;
	mpz_class x, y;
	
	mpz_class nwd = EuclideanExtNWD(N, M, &x, &y);

	if (nwd == 1) {
		for (int i = 0; i < cryptogram.size(); i++)
		{
			//System::String^ decryptedMess = gcnew System::String('0', privateKey.size());
			string decryptedMess(privateKey.size(), '0');

			mpz_class inverseN = (x + M) % M;

			mpz_class cText(cryptogram[i]);
			/*istringstream temp(cryptogram[i]);
			temp >> cText;*/

			mpz_class step = (cText * inverseN) % M;

			while (step != 0)
			{
				for (int j = 0; j < privateKey.size(); j++)
				{
					if (privateKey[j] > step)
					{
						if (j == 0)
						{
							step = 0;
							break;
						}

						decryptedMess[j - 1] = '1';
						step = step - privateKey[j - 1];
						break;
					}
					if (j == privateKey.size() - 1)
					{
						decryptedMess[j] = '1';
						step = step - privateKey[j];
						break;
					}
				}
			}
			mess += gcnew System::String(decryptedMess.c_str());
		}
	}
	unsigned long long messlength = mess->Length;
	System::IO::FileStream^ decryptedFile = System::IO::File::Create(plainFilePath);
	cli::array<unsigned char>^ PT = gcnew cli::array<unsigned char>(messlength / 8 + 1);
	for (int i = 0, x = 0; i < messlength; i += 8, x++)
	{
		if (i + 8 < messlength)
			PT[x] = System::Convert::ToByte(mess->Substring(i, 8), 2);
		else
			PT[x] = System::Convert::ToByte(mess->Substring(i), 2);
	}

	decryptedFile->Write(PT, 0, PT->Length - 1);
	decryptedFile->Close();
	return "Deszyfrowanie zakoñczone pomyœlnie!";
}

System::String^ Knapsack::GetPublicKey()
{
	return IntVectorToString(publicKey);
}

System::String^ Knapsack::GetPrivateKey()
{
	return IntVectorToString(privateKey);
}

System::String^ Knapsack::SaveLoadPublicKey(System::String^ Path, bool option)
{
	if (option) {
		string PathToSave = msclr::interop::marshal_as<string>(Path);
		if (VectorIntSaveFile(publicKey, PathToSave)) return "OK";
		else return "nie zapisano";
	}
	else {
		publicKey.clear();
		string PathToLoad = msclr::interop::marshal_as<string>(Path);
		if (FiletoIntVector(publicKey, PathToLoad)) return "OK";
		else return "nie wczytano";
	}
	
}

System::String^ Knapsack::SaveLoadPrivateKey(System::String^ Path, bool option)
{
	if (option) {
		string PathToSave = msclr::interop::marshal_as<string>(Path);
		if (VectorIntSaveFile(privateKey, PathToSave)) return "OK";
		else return "nie zapisano";
	}
	else {
		privateKey.clear();
		string PathToLoad = msclr::interop::marshal_as<string>(Path);
		if (FiletoIntVector(privateKey, PathToLoad)) return "OK";
		else return "nie wczytano";
	}
}

System::String^ Knapsack::SaveLoadM(System::String^ Path, bool option)
{
	if (option) {
		vector<mpz_class> tmp;
		tmp.push_back(M);
		string PathToSave = msclr::interop::marshal_as<string>(Path);
		if (VectorIntSaveFile(tmp, PathToSave)) return "OK";
		else return "nie zapisano";
	}
	else{
		vector<mpz_class> tmp;
		string PathToLoad = msclr::interop::marshal_as<string>(Path);
		if (FiletoIntVector(tmp, PathToLoad)) {
			M = tmp[0];
			return "OK";
		}
		else { 
			M = mpz_class();
			return "nie wczytano";
		};
	}

}

System::String^ Knapsack::SaveLoadN(System::String^ Path, bool option)
{
	if (option)
	{
		vector<mpz_class> tmp;
		tmp.push_back(N);
		string PathToSave = msclr::interop::marshal_as<string>(Path);
		if (VectorIntSaveFile(tmp, PathToSave)) return "OK";
		else return "nie zapisano";
	}
	else {
		vector<mpz_class> tmp;
		string PathToLoad = msclr::interop::marshal_as<string>(Path);
		if (FiletoIntVector(tmp, PathToLoad)) {
			N = tmp[0];
			return "OK";
		}
		else {
			N = mpz_class();
			return "nie wczytano";
		}
	}
	
}

System::String^ Knapsack::GetM()
{
	return gcnew System::String((M.get_str()).c_str());
}

System::String^ Knapsack::GetN()
{
	return gcnew System::String((N.get_str()).c_str());
}

mpz_class Knapsack::NWD(mpz_class a, mpz_class b)
{
	if (b == 0) return a;
	return NWD(b, a % b);
}

System::String^ Knapsack::IntVectorToString(vector<mpz_class> vector)
{
	System::String^ result = "{";
	for (auto item : vector)
	{
		System::String^ temp = gcnew System::String((item.get_str()).c_str());
		result += temp + ",";
	}
	result = result->Substring(0, result->Length - 1) + "}";

	return result;
}

System::String^ Knapsack::Ascii2Bin(System::String^ text)
{
	System::String^ messInBinary = "";
	for (int i = 0; i < text->Length; i++)
	{
		System::String^ tmp = gcnew System::String((bitset<8>(text[i]).to_string()).c_str());
		messInBinary += tmp;
	}
	return messInBinary;
}

System::String^ Knapsack::Bin2Ascii(System::String^ mess)
{
	string messInAscii= "";
	bitset<8> bit;

	for (int i = 0; i < mess->Length; i += 8) {
		for (int j = 0; j < 8; j++) {
			if (mess[i + j] == '1')
				bit[7 - j] = true;
			else
				bit[7 - j] = false;
		}
		messInAscii += char(bit.to_ulong());
	}
	return gcnew System::String(messInAscii.c_str());
}

mpz_class Knapsack::EuclideanExtNWD(mpz_class a, mpz_class b, mpz_class *x, mpz_class *y)
{
	if (a == 0) {
		*x = 0;
		*y = 1;
		return b;
	}

	mpz_class x1;
	mpz_class y1;

	mpz_class nwd = EuclideanExtNWD(b % a, a, &x1, &y1);

	*x = y1-(b / a) * x1;
	*y = x1;

	return nwd;
}

bool Knapsack::VectorSaveFile(vector<string> vector, string pathToSave)
{
	ofstream file(pathToSave, ios::out);
	if (file.is_open())
	{
		for (unsigned long long i = 0; i < vector.size(); i++)
		{
			file << vector[i] << endl;
		}
		file.close();
		return true;
	}
	return false;
}

bool Knapsack::VectorIntSaveFile(vector<mpz_class> vector, string pathToSave)
{
	ofstream file(pathToSave, ios::out);
	if (file.is_open())
	{
		for (unsigned long long i = 0; i < vector.size(); i++)
		{
			file << vector[i] << endl;
		}
		file.close();
		return true;
	}
	return false;
}

bool Knapsack::FiletoVector(vector<string> &vector, string pathFile)
{
	string temp;
	ifstream file(pathFile, ios::in);
	if (file.is_open())
	{
		while (getline(file, temp))
		{
			if (temp.size() > 0) vector.push_back(temp);
		}
		file.close();
		return true;
	}
	return false;
}

bool Knapsack::FiletoIntVector(vector<mpz_class>& vector, string pathFile)
{
	string temp;
	ifstream file(pathFile, ios::in);
	if (file.is_open())
	{
		while (getline(file, temp))
		{
			if (temp.size() > 0) vector.push_back(mpz_class(temp));
		}
		file.close();
		return true;
	}
	return false;
}
