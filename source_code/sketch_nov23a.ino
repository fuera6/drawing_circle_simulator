#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;

int angle1 = 0, angle2 = 0, angle3 = 0; //세 개의 서보모터의 각도 변수
int pin1 = 1, pin2 = 2, pin3 = 3; //세 개의 서보모터의 핀 변수
int ledPin = 6;
int trigPin = 4, echoPin = 5; //초음파 센서의 입출력 핀 변수
int height = 4; //오토 레벨링 높이(단위:cm)
int error = 1; //오토 레벨링 높이 오차(단위:cm)

void setup() {
  servo1.attach(pin1);
  servo2.attach(pin2);
  servo3.attach(pin3);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int distance = 0; //autoleveling에 쓰일 변수
  long degree;
  char color;
  char c;
  Serial.println("Welcome to the Drawing Circle Simulation!");
  Serial.println("a. Big Sector Form");
  Serial.println("b. Small Sector Form");  //선택지
  while (Serial.available() == 0) {}
  c = Serial.read();

  if (c == 'a') {
    Serial.println("You chose a big sector form.");
    Serial.println("Please input the degree.(0~180)");
    while (Serial.available() == 0) {}
    degree = Serial.parseInt();
    Serial.println("Please input the color.");
    Serial.println("a. Red");
    Serial.println("b. Yellow");
    while (Serial.available() == 0) {}
    color = Serial.read();
    Serial.println("Setting is over. Autoleveling will start after 3 seconds.");
    while (1)
    {
      delay(3000);
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      distance = pulseIn(echoPin, HIGH) / 58.2;
      Serial.print("Result of the autoleveling: ");
      Serial.print(distance);
      Serial.println("cm"); //오토 레벨링 결과 출력
      delay(1000);
      if (distance > height + error || distance < height - error) {
        Serial.println("Autoleveling failed.");
        Serial.println("a. First page");
        Serial.println("b. Restart autoleveling");
        while (Serial.available() == 0) {}
        c = Serial.read();
        if (c == 1) {
          Serial.println("Return to the first page.");
          delay(1000);
          break;
        }
        else {
          Serial.println("Restart autoleveling after 3 seconds.");
        }
      }

      else
      {
        Serial.println("Autoleveling succeded!");
        Serial.println("The sector form will be drawn after 3000 seconds.");
        delay(1000);
        Serial.print("3 ");
        delay(1000);
        Serial.print("2 ");
        delay(1000);
        Serial.println("1");
        delay(1000);
        analogWrite(ledPin, 255);
        if (color == 'a') {
          angle3 = 0;
          servo3.write(angle3);
        }
        else if (color == 'b') {
          angle3 = 180;
          servo3.write(angle3);
        }
        delay(1000);
        for (angle1 = 0; angle1 < degree; angle1++) {
          servo1.write(angle1);
          delay(100);
        }
        delay(1000);
        analogWrite(ledPin, 0);
        Serial.println("Succeeded in drawing.");
        Serial.println("Return to the first page.");
        servo1.write(0);
        servo2.write(0);
        servo3.write(0);
        delay(3000);
        break;
      }
    }
  }



  else if (c == 'b') {
    Serial.println("You chose a small sector form.");
    Serial.println("Please input the degree.(0~180)");
    while (Serial.available() == 0) {}
    degree = Serial.parseInt();
    Serial.println("Please input the color.");
    Serial.println("a. Red");
    Serial.println("b. Yellow");
    while (Serial.available() == 0) {}
    color = Serial.read();
    Serial.println("Setting is over. Autoleveling will start after 3 seconds.");
    while (1)
    {
      delay(3000);
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      distance = pulseIn(echoPin, HIGH) / 58.2;
      Serial.print("Result of the autoleveling: ");
      Serial.print(distance);
      Serial.println("cm"); //오토 레벨링 결과 출력
      delay(1000);
      if (distance > height + error || distance < height - error) {
        Serial.println("Autoleveling failed.");
        Serial.println("a. First page");
        Serial.println("b. Restart autoleveling");
        while (Serial.available() == 0) {}
        c = Serial.read();
        if (c == 1) {
          Serial.println("Return to the first page.");
          delay(1000);
          break;
        }
        else {
          Serial.println("Restart autoleveling after 3 seconds.");
        }
      }

      else
      {
        Serial.println("Autoleveling succeded!");
        Serial.println("The sector form will be drawn after 3000 seconds.");
        delay(1000);
        Serial.print("3 ");
        delay(1000);
        Serial.print("2 ");
        delay(1000);
        Serial.println("1");
        delay(1000);
        analogWrite(ledPin, 255);
        if (color == 'a') {
          angle3 = 0;
          servo3.write(angle3);
        }
        else if (color == 'b') {
          angle3 = 180;
          servo3.write(angle3);
        }
        delay(1000);
        for (angle2 = 0; angle2 < angle2; angle2++) {
          servo2.write(angle2);
          delay(100);
        }
        delay(1000);
        analogWrite(ledPin, 0);
        Serial.println("Succeeded in drawing.");
        Serial.println("Return to the first page.");
        servo1.write(0);
        servo2.write(0);
        servo3.write(0);
        delay(3000);
        break;
      }
    }
  }
