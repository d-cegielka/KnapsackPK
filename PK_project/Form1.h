#pragma once

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading::Tasks;

	Knapsack* date = new Knapsack();

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ cryptFileButton;
	protected:




	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::RichTextBox^ plainTextBox;
	private: System::Windows::Forms::Button^ decryptFileButton;


	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ GenerateKeyButton;
	private: System::Windows::Forms::RichTextBox^ cryptTextBox;





	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Button^ DecryptTextButton;

	private: System::Windows::Forms::Button^ EncryptTextButton;

	private: System::Windows::Forms::RichTextBox^ PublicKeyTextBox;
	private: System::Windows::Forms::RichTextBox^ PrivateKeyTextBox;









	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ BackpackSizeBox;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ loadKeyButton;

	private: System::Windows::Forms::Button^ saveKeyButton;

	private: System::Windows::Forms::RichTextBox^ MTextBox;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ NTextBox;
	private: System::Windows::Forms::Button^ cryptTextClearButton;
	private: System::Windows::Forms::Button^ plainTextClearButton;





	protected:



	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->cryptFileButton = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->plainTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->decryptFileButton = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->GenerateKeyButton = (gcnew System::Windows::Forms::Button());
			this->cryptTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->loadKeyButton = (gcnew System::Windows::Forms::Button());
			this->saveKeyButton = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->cryptTextClearButton = (gcnew System::Windows::Forms::Button());
			this->plainTextClearButton = (gcnew System::Windows::Forms::Button());
			this->DecryptTextButton = (gcnew System::Windows::Forms::Button());
			this->EncryptTextButton = (gcnew System::Windows::Forms::Button());
			this->PublicKeyTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->PrivateKeyTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->BackpackSizeBox = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->MTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->NTextBox = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// cryptFileButton
			// 
			this->cryptFileButton->Location = System::Drawing::Point(17, 28);
			this->cryptFileButton->Name = L"cryptFileButton";
			this->cryptFileButton->Size = System::Drawing::Size(110, 23);
			this->cryptFileButton->TabIndex = 1;
			this->cryptFileButton->Text = L"Zaszyfruj plik";
			this->cryptFileButton->UseVisualStyleBackColor = true;
			this->cryptFileButton->Click += gcnew System::EventHandler(this, &Form1::cryptFileButton_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(22, 27);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(67, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Tekst jawny:";
			// 
			// plainTextBox
			// 
			this->plainTextBox->Location = System::Drawing::Point(25, 43);
			this->plainTextBox->Name = L"plainTextBox";
			this->plainTextBox->Size = System::Drawing::Size(337, 190);
			this->plainTextBox->TabIndex = 4;
			this->plainTextBox->Text = L"";
			// 
			// decryptFileButton
			// 
			this->decryptFileButton->Location = System::Drawing::Point(133, 28);
			this->decryptFileButton->Name = L"decryptFileButton";
			this->decryptFileButton->Size = System::Drawing::Size(110, 23);
			this->decryptFileButton->TabIndex = 5;
			this->decryptFileButton->Text = L"Odszyfruj plik";
			this->decryptFileButton->UseVisualStyleBackColor = true;
			this->decryptFileButton->Click += gcnew System::EventHandler(this, &Form1::decryptFileButton_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(55, 36);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(83, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Klucz publiczny:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(55, 147);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(81, 13);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Klucz prywatny:";
			// 
			// GenerateKeyButton
			// 
			this->GenerateKeyButton->Location = System::Drawing::Point(452, 192);
			this->GenerateKeyButton->Name = L"GenerateKeyButton";
			this->GenerateKeyButton->Size = System::Drawing::Size(96, 49);
			this->GenerateKeyButton->TabIndex = 12;
			this->GenerateKeyButton->Text = L"Generuj klucze";
			this->GenerateKeyButton->UseVisualStyleBackColor = true;
			this->GenerateKeyButton->Click += gcnew System::EventHandler(this, &Form1::GenerateKeyButton_Click);
			// 
			// cryptTextBox
			// 
			this->cryptTextBox->Location = System::Drawing::Point(394, 43);
			this->cryptTextBox->Name = L"cryptTextBox";
			this->cryptTextBox->Size = System::Drawing::Size(337, 190);
			this->cryptTextBox->TabIndex = 13;
			this->cryptTextBox->Text = L"";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(391, 27);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(101, 13);
			this->label5->TabIndex = 14;
			this->label5->Text = L"Zaszyfrowany tekst:";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->loadKeyButton);
			this->groupBox1->Controls->Add(this->saveKeyButton);
			this->groupBox1->Controls->Add(this->cryptFileButton);
			this->groupBox1->Controls->Add(this->decryptFileButton);
			this->groupBox1->Location = System::Drawing::Point(561, 151);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(260, 90);
			this->groupBox1->TabIndex = 15;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Szyfrowanie plików";
			// 
			// loadKeyButton
			// 
			this->loadKeyButton->Location = System::Drawing::Point(134, 58);
			this->loadKeyButton->Name = L"loadKeyButton";
			this->loadKeyButton->Size = System::Drawing::Size(109, 23);
			this->loadKeyButton->TabIndex = 7;
			this->loadKeyButton->Text = L"Wczytaj klucze";
			this->loadKeyButton->UseVisualStyleBackColor = true;
			this->loadKeyButton->Click += gcnew System::EventHandler(this, &Form1::loadKeyButton_Click);
			// 
			// saveKeyButton
			// 
			this->saveKeyButton->Location = System::Drawing::Point(17, 58);
			this->saveKeyButton->Name = L"saveKeyButton";
			this->saveKeyButton->Size = System::Drawing::Size(110, 23);
			this->saveKeyButton->TabIndex = 6;
			this->saveKeyButton->Text = L"Zapisz klucze";
			this->saveKeyButton->UseVisualStyleBackColor = true;
			this->saveKeyButton->Click += gcnew System::EventHandler(this, &Form1::saveKeyButton_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->cryptTextClearButton);
			this->groupBox2->Controls->Add(this->plainTextClearButton);
			this->groupBox2->Controls->Add(this->DecryptTextButton);
			this->groupBox2->Controls->Add(this->EncryptTextButton);
			this->groupBox2->Controls->Add(this->plainTextBox);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->cryptTextBox);
			this->groupBox2->Location = System::Drawing::Point(58, 260);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(761, 280);
			this->groupBox2->TabIndex = 16;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Szyfrowanie tekstu";
			// 
			// cryptTextClearButton
			// 
			this->cryptTextClearButton->Location = System::Drawing::Point(656, 14);
			this->cryptTextClearButton->Name = L"cryptTextClearButton";
			this->cryptTextClearButton->Size = System::Drawing::Size(75, 23);
			this->cryptTextClearButton->TabIndex = 18;
			this->cryptTextClearButton->Text = L"Wyczyœæ";
			this->cryptTextClearButton->UseVisualStyleBackColor = true;
			this->cryptTextClearButton->Click += gcnew System::EventHandler(this, &Form1::cryptTextClearButton_Click);
			// 
			// plainTextClearButton
			// 
			this->plainTextClearButton->Location = System::Drawing::Point(287, 14);
			this->plainTextClearButton->Name = L"plainTextClearButton";
			this->plainTextClearButton->Size = System::Drawing::Size(75, 23);
			this->plainTextClearButton->TabIndex = 17;
			this->plainTextClearButton->Text = L"Wyczyœæ";
			this->plainTextClearButton->UseVisualStyleBackColor = true;
			this->plainTextClearButton->Click += gcnew System::EventHandler(this, &Form1::plainTextClearButton_Click);
			// 
			// DecryptTextButton
			// 
			this->DecryptTextButton->Location = System::Drawing::Point(450, 239);
			this->DecryptTextButton->Name = L"DecryptTextButton";
			this->DecryptTextButton->Size = System::Drawing::Size(209, 23);
			this->DecryptTextButton->TabIndex = 16;
			this->DecryptTextButton->Text = L"Deszyfruj";
			this->DecryptTextButton->UseVisualStyleBackColor = true;
			this->DecryptTextButton->Click += gcnew System::EventHandler(this, &Form1::DecryptTextButton_Click);
			// 
			// EncryptTextButton
			// 
			this->EncryptTextButton->Location = System::Drawing::Point(82, 239);
			this->EncryptTextButton->Name = L"EncryptTextButton";
			this->EncryptTextButton->Size = System::Drawing::Size(209, 23);
			this->EncryptTextButton->TabIndex = 15;
			this->EncryptTextButton->Text = L"Szyfruj";
			this->EncryptTextButton->UseVisualStyleBackColor = true;
			this->EncryptTextButton->Click += gcnew System::EventHandler(this, &Form1::EncryptTextButton_Click);
			// 
			// PublicKeyTextBox
			// 
			this->PublicKeyTextBox->Location = System::Drawing::Point(58, 52);
			this->PublicKeyTextBox->Name = L"PublicKeyTextBox";
			this->PublicKeyTextBox->Size = System::Drawing::Size(369, 76);
			this->PublicKeyTextBox->TabIndex = 17;
			this->PublicKeyTextBox->Text = L"";
			// 
			// PrivateKeyTextBox
			// 
			this->PrivateKeyTextBox->Location = System::Drawing::Point(58, 164);
			this->PrivateKeyTextBox->Name = L"PrivateKeyTextBox";
			this->PrivateKeyTextBox->Size = System::Drawing::Size(369, 77);
			this->PrivateKeyTextBox->TabIndex = 18;
			this->PrivateKeyTextBox->Text = L"";
			// 
			// BackpackSizeBox
			// 
			this->BackpackSizeBox->FormattingEnabled = true;
			this->BackpackSizeBox->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"32", L"64", L"128", L"256", L"512" });
			this->BackpackSizeBox->Location = System::Drawing::Point(299, 25);
			this->BackpackSizeBox->Name = L"BackpackSizeBox";
			this->BackpackSizeBox->Size = System::Drawing::Size(121, 21);
			this->BackpackSizeBox->TabIndex = 19;
			this->BackpackSizeBox->Text = L"32";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(204, 28);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(95, 13);
			this->label1->TabIndex = 20;
			this->label1->Text = L"Wielkoœæ plecaka:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(449, 33);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(19, 13);
			this->label6->TabIndex = 21;
			this->label6->Text = L"M:";
			// 
			// MTextBox
			// 
			this->MTextBox->Location = System::Drawing::Point(452, 52);
			this->MTextBox->Name = L"MTextBox";
			this->MTextBox->Size = System::Drawing::Size(369, 76);
			this->MTextBox->TabIndex = 22;
			this->MTextBox->Text = L"";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(449, 147);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(18, 13);
			this->label7->TabIndex = 23;
			this->label7->Text = L"N:";
			// 
			// NTextBox
			// 
			this->NTextBox->Location = System::Drawing::Point(452, 164);
			this->NTextBox->Name = L"NTextBox";
			this->NTextBox->Size = System::Drawing::Size(96, 20);
			this->NTextBox->TabIndex = 24;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(870, 578);
			this->Controls->Add(this->NTextBox);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->MTextBox);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->BackpackSizeBox);
			this->Controls->Add(this->PrivateKeyTextBox);
			this->Controls->Add(this->PublicKeyTextBox);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->GenerateKeyButton);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Name = L"Form1";
			this->Text = L"Algorytm Plecakowy";
			this->groupBox1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void GenerateKeyButton_Click(System::Object^ sender, System::EventArgs^ e) {
	date->GenerateKey(int::Parse(BackpackSizeBox->Text));
	PublicKeyTextBox->Text = date->GetPublicKey();
	PrivateKeyTextBox->Text = date->GetPrivateKey();
	MTextBox->Text = date->GetM();
	NTextBox->Text = date->GetN();
}
private: System::Void EncryptTextButton_Click(System::Object^ sender, System::EventArgs^ e) {
	cryptTextBox->Text = date->EncryptMessage(plainTextBox->Text, int::Parse(BackpackSizeBox->Text));
	if (cryptTextBox->Text == "}") cryptTextBox->Clear();
}
private: System::Void DecryptTextButton_Click(System::Object^ sender, System::EventArgs^ e) {
	plainTextBox->Clear();
	if (cryptTextBox->Text != "") plainTextBox->Text = date->DecryptMessage();
	else return;
}
private: System::Void plainTextClearButton_Click(System::Object^ sender, System::EventArgs^ e) {
	plainTextBox->Clear();
}
private: System::Void cryptTextClearButton_Click(System::Object^ sender, System::EventArgs^ e) {
	cryptTextBox->Clear();
}
private: System::Void cryptFileButton_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ cryptInfo;
	OpenFileDialog^ FileToEncrypt = gcnew OpenFileDialog();
	FileToEncrypt->Title = "Wybierz plik, który ma zostaæ zaszyfrowany";
	if (FileToEncrypt->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		String^ CryptFile = FileToEncrypt->FileName + ".encrypt";
		cryptInfo = date->EncryptFileF(FileToEncrypt->FileName, CryptFile, int::Parse(BackpackSizeBox->Text));
		MessageBox::Show(cryptInfo);
	}
}
private: System::Void decryptFileButton_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ cryptInfo;
	OpenFileDialog^ FileToDecrypt = gcnew OpenFileDialog();
	FileToDecrypt->Title = "Wybierz plik, który ma zostaæ odszyfrowany";
	FileToDecrypt->Filter = "Pliki zaszyfrowane (*.encrypt)|*.encrypt";
	if (FileToDecrypt->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		//String^ DecryptFile = FileToDecrypt->FileName + ".pdf";
		String^ DecryptFile = String::Concat(
			FileToDecrypt->FileName->Replace(FileToDecrypt->SafeFileName, String::Empty),
			"decrypt_",
			FileToDecrypt->SafeFileName->Replace(".encrypt", String::Empty)
		);
		cryptInfo = date->DecryptFileF(FileToDecrypt->FileName, DecryptFile);
		MessageBox::Show(cryptInfo);
	}
}
private: System::Void saveKeyButton_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ cryptInfo = "";
	FolderBrowserDialog^ SaveKeyFilesFolder = gcnew FolderBrowserDialog();
	SaveKeyFilesFolder->Description = "Wybierz folder do zapisania kluczy.";
	SaveKeyFilesFolder->RootFolder = System::Environment::SpecialFolder::MyComputer;
	if (SaveKeyFilesFolder->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		String^ PublicKeyFilePath = SaveKeyFilesFolder->SelectedPath + "\\" +"publickey.txt";
		String^ PrivateKeyFilePath = SaveKeyFilesFolder->SelectedPath + "\\" + "privatekey.txt";
		String^ MFilePath = SaveKeyFilesFolder->SelectedPath + "\\" + "M.txt";
		String^ NFilePath = SaveKeyFilesFolder->SelectedPath + "\\" + "N.txt";
		cryptInfo += "Plik publickey.txt: " + date->SaveLoadPublicKey(PublicKeyFilePath, true) + " \n";
		cryptInfo += "Plik privatekey.txt: " + date->SaveLoadPrivateKey(PrivateKeyFilePath, true) + " \n";
		cryptInfo += "Plik M.txt: " + date->SaveLoadM(MFilePath, true) + " \n";
		cryptInfo += "Plik N.txt: " + date->SaveLoadN(NFilePath, true);
		//cryptInfo = date->DecryptFileF(FileToDecrypt->FileName, DecryptFile);
		MessageBox::Show(cryptInfo);
	}
}
private: System::Void loadKeyButton_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ cryptInfo = "";
	FolderBrowserDialog^ LoadKeyFilesFolder = gcnew FolderBrowserDialog();
	LoadKeyFilesFolder->Description = "Wybierz folder z kluczami.";
	LoadKeyFilesFolder->RootFolder = System::Environment::SpecialFolder::MyComputer;
	if (LoadKeyFilesFolder->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		String^ PublicKeyFilePath = LoadKeyFilesFolder->SelectedPath + "\\" + "publickey.txt";
		String^ PrivateKeyFilePath = LoadKeyFilesFolder->SelectedPath + "\\" + "privatekey.txt";
		String^ MFilePath = LoadKeyFilesFolder->SelectedPath + "\\" + "M.txt";
		String^ NFilePath = LoadKeyFilesFolder->SelectedPath + "\\" + "N.txt";
		cryptInfo += "Plik publickey.txt: " + date->SaveLoadPublicKey(PublicKeyFilePath, false) + " \n";
		cryptInfo += "Plik privatekey.txt: " + date->SaveLoadPrivateKey(PrivateKeyFilePath, false) + " \n";
		cryptInfo += "Plik M.txt: " + date->SaveLoadM(MFilePath, false) + " \n";
		cryptInfo += "Plik N.txt: " + date->SaveLoadN(NFilePath, false);
		//cryptInfo = date->DecryptFileF(FileToDecrypt->FileName, DecryptFile);
	}
	PublicKeyTextBox->Text = date->GetPublicKey();
	if (PublicKeyTextBox->Text == "}") PublicKeyTextBox->Clear();
	PrivateKeyTextBox->Text = date->GetPrivateKey();
	if (PrivateKeyTextBox->Text == "}") PublicKeyTextBox->Clear();
	MTextBox->Text = date->GetM();
	NTextBox->Text = date->GetN();
	MessageBox::Show(cryptInfo);
}

};
}