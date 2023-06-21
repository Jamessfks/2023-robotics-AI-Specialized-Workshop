#include <Arduino.h>

bool isPrime(int number) {
  if (number <= 1)
    return false;
  for (int i = 2; i * i <= number; i++) {
    if (number % i == 0)
      return false;
  }
  return true;
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("Enter 'break' to stop the loop or press any key to continue...");
  
  while (!Serial.available()); // Wait for user input
  String input = Serial.readStringUntil('\n');
  
  if (input == "break") {
    Serial.println("Loop stopped.");
    while (1); // Infinite loop to halt the program
  }

  Serial.println("Generating the first 30 prime numbers:");
  
  int count = 0;
  int number = 2;
  
  while (count < 30) {
    if (isPrime(number)) {
      Serial.print(number);
      Serial.print(" ");
      count++;
    }
    number++;
  }
  
  Serial.println();
}
