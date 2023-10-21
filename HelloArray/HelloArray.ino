#include <Array.h>

int rawArray[] = {1,2,3,4,5,6,7,8,9,10};
int colmArray[] = {1,2,3,4,5,6,6,8,9,10};


void setup(){
  Serial.begin(9600);
  Serial.println("The contents of the array:");
 for (int i = 0; i<sizeof(rawArray)+1; ++i){
 if (rawArray[i] == colmArray[i]){
    Serial.print ("element ");  Serial.print (i); Serial.println (" matches");
    }
else {
    Serial.print ("element ");  Serial.print (i); Serial.println (" does not match");
    }
}
}

void loop(){/*no loop*/}
