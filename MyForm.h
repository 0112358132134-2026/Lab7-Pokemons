#pragma once
#include <fstream>
#include "Orden.h"
#include "Lista.h"
using namespace System::IO;
using namespace System::Diagnostics;

namespace Lab6PabloCuevas {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnCalcular;

	private: System::Windows::Forms::ComboBox^ comboBoxMetodo;
	private: System::Windows::Forms::Label^ lbl1;
	private: System::Windows::Forms::Label^ lbl2;
	private: System::Windows::Forms::TextBox^ txtMostrar;

	private: System::Windows::Forms::Label^ lbResultado;
	private: System::Windows::Forms::ComboBox^ comboBoxOrden;
	private: System::Windows::Forms::Label^ lbTiempo;
	private: System::Windows::Forms::Label^ lbltexto;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->btnCalcular = (gcnew System::Windows::Forms::Button());
			this->comboBoxOrden = (gcnew System::Windows::Forms::ComboBox());
			this->comboBoxMetodo = (gcnew System::Windows::Forms::ComboBox());
			this->lbl1 = (gcnew System::Windows::Forms::Label());
			this->lbl2 = (gcnew System::Windows::Forms::Label());
			this->txtMostrar = (gcnew System::Windows::Forms::TextBox());
			this->lbResultado = (gcnew System::Windows::Forms::Label());
			this->lbTiempo = (gcnew System::Windows::Forms::Label());
			this->lbltexto = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnCalcular
			// 
			this->btnCalcular->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Book", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCalcular->Location = System::Drawing::Point(267, 31);
			this->btnCalcular->Name = L"btnCalcular";
			this->btnCalcular->Size = System::Drawing::Size(75, 45);
			this->btnCalcular->TabIndex = 0;
			this->btnCalcular->Text = L"Agregar y Calcular";
			this->btnCalcular->UseVisualStyleBackColor = true;
			this->btnCalcular->Click += gcnew System::EventHandler(this, &MyForm::BtnCalcular_Click);
			// 
			// comboBoxOrden
			// 
			this->comboBoxOrden->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->comboBoxOrden->Cursor = System::Windows::Forms::Cursors::Hand;
			this->comboBoxOrden->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Book", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBoxOrden->ForeColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->comboBoxOrden->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Por generación", L"Por National Number" });
			this->comboBoxOrden->Location = System::Drawing::Point(67, 62);
			this->comboBoxOrden->Name = L"comboBoxOrden";
			this->comboBoxOrden->Size = System::Drawing::Size(137, 23);
			this->comboBoxOrden->TabIndex = 1;
			this->comboBoxOrden->Text = L"No dejar vacio";
			// 
			// comboBoxMetodo
			// 
			this->comboBoxMetodo->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->comboBoxMetodo->Cursor = System::Windows::Forms::Cursors::Hand;
			this->comboBoxMetodo->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Book", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBoxMetodo->ForeColor = System::Drawing::Color::Black;
			this->comboBoxMetodo->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Bubble Sort", L"Quick Sort", L"Stupid Sort" });
			this->comboBoxMetodo->Location = System::Drawing::Point(67, 124);
			this->comboBoxMetodo->Name = L"comboBoxMetodo";
			this->comboBoxMetodo->Size = System::Drawing::Size(137, 23);
			this->comboBoxMetodo->TabIndex = 2;
			this->comboBoxMetodo->Text = L"No dejar vacio";
			// 
			// lbl1
			// 
			this->lbl1->AutoSize = true;
			this->lbl1->BackColor = System::Drawing::Color::White;
			this->lbl1->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Book", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->lbl1->Location = System::Drawing::Point(52, 42);
			this->lbl1->Name = L"lbl1";
			this->lbl1->Size = System::Drawing::Size(167, 15);
			this->lbl1->TabIndex = 3;
			this->lbl1->Text = L"¿De qué forma lo desea ordenar\?";
			// 
			// lbl2
			// 
			this->lbl2->AutoSize = true;
			this->lbl2->BackColor = System::Drawing::Color::White;
			this->lbl2->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Book", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->lbl2->Location = System::Drawing::Point(21, 101);
			this->lbl2->Name = L"lbl2";
			this->lbl2->Size = System::Drawing::Size(235, 15);
			this->lbl2->TabIndex = 4;
			this->lbl2->Text = L"¿Qué método de ordenamiento desea emplear\?";
			// 
			// txtMostrar
			// 
			this->txtMostrar->Location = System::Drawing::Point(33, 165);
			this->txtMostrar->Multiline = true;
			this->txtMostrar->Name = L"txtMostrar";
			this->txtMostrar->Size = System::Drawing::Size(195, 196);
			this->txtMostrar->TabIndex = 5;
			// 
			// lbResultado
			// 
			this->lbResultado->AutoSize = true;
			this->lbResultado->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Book", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbResultado->Location = System::Drawing::Point(276, 136);
			this->lbResultado->Name = L"lbResultado";
			this->lbResultado->Size = System::Drawing::Size(0, 15);
			this->lbResultado->TabIndex = 6;
			// 
			// lbTiempo
			// 
			this->lbTiempo->AutoSize = true;
			this->lbTiempo->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Book", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbTiempo->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->lbTiempo->Location = System::Drawing::Point(234, 348);
			this->lbTiempo->Name = L"lbTiempo";
			this->lbTiempo->Size = System::Drawing::Size(16, 15);
			this->lbTiempo->TabIndex = 7;
			this->lbTiempo->Text = L"...";
			// 
			// lbltexto
			// 
			this->lbltexto->AutoSize = true;
			this->lbltexto->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Book", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbltexto->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->lbltexto->Location = System::Drawing::Point(234, 319);
			this->lbltexto->Name = L"lbltexto";
			this->lbltexto->Size = System::Drawing::Size(109, 15);
			this->lbltexto->TabIndex = 8;
			this->lbltexto->Text = L"Tiempo de ejecución:";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(354, 380);
			this->Controls->Add(this->lbltexto);
			this->Controls->Add(this->lbTiempo);
			this->Controls->Add(this->lbResultado);
			this->Controls->Add(this->txtMostrar);
			this->Controls->Add(this->lbl2);
			this->Controls->Add(this->lbl1);
			this->Controls->Add(this->comboBoxMetodo);
			this->Controls->Add(this->comboBoxOrden);
			this->Controls->Add(this->btnCalcular);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Pokemones";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void BtnCalcular_Click(System::Object^ sender, System::EventArgs^ e) {
		//El archivo para el ejemplo de este lab está en la carpeta del mismo. Es un archivo txt: "Pokemons".
		//Cada Pokemon está distribuido de la siguiente manera: <nombre>-#000-#000-#00... Donde el segundo #es el "National Number" y el tercer #es la generación. 
	
		lbTiempo->Text = "...";
		//Este if valida que los dos ComboBox esten llenos, sino lo estan, mandará un mensaje que deben estar llenos para seguir.
		if (comboBoxOrden->Text == "No dejar vacio" || comboBoxMetodo->Text == "No dejar vacio")
		{
			System::Windows::Forms::MessageBox::Show("ERROR: Debe llenar los dos ComboBox.");
		}
		else
		{
			//Si los dos estan llenos, podrá avanzar.
			if (comboBoxOrden->Text != nullptr && comboBoxMetodo->Text != nullptr)
			{
				//Variables
				String^ Path;
				StreamReader^ streamReader;
				String^ textoDelArchivo;
				Orden^ orden = gcnew Orden;
				try
				{
					OpenFileDialog Dialogo;
					if (Dialogo.ShowDialog() == System::Windows::Forms::DialogResult::OK)
					{
						Path = Dialogo.FileName;
						streamReader = gcnew StreamReader(Path);
						textoDelArchivo = streamReader->ReadToEnd();
					}
				}
				catch (...)
				{
					lbResultado->Text = "Se ha dectectado un error...";
				}

				//Este arreglo separa todos los pokemons por el char ",".
				array <String^>^ separar = textoDelArchivo->Split(',');

				//Estos ifs verifican cual será la forma a ordenar los datos.
				Lista nuevalista;
				if (comboBoxOrden->Text == "Por generación")
				{
					if (comboBoxMetodo->Text == "Bubble Sort")
					{
						//
						Stopwatch Chrono;
						Chrono.Start();
						orden->BubleSortGeneracion(separar, separar->Length);
						Chrono.Stop();
						lbTiempo->Text = Chrono.Elapsed.ToString();
						//
						for (int i = 0; i < separar->Length; i++)
						{
							nuevalista.MeterNumero(separar[i]);
						}					
						nuevalista.MostrarLista();
					}
					if (comboBoxMetodo->Text == "Quick Sort")
					{
						//
						Stopwatch Chrono;
						Chrono.Start();
						orden->QuickSortGeneracion(separar,0,69);
						Chrono.Stop();
						lbTiempo->Text = Chrono.Elapsed.ToString();
						//
						for (int i = 0; i < separar->Length; i++)
						{
							nuevalista.MeterNumero(separar[i]);
						}
						nuevalista.MostrarLista();
					}
					if (comboBoxMetodo->Text == "Stupid Sort")
					{
						//
						Stopwatch Chrono;
						Chrono.Start();
						orden->StupidSortGeneracion(separar,69);
						Chrono.Stop();
						lbTiempo->Text = Chrono.Elapsed.ToString();
						//
						for (int i = 0; i < separar->Length; i++)
						{
							nuevalista.MeterNumero(separar[i]);
						}
						nuevalista.MostrarLista();
					}
				}
				if (comboBoxOrden->Text == "Por National Number")
				{
					if (comboBoxMetodo->Text == "Bubble Sort")
					{
						//
						Stopwatch Chrono;
						Chrono.Start();
						orden->BubleSortNumber(separar, separar->Length);
						Chrono.Stop();
						lbTiempo->Text = Chrono.Elapsed.ToString();
						//
						for (int i = 0; i < separar->Length; i++)
						{
							nuevalista.MeterNumero(separar[i]);
						}
						nuevalista.MostrarLista();
					}
					if (comboBoxMetodo->Text == "Quick Sort")
					{
						//
						Stopwatch Chrono;
						Chrono.Start();
						orden->QuickSortNumber(separar,0,69);
						Chrono.Stop();
						lbTiempo->Text = Chrono.Elapsed.ToString();
						//
						for (int i = 0; i < separar->Length; i++)
						{
							nuevalista.MeterNumero(separar[i]);
						}
						nuevalista.MostrarLista();
					}
					if (comboBoxMetodo->Text == "Stupid Sort")
					{
						//
						Stopwatch Chrono;
						Chrono.Start();
						orden->StupidSortNumber(separar,69);
						Chrono.Stop();
						lbTiempo->Text = Chrono.Elapsed.ToString();
						//
						for (int i = 0; i < separar->Length; i++)
						{
							nuevalista.MeterNumero(separar[i]);
						}
						nuevalista.MostrarLista();
					}
				}
			}
		}
	}
};
}
