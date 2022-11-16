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
	/// Resumen de ReporDashboard
	/// </summary>
	public ref class ReporDashboard : public System::Windows::Forms::Form
	{
	public:
		Form^ obj;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ viewer;

	public:
		GroceryManager* gm;

		ReporDashboard(Form^ obj1, GroceryManager* gm) {
			obj = obj1;

			this->gm = gm;

			InitializeComponent();

			this->comboBox1->Items->Add("Pasillo mas visitado");
			this->comboBox1->Items->Add("Pasillo menos visitado");
			this->comboBox1->Items->Add("Productos por pasillo más vendidos");
			this->comboBox1->Items->Add("Marcas mas vendidos");
			this->comboBox1->Items->Add("Cliente que mas compro");
			this->comboBox1->Items->Add("Cliente que menos compro");
			this->comboBox1->Items->Add("Producto que mas se cargo en las gondolas");
			this->comboBox1->Items->Add("Cliente que mas facturo");
			this->comboBox1->Items->Add("Marcas de un producto");
			this->comboBox1->Items->Add("Factura de mayor monto");
			this->comboBox1->Items->Add("Productos de un pasillo");
			this->comboBox1->Items->Add("Clientes del supermercado");
			this->comboBox1->Items->Add("Pasillos del supermercado");
			this->comboBox1->Items->Add("Inventario del supermercado");









		}
	public:
		ReporDashboard(void)
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
		~ReporDashboard()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ button1;
    


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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->viewer = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Black", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(70, 116);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(156, 40);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Reportes";
			// 
			// comboBox1
			// 
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(60, 177);
			this->comboBox1->Margin = System::Windows::Forms::Padding(4);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(274, 30);
			this->comboBox1->TabIndex = 6;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->viewer);
			this->panel1->Location = System::Drawing::Point(386, 42);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(957, 748);
			this->panel1->TabIndex = 2;
			// 
			// viewer
			// 
			this->viewer->Location = System::Drawing::Point(389, 37);
			this->viewer->Multiline = true;
			this->viewer->Name = L"viewer";
			this->viewer->Size = System::Drawing::Size(538, 301);
			this->viewer->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial Black", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(60, 251);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(268, 95);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Accept";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &ReporDashboard::button1_Click);
			// 
			// ReporDashboard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 17);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1401, 820);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			this->Name = L"ReporDashboard";
			this->Text = L"ReporDashboard";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &ReporDashboard::ReporDashboard_FormClosed);
			this->Load += gcnew System::EventHandler(this, &ReporDashboard::ReporDashboard_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ReporDashboard_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		obj->Show();
	}
	private: System::Void ReporDashboard_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		switch (this->comboBox1->SelectedIndex)
		{
			case 0:
			
			this->viewer->Text = gcnew String(gm->getProcessedClients()->DisplayMostVisitedAisle().c_str());
			break;
			case 1:
				//obj->ShowDialog("Reporte 2");
				break;
			default:
			break;
		}
		
	}
};
}
