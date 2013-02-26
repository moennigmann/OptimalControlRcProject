#pragma once
#include "ClientCreator.h"
#include <SerialClass.h>
#include <PID_Controller.h>

namespace RC_Cars {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung f�r Form1
	/// </summary>

	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			
			createClient();
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				disconnectClient();
				delete components;
			}
		}
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	protected: 
	private: System::Windows::Forms::Button^  button_start;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  button_stop;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TrackBar^  trackBar1;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  button1;
	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode f�r die Designerunterst�tzung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor ge�ndert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->button_start = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button_stop = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar1))->BeginInit();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->WorkerSupportsCancellation = true;
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &Form1::backgroundWorker1_DoWork);
			this->backgroundWorker1->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &Form1::backgroundWorker1_RunWorkerCompleted);
			// 
			// button_start
			// 
			this->button_start->Location = System::Drawing::Point(11, 13);
			this->button_start->Name = L"button_start";
			this->button_start->Size = System::Drawing::Size(75, 23);
			this->button_start->TabIndex = 0;
			this->button_start->Text = L"Start";
			this->button_start->UseVisualStyleBackColor = true;
			this->button_start->Click += gcnew System::EventHandler(this, &Form1::button_start_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->Location = System::Drawing::Point(174, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(800, 800);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox1_Paint);
			// 
			// button_stop
			// 
			this->button_stop->Enabled = false;
			this->button_stop->Location = System::Drawing::Point(92, 13);
			this->button_stop->Name = L"button_stop";
			this->button_stop->Size = System::Drawing::Size(75, 23);
			this->button_stop->TabIndex = 1;
			this->button_stop->Text = L"Stop";
			this->button_stop->UseVisualStyleBackColor = true;
			this->button_stop->Click += gcnew System::EventHandler(this, &Form1::button_stop_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(43, 35);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(38, 20);
			this->textBox1->TabIndex = 5;
			this->textBox1->Text = L"0.1";
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->textBox1->Leave += gcnew System::EventHandler(this, &Form1::textBox1_Leave);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(7, 38);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(30, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"KP =";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(43, 62);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(38, 20);
			this->textBox2->TabIndex = 6;
			this->textBox2->Text = L"1";
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->textBox2->Leave += gcnew System::EventHandler(this, &Form1::textBox2_Leave);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(43, 89);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(38, 20);
			this->textBox3->TabIndex = 7;
			this->textBox3->Text = L"0";
			this->textBox3->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->textBox3->Leave += gcnew System::EventHandler(this, &Form1::textBox3_Leave);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(8, 65);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(29, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Tn =";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(8, 92);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(29, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Tv =";
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(3, 5);
			this->trackBar1->Maximum = 60;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(149, 45);
			this->trackBar1->TabIndex = 3;
			this->trackBar1->Value = 30;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &Form1::trackBar1_Scroll);
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->textBox2);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->textBox3);
			this->panel1->Location = System::Drawing::Point(11, 133);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(156, 120);
			this->panel1->TabIndex = 3;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(11, 8);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(70, 13);
			this->label4->TabIndex = 9;
			this->label4->Text = L"PID-Controler";
			// 
			// panel2
			// 
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->button1);
			this->panel2->Controls->Add(this->label5);
			this->panel2->Controls->Add(this->trackBar1);
			this->panel2->Location = System::Drawing::Point(11, 42);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(157, 85);
			this->panel2->TabIndex = 2;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(43, 56);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 4;
			this->button1->Text = L"stop";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(57, 37);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(43, 13);
			this->label5->TabIndex = 12;
			this->label5->Text = L"Throttle";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(990, 830);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button_stop);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button_start);
			this->Name = L"Form1";
			this->Text = L"Form1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void button_start_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->button_start->Enabled = false;
				 this->button_stop->Enabled = true;
				 this->button_stop->Focus();
				 backgroundWorker1->RunWorkerAsync();
			 }
private: System::Void pictureBox1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			 
			 Pen^ pen=gcnew Pen(Color::Red, 3);
			 Pen^ pen2=gcnew Pen(Color::Green, 5);
			 Pen^ pen3=gcnew Pen(Color::Black, 2);

			 //draw red cross
			 for (int i=0; i<5;i++){
				e->Graphics->DrawLine(pen,(int)X[i]/5+400-6,(int)-Y[i]/5+400,(int)X[i]/5+400+7,(int)-Y[i]/5+400);
				e->Graphics->DrawLine(pen,(int)X[i]/5+400,(int)-Y[i]/5+400-6,(int)X[i]/5+400,(int)-Y[i]/5+400+7);
			 }

			 //draw controller output value
			 e->Graphics->DrawLine(pen2,10,10,10+(15+u)*10,10);
			 e->Graphics->DrawLine(pen3,10,5,310,5);

			 delete pen; delete pen2; delete pen3;
		 }
private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
			const int rSetPoint = 500;	//set-point radius;
			int steering=15, oldSteering=15, oldThrottle=30;
			LARGE_INTEGER frequency;        // ticks per second, for accurate time measurement
			LARGE_INTEGER t1, t2;           // ticks, for accurate time measurement

			// Create txt-File
			DataTxt.std::ofstream::open("Data.txt"); 
			DataTxt << "time\tX1\tY1\tRZ1\tX2\tY2\tRZ2\tX3\tY3\tRZ3\tX4\tY4\tRZ4\tX5\tY5\tRZ5\n" ;
			
			QueryPerformanceFrequency(&frequency); // get ticks per second
			QueryPerformanceCounter(&t1);	// get starting time

			Serial *mycomport = new Serial("COM3");		//use the Arduino COM Port here, can be found in Arduino IDE
			PID_Controller controller1(uMin, uMax);
			while (true){
				//get coordinates (waits for new frame (Vicon Tracker frame rate) )
				getCoordinates();

				//PID-controller
				u = controller1.step(rSetPoint, sqrt(X[0]*X[0]+Y[0]*Y[0]), KP, Tn, Tv); 
				
				//get time for txt
				QueryPerformanceCounter(&t2);
				
				//send data to car
				steering = (int) u - uMin;
				if (steering != oldSteering)
					mycomport->WriteData(steering |= 1 << 7, 1);	//steering
				oldSteering = steering;
				if (throttle != oldThrottle)
					mycomport->WriteData(throttle, 1);	//throttle
				oldThrottle = throttle;

				//write txt
				DataTxt << (t2.QuadPart - t1.QuadPart) * 1000 / frequency.QuadPart << "\t" //time
					//<< u <<"\t"<< controller.error << "\t"<< controller.E <<"\n";
						<< X[0] << "\t"	<< Y[0] << "\t"	<< D[0] << "\t"	
						<< X[1] << "\t"	<< Y[1] << "\t"	<< D[1] << "\t"
						<< X[2] << "\t"	<< Y[2] << "\t"	<< D[2] << "\t"
						<< X[3] << "\t"	<< Y[3] << "\t"	<< D[3] << "\t"
						<< X[4] << "\t"	<< Y[4] << "\t"	<< D[4] << "\n";

				//redraw pictureBox1
				pictureBox1->Invalidate();

				//check for cancellation
				if (this->backgroundWorker1->CancellationPending){
					
					break;
				}
			 }
		 }
private: System::Void button_stop_Click(System::Object^  sender, System::EventArgs^  e) {
			 //initializes backgroundWorker1 cancellation
			 this->trackBar1->Value = 30;
			 throttle = 30;
			 this->backgroundWorker1->CancelAsync();
			 this->button_stop->Enabled = false;
			 this->button_start->Enabled = true;
			 this->button_start->Focus();
		 }
private: System::Void backgroundWorker1_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) {
			 DataTxt.std::ofstream::close();
			 //MessageBox::Show("");
		 }
private: System::Void textBox1_Leave(System::Object^  sender, System::EventArgs^  e) {
			 KP = System::Convert::ToDouble(this->textBox1->Text);
		 }
private: System::Void textBox2_Leave(System::Object^  sender, System::EventArgs^  e) {
			 double x = System::Convert::ToDouble(this->textBox2->Text);
			 //Tn must be greater than zero
			 if (x>0)
				 Tn = x;
			 else{
				 this->textBox2->Text = "1";
				 Tn = 1;
			 }
		 }
private: System::Void textBox3_Leave(System::Object^  sender, System::EventArgs^  e) {
			 double x = System::Convert::ToDouble(this->textBox3->Text);
			 //Tv must not be less than zero
			 if (x<0){
				 this->textBox3->Text = "0";
				 Tv = 0;
			 }
			 else
				 Tv = x;
		 }
private: System::Void trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e) {
			 //throttle = 0 => max forward; throttle = 60 max backward; trackBar1 = [0;60]
			 throttle = 60 - this->trackBar1->Value;
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 //sets treckBar1 and throttle to 30 => motor stop
			 this->trackBar1->Value = 30;
			 throttle = 30;
		 }
};
}