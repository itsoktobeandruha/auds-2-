#pragma once
#include <math.h>
namespace visuals {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::PictureBox^ picture;
	private: System::Windows::Forms::Timer^ timer;

	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->picture = (gcnew System::Windows::Forms::PictureBox());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picture))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(712, 23);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(186, 94);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Start";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(712, 161);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(186, 93);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Stop";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(712, 308);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(186, 95);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Clear";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// picture
			// 
			this->picture->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->picture->Location = System::Drawing::Point(12, 23);
			this->picture->Name = L"picture";
			this->picture->Size = System::Drawing::Size(671, 545);
			this->picture->TabIndex = 4;
			this->picture->TabStop = false;
			// 
			// timer
			// 
			this->timer->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->ClientSize = System::Drawing::Size(924, 580);
			this->Controls->Add(this->picture);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"Draw Circle";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picture))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

		double getY(double x, int r)
		{
			return sqrt(r * r - x * x);
		}


	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		timer->Start();
	}

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		timer->Stop();
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		picture->Image = nullptr;
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Random^ rn = gcnew Random;

		Pen^ penDr = gcnew Pen(Color::FromArgb(rn->Next(256), rn->Next(256), rn->Next(256)));
		/*e->Graphics->DrawEllipse(penDr, 100, 50, 80, 40);*/
		/*Pen^ penDr = gcnew Pen(Color::FromArgb(255, 0, 0));*/
		int r = 90;
		double y1;
		for (double x; x <= r; x += 0.1)
		{
			y1 = getY(x, r);
			this->picture->CreateGraphics()->DrawEllipse(penDr, x + 300, y1 + 200, 20, 20);
			this->picture->CreateGraphics()->DrawEllipse(penDr, x + 300, -y1 + 200, 20, 20);
			this->picture->CreateGraphics()->DrawEllipse(penDr, -x + 300, y1 + 200, 20, 20);
			this->picture->CreateGraphics()->DrawEllipse(penDr, -x + 300, -y1 + 200, 20, 20);
		}
	}
};
}