#pragma once

public ref class Datos
{
private:
    static Datos^ instance;

    Datos() //constructor
    {
        Username = "admin";
        Password = "admin";
    }

public:
    //datos
    property System::String^ Username;
    property System::String^ Password;

    //instancia estática
    static property Datos^ Instance
    {
        Datos^ get()
        {
            if (instance == nullptr)
            {
                instance = gcnew Datos();
            }
            return instance;
        }
    }
};