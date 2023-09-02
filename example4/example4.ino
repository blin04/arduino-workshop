int d1 = 3;
int d2 = 4;
int d3 = 5;
int d4 = 6;
int pot = A0;

void setup() {
  // put your setup code here, to run once:
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  int pot_value = analogRead(pot);
  int mapped_value = map(pot_value, 0, 1023, 0, 4);

  if (mapped_value >= 1) digitalWrite(d1, HIGH);
  else digitalWrite(d1, LOW);

  if (mapped_value >= 2) digitalWrite(d2, HIGH);
  else digitalWrite(d2, LOW);

  if (mapped_value >= 3) digitalWrite(d3, HIGH);
  else digitalWrite(d3, LOW);

  if (mapped_value >= 4) digitalWrite(d4, HIGH);
  else digitalWrite(d4, LOW);
}
