int IN1 = 9;
int IN2 = 7;
int IN3 = 6;
int IN4 = 5;
int ENA = 10;
int ENB = 3;
int left = 11;
int middle = 12;
int right = 8;
int l, m, r;
bool forward = false;
void setup() {
  // put your setup code here, to run once:
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  //
  pinMode(left, INPUT);
  pinMode(middle, INPUT);
  pinMode(right, INPUT);
}

void loop() {

  l = digitalRead(left);
  m = digitalRead(middle);
  r = digitalRead(right);

  // Forward();
  if ((l == 1 && m == 1 && r == 1)) {
    Forward();
  } else if (l == 0 && m == 1 && r == 0) {
    Forward();
  } else if (l == 1 && m == 0 && r == 0) {
    Left();
  } else if (l == 1 && m == 1 && r == 0) {
    Left();
  } else if (l == 0 && m == 0 && r == 1) {
    Right();
  } else if (l == 0 && m == 1 && r == 1) {
    Right();
  } 
  else
    Backward();

}

void stop() {
  analogWrite(ENA, 150);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENB, 150);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void Forward() {
  forward = true;
  analogWrite(ENA, 255);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENB, 255);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void Backward() {
  analogWrite(ENA, 150);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENB, 150);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void Right(){
    if(forward)
  {
    forward = false;
    // Backward();
    // delay(10);
  }
analogWrite(ENA, 255);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
    analogWrite(ENB,  255);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
}
void Left() {
  if(forward)
  {
    forward = false;
    // Backward();
    // delay(10);
  }
  analogWrite(ENA,  255);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  analogWrite(ENB,  255);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

