const int trigPin = 2;                         // Trig 핀 할당
const int echoPin = 4;                         // Echo 핀 할당
 
void setup()
{
    Serial.begin(115200);                      // 시리얼 초기화
    Serial.println("Hello Arduino!!");
 
    pinMode(trigPin, OUTPUT);                  // Trig 핀 output으로 세팅
    pinMode(echoPin, INPUT);                   // Echo 핀 input으로 세팅
}
 
void loop()
{
    double duration, distance;                   // 기본 변수 선언
 
    //Trig 핀으로 10us의 pulse 발생
    digitalWrite(trigPin, LOW);                // Trig 핀 Low
    delayMicroseconds(2);                      // 2us 유지
    digitalWrite(trigPin, HIGH);               // Trig 핀 High
    delayMicroseconds(10);                     // 10us 유지
    digitalWrite(trigPin, LOW);                // Trig 핀 Low
 
    /*Echo 핀으로 들어오는 펄스의 시간 측정    */
    duration = pulseIn(echoPin, HIGH);         // pulseIn함수가 호출되고 펄스가 입력될 때까지의 시간. us단위로 값을 리턴.
 
    /*음파가 반사된 시간을 거리로 환산
      음파의 속도는 340m/s 이므로 1cm를 이동하는데 약 29us.
      따라서, 음파의 이동거리 = 왕복시간 / 1cm 이동 시간 / 2 이다. */
    distance = (duration / 2.9) / 2;           // 밀리미터로 환산
    //distance = duration / 29 / 2;            // 센치미터로 환산
    //distance = duration / 74 / 2;            // 인치로 환산
 
    Serial.print(distance);
    Serial.print("mm");
    Serial.println();
 
    delay(1000);
}

