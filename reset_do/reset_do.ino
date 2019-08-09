#define RESET 3
#define DO1 4
#define DO2 5
#define DO3 6
#define DO4 7
#define DO5 8
#define DO6 9
#define DO7 10
#define DO8 11
int receivedInt; //
int DO1State = 0;
int DO1lastState = 1;
int DO2State = 0;
int DO2lastState = 1;
int DO3State = 0;
int DO3lastState = 1;
int DO4State = 0;
int DO4lastState = 1;
int DO5State = 0;
int DO5lastState = 1;
int DO6State = 0;
int DO6lastState = 1;
int DO7State = 0;
int DO7lastState = 1;
int DO8State = 0;
int DO8lastState = 1;

void setup() {
  Serial.begin(115200);
  pinMode(RESET, OUTPUT);
  digitalWrite(RESET, HIGH);
  //  PORTD = B00001000;
  //   DDRD = DDRD | B11111100;
  //   DDRB = B00000000;
  //  pinMode(DO1, OUTPUT);
  //  digitalWrite(DO1, HIGH);
  //  pinMode(DO2, OUTPUT);
  //  digitalWrite(DO2, HIGH);
  //  pinMode(DO3, OUTPUT);
  //  digitalWrite(DO3, HIGH);
  //  pinMode(DO4, OUTPUT);
  //  digitalWrite(DO4, HIGH);
  //  pinMode(DO5, OUTPUT);
  //  digitalWrite(DO5, HIGH);
  //  pinMode(DO6, OUTPUT);
  //  digitalWrite(DO6, HIGH);
  //  pinMode(DO7, OUTPUT);
  //  digitalWrite(DO7, HIGH);
  //
  for (int i = 4; i <= 11; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
  Serial.println("\e[1H\e[2J"); //экран
  menu();
}


void loop() {
  recvInt();       //
  PrintByInput();   //
}

void recvInt() {
  while (Serial.available() == 0) {  } //
  receivedInt = Serial.parseInt();   //

}

void PrintByInput() {
  if (receivedInt != NULL) {       //

    switch (receivedInt) {            //
      case 1:
        Serial.println("\e[1H\e[2J"); //экран
        //Serial.println(bitRead(PORTD, 3)); //Reads bit 3 of register PORTD which contains the current state (high/low) of pin 3.
        Serial.println("OPTION-RESET");
        //Serial.println(receivedInt);
        digitalWrite(RESET, LOW);
        delay(500);
        digitalWrite(RESET, HIGH);
        menu();
        break;
      case 2: //DO1
        Serial.println("\e[1H\e[2J"); //экран
        DO1State = bitRead(PORTD, 4);
        if (DO1State != DO1lastState) {
          if (DO1State == 1) {
            PORTD &= ~_BV(PD4);
          }
          else {
            PORTD |= _BV(PD4);
          }
        }
        // save the current state as the last state, for next time through the loop
        DO1lastState = DO1State;
        menu();
        break;

      case 3: //DO2
        Serial.println("\e[1H\e[2J"); //экран
        DO2State = bitRead(PORTD, 5);
        if (DO2State != DO2lastState) {
          if (DO2State == 1) {
            PORTD &= ~_BV(PD5);
          }
          else {
            PORTD |= _BV(PD5);
          }
        }
        // save the current state as the last state, for next time through the loop
        DO2lastState = DO2State;
        menu();
        break;
      case 4: //DO3
        Serial.println("\e[1H\e[2J"); //экран
        DO3State = bitRead(PORTD, 6);
        if (DO3State != DO3lastState) {
          if (DO3State == 1) {
            PORTD &= ~_BV(PD6);
          }
          else {
            PORTD |= _BV(PD6);
          }
        }
        // save the current state as the last state, for next time through the loop
        DO3lastState = DO3State;
        menu();
        break;

      case 5: //DO4
        Serial.println("\e[1H\e[2J"); //экран
        DO4State = bitRead(PORTD, 7);
        if (DO4State != DO4lastState) {
          if (DO4State == 1) {
            PORTD &= ~_BV(PD7);
          }
          else {
            PORTD |= _BV(PD7);
          }
        }
        // save the current state as the last state, for next time through the loop
        DO4lastState = DO4State;
        menu();
        break;

      case 6: //DO5
        Serial.println("\e[1H\e[2J"); //экран
        DO5State = bitRead(PORTB, 0);
        if (DO5State != DO5lastState) {
          if (DO5State == 1) {
            PORTB &= ~_BV(PB0);
          }
          else {
            PORTB |= _BV(PB0);
          }
        }
        // save the current state as the last state, for next time through the loop
        DO5lastState = DO5State;
        menu();
        break;

      case 7: //DO6
        Serial.println("\e[1H\e[2J"); //экран
        DO6State = bitRead(PORTB, 1);
        if (DO6State != DO6lastState) {
          if (DO6State == 1) {
            PORTB &= ~_BV(PB1);
          }
          else {
            PORTB |= _BV(PB1);
          }
        }
        // save the current state as the last state, for next time through the loop
        DO6lastState = DO6State;
        menu();
        break;

      case 8: //DO7
        Serial.println("\e[1H\e[2J"); //экран
        DO7State = bitRead(PORTB, 2);
        if (DO7State != DO7lastState) {
          if (DO7State == 1) {
            PORTB &= ~_BV(PB2);
          }
          else {
            PORTB |= _BV(PB2);
          }
        }
        // save the current state as the last state, for next time through the loop
        DO7lastState = DO7State;
        menu();
        break;

      case 9: //DO8
        Serial.println("\e[1H\e[2J"); //экран
        DO8State = bitRead(PORTB, 3);
        if (DO8State != DO8lastState) {
          if (DO8State == 1) {
            PORTB &= ~_BV(PB3);
          }
          else {
            PORTB |= _BV(PB3);
          }
        }
        DO8lastState = DO8State;
        menu();
        break;


      default:
        Serial.println("\e[1H\e[2J"); //экран
        break;
        menu();
    }
    receivedInt = NULL;
  }
}
void menu() {
  Serial.println("<MAIN MENU>");
  Serial.println("------------------------");
  Serial.println("1.) D3  -> RESET ");
  //Serial.println(bitRead(PORTD, 3));
  Serial.print("2.) D4  -> INP1 state ");
  Serial.println(bitRead(PORTD, 4));
  Serial.print("3.) D5  -> INP2 state ");
  Serial.println(bitRead(PORTD, 5));
  Serial.print("4.) D6  -> INP3 state ");
  Serial.println(bitRead(PORTD, 6));
  Serial.print("5.) D7  -> INP4 state ");
  Serial.println(bitRead(PORTD, 7));
  Serial.print("6.) D8  -> INP5 state ");
  Serial.println(bitRead(PORTB, 0));
  Serial.print("7.) D9  -> INP6 state ");
  Serial.println(bitRead(PORTB, 1));
  Serial.print("8.) D10 -> INP7 state ");
  Serial.println(bitRead(PORTB, 2));
  Serial.print("9.) D11 -> INP8 state ");
  Serial.println(bitRead(PORTB, 3));
  Serial.println("------------------------");

}
