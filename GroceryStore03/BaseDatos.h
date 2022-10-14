#pragma once

namespace GroceryStore03 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de BaseDatos
	/// </summary>
	public ref class BaseDatos : public System::Windows::Forms::Form
	{
	public:
		BaseDatos(void)
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
		~BaseDatos()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;

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
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(25, 23);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(286, 100);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Insertar";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(24, 178);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(287, 100);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Modicar";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(25, 335);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(286, 110);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Eliminar";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(564, 23);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(286, 100);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Consultar Descuento";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(564, 178);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(286, 100);
			this->button5->TabIndex = 4;
			this->button5->Text = L"Consultar Descuento";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(563, 345);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(287, 100);
			this->button6->TabIndex = 5;
			this->button6->Text = L"Modificar Descuento";
			this->button6->UseVisualStyleBackColor = true;
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(273, 507);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(354, 45);
			this->button7->TabIndex = 6;
			this->button7->Text = L"Salir";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &BaseDatos::button7_Click);
			// 
			// BaseDatos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(982, 601);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"BaseDatos";
			this->Text = L"BaseDatos";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
	
	}
};
}
