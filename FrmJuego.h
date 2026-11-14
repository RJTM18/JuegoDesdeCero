#pragma once
#include "Sprite.h"

namespace JuegoDesdeCero {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for FrmJuego
	/// </summary>
	public ref class FrmJuego : public System::Windows::Forms::Form	{
	public:
		FrmJuego(void) {
			InitializeComponent();
			
		}

	protected:
		~FrmJuego() {
			if (components) { delete components; }
		}

	private:
		Bitmap^ caballero;
		Direcciones teclaPresionada;

	private: System::Windows::Forms::Panel^ panel1;
	private: System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1526, 563);
			this->panel1->TabIndex = 0;
			// 
			// FrmJuego
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1526, 563);
			this->Controls->Add(this->panel1);
			this->Name = L"FrmJuego";
			this->Text = L"Juego";
			this->Load += gcnew System::EventHandler(this, &FrmJuego::FrmJuego_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	Bitmap^ cargarImagen(String^ name) {
		String^ ruta = Path::Combine(Application::StartupPath, name);
		if (!File::Exists(ruta)) ruta = name;
		return gcnew Bitmap(ruta);
	}

	//Size retorna un struct
	const struct Size& getSpriteSheetSize() const {
		return caballero->Size();
	}

	private: System::Void FrmJuego_Load(System::Object^ sender, System::EventArgs^ e) {
		caballero = cargarImagen("Sprite\\caballero.png");
		teclaPresionada = Ninguno;

	}
	};
}
