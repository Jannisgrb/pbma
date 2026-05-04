#ifndef BRUCH_H_
#define BRUCH_H_
using namespace std;

class Bruch {
private:
	int Zaehler;
	int Nenner;
	void normalisiere();
	int ggt(int a, int b);

public:
	Bruch(int Zaehler = 0, int Nenner = 1);
	int zaehler() const;
	int nenner() const;

	Bruch &operator*=(const Bruch &other);
};

Bruch operator*(Bruch links, const Bruch &rechts);
bool operator==(const Bruch &links, const Bruch &rechts);
bool operator!=(const Bruch &links, const Bruch &rechts);
#endif /* BRUCH_H_ */
