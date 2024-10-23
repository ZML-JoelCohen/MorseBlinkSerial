/*
  Title: Blink Morse Serial
  Organization: Zen Maker Lab Inc.
  Author: joel Cohen

  Description:

  This project walks you through how to create a program that takes serial input on the arduino and
  displays messages comprised of english characters through morse code on an LED.

  Concepts taught:

    - Variables
    - Functions
    - For-loops
    - Conditionals
    - Arrays
    - Integrated Circuits

*/

#define SHORT_DELAY 500
#define LONG_DELAY 1000

const char *morseCode[] = {
    ".-",    // A
    "-...",  // B
    "-.-.",  // C
    "-..",   // D
    ".",     // E
    "..-.",  // F
    "--.",   // G
    "....",  // H
    "..",    // I
    ".---",  // J
    "-.-",   // K
    ".-..",  // L
    "--",    // M
    "-.",    // N
    "---",   // O
    ".--.",  // P
    "--.-",  // Q
    ".-.",   // R
    "...",   // S
    "-",     // T
    "..-",   // U
    "...-",  // V
    ".--",   // W
    "-..-",  // X
    "-.--",  // Y
    "--.."   // Z
};

void shortBlink( ) {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(SHORT_DELAY);
  digitalWrite(LED_BUILTIN, LOW); 
  delay(SHORT_DELAY);
}
void longBlink() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(LONG_DELAY);
  digitalWrite(LED_BUILTIN, LOW); 
  delay(SHORT_DELAY);
}

int parseLetter(char letter) {
  int index = letter - 'a';
  int running_time = 0;

  String morse_sequence = morseCode[index];

  for (int i = 0; i < morse_sequence.length(); i++) {
    char morse_character = morse_sequence[i];

    if (morse_character == '.') {
      shortBlink();
      running_time = running_time + SHORT_DELAY;
    } else if (morse_character == '-') {
      longBlink();
      running_time = running_time + LONG_DELAY;
    }

    running_time = running_time + SHORT_DELAY;
  }

  return running_time;

}

int allLowerCase(String sentence) {
  
}



int parseString(String sentence, int shortDelay = SHORT_DELAY, int longDelay = LONG_DELAY) {
  int time_elapsed = 0;
  
  for (int character_i = 0; character_i < sentence.length(); character_i++) {
    char letter = sentence[character_i];

    if (letter == ' ') {
      delay(LONG_DELAY);
      time_elapsed = time_elapsed + LONG_DELAY;
      continue;
    }
    
    time_elapsed = time_elapsed + parseLetter(letter);
  }

  return time_elapsed;
}

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  parseString("Hello World");
}
