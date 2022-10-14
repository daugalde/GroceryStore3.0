#pragma once

namespace GroceryStore03 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MenuAdmin
	/// </summary>
	public ref class MenuAdmin : public System::Windows::Forms::Form
	{
	public:
		MenuAdmin(void)
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
		~MenuAdmin()
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

	protected:





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
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(272, 98);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(333, 77);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Mantenimiento Base Datos";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(272, 193);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(332, 77);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Facturar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MenuAdmin::button2_Click_1);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(273, 290);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(332, 68);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Revisar Gondolas";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(273, 377);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(331, 77);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Verificar el Inventario";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(273, 470);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(332, 77);
			this->button5->TabIndex = 4;
			this->button5->Text = L"Reportes";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(721, 470);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(202, 75);
			this->button6->TabIndex = 5;
			this->button6->Text = L"Salir";
			this->button6->UseVisualStyleBackColor = true;
			// 
			// MenuAdmin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 585);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MenuAdmin";
			this->Text = L"MenuAdmin";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click_1(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
