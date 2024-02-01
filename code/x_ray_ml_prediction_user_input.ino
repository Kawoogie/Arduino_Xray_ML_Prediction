#include "RandomForest.h" // Load the header file with the model

// Constants to process user inputs
const byte numChars = 32;
char receivedChars[numChars];
char tempChars[numChars];        // temporary array for use when parsing

// variables to hold the parsed data
float altwo = 0.0;
float alfour = 0.0;
float tungsten = 0.0;

// Initialize the model
Eloquent::ML::Port::RandomForestRegressor mlmodel;

// variable to hold the function prediction
float prediction = 0.0;


boolean newData = false;

//============

void setup() {
    Serial.begin(115200);
    Serial.println("Prediction input of 3 float values for 2mm Al, 4mm Al, and Tungsten");
    Serial.println("Enter data in this style [0.876, 0.654, 0.54324]  ");
    Serial.println();
}

//============

void loop() {
    recvWithStartEndMarkers();
    if (newData == true) {
        strcpy(tempChars, receivedChars);
            // this temporary copy is necessary to protect the original data
            //   because strtok() used in parseData() replaces the commas with \0
        parseData();
        showParsedData();
        makePrediction();
        showPrediction();
        newData = false;
    }
}


//============ Helper Functions ===============

/*=======================================================================
Functions to help with the Machine Learning Predictions 
and output
  void makePrediction()
  void showPrediction()
*/

void makePrediction(){
  float inputData[3] = {altwo, alfour, tungsten};
  prediction = mlmodel.predict(inputData);
}

//============

void showPrediction(){
    Serial.print("ML Prediction: ");
    Serial.println(prediction);
    Serial.println();
}

/*=======================================================================
Functions for helping with the user input and parsing of data:
  voidrecvWithStartEndMarkers()
  void parseData()
  void showParsedData()

*/

void recvWithStartEndMarkers() {
    static boolean recvInProgress = false;
    static byte ndx = 0;
    char startMarker = '[';
    char endMarker = ']';
    char rc;

    while (Serial.available() > 0 && newData == false) {
        rc = Serial.read();

        if (recvInProgress == true) {
            if (rc != endMarker) {
                receivedChars[ndx] = rc;
                ndx++;
                if (ndx >= numChars) {
                    ndx = numChars - 1;
                }
            }
            else {
                receivedChars[ndx] = '\0'; // terminate the string
                recvInProgress = false;
                ndx = 0;
                newData = true;
            }
        }

        else if (rc == startMarker) {
            recvInProgress = true;
        }
    }
}

//============

void parseData() {      // split the data into its parts

    char * strtokIndx; // this is used by strtok() as an index

    strtokIndx = strtok(tempChars,",");      // get the first part - float for the Al 2 mm
     altwo = atof(strtokIndx); // convert it to a float
 
    strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
    alfour = atof(strtokIndx);     // convert this part to a float

    strtokIndx = strtok(NULL, ",");
    tungsten = atof(strtokIndx);     // convert this part to a float

}

//============

void showParsedData() {
    Serial.println("Input Values:");
    Serial.print("2mm Al: ");
    Serial.println(altwo);
    Serial.print("4mm Al ");
    Serial.println(alfour);
    Serial.print("Tungsten ");
    Serial.println(tungsten);
}