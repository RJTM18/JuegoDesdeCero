#pragma once
#include "Juego.H"

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
			juego = nullptr;
		}

	protected:
		~FrmJuego() {
			if (components) { delete components; }
			if (juego != nullptr) delete juego;
		}

	private:
		Juego* juego;

		Bitmap^ Mario;

		Direcciones teclaPresionada;

	private: System::Windows::Forms::Panel^ pnlSprite;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->pnlSprite = (gcnew System::Windows::Forms::Panel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// pnlSprite
			// 
			this->pnlSprite->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlSprite->Location = System::Drawing::Point(0, 0);
			this->pnlSprite->Name = L"pnlSprite";
			this->pnlSprite->Size = System::Drawing::Size(1526, 563);
			this->pnlSprite->TabIndex = 0;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &FrmJuego::Timer1_tick);
			// 
			// FrmJuego
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1526, 563);
			this->Controls->Add(this->pnlSprite);
			this->Name = L"FrmJuego";
			this->Text = L"Juego";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &FrmJuego::FrmJuego_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmJuego::FrmJuego_keyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmJuego::FrmJuego_keyUp);
			this->ResumeLayout(false);

		}
#pragma endregion
	Bitmap^ cargarImagen(String^ name) {
		String^ ruta = Path::Combine(Application::StartupPath, name);
		if (!File::Exists(ruta)) ruta = name;
		return gcnew Bitmap(ruta);
	}

	private: System::Void FrmJuego_Load(System::Object^ sender, System::EventArgs^ e) {
		juego = new Juego(pnlSprite->Height, pnlSprite->Width);
		
		Mario = cargarImagen("Sprite\\Mario.png");
		juego->crearMario(
			/* Posicion x: */			30, 
			/* Posicion y: */			pnlSprite->Height / 2, 
			/* Anchura de Imagen: */	Mario->Width,
			/* Altura de Imagen: */		Mario->Height,
			/* Nº Columnas: */			10, 
			/* Nº Filas: */				19, 
			/* Velocidad: */			30, 
			/* Escala: */				4
		);

		teclaPresionada = Ninguno;
	}

	private: System::Void Timer1_tick(System::Object^ sender, System::EventArgs^ e) {
			int AltoPantalla = pnlSprite->Height;
			int AnchoPantalla = pnlSprite->Width;

			if (AltoPantalla <= 0 || AnchoPantalla <= 0) return;
			
			juego->moverMario(teclaPresionada, AnchoPantalla, AltoPantalla);

			Graphics^ canvas = pnlSprite->CreateGraphics();
			BufferedGraphics^ buffer = BufferedGraphicsManager::Current->Allocate(canvas, pnlSprite->ClientRectangle);
			buffer->Graphics->Clear(Color::White);

			juego->dibujarMario(buffer->Graphics, Mario);
			buffer->Render(canvas);

			delete buffer;
			delete canvas;
		}

		private: System::Void FrmJuego_keyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
			if (e->KeyCode == Keys::Down || e->KeyCode == Keys::S)	teclaPresionada = Abajo;
			if (e->KeyCode == Keys::Up || e->KeyCode == Keys::W)	teclaPresionada = Arriba;
			if (e->KeyCode == Keys::Left || e->KeyCode == Keys::A)	teclaPresionada = Izquierda;
			if (e->KeyCode == Keys::Right || e->KeyCode == Keys::D) teclaPresionada = Derecha;
			if (e->KeyCode == Keys::Space) juego->saltarMario(teclaPresionada, pnlSprite->Width, pnlSprite->Height);
		}

		private: System::Void FrmJuego_keyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
			if (e->KeyCode == Keys::Down || e->KeyCode == Keys::S)  { if (teclaPresionada == Abajo)		teclaPresionada = Ninguno; }
			if (e->KeyCode == Keys::Up || e->KeyCode == Keys::W)	{ if (teclaPresionada == Arriba)	teclaPresionada = Ninguno; }
			if (e->KeyCode == Keys::Left || e->KeyCode == Keys::A)  { if (teclaPresionada == Izquierda) teclaPresionada = Ninguno; }
			if (e->KeyCode == Keys::Right || e->KeyCode == Keys::D) { if (teclaPresionada == Derecha)	teclaPresionada = Ninguno; }
		}

};
}
