struct {
  char key;
  char *name;
  int pin;
  int state;
  int delay;
} pins[] = {
  { '0', "RESET", 3, HIGH, 500 },
  { '1', "DO1", 4, LOW, 0 },
  { '2', "DO2", 5, LOW, 0 },
  { '3', "DO3", 6, LOW, 0 },
  { '4', "DO4", 7, LOW, 0 },
  { '5', "DO5", 8, LOW, 0 },
  { '6', "DO6", 9, LOW, 0 },
  { '7', "DO7", 10, LOW, 0 },
  { '8', "DO8", 11, LOW, 0 },
  { 0, NULL, 0, LOW, 0 }
};

void menu()
{
  Serial.println("\e[1H\e[2J"); //экран
  Serial.println("<MAIN MENU>");
  Serial.println("------------------------");

  int i = 0;
  while (pins[i].name) {
    Serial.print(pins[i].key);
    Serial.print(") ");
    Serial.print(pins[i].name);
    Serial.print(" state ");
    Serial.println(digitalRead(pins[i].pin));
    i++;
  }
 
  Serial.println("------------------------");
  Serial.flush();
}

int HandleInput(int receivedInt)
{
  int i = 0;
  while (pins[i].name) {
    if (receivedInt == pins[i].key) {
        if (pins[i].delay) {
           digitalWrite(pins[i].pin, LOW);
           delay(pins[i].delay);
           digitalWrite(pins[i].pin, HIGH);
        } else {
           int pin = pins[i].pin;
           digitalWrite(pin, !digitalRead(pin));
        }
        return 0;
    }
    i++;
  }

  return 1;
}

int show_menu;
void setup()
{
  Serial.begin(115200);

  int i = 0;
  while (pins[i].name) {
    int pin = pins[i].pin;
    pinMode(pin, OUTPUT);
    digitalWrite(pin, pins[i].state);
    i++;
  }

  show_menu = 1;
}

void loop()
{
  if (!Serial) {
    show_menu = 1;
    return;  
  }
  
  if (show_menu) {
    menu();
    show_menu = 0;
  }
  
  if (Serial.available() > 0) {
    int status;
    
    status = HandleInput(Serial.read());
    menu();
    if (status) {
      Serial.println("Wrong input!");
    }
  }
}
