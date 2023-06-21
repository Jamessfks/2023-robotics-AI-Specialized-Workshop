#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Initialize the LCD display

void setup() {
  lcd.begin(16, 2); // Set the LCD display to 16x2
  lcd.print("Weight (kg):"); // Display prompt for weight input
}

void loop() {
  float weight, height, bmi;
  String category;

  while (!Serial.available()) {
    // Wait for weight input from the user
  }
  weight = Serial.parseFloat(); // Read weight from the user

  lcd.clear();
  lcd.print("Height (m):"); // Display prompt for height input

  while (!Serial.available()) {
    // Wait for height input from the user
  }
  height = Serial.parseFloat(); // Read height from the user

  // Calculate BMI
  bmi = weight / (height * height);

  // Determine category based on BMI value
  if (bmi < 16.0) {
    category = "Severely Underweight";
  } else if (bmi >= 16.0 && bmi <= 18.4) {
    category = "Underweight";
  } else if (bmi >= 18.5 && bmi <= 24.9) {
    category = "Normal";
  } else if (bmi >= 25.0 && bmi <= 29.9) {
    category = "Overweight";
  } else if (bmi >= 30.0 && bmi <= 34.9) {
    category = "Moderately Obese";
  } else if (bmi >= 35.0 && bmi <= 39.9) {
    category = "Severely Obese";
  } else {
    category = "Morbidly Obese";
  }

  // Calculate normal weight range
  float minWeight = 18.5 * height * height;
  float maxWeight = 24.9 * height * height;

  lcd.clear();
  lcd.print("BMI: ");
  lcd.print(bmi); // Display calculated BMI
  lcd.setCursor(0, 1);
  lcd.print("Category: ");
  lcd.print(category); // Display BMI category
  delay(5000);

  lcd.clear();
  lcd.print("Normal Weight:");
  lcd.setCursor(0, 1);
  lcd.print(minWeight);
  lcd.print(" - ");
  lcd.print(maxWeight); // Display normal weight range
  delay(5000);
}
