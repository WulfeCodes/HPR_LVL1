#include <Arduino.h>
#include <Stream.h>
#include <Wire.h>
#include <string.h>
enum modeType {wakeup, sleep, normal, configure};

//Communicates via UART 
class LoRaModule{

    public:
        bool startup(int M0,int M1,modeType);
        std::string readMessage();
        bool sendMessage(String);
        char buffer[256];
        std::string receivedString;
        size_t bufferSize = sizeof(buffer);
        int Aux;

    std::string receiveMessage(){
        if (digitalRead(this->Aux)!=LOW){
            return NULL;
            Serial.println("Buffer was full, will try next cycle");
        }
        else{
            int i =0;
            memset(this->buffer, 0, this->bufferSize);
            //BEWARE, A WHILE LOOP
            //Clear buffer before reading msg
            while(Serial.available()){
                this->buffer[i]=Serial.read();
                i+=1;
            }
            this->receivedString = this->buffer;
            Serial.println(this->buffer);

            return this->receivedString;
        }

    }

    bool sendMessage(char msg[]){
        if (digitalRead(this->Aux)!=LOW){
            return false;
            Serial.println("Buffer was full, will try next cycle");
        }

        else{
            Serial.write(msg);
        }
    }
    
    bool startup(int Aux ,int M0,int M1,modeType& modeChosen){

        if(!Wire.begin(M0) || !Wire.begin(M1)|| !Wire.begin(Aux)){
            return false;
        }

        try{
            pinMode(M0,OUTPUT);
            pinMode(M1,OUTPUT);
            pinMode(Aux,INPUT);
            this->Aux=Aux;
            if(modeChosen==wakeup){
                //Setting that you can set sleep and wake oscillations by some rate
                digitalWrite(M0,HIGH);
                digitalWrite(M1,LOW);           
                
            }
            else if(modeChosen==sleep){
                digitalWrite(M0,HIGH);
                digitalWrite(M1,HIGH);
                //Low-power sleep state where the module consumes minimal power. It typically cannot transmit or receive in this mode and ignores UART input until woken up by changing the M0/M1 pins.

            }

            else if(modeChosen==normal){
                digitalWrite(M0,LOW);
                digitalWrite(M1,LOW);
            }

            else{
                //Configuration code, allows access to internal registers to control parameters of radio
                //In competition this may need to be actually set, but automatic is fine for now
                // digitalWrite(M0,LOW);
                // digitalWrite(M1,HIGH);

                //model Factory default parameter value: C0 00 00 62 00 12
                //Module model, frequency, address, channel, air speed, baud rate, Serial format, pwr
                //E22-900T33S, 868.125MHz, 0x0000, 0x12, 2.4kbps, 9600, 8N1, 33dbm
            }
            
            return true;
        } 

        catch(...){
            return false;
        }


    }
};