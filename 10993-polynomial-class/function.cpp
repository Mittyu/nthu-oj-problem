#include "function.h"

#include <iostream>

using namespace std;

Polynomial::Polynomial() {
  greatestPower = 0;
  for (auto &i : this->coefficients) i = 0;
}

Polynomial::Polynomial(const int power, const int coefficients[51]) {
  this->greatestPower = power;
  int i;
  for ( i = 0; i <= power; i++) this->coefficients[i] = coefficients[i];
  for ( ; i < 51; i++) this->coefficients[i] = 0;
}

Polynomial Polynomial::add(const Polynomial partner) const {
  Polynomial* ans = new Polynomial();
  
  ans->greatestPower = max(this->greatestPower, partner.greatestPower);

  for (int i = 0; i <= ans->greatestPower; i++)
    ans->coefficients[i] = this->coefficients[i] + partner.coefficients[i];
  
  return *ans;
}

Polynomial Polynomial::subtract(const Polynomial partner) const{
  Polynomial* ans = new Polynomial();
  
  ans->greatestPower = max(this->greatestPower, partner.greatestPower);

  for (int i = 0; i <= ans->greatestPower; i++)
    ans->coefficients[i] = this->coefficients[i] - partner.coefficients[i];
  
  return *ans;
}

Polynomial Polynomial::multiplication(const Polynomial partner) const {
  Polynomial* ans = new Polynomial();

  ans->greatestPower = this->greatestPower + partner.greatestPower;

  for (int i = 0; i <= this->greatestPower; i++) {
    for (int j = 0; j <= partner.greatestPower; j++) {
      ans->coefficients[i + j] += this->coefficients[i] * partner.coefficients[j];
    }
  }

  return *ans;
}

void Polynomial::output() const {
  for (int i = greatestPower; i > 0; i--) cout << this->coefficients[i] << " ";
  cout << this->coefficients[0];
}