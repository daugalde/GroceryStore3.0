#pragma once

namespace GroceryStore03 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de VentanaPrincipal
	/// </summary>
	public ref class VentanaPrincipal : public System::Windows::Forms::Form
	{
	public:
		VentanaPrincipal(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~VentanaPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;



	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(46, 166);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(289, 101);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Administrador";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &VentanaPrincipal::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(362, 166);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(279, 99);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Usuario";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(462, 69);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(95, 16);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Menu Principal";
			this->label1->Click += gcnew System::EventHandler(this, &VentanaPrincipal::label1_Click_1);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(680, 166);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(266, 99);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Vendedor";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(362, 351);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(279, 39);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Salir";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// VentanaPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1050, 431);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"VentanaPrincipal";
			this->Text = L"VentanaPrincipal";
			this->Load += gcnew System::EventHandler(this, &VentanaPrincipal::VentanaPrincipal_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void VentanaPrincipal_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
