// Dz 05.10 OOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <string>
using namespace std;

// Абстрактный класс "Континент"
class Continent {
protected:
    string name;
public:
    Continent(string n) : name(n) {}
    virtual void PrintContinent() = 0;
};

// Абстрактный класс "Травоядное животное"
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
        
// Класс "Антилопа Гну"
class Wildebeest : public Herbivore {
private:
    double weight;
    bool life;
public:
    Wildebeest(double w, bool l, string n) : weight(w), life(l), Herbivore(n) {}
    void EatGrass() {
        weight += 10;
        cout << "+ 10 к весу\n";
    }
    void Life(bool life) {
        if (life == true) {
            cout << name << " живой" << endl;
        }
        else {
            cout << name << " мёртвый :/" << endl;
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
        cout << "Животное: " << name << endl;   
        cout << "Вес: " << weight << endl;
    }
};

// Абстрактный класс "Плотоядное животное"
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
           cout << name << " слопал " << herbivore->GetName() << endl;    
           cout << "+10 к силе\n";  
       } 
       else {
           power -= 10; 
           cout << herbivore->GetName() << " оказался жиробасом... -10 к силе\n";
       }
    }
    void Print()    
    {
        cout << "Животное: " << name << endl;
        cout << "Сила: " << power << endl;    
    }
};


// Класс "Африка"
class Africa : public Continent {
private:
    string flora;
    string fauna;
public:
    Africa(string n) : Continent(n) {}
    void PrintContinent() {
        cout << name << endl;
        cout << "Флора: " << flora << endl;
        cout << "Фауна: " << fauna << endl;
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
    cout << "Выберите континент:\n";
    cout << "1 - Африка\n";
    cout << "2 - Северная Америка\n";
    cout << "Ваш выбор: ";
    cin >> choice;

    Herbivore* herbivore = nullptr; 
    Carnivore* carnivore =  nullptr;    

    switch (choice) {
    case 1: // Африка
    {
        Africa obj1("Африка");
        obj1.SetFlora("Саванны, джунгли, пустыни");
        obj1.SetFauna("Слоны, львы, жирафы, зебры, гепарды, носороги");
        obj1.PrintContinent();
        cout << "\n";
        // Антилопа Гну
        herbivore = new Wildebeest(70.7, true, "Антилопа Гну");
        herbivore->EatGrass();
        herbivore->Life(true);
        herbivore->PrintAnimal();
        cout << "\n";   
        // Лев
        carnivore = new Lion(100.10, "Лев");    
        carnivore->Eat(herbivore);
        carnivore->Print(); 
        break;
    }
    case 2: // Северная Америка

        break;
    }

    delete herbivore;
    delete carnivore;   

    return 0;
}

//Класс "Континент" (Continent) :
//
//	Абстрактный класс, представляющий континент.
//	Возможные поля :
//Название континента(например, строковое поле "name").
//Информация о флоре и фауне(например, список видов растений и животных).
//Население травоядных и плотоядных(списки объектов травоядных и плотоядных).
//Абстрактные методы :
//Абстрактный метод для добавления травоядных и плотоядных в континент.
//Абстрактный метод для описания континента.
//Класс "Африка" (Africa) :
//
//	Конкретный класс, наследник "Континент".
//	Методы :
//	Реализация методов для добавления травоядных и плотоядных в Африку.
//	Реализация метода для описания Африки.
//	Класс "Северная Америка" (North America) :
//
//	Конкретный класс, наследник "Континент".
//	Методы :
//	Реализация методов для добавления травоядных и плотоядных в Северную Америку.
//	Реализация метода для описания Северной Америки.
//	Абстрактный класс "Травоядное животное" (Herbivore) :
//
//	Абстрактный класс, представляющий травоядных.
//	Возможные поля :
//Вес(например, поле "weight").
//Жизнь(например, булево поле "isAlive").
//Абстрактный метод :
//Абстрактный метод "Кушать траву", который увеличивает вес на + 10.
//Класс "Антилопа Гну" (Wildebeest) :
//
//	Конкретный класс, наследник "Травоядное животное".
//	Методы :
//	Реализация метода "Кушать траву".
//	Класс "Бизон" (Bison) :
//
//	Конкретный класс, наследник "Травоядное животное".
//	Методы :
//	Реализация метода "Кушать траву".
//	Абстрактный класс "Плотоядное животное" (Carnivore) :
//
//	Абстрактный класс, представляющий плотоядных.
//	Возможные поля :
//Сила(например, поле "strength").
//Абстрактный метод :
//Абстрактный метод "Кушать травоядное животное", который принимает объект травоядного и обрабатывает его согласно вашей логике(прибавляет или уменьшает силу).
//Класс "Лев" (Lion) :
//
//	Конкретный класс, наследник "Плотоядное животное".
//	Методы :
//	Реализация метода "Кушать травоядное животное".
//	Класс "Волк" (Wolf) :
//
//	Конкретный класс, наследник "Плотоядное животное".
//	Методы :
//	Реализация метода "Кушать травоядное животное".
//	Класс "Мир животных" (Animal World) :
//
//	Класс, который управляет всеми процессами в вашем мире животных.
//	Методы :
//	Метод "Питание травоядных", который инициирует всех травоядных приступить к кормежке.
//	Метод "Питание плотоядных", который заставляет всех плотоядных охотиться на травоядных.
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
