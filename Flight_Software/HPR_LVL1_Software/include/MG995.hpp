#include <Arduino.h>
#include <Wire.h>
#include <Servo.h>
#include <string.h>


class MG995_Servo{

    public:
        Servo myServo;
        bool startup(int WireNum);
        void moveServo(float num);
        void danceTest(float delayer);
        char message[50];


    bool startup(int WireNum){

        if(!Wire.begin(WireNum) || !myServo.attach(WireNum)){
            return false;
        }
        
        else{
            return true;

        }
    }

    void danceTest(float delayer){

        try {
        
            float angles[5] = {-45.0,-22.5,0.0,22.5,45.0};

            for(int i = 0; i<angles.length(); i++){
                myServo.write(angles[i]);
                delay(delayer);
            }

            myServo.write(angles[0]);
            myServo.write(0.0);
            Serial.println("dance test complete");
            }
        
        catch(const exception& e){
            Serial.println("error in dance test");

        }

    }

    void moveServo(float num){

        if(!myServo.write(num)){
            sprintf(message, "Servo failed to move!");
            Serial.println(message);
        }
        else{
            sprintf(message,"Servo Moved = %.4f degrees",num);
            Serial.println(message);
        }

    }

}

