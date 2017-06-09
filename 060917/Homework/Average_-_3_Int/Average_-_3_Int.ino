
void setup() {
  Serial.begin(9600);
}

void loop() {
  //define the numbers to take the avrage from
  int input1 = 10;
  int input2 = 5;
  int input3 = 20;

  // define avrage with three arguments insde ()
  int avg = average(input1, input2, input3);

  // print the avrage
  Serial.println(avg);
  delay(500);
}

// the avrage function replacing its three arguments with integers to calculate
long average(int x, int y, int z) {
  int answer;
  answer = (x + y + z) / 3;
  return answer;
}
