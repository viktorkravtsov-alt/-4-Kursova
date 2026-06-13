#pragma once

#include "Shapes.h"

namespace LB4Forms {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class MyForm : public System::Windows::Forms::Form
    {
    private:
        ShapeContainer* container;

    public:
        MyForm(void)
        {
            InitializeComponent();
            container = new ShapeContainer();

            container->add(new Sphere(3.0));
            container->add(new Box(2.0, 3.0, 4.0));
            container->add(new Cone(2.0, 5.0));
            container->add(new Cylinder(1.5, 4.0));
            container->add(new Sphere(1.0));

            comboBoxType->SelectedIndex = 0;
        }

    protected:
        ~MyForm()
        {
            delete container;
            if (components)
            {
                delete components;
            }
        }

    private:
        System::ComponentModel::Container^ components;

        System::Windows::Forms::ComboBox^ comboBoxType;
        System::Windows::Forms::Label^ label1;
        System::Windows::Forms::Label^ label2;
        System::Windows::Forms::Label^ label3;
        System::Windows::Forms::Label^ label4;
        System::Windows::Forms::TextBox^ textBoxParam1;
        System::Windows::Forms::TextBox^ textBoxParam2;
        System::Windows::Forms::TextBox^ textBoxParam3;
        System::Windows::Forms::Button^ btnAdd;
        System::Windows::Forms::Button^ btnShowAll;
        System::Windows::Forms::Button^ btnFindMin;
        System::Windows::Forms::TextBox^ textBoxOutput;

        void InitializeComponent(void)
        {
            this->comboBoxType = (gcnew System::Windows::Forms::ComboBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->textBoxParam1 = (gcnew System::Windows::Forms::TextBox());
            this->textBoxParam2 = (gcnew System::Windows::Forms::TextBox());
            this->textBoxParam3 = (gcnew System::Windows::Forms::TextBox());
            this->btnAdd = (gcnew System::Windows::Forms::Button());
            this->btnShowAll = (gcnew System::Windows::Forms::Button());
            this->btnFindMin = (gcnew System::Windows::Forms::Button());
            this->textBoxOutput = (gcnew System::Windows::Forms::TextBox());
            this->SuspendLayout();

            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(20, 20);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(60, 13);
            this->label1->Text = L"Тип фігури:";

            this->comboBoxType->FormattingEnabled = true;
            this->comboBoxType->Items->AddRange(gcnew cli::array<System::Object^>(4) {
                L"Куля (Sphere)", L"Паралелепіпед (Box)", L"Конус (Cone)", L"Циліндр (Cylinder)"
            });
            this->comboBoxType->Location = System::Drawing::Point(120, 17);
            this->comboBoxType->Name = L"comboBoxType";
            this->comboBoxType->Size = System::Drawing::Size(200, 21);
            this->comboBoxType->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBoxType_SelectedIndexChanged);

            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(20, 55);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(80, 13);
            this->label2->Text = L"Параметр 1 (radius/a):";

            this->textBoxParam1->Location = System::Drawing::Point(160, 52);
            this->textBoxParam1->Name = L"textBoxParam1";
            this->textBoxParam1->Size = System::Drawing::Size(160, 20);
            this->textBoxParam1->Text = L"1.0";

            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(20, 85);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(80, 13);
            this->label3->Text = L"Параметр 2 (height/b):";

            this->textBoxParam2->Location = System::Drawing::Point(160, 82);
            this->textBoxParam2->Name = L"textBoxParam2";
            this->textBoxParam2->Size = System::Drawing::Size(160, 20);
            this->textBoxParam2->Text = L"1.0";

            this->label4->AutoSize = true;
            this->label4->Location = System::Drawing::Point(20, 115);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(80, 13);
            this->label4->Text = L"Параметр 3 (c):";

            this->textBoxParam3->Location = System::Drawing::Point(160, 112);
            this->textBoxParam3->Name = L"textBoxParam3";
            this->textBoxParam3->Size = System::Drawing::Size(160, 20);
            this->textBoxParam3->Text = L"1.0";

            this->btnAdd->Location = System::Drawing::Point(20, 150);
            this->btnAdd->Name = L"btnAdd";
            this->btnAdd->Size = System::Drawing::Size(120, 30);
            this->btnAdd->Text = L"Додати фігуру";
            this->btnAdd->UseVisualStyleBackColor = true;
            this->btnAdd->Click += gcnew System::EventHandler(this, &MyForm::btnAdd_Click);

            this->btnShowAll->Location = System::Drawing::Point(150, 150);
            this->btnShowAll->Name = L"btnShowAll";
            this->btnShowAll->Size = System::Drawing::Size(120, 30);
            this->btnShowAll->Text = L"Показати всі";
            this->btnShowAll->UseVisualStyleBackColor = true;
            this->btnShowAll->Click += gcnew System::EventHandler(this, &MyForm::btnShowAll_Click);

            this->btnFindMin->Location = System::Drawing::Point(280, 150);
            this->btnFindMin->Name = L"btnFindMin";
            this->btnFindMin->Size = System::Drawing::Size(160, 30);
            this->btnFindMin->Text = L"Знайти мін. об'єм";
            this->btnFindMin->UseVisualStyleBackColor = true;
            this->btnFindMin->Click += gcnew System::EventHandler(this, &MyForm::btnFindMin_Click);

            this->textBoxOutput->Location = System::Drawing::Point(20, 195);
            this->textBoxOutput->Multiline = true;
            this->textBoxOutput->Name = L"textBoxOutput";
            this->textBoxOutput->ReadOnly = true;
            this->textBoxOutput->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
            this->textBoxOutput->Size = System::Drawing::Size(420, 200);
            this->textBoxOutput->Font = gcnew System::Drawing::Font(L"Consolas", 9);

            this->ClientSize = System::Drawing::Size(460, 420);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->comboBoxType);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->textBoxParam1);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->textBoxParam2);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->textBoxParam3);
            this->Controls->Add(this->btnAdd);
            this->Controls->Add(this->btnShowAll);
            this->Controls->Add(this->btnFindMin);
            this->Controls->Add(this->textBoxOutput);
            this->Name = L"MyForm";
            this->Text = L"ЛР №4. Фігури у просторі - візуальний інтерфейс";
            this->ResumeLayout(false);
        }

        String^ ToManaged(const std::wstring& s)
        {
            return gcnew String(s.c_str());
        }

        System::Void comboBoxType_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
        {
            switch (comboBoxType->SelectedIndex)
            {
            case 0:
                label2->Text = L"Параметр 1 (radius):";
                label3->Text = L"";
                label4->Text = L"";
                textBoxParam2->Visible = false;
                textBoxParam3->Visible = false;
                break;
            case 1:
                label2->Text = L"Параметр 1 (a):";
                label3->Text = L"Параметр 2 (b):";
                label4->Text = L"Параметр 3 (c):";
                textBoxParam2->Visible = true;
                textBoxParam3->Visible = true;
                break;
            case 2:
                label2->Text = L"Параметр 1 (radius):";
                label3->Text = L"Параметр 2 (height):";
                label4->Text = L"";
                textBoxParam2->Visible = true;
                textBoxParam3->Visible = false;
                break;
            case 3:
                label2->Text = L"Параметр 1 (radius):";
                label3->Text = L"Параметр 2 (height):";
                label4->Text = L"";
                textBoxParam2->Visible = true;
                textBoxParam3->Visible = false;
                break;
            }
        }

        System::Void btnAdd_Click(System::Object^ sender, System::EventArgs^ e)
        {
            try
            {
                double p1 = Convert::ToDouble(textBoxParam1->Text);
                double p2 = textBoxParam2->Visible ? Convert::ToDouble(textBoxParam2->Text) : 0;
                double p3 = textBoxParam3->Visible ? Convert::ToDouble(textBoxParam3->Text) : 0;

                switch (comboBoxType->SelectedIndex)
                {
                case 0: container->add(new Sphere(p1)); break;
                case 1: container->add(new Box(p1, p2, p3)); break;
                case 2: container->add(new Cone(p1, p2)); break;
                case 3: container->add(new Cylinder(p1, p2)); break;
                }

                MessageBox::Show(L"Фігуру додано до контейнера!", L"Інформація",
                    MessageBoxButtons::OK, MessageBoxIcon::Information);
            }
            catch (Exception^)
            {
                MessageBox::Show(L"Помилка введення даних! Перевірте параметри.", L"Помилка",
                    MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }

        System::Void btnShowAll_Click(System::Object^ sender, System::EventArgs^ e)
        {
            std::wstring info = container->getAllInfo();
            textBoxOutput->Text = L"Список фігур у контейнері (" + container->getCount() + L" шт.):\r\n\r\n"
                + ToManaged(info);
        }

        System::Void btnFindMin_Click(System::Object^ sender, System::EventArgs^ e)
        {
            Shape3D* minShape = container->findMinVolume();
            if (minShape)
            {
                textBoxOutput->Text = L"Фігура з найменшим об'ємом:\r\n\r\n" + ToManaged(minShape->toString());
            }
            else
            {
                textBoxOutput->Text = L"Контейнер порожній.";
            }
        }
    };
}
