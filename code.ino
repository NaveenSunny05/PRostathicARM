#include <Servo.h>
#include <LiquidCrystal.h>

Servo pinky;
Servo ring;
Servo middle;
Servo index;
Servo thumb;

// Define analog pins for the electrodes
const int alphaPin = A0;
const int betaPin = A1;
const int gammaPin = A2;
const int deltaPin = A3;
const int thetaPin = A4;

int alpha = 0;
int beta = 0;
int gamma = 0;
int delta = 0;
int theta = 0;

// Define pins for the LCD
const int rs = 12, en = 11, d4 = 10, d5 = 9, d6 = 8, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  pinky.attach(6);
  ring.attach(5);
  middle.attach(4);
  index.attach(3);
  thumb.attach(2);
  
  Serial.begin(9600); // Start serial communication at 9600 baud
  lcd.begin(16, 4);   // Initialize the LCD with 16 columns and 4 rows
}

void loop() {
  // Read analog values from electrodes
  alpha = analogRead(alphaPin);
  beta = analogRead(betaPin);
  gamma = analogRead(gammaPin);
  delta = analogRead(deltaPin);
  theta = analogRead(thetaPin);

  // Control the servos based on the received values
  pinky.write(map(alpha, 0, 1023, 0, 180));
  ring.write(map(beta, 0, 1023, 0, 180));
  middle.write(map(gamma, 0, 1023, 0, 180));
  index.write(map(delta, 0, 1023, 0, 180));
  thumb.write(map(theta, 0, 1023, 0, 180));

  // Display the values on the LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Alpha: ");
  lcd.print(alpha);
  lcd.setCursor(0, 1);
  lcd.print("Beta: ");
  lcd.print(beta);
  lcd.setCursor(0, 2);
  lcd.print("Gamma: ");
  lcd.print(gamma);
  lcd.setCursor(0, 3);
  lcd.print("Delta: ");
  lcd.print(delta);

  delay(200); // Add a small delay to avoid flickering
}
