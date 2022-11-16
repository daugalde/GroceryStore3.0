#pragma once
#include "AdminDashboard.h"
#include "SellerDashboard.h"
#include "ClientDashboard.h"
#include "ReporDashboard.h"
#include "../DataStructures/GroceryManager.h"

namespace Program {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainMenuGrocery
	/// </summary>
	public ref class MainMenuGrocery : public System::Windows::Forms::Form
	{

		GroceryManager* gm = new GroceryManager;

	public:
		MainMenuGrocery(void)
		{
			gm->InitStoreLoad();
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainMenuGrocery()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ adminBtn;

	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ sellerBtn;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ button1;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainMenuGrocery::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->adminBtn = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->sellerBtn = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(359, 125);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(146, 31);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Main Menu";
			this->label1->TextAlign = System::Drawing::ContentAlignment::BottomRight;
			// 
			// adminBtn
			// 
			this->adminBtn->Location = System::Drawing::Point(304, 191);
			this->adminBtn->Name = L"adminBtn";
			this->adminBtn->Size = System::Drawing::Size(247, 55);
			this->adminBtn->TabIndex = 1;
			this->adminBtn->Text = L"Administrator";
			this->adminBtn->UseVisualStyleBackColor = true;
			this->adminBtn->Click += gcnew System::EventHandler(this, &MainMenuGrocery::adminBtn_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(304, 274);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(247, 55);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Client";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainMenuGrocery::button2_Click);
			// 
			// sellerBtn
			// 
			this->sellerBtn->Location = System::Drawing::Point(304, 357);
			this->sellerBtn->Name = L"sellerBtn";
			this->sellerBtn->Size = System::Drawing::Size(247, 55);
			this->sellerBtn->TabIndex = 3;
			this->sellerBtn->Text = L"Seller";
			this->sellerBtn->UseVisualStyleBackColor = true;
			this->sellerBtn->Click += gcnew System::EventHandler(this, &MainMenuGrocery::SellerBtn);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->Location = System::Drawing::Point(304, 49);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(272, 46);
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(304, 446);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(248, 51);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Consultas";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainMenuGrocery::button1_Click);
			// 
			// MainMenuGrocery
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(15, 30);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(980, 596);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->sellerBtn);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->adminBtn);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(6);
			this->Name = L"MainMenuGrocery";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MainMenuGrocery";
			this->Load += gcnew System::EventHandler(this, &MainMenuGrocery::MainMenuGrocery_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void adminBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		AdminDashboard^ dashboard = gcnew AdminDashboard(this, this->gm);
		dashboard->ShowDialog();
	}
	private: System::Void SellerBtn(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		SellerDashboard^ dashboard = gcnew SellerDashboard(this, this->gm);
		dashboard->ShowDialog();

	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		ClientDashboard^ dashboard = gcnew ClientDashboard(this, this->gm);
		dashboard->ShowDialog();

	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		ReporDashboard^ dashboard = gcnew ReporDashboard(this, this->gm);
		dashboard->ShowDialog();

	}



	private: System::Void MainMenuGrocery_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	
};
};

