int d1 = 3;
int d2 = 4;
int d3 = 5;
int d4 = 6;
int pot = A0;
int button = 10;

String pass = "301001";
String input = "";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT);
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:

  int pot_value = analogRead(pot);

  int map_value = map(pot_value, 0, 1023, 0, 4);

  if (map_value >= 1) digitalWrite(d1, HIGH);
  else digitalWrite(d1, LOW);
  
  if (map_value >= 2) digitalWrite(d2, HIGH);
  else digitalWrite(d2, LOW);

  if (map_value >= 3) digitalWrite(d3, HIGH);
  else digitalWrite(d3, LOW);

  if (map_value >= 4) digitalWrite(d4, HIGH);
  else digitalWrite(d4, LOW);

  if (digitalRead(button) == 0) {
    while(digitalRead(button) == 0) { continue; } 
    
    input += char(map_value + '0');

    Serial.println(input);

    if (input.length() == pass.length()) {
      if (pass.compareTo(input) == 0) {
        Serial.println("Uspesno uneta sifra!"); 
        input = "";
        delay(500);
        exit(0);
      }
      else {
        Serial.println("Pogresna sifra!");   
      }
      input = "";
    }   
  }
}
