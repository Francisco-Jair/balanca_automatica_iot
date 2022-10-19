#include "HX711.h"

# define ZEROVAL 602498 // valor raw zero
# define  CALIBVAL -522851 // valor raw referente
# define PESOBASE 60 // peco base


//HX711
const int LOADCELL_DOUT_PIN = 3;
const int LOADCELL_SCK_PIN = 2;


long long BUFF[25] = {0};
byte BUFFL = 0;

HX711 scale;

long ReadRAW();
float ConvertVal(long RAWVAL);



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  // scale.set_scale();
  BUFFL = sizeof(BUFF) / sizeof(BUFF[0]);
  // delay(2000);
  // scale.tare();
  // Serial.println("Balanca zerada");
}

void loop() {

  // put your main code here, to run repeatedly:
  long RAW = ReadRAW();
  Serial.print("RAW: ");
  // Serial.print(scale.get_units(), 1);
  Serial.print(RAW);
  Serial.print(" GRAMAS: ");
  Serial.println(ConvertVal(RAW));
  delay(500);
  
}


float ConvertVal(long RAWVAL){
  float unit = (float)PESOBASE / (float)(ZEROVAL - CALIBVAL);

  return (float)(ZEROVAL - RAWVAL) * unit;
}

long ReadRAW(){
  long long ACC = 0;
  for(short z = 0; z < BUFFL; z++){
    while(!scale.is_ready());
    long reading = scale.read();

    for(short i = 0; i < BUFFL - 1; i++){
      BUFF[i] = BUFF[i + 1];
    }
    BUFF[BUFFL - 1] = reading;

  }

  for(short i = 0; i < BUFFL; i++){
    ACC = ACC + BUFF[i];
  }

  return (long)ACC / BUFFL;
}