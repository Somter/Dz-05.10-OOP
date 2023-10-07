// Dz 05.10 OOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <string>
using namespace std;

// ����������� ����� "���������"
class Continent {
protected:
    string name;
public:
    Continent(string n) : name(n) {}
    virtual void PrintContinent() = 0;
};

// ����������� ����� "���������� ��������"
class Herbivore {
protected:
    string name;
public:
    Herbivore(string n) : name(n) {}
    virtual void EatGrass() {}
    virtual void Life(bool life) {}
    virtual void PrintAnimal() {}
    virtual double GetWeight() const { return 0.0; }
    virtual string GetName() const { return ""; }      
};          
        
// ����� "�������� ���"
class Wildebeest : public Herbivore {
private:
    double weight;
    bool life;
public:
    Wildebeest(double w, bool l, string n) : weight(w), life(l), Herbivore(n) {}
    void EatGrass() {
        weight += 10;
        cout << "+ 10 � ����\n";
    }
    void Life(bool life) {
        if (life == true) {
            cout << name << " �����" << endl;
        }
        else {
            cout << name << " ������ :/" << endl;
        }
    }
    double GetWeight() const
    {
        return weight;      
    }
    string GetName() const   
    {
        return name;       
    }
    void PrintAnimal() {
        cout << "��������: " << name << endl;   
        cout << "���: " << weight << endl;
    }
};

// ����������� ����� "���������� ��������"
class Carnivore {
protected:
    string name;
    double power;
public:
    Carnivore(double p, string n) : power(p), name(n){}       
    virtual void Eat(Herbivore* herbivore) {}   
    virtual void Print() {} 
};

class Lion : public Carnivore
{
public: 
    Lion() = default;
    Lion(int p, string n): Carnivore(p, n) {}
    void Eat(Herbivore* herbivore) 
    {
       if (power > herbivore->GetWeight())          
       {
           power += 10;
           cout << name << " ������ " << herbivore->GetName() << endl;    
           cout << "+10 � ����\n";  
       } 
       else {
           power -= 10; 
           cout << herbivore->GetName() << " �������� ���������... -10 � ����\n";
       }
    }
    void Print()    
    {
        cout << "��������: " << name << endl;
        cout << "����: " << power << endl;    
    }
};


// ����� "������"
class Africa : public Continent {
private:
    string flora;
    string fauna;
public:
    Africa(string n) : Continent(n) {}
    void PrintContinent() {
        cout << name << endl;
        cout << "�����: " << flora << endl;
        cout << "�����: " << fauna << endl;
    }
    void SetFlora(string f) {
        flora = f;
    }
    void SetFauna(string f) {
        fauna = f;
    }
};
int main() {
    setlocale(LC_ALL, "");
    int choice;
    cout << "�������� ���������:\n";
    cout << "1 - ������\n";
    cout << "2 - �������� �������\n";
    cout << "��� �����: ";
    cin >> choice;

    Herbivore* herbivore = nullptr; 
    Carnivore* carnivore =  nullptr;    

    switch (choice) {
    case 1: // ������
    {
        Africa obj1("������");
        obj1.SetFlora("�������, �������, �������");
        obj1.SetFauna("�����, ����, ������, �����, �������, ��������");
        obj1.PrintContinent();
        cout << "\n";
        // �������� ���
        herbivore = new Wildebeest(70.7, true, "�������� ���");
        herbivore->EatGrass();
        herbivore->Life(true);
        herbivore->PrintAnimal();
        cout << "\n";   
        // ���
        carnivore = new Lion(100.10, "���");    
        carnivore->Eat(herbivore);
        carnivore->Print(); 
        break;
    }
    case 2: // �������� �������

        break;
    }

    delete herbivore;
    delete carnivore;   

    return 0;
}

//����� "���������" (Continent) :
//
//	����������� �����, �������������� ���������.
//	��������� ���� :
//�������� ����������(��������, ��������� ���� "name").
//���������� � ����� � �����(��������, ������ ����� �������� � ��������).
//��������� ���������� � ����������(������ �������� ���������� � ����������).
//����������� ������ :
//����������� ����� ��� ���������� ���������� � ���������� � ���������.
//����������� ����� ��� �������� ����������.
//����� "������" (Africa) :
//
//	���������� �����, ��������� "���������".
//	������ :
//	���������� ������� ��� ���������� ���������� � ���������� � ������.
//	���������� ������ ��� �������� ������.
//	����� "�������� �������" (North America) :
//
//	���������� �����, ��������� "���������".
//	������ :
//	���������� ������� ��� ���������� ���������� � ���������� � �������� �������.
//	���������� ������ ��� �������� �������� �������.
//	����������� ����� "���������� ��������" (Herbivore) :
//
//	����������� �����, �������������� ����������.
//	��������� ���� :
//���(��������, ���� "weight").
//�����(��������, ������ ���� "isAlive").
//����������� ����� :
//����������� ����� "������ �����", ������� ����������� ��� �� + 10.
//����� "�������� ���" (Wildebeest) :
//
//	���������� �����, ��������� "���������� ��������".
//	������ :
//	���������� ������ "������ �����".
//	����� "�����" (Bison) :
//
//	���������� �����, ��������� "���������� ��������".
//	������ :
//	���������� ������ "������ �����".
//	����������� ����� "���������� ��������" (Carnivore) :
//
//	����������� �����, �������������� ����������.
//	��������� ���� :
//����(��������, ���� "strength").
//����������� ����� :
//����������� ����� "������ ���������� ��������", ������� ��������� ������ ����������� � ������������ ��� �������� ����� ������(���������� ��� ��������� ����).
//����� "���" (Lion) :
//
//	���������� �����, ��������� "���������� ��������".
//	������ :
//	���������� ������ "������ ���������� ��������".
//	����� "����" (Wolf) :
//
//	���������� �����, ��������� "���������� ��������".
//	������ :
//	���������� ������ "������ ���������� ��������".
//	����� "��� ��������" (Animal World) :
//
//	�����, ������� ��������� ����� ���������� � ����� ���� ��������.
//	������ :
//	����� "������� ����������", ������� ���������� ���� ���������� ���������� � ��������.
//	����� "������� ����������", ������� ���������� ���� ���������� ��������� �� ����������.
// 
// 
// 
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
