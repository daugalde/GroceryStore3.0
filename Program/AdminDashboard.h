#pragma once
#include "../DataStructures/GroceryManager.h"

namespace Program {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AdminDashboard
	/// </summary>
	public ref class AdminDashboard : public System::Windows::Forms::Form
	{

	public:
		Form^ obj;
		GroceryManager* gm;
		AdminDashboard(Form ^obj1, GroceryManager* gm)
		{
			obj = obj1;
			this->gm = gm;
			InitializeComponent();

			this->viewer->Text =  gcnew String(gm->getStore().getAisles()->getInfo().c_str());;
		}

		AdminDashboard(void)
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
		~AdminDashboard()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::TextBox^ viewer;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->viewer = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(647, 75);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(241, 32);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Dashboard Admin";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(72, 129);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(151, 32);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Insert Data";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(72, 189);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(107, 32);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Aisle Id";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(72, 235);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(212, 32);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Product Aisle Id";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(72, 285);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(142, 32);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Product Id";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(383, 189);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(186, 38);
			this->textBox1->TabIndex = 5;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(383, 235);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(186, 38);
			this->textBox2->TabIndex = 6;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(383, 285);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(186, 38);
			this->textBox3->TabIndex = 7;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(72, 590);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(184, 32);
			this->label6->TabIndex = 8;
			this->label6->Text = L"Client / Seller";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(378, 634);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(186, 38);
			this->textBox4->TabIndex = 9;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(72, 637);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(37, 32);
			this->label7->TabIndex = 10;
			this->label7->Text = L"Id";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(72, 685);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(89, 32);
			this->label8->TabIndex = 11;
			this->label8->Text = L"Name";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(378, 685);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(186, 38);
			this->textBox5->TabIndex = 12;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(78, 349);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(145, 84);
			this->button1->TabIndex = 13;
			this->button1->Text = L"Aisle Only";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(267, 349);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(193, 84);
			this->button2->TabIndex = 14;
			this->button2->Text = L"Product Aisle Only";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(498, 349);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(145, 84);
			this->button3->TabIndex = 15;
			this->button3->Text = L"Product Only";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(73, 746);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(145, 84);
			this->button4->TabIndex = 16;
			this->button4->Text = L"Add Client";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(262, 746);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(145, 84);
			this->button5->TabIndex = 17;
			this->button5->Text = L"Add Seller";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(699, 129);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(94, 32);
			this->label9->TabIndex = 18;
			this->label9->Text = L"Action";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(705, 189);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(183, 39);
			this->comboBox1->TabIndex = 19;
			// 
			// viewer
			// 
			this->viewer->Location = System::Drawing::Point(994, 190);
			this->viewer->Multiline = true;
			this->viewer->Name = L"viewer";
			this->viewer->Size = System::Drawing::Size(488, 640);
			this->viewer->TabIndex = 20;
			this->viewer->TextChanged += gcnew System::EventHandler(this, &AdminDashboard::viewer_TextChanged);
			// 
			// AdminDashboard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(16, 31);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1567, 949);
			this->Controls->Add(this->viewer);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(6);
			this->Name = L"AdminDashboard";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"AdminDashboard";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &AdminDashboard::AdminDashboard_FormClosed);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void AdminDashboard_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		obj->Show();
	}
	
	private: System::Void viewer_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
