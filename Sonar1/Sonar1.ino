void setup()
{
    pinMode(9, OUTPUT);
    pinMode(10,OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, INPUT);
    pinMode(13, OUTPUT);
}
void loop()
{
    digitalWrite(13, HIGH);
    delayMicroseconds(10);
    digitalWrite(13, LOW);

    long dur = pulseIn(12, HIGH);
    long dis = dur / 29 / 2;
    if(dis < 10) 
    {
    analogWrite(11,255);
    analogWrite(10, 0);
    analogWrite(9, 0);
    }
    else if(dis < 20) 
    {
	analogWrite(11,0);
        analogWrite(10,255);
	analogWrite(9,0);
    }
    else if(dis < 30) 
    {
	analogWrite(11,0);
	analogWrite(10, 0);
	analogWrite(9,255);
    }
}
