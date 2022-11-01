#pragma once

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
	public:
		MainMenuGrocery(void)
		{
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
	private: System::Windows::Forms::Button^ button3;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->adminBtn = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(215, 78);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(119, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Main Menu";
			this->label1->TextAlign = System::Drawing::ContentAlignment::BottomRight;
			// 
			// adminBtn
			// 
			this->adminBtn->Location = System::Drawing::Point(150, 124);
			this->adminBtn->Name = L"adminBtn";
			this->adminBtn->Size = System::Drawing::Size(247, 55);
			this->adminBtn->TabIndex = 1;
			this->adminBtn->Text = L"Administrator";
			this->adminBtn->UseVisualStyleBackColor = true;
			this->adminBtn->Click += gcnew System::EventHandler(this, &MainMenuGrocery::adminBtn_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(150, 202);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(247, 55);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Client";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(150, 282);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(247, 55);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Seller";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// MainMenuGrocery
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(568, 502);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->adminBtn);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(6);
			this->Name = L"MainMenuGrocery";
			this->Text = L"MainMenuGrocery";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void adminBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("Admin window should go here");
	}
	};
}
