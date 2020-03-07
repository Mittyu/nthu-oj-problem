#include <iostream>
#include <string>
using namespace std;
// abstract class
class Food {
	public:
		enum class Type {
			IdiotSandwich,
			NormalSandwich
		};
		friend std::ostream & operator << (std::ostream &out, Food &d) {
			d.print(out);
			return out;
		}
		Type getType() { return type; }
		void setType(Type x) { type = x; }
	private:
		virtual void print(std::ostream &out) {}
		Type type;
};

class IdiotSandwich : public Food {
	public:
		IdiotSandwich(int x) {
			setType(Type::IdiotSandwich);
			setINT(x);
		}
		void setINT(int x) { intelligence = x; }
		int getINT() { return intelligence; }
	private:
		// TODO
		void print(std::ostream &out);
		int intelligence;
};

class NormalSandwich : public Food {
	public:
		NormalSandwich(std::string x) {
			setType(Type::NormalSandwich);
			setName(x);
		}
		void setName(std::string x) { name = x; }
		std::string getName() { return name; }
	private:
		// TODO
		void print(std::ostream &out);
		std::string name;
};

class Dish {
	public:
		Dish() { food = nullptr; }
		~Dish();
		Food &getFood() { return (*food); }
		const Food &getFood() const { return (*food); }
		// TODO
		friend std::istream & operator >> (std::istream &in, Dish &d);
		Food *food;
};

Dish::~Dish(){
    delete food;
}

void IdiotSandwich::print(ostream & out){
    out << "An idiot sandwich with intelligence level " << getINT() << " only.";
}

void NormalSandwich::print(ostream & out){
    out << getName() << ". Masterpiece of sandwiches.";
}

std::istream & operator >> (std::istream &in, Dish &d)
{
    string s;
    in>>s;

    if (d.food != nullptr){
        delete d.food;
        d.food=nullptr;
    }

    if (s=="Ramsay"){

        int level;
        in>>level;
        d.food=new IdiotSandwich(level);

    }
    else{
        d.food=new NormalSandwich(s);
    }
    return in;
}
