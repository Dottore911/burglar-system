#include <sim800cmd.h>
#include <atparameter.h>
#include <msTimer.h>
#include <doEvent.h>

Sim800Cmd projekt(fundebug);

void setup() {
  pinMode(7,OUTPUT);
  digitalWrite(7,LOW);
  pinMode(8,INPUT);
  

}

void loop() {
  int pin_stat=digitalRead(8);
  if(pin_stat>0){
    digitalWrite(7,HIGH);
    delay(1000);
    digitalWrite(7,LOW);
    while((projekt.sim800init())==0);
    delay(1000);
    projekt.setSMSEnablePrompt(OPEN);
    projekt.sendSMS("002B00340038003600300031003700380030003200370038","0049006E007400720075006400650072002100210021002100200049006E0074007200750064006500720021002100210020004200650065007000200042006500650070002000420065006500700021002100210021");
    
    
  }
  else{
    digitalWrite(7,LOW);
  }

}
void fundebug(){
  
}
  
