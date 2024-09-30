void(*SpeedMotor)(int);
void(*SwingMotor)(int);

int SpeedMotor(int motor_speed)
{
	static int motorSpeed = motor_speed;
	return motorSpeed;
}

bool SwingMotor(bool motor_swing)
{
	static bool motorSwing = motor_swing;
	return motorSwing;
}

void fan_init() {
	
}