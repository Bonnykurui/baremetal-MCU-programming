
/*
Bare-metal example
Toggling led using C
red led is connected to ptc9
uses header file from MCUxpresso which is compliant with CMSIS,each PORT
is defied as pointer to struct with the registers as members of struct
*/


#include "MK66F18.h"
//delay function
delay_ms(int n){
  int j;
  int i;
  for (i = 0; i < n; i++) {
    for (j = 0; j < 7000; j++) {}
  }
}
int main(void) {
  //enable clock to port C
  SIM->SCGC5|=0x800;
  //make PTC9 pin as GPIO
  PORTC->PCR[9]=0x100;
  //make ptc 9 as output pin
  PTC->PDDR|=0x200;
  while (1) {
    //turn on red led on PTC 9
    PTC->PDOR &=~0x200;
    delay_ms(100);//delay
    //turn off red led on PTC 9
    PTC->PDOR |=0x200;
    delay_ms(100);//delay
  }

}
