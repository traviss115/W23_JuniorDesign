const int amplitude = 1023; // Set the amplitude of the wave
const int frequency = 10; // Set the frequency of the wave
const int phase = 0; // Set the phase of the wave
const int offset = 0; // Set the DC offset of the wave
const int sampleRate = 5000; // Set the sample rate in Hz

void setup() {
  // Initialize serial communication at 115200 baud rate
  Serial.begin(115200);
}

void loop() {
  // Calculate the value of the wave at the current time
  double t = (double)micros()/1000000;
  double value = offset + amplitude * sin(2 * PI * frequency * t + phase);

  // Send the value to the computer over serial
  Serial.println(value);

  // Wait until it is time to sample again
  double delayTime = 2.0 / sampleRate - (double)(micros() % (int)(1000000.0 / sampleRate)) / 1000000.0;
  delayMicroseconds((int)(delayTime * 1000000));
}
