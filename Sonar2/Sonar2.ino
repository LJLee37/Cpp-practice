void setup()
{
    pinMode(13, OUTPUT);
    pinMode(12, INPUT);
    pinMode(8, OUTPUT);
}
inline void dw(int pin, int sig)
{
    digitalWrite(pin, sig);
}
inline void dm(int micsec)
{
    delayMicroseconds(micsec);
}
void loop()
{
    dw(13, LOW);
    dm(2);
    dw(13, HIGH);
    dm(2);
    dw(13, LOW);
    long dur = pulseIn(12, HIGH);
    if(!dur)
	return;
    long dis = dur / 50.2;
    if(!(dis/10))
    {
	tone(8, 450, 1000);
	delay(1000);
	noTone(8);
    }
    else if (dis < 20)
    {
	tone (8, 330, 1000);
	delay(1000);
	noTone(8);
    }
    else if (dis < 30)
    {
	tone(8, 262, 1000);
	delay(1000);
	noTone(8);
    }
}
