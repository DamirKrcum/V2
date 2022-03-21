#pragma once
#include <iostream>
#include "PomocneFunkcije.h"
#include "Datum.h"
using namespace std;


class Radnik {
private:
    char* _ime;
    char* _prezime;
    Datum* _datumRodjenja;
    bool* _spol;
    char _radnoMjesto[100];
    char* _grad;
    char _email[100];
public:
    //Z3.1
    Radnik() {
        _ime = nullptr;
        _prezime = nullptr;
        _datumRodjenja = nullptr;
        _spol = nullptr;
        strcpy_s(_radnoMjesto, 100, " ");
        _grad = nullptr;
        strcpy_s(_email, 100, " ");

    }
    //Z3.2
    Radnik(const char* ime, const char* prezime, Datum datum, bool spol, const char* radnoM, const char* grad, const char* email) {
        _ime = AlocirajIKopiraj(ime);
        _prezime = AlocirajIKopiraj(prezime);
        _datumRodjenja = new Datum(datum.GetDan(), datum.GetMjesec(), datum.GetGodina());
        _spol = new bool(spol);
        strcpy_s(_radnoMjesto, 100, radnoM);
        _grad = AlocirajIKopiraj(grad);
        strcpy_s(_email, 100, email);
    }

    //Z3.3
    char* GetIme() const { return _ime; }
    char* GetPrezime() const { return _prezime; }
    Datum GetDatumRodjenja() const {return *_datumRodjenja; }
    bool GetSpol() const { return *_spol; }
    const char* GetRadnoMjesto() const { return _radnoMjesto; }
    char* GetGrad() const { return _grad; }
    const char* GetEmail() const { return _email; }

    //Z3.4
    void SetIme(const char* ime) {
        if (_ime != nullptr)
            delete[] _ime;
        _ime = AlocirajIKopiraj(ime);
    }
    void SetPrezime(const char* prezime) {
        if (_prezime != nullptr)
            delete[] _prezime;
        _prezime = AlocirajIKopiraj(prezime);
    }
    void SetDatumRodjenja(Datum datum) {
        if (_datumRodjenja == nullptr)
            _datumRodjenja = new Datum;
        _datumRodjenja->SetDan(datum.GetDan());
        _datumRodjenja->SetMjesec(datum.GetMjesec());
        _datumRodjenja->SetGodina(datum.GetGodina());
    }
    void SetSpol(bool spol) {
        if (_spol == nullptr)
            _spol = new bool;
        *_spol = spol;
    }
    void SetRadnoMjesto(const char* radnoMjesto) {  
        for (int i = 0; i < 100; i++)
        {
            _radnoMjesto[i] = ' ';
        }
        strcpy_s(_radnoMjesto, 100, radnoMjesto);

    }
    void SetGrad(const char* grad) {
        if (_grad != nullptr)
            delete[] _grad;
        _grad = AlocirajIKopiraj(grad);
    }
    void SetEmail(const char* email) {       
        for (int i = 0; i < 100; i++)
        {
            _email[i] = ' ';
        }
        strcpy_s(_email, 100, email);

    }
    //Z3.5
    void Ispis() {
        cout << "Ime: " << _ime << endl;
        cout << "Prezime: " << _prezime << endl;
        cout << "Datum: ";
        _datumRodjenja->Ispis();
        cout << "Spol: " << (_spol ? "Muski" : "Zenski") << endl;
        cout << "Radno mjesto: " << _radnoMjesto << endl;
        cout << "Grad: " << _grad << endl;
        cout << "E-mail: " << _email << endl;


    }
    //Z3.6
    ~Radnik() {
        delete[] _ime; _ime = nullptr;
        delete[] _prezime; _prezime = nullptr;
        delete[] _grad; _grad = nullptr;
        delete _datumRodjenja; _datumRodjenja = nullptr;
        delete _spol; _spol = nullptr;

    }
};