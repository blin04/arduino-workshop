int pin = 10;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(pin, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int button = digitalRead(pin);
  Serial.println(button);
}
