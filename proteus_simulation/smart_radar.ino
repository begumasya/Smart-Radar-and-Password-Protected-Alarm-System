#include <Servo.h>
#include <LiquidCrystal.h>
#include <Keypad.h>

LiquidCrystal lcd(7, 8, 5, 4, 3, 2);
Servo radarServo;

const int SERVO_PIN    = 6;
const int POT_PIN      = A0;
const int LED_RED      = 12;
const int LED_GREEN    = 11;

const byte ROWS = 4;
const byte COLS = 3;

char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte rowPins[ROWS] = {A1, A2, A3, A4};
byte colPins[COLS] = {9, 10, 13};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

const String PASSWORD_LOCK   = "2015";
const String PASSWORD_UNLOCK = "2009";

String enteredPassword = "";
bool systemLocked = false;

const int DIST_THRESHOLD = 40;
bool alarmActive = false;

int angle = 0;
int direction = 1;

void setup() {
  Serial.begin(9600);

  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);

  radarServo.attach(SERVO_PIN);
  radarServo.write(0);

  lcd.begin(16, 2);
  lcd.print("RADAR STARTING");
  delay(1500);
  lcd.clear();
}

void readKeypad() {
  char key = keypad.getKey();

  if (!key) return;

  if (key == '*') {
    enteredPassword = "";
    lcd.setCursor(0, 1);
    lcd.print("Cleared        ");
  }

  else if (key == '#') {

    if (enteredPassword == PASSWORD_LOCK && !systemLocked) {
      systemLocked = true;
      alarmActive = false;
      enteredPassword = "";

      radarServo.detach();

      digitalWrite(LED_RED, LOW);
      digitalWrite(LED_GREEN, LOW);

      lcd.clear();
      lcd.print("SYSTEM LOCKED");
    }

    else if (enteredPassword == PASSWORD_UNLOCK) {
      systemLocked = false;
      alarmActive = false;
      enteredPassword = "";

      radarServo.attach(SERVO_PIN);

      digitalWrite(LED_RED, LOW);
      digitalWrite(LED_GREEN, HIGH);

      lcd.clear();
      lcd.print("SYSTEM ACTIVE");
      delay(1000);
      lcd.clear();
    }

    else {
      enteredPassword = "";

      lcd.clear();
      lcd.print("WRONG PASSWORD");
      delay(800);
      lcd.clear();
    }
  }

  else {
    enteredPassword += key;

    if (enteredPassword.length() > 4) {
      enteredPassword = enteredPassword.substring(1);
    }

    lcd.setCursor(0, 0);
    lcd.print("ENTERING PASS");

    lcd.setCursor(0, 1);
    lcd.print("Pass: ");
    for (int i = 0; i < enteredPassword.length(); i++) {
      lcd.print("*");
    }
    lcd.print("        ");
  }
}

void loop() {

  readKeypad();

  if (systemLocked) return;

  radarServo.write(angle);
  delay(40);

  int raw = analogRead(POT_PIN);
  int distance = map(raw, 0, 1023, 0, 400);

  if (distance <= DIST_THRESHOLD && !alarmActive) {
    alarmActive = true;
    enteredPassword = "";

    lcd.clear();
    lcd.print("!! ALARM !!");
  }

  if (alarmActive) {
    digitalWrite(LED_RED, HIGH);
    digitalWrite(LED_GREEN, LOW);

    lcd.setCursor(0, 0);
    lcd.print("!! ALARM !!     ");
  }
  else {
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_GREEN, HIGH);

    lcd.setCursor(0, 0);
    lcd.print("Angle:");
    lcd.print(angle);
    lcd.print("     ");

    lcd.setCursor(0, 1);
    lcd.print("Dist:");
    lcd.print(distance);
    lcd.print("cm   ");
  }

  Serial.print("Angle: ");
  Serial.print(angle);
  Serial.print(" | Distance: ");
  Serial.println(distance);

  angle += direction * 2;

  if (angle >= 180) {
    angle = 180;
    direction = -1;
  } 
  else if (angle <= 0) {
    angle = 0;
    direction = 1;
  }
}