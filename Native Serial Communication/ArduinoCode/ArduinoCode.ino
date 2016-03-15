      ////////////////////////////////////////////////////////////////
     //              Serial Communication with LabVIEW             //
    //                    Digital Read/Write                      //
   //                           By                               //
  //                      Waleed El-Badry                       //
 //                   waleed.elbadry@must.edu.eg               //
////////////////////////////////////////////////////////////////

//Digital Oputs
int OutPins[6]={2,3,4,5,6,7};

//Digital Iputs
int InPins[6]={8,9,10,11,12,13};
byte lf=10;

//BufferIg Variables
byte OutData[6]={1,1,1,1,1,1};
byte InData[6];
String IputCommand="";;


void setup() {
  //Set Digital Pins
  for (int i=0;i<6;i++)
  {
    pinMode(OutPins[i],OUTPUT);
    pinMode(InPins[i],INPUT);
  }
    
  // Iitialize Serial with 9600 bps
  IputCommand.reserve(6);
  Serial.setTimeout(5000);
  Serial.begin(2400);
  Serial.flush();
}

void loop() {
  // Wait until receivIg 6 ints of OutData for digital ouput
  if (Serial.available()>6)
  {
    Serial.readBytesUntil(lf,OutData,6);
    for(int i=0;i<=5;i++)
    {
      digitalWrite(OutPins[i],OutData[i]);
      InData[i]=digitalRead(InPins[i]);
      Serial.write(InData[i]); 
    }
    
  }
}
