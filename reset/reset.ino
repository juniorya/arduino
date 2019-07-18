#define RESET 3
#define POWER 4
int receivedInt; //

void setup() {
Serial.begin(115200); //

//Print main menu
Serial.println("<MAIN MENU>");
Serial.println("------------------------");
Serial.println("1.) RESET");
Serial.println("2.) POWER ON");
Serial.println("3.) POWER OFF");
Serial.println("------------------------");
pinMode(RESET, OUTPUT);
digitalWrite(RESET, HIGH);
pinMode(POWER, OUTPUT);
digitalWrite(POWER, HIGH);
}


void loop() {
 recvInt();       //
 PrintByInput();   // 
}

void recvInt() { 
 while(Serial.available() == 0) {  } //
 receivedInt = Serial.parseInt();   // 
  
}

void PrintByInput() {
 if (receivedInt != NULL) {       //

switch (receivedInt) {            //
    case 1:
        Serial.println("\e[1H\e[2J"); //экран
        Serial.println("OPTION-RESET");  
        //Serial.println(receivedInt);  
        digitalWrite(RESET, LOW);
        delay(500);
        digitalWrite(RESET, HIGH);
        menu();   
    break;
    case 2:
        Serial.println("\e[1H\e[2J"); //экран
        Serial.println("OPTION-POWER ON - do not");  
        //Serial.println(receivedInt);
        menu(); 
    break;
    case 3:
        Serial.println("\e[1H\e[2J"); //экран
        Serial.println("OPTION-POWER OFF - do not");  
        //Serial.println(receivedInt); 
        menu();     
    break;    
    default:
        Serial.println("\e[1H\e[2J"); //экран
        Serial.println("!WRONG INPUT!");
        break;
        menu(); 
  } 
 receivedInt = NULL;
 }
}
void menu(){
  Serial.println("<MAIN MENU>");
  Serial.println("------------------------");
  Serial.println("1.) RESET");
  Serial.println("2.) POWER ON");
  Serial.println("3.) POWER OFF");
  Serial.println("------------------------");
}
