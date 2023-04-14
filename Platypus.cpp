#include "Platypus.h"

//uparametro konstruqtoris implementacia 
//romelshic vidzaxebt gamochekvis funqcias 
Platypus::Platypus()
{
	hatch();
}
//destruqtori
Platypus::~Platypus(){ }
//parametrebiani konstruqtori
Platypus::Platypus(float w, short age1, char n, char g, bool alive1 = true, bool m = false) {
		//monacemebis shemowmeba da shesabamis cvladebze mishvnelobis minicheba
		if (w > 0 && w<=10) { weight = w; }

		else {
			cerr << "***   input error   ***" << endl;
		}

		if (age1 >= 0) { age = age1; }

		else {
			cerr << "***   input error   ***" << endl;
		}

		if ((n >= 'a' && n <= 'z') || (n >= 'A' && n <= 'Z')) { name = n; }

		else {
			cerr << "***   input error   ***" << endl;	
		}

		if (g == 'm' || g == 'f' || g == 'M' || g == 'F') { gender = g; }

		else {
			cerr << "***   input error   ***" << endl;
		}
		alive = alive1;
		mutant = m;
}

//bechdvis funqcia, romelic bechdavs obieqtis informacias shesabamisi gzavnilis tanxlebit
void Platypus::print(ostream& out) const {
	if (weight > 0 || weight<=10) {
		if (age >= 0) {
			if ((name >= 'a' && name <= 'z') || (name >= 'A' && name <= 'Z')) {
				if (gender == 'm' || gender == 'f' || gender == 'M' || gender == 'F') {
					out << "name : " << name << "\n" << "weight : " 
					<< weight << "\n" << "age : " << age << "\n"
					<< "gender : " << gender << "\n";
				if (alive) out << "status of live : alive" << "\n";
				else out << "status of live : dead" << "\n";
				if (mutant) out << name << " is a mutant " << "\n";
				else out << name << " isn't a mutant " << "\n";
				}
				else{ cerr << "***   input error   ***" << endl; }
			}
			else{ cerr << "***   input error   ***" << endl; }
		}
		else{ cerr << "***   input error   ***" << endl; }
	}
	else{ cerr << "***   input error   ***" << endl; }

	
 }
//brdzolis funqcia, romelic bechdavs gamarjvebul monawiles
//damarcxebuli ki kvdeba
void Platypus::fight(Platypus& p){
	if (p.alive && alive) { // shemowmeba cocxalia tu ara
		float x = (weight / p.weight) * 50; // formula romlis mixedvit vitvlit tu vin gaimarjvebs
		//shemtxveviti ricxvebis generatori 
		default_random_engine dre(time(NULL));
		uniform_real_distribution<float> uni(0, 100);
		float r = uni(dre);
		if (x > r) {
			cout << " the fight won : " << name << endl;
			p.alive = false;
			cout << p.name << " live status : dead " << endl;
		}
		else {
			cout << " the fight won : " << p.name << endl;
			alive = false;
			cout << name << " live status : dead " << endl;
		}
	}
	else {
		if  (!p.alive){cerr << p.name << " is deaed and can not fight " << endl;}
		else{cerr << name << " is deaed and can not fight " << endl;}
	}
}
// gamokvebis funqcia 
void Platypus::eat() {
	if (alive) { //shemowmeba cocxalia tu ara
		float w1 = (weight * 0.1) / 100;// masis momatebis shualedebis gamotvla
		float w2 = (weight * 5.0) / 100;
		default_random_engine dre(time(NULL)); // shemtxveviti ricxvebis generatori
		uniform_real_distribution<float> uni(w1, w2);
		float addW = uni(dre); // cvlads vanichebt shemtxvevit ricxvs
		weight += addW; //izrdeba masa 
	}
	else {
		cout << name << " is dead and can not eat " << endl;
	}
}
//gamochekvis funqcia
void Platypus:: hatch() {
	//vanichebt cvladebs shesabamis mnishvnelobebs
	age = 0;
	alive = true;
	mutant = false;
	cout << "enter the name initial : ";
	cin >> name;
	
	if ((name >= 'a' && name <= 'z') || (name >= 'A' && name <= 'Z')) //monacemebis shemowmeba
	{ 
		default_random_engine dre(time(NULL));	
		uniform_real_distribution<float> uni(0.1, 1);		
		weight = uni(dre);		
		char g[2] = { 'm', 'f' };
		srand(time(NULL));	
		gender = g[rand()%2];	//sqess enicheba shemtxveviti mnishvneloba 
	} 
	else {
		cerr << "***   input error   ***" << endl;
	}
}
//asakis matebis funqcia
void Platypus::age_me() {
	if (alive) {
		if (weight >= 10) {
			alive = false;
			cout << name << " is dead ";
		}
		else {
			cout << "probability of death : " << 10 * weight << '%' << endl; //sikvdilis albatoba
		}
		if (mutant) {
			cout << name << " is mutant" << endl;
		}
		//albatobis gamotvla, gaxdeba tu ara obieqti mutanti
		else {
			srand(time(NULL));
			float r = (rand() % 100) + 1;

			if (r <= 2) {
				mutant = true;
				cout << name << " is mutant  now" << endl;
			}
			else {
				cout << name << " isn't mutant" << endl;
			}
		}
		eat(); //vidzaxebt gaokvebis funqcias
		age++; //asakis zrda
	}
	else {
		cout << name << " is dead and can not grow " << endl;
	}
}
//wvdomis funqciis gansazgvra
float Platypus::get_w()const {
	return weight;
}
//wvdomis funqciis gansazgvra
short Platypus::get_age()const {
	return age;
}
//wvdomis funqciis gansazgvra
char Platypus::get_n()const {
	return name;
}
//wvdomis funqciis gansazgvra
char Platypus::get_g()const {
	return gender;
}
//wvdomis funqciis gansazgvra
bool Platypus::get_alive()const {
	 if (alive) {
		 return "status of live : alive";
	}
	 else {
		 return "status of live : dead";
	 }
}
//wvdomis funqciis gansazgvra
bool Platypus::get_m() const {
	if (mutant) {
		return "is a mutant";
	} else {
		return "isn't a mutant";
	}
}
//operatoris gadatvirtvis implementacia
ostream& operator<<(ostream& out, const Platypus& p) { 
	p.print(out);
	return out;
}




