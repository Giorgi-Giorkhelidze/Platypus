//klasis wevr monacemebia:
//			wight, age, name,gende, alive, mutant
//klasis wevr funqciebia:
//			Platypus - uparametro konstruqtori
//			platypus - parametrebiani konstruqtori
//			~Platypus - destruqtori
//			print, fight, age_me, eat, hatch
//			get_w, get_age, get_n, get_g, get_alive, get_m
		
#pragma once
#ifndef __Platypus__
#define __Platypus__
#include <iostream>
#include <random>
#include <ctime>

using namespace std;
class Platypus
{
private:
	float weight; //kg
	short age; //month
	char name; // initial
	char gender; // 'm' or 'f'
	bool alive; // is alive or not
	bool mutant; //is a mutant or not 

public:
	Platypus(); // kostruqtori(uparametro)

	~Platypus(); // destruqtori

	Platypus(float,  short, char, char, bool, bool); //konstruqtori(parametrebi)

	void print(ostream& out) const; // ekranze gamotanis fumqcia

	void age_me(); //asakis zrdis funqcia

	void fight(Platypus&); //brdzolis fuqcia

	void eat(); // gamokvebis finqcia

	void hatch(); //gamochekvis funqcia 

	float get_w()const; //masis amokitxva

	short get_age()const; //asakis amokiTxva

	char get_n()const; //saxelis amokiTxva

	char get_g()const; // sqeisi

	bool get_alive()const; //sicocxlis statusi

	bool get_m()const; //matanti


};


ostream& operator<<(ostream& out, const Platypus& p); // gamotanis operatori gadatvirtva

#endif // !Platypus

