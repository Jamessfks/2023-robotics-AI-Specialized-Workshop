#include <Arduino.h>

bool isPrime(int number) {
  if (number < 2) {
    return false;
  }
  for (int i = 2; i <= sqrt(number); i++) {
    if (number % i == 0) {
      return false;
    }
  }
  return true;
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  int count = 0;
  int number = 2;
  int primeNumbers[30];

  while (count < 30) {
    if (isPrime(number)) {
      primeNumbers[count] = number;
      count++;
    }
    number++;
  }

  for (int i = 0; i < 30; i++) {
    Serial.println(primeNumbers[i]);
    delay(1000);
  }

  while (1) {
    // Infinite loop to keep the prime numbers displayed
  }
}
