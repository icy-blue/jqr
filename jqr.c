// 18.7.11
// by Team of Brozne Age

/*---------- for dev ----------*/
// void motor(int x, int y) {}
// void servo(int x, int y) {}
// int seconds(int x) { return 0; }
// void cls() {}
// void locate(int x, int y) {}
// int getadc(int x) { return 0; }
// int geteadc(int x) { return 0; }
// void wait(float x) {}
// int getport(int x) { return 0; }
// int selector() { return 0; }
// void sound(int x, int y) {}
// #include <stdio.h>

/*---------- const datas ----------*/
int frontBaceValue[] = { -1, 438, 622, 492, 458 };
int backBaceValue[] = { -1, 683, 657, 562, 467 };
int leftBaceValue = 468;
int rightBaceValue = 633;
int colorA_baceValue[] = { -1, 643, 552, 428, 278, 396 };
int colorB_baceValue[] = { -1, 645, 513, 256, 196, 532 };

int colorToPosition[] = { -1, 11, 12, 8, 9, 10 };
int reDirection[] = { 4, 5, 6, 7, 0, 1, 2, 3 };
int tmpObjectTo[] = { -1, 7, 5 };

int baceTurnplateAngle = 65;
int turnplateAngle[3][6] = { { -1, -1, -1, -1, -1, -1 },
							 { -1, -10, 10, 15, 0, -15 },
							 { -1, 10, -10, -15, 0, 15 } };
int turnplateBackAngle[3][6] = { { -1, -1, -1, -1, -1, -1 },
								 { -1, 5, 0, 0, 5, 5 },
							     { -1, 0, 5, 5, 5, 0 } };
float baceTask2ApproachTime = 1.45;
float task2ApproachTime[6] = { -1, 0, 0, 0.7, 0.9, 0.7 };

int toneTime = 333;
int beep[] = { -1, 523, 587, 659, 698, 784, 880, 988, 1047, 1175, 1319, 1397, 1568, 1760, 1967, 262, 294, 330, 349, 392, 440, 494 };
// musics
int m_nullMusic[] = { 0 };
float t_nullMusic[] = { -1 };
int m_xiaoxingxing[] = { 14, -1, -1, -5, -5, -6, -6, -5, -4, -4, -3, -3, -2, -2, -1 };
float t_xiaoxingxing[] = { -1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2 };
int m_liangzhilaohu[] = { 14, -1, -2, -3, -1, -1, -2, -3, -1, -3, -4, -5, -3, -4, -5 };
float t_liangzhilaohu[] = { -1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2 };
int m_rongyao[] = { 18, 15, -5, -2, -2, -2, -1, -1, -2, 15, -2, -3, -2, -2, -1, -2, -3, -5, -3 };
float t_rongyao[] = { -1, 1, 1, 1, 1, 0.5, 0.5, 0.5, 2, 1, 0.5, 0.5, 1, 0.5, 0.5, 0.5, 0.5, 0.5, 2 };
int m_summer[] = { 16, 15, -1, -2, -3, -2, -1, -1, 15, -1, -2, -3, -2, -1, -2, -3, -3 };
float t_summer[] = { -1, 0.5, 0.5, 0.5, 0.5, 1, 0.5, 3, 0.5, 0.5, 0.5, 0.5, 1, 0.5, 1, 1, 2 };
int m_sky[] = { 13, 16, 17, -1, 17, -1, -3, 17, 13, 16, 15, 16, -1, 15/*, -3, -4, -3, -4, 1, -3, 1, 1, 1, -7, -4, -4, -7, -7*/ };
float t_sky[] = { -1, 0.5, 0.5, 1.5, 0.5, 1, 1, 3, 1, 1.5, 0.5, 1, 1, 3/*, 1, 1.5, 0.5, 1, 1, 3, 0.33, 0.33, 0.33, 1.5, 0.5, 1, 1, 3*/ };
int m_humor[] = { 25, -1, -2, -1, -2, -3, -5, -6, -5, 1, -7, 2, 1, -7, 2, 1, -6, -5, -5, -6, -5, 1, -6, -5, -3, -2 };
float t_humor[] = { -1, 1, 0.5, 1, 0.5, 1, 0.5, 1, 0.5, 1, 0.5, 1, 0.5, 1, 0.5, 1, 0.5, 1, 0.5, 1, 0.5, 1, 0.5, 1, 0.5, 3 };
int m_me[] = { 14, -1, -2, -3, -1, -5, -3, -2, -5, -2, -1, 16, -3, -1, 17/*, -7, -6, -7, 1, 2, -5, 1, 2, 3, 4, 4, 3, 2, 1, 2*/ };
float t_me[] = { -1, 0.5, 0.5, 0.5, 0.5, 1.5, 0.5, 1, 1, 1, 0.5, 0.5, 1.5, 0.5, 2/*, 1, 1, 1, 0.5, 0.5, 1, 1, 0.5, 0.5, 1, 0.5, 0.5, 0.5, 0.5, 2*/ };
int m_pingfan[] = { 14, 16, 17, -1, -2, -1, -2, -3, -5, -6, -5, -4, -3, -3, -2 };
float t_pingfan[] = { -1, 1, 1, 1, 1, 0.5, 1.5, 1, 0.5, 1, 1.5, 1, 1.5, 1.5, 3 };

#define PLATFORM_DOWN (!getport(9))
#define PLATFORM_MID getport(8)
#define PLATFORM_UP getport(7)

#define POS_CENTER 16
#define POS_HOME 14

// cm/s
// FS : 33
// MS : 18.5
// SS : 4
#define FAST_SPEED 800
#define MID_SPEED 400
#define SLOW_SPEED 150
#define PLATFORM_SPEED 400

#define CLAW_SERVO 4
#define HOOK_SERVO 3
#define TURNPLATE_SERVO 2
#define PLATFORM_MOTOR 3
#define LEFT_MOTOR 4
#define RIGHT_MOTOR 2

#define CATCH_ANGLE 67 // 1
#define LOOSE_ANGLE 62 // 4
#define RELEASE_ANGLE 50 // 2
#define WIDE_ANGLE 40 // 3

#define OBJECT_NEAR_SENSOR_VALUE 450

int cntW, cntB, crossingLine; float timeLock;

/*---------- robot datas ----------*/
int position_;
int direction_;

int calwState; // 1catch 2release 3wide
int platformState; // 3up 2mid 1down -1unknown

int objectColor;

int transforming_;
int tmpTransforming;

int accomplishedObjectNum[10] = { 0 };
int cannotTransfer[20] = { 0 };
int tmpObjectCnt;

int playingMusic;
int* m_tape; float* t_tape;

int statedSpeed;
int actualSpeed;
float leftSpeedRate;
float rightSpeedRate;
int accCnt;
int usingACC;

/*---------- functions ----------*/
void runTask1();
void transferForTask1(int pos);
void runTask2();
void transferForTask2(int pos);

void moveTo(int destination);
int catchObject();
void releaseObject();
void platformMove(char* op);
int catchObjectByHook(int id, int op);

int onLine(char* op);
int onLineDebounce(char* op);

int colorDiscrimination();
int guessColor();

void moveToCenter();
void turnToOnCenter(int targetDirection);
void moveFromCenterTo(int destination);
void moveWithCountingLine(int lineNum, int op, int speed);
void moveWithTime(float timeLimit, int op, int speed);
void turnWithCountingLine(int lineNum, int op);
void moveApproach();

void trackLine(int op);
int countLine(char* sid);
void setSpeed(int speed);
void setTurn(float lsr, float rsr);
void _go_(int speed);
void changeSpeed();
void _motor_();

int getDirectionByPos(int pos);
int getLineNumToCenter(int pos);
int getLineNumWhenTurnTo(int tarDir);
int reverseDirection(int dir);
int getPosByColor(int color);
void checkDirection(int dir);
void checkPosition(int pos);

void init();
void correctSensors();
void throwError(char* where, char* errLog);

void prepareForReleaseObject();
void _servo_(float t, int from, int to, int sid);
void clawTo(int angle);

int equal(int a,int b,int x);
int abs(int x);

void playMusic();
void struckUpWithObjCol();

void main_1(void* p);
void main_2(void* p);
void main_3(void* p);


int main(void) 
{
	int op = selector();
	init(); // sound(1000, 500);
	if (op == 0) {
		correctSensors();
	}
	else if (op == 1) {
		moveWithTime(5, 1, FAST_SPEED);
		wait(1);
		moveWithTime(5, -1, FAST_SPEED);
		wait(1);
	}
	else if (op == 2) {
		while (1) {
			int i; for (i = 0; i <= 16; i++) {
				moveTo(i);
			}
		}
	}
	else if (op == 3) {
		runTask1();
	}
	else if (op == 4) {
		runTask2();
	}
	else if (op == 5) {
		runTask1();
		runTask2();
		moveTo(POS_HOME);
	}
	else if (op == 6) {
		startmain (1, 1);
		runTask1();
		runTask2();
		moveTo(POS_HOME);
	}
	else if (op == 7) {
		usingACC = 0;
		runTask1();
		runTask2();
		moveTo(POS_HOME);
	}
	else if (op == 8) {
        while(1) {
            cls();
            locate(2, 5);
            printf("%d", onLine("f2"));
            locate(3, 5);
            printf("%d", onLine("f3"));
            wait(0.1);
        }
	}
	else if (op == 9) {
		clawTo(WIDE_ANGLE);
		wait(1);
		clawTo(RELEASE_ANGLE);
		wait(1);
		clawTo(LOOSE_ANGLE);
		wait(1);
		clawTo(CATCH_ANGLE);
		sound(1000, 1000);
		wait(1);
	}
	else if (op == 10) {
		platformMove("mid");
		wait(1);
		platformMove("up");
		wait(1);
		platformMove("mid");
		wait(1);
		platformMove("down");
		wait(1);
		platformMove("up");
		wait(1);
		platformMove("down");
		wait(1);
	}
	// sound(1000, 500);
}

// init robot datas
void init() {
	position_ = POS_HOME;
	direction_ = getDirectionByPos(POS_HOME);

	clawTo(RELEASE_ANGLE);
	platformMove("down");
	servo(HOOK_SERVO, 120);
	servo(TURNPLATE_SERVO, baceTurnplateAngle);

	objectColor = 0;  transforming_ = 0; tmpTransforming = 0;
	int i; for(i = 1; i <= 5; i++) accomplishedObjectNum[i] = 0;

	tmpObjectCnt = 0;
	for (i = 0; i <= 16; i++) cannotTransfer[i] = 0;

	playingMusic = 0;
	m_tape = m_nullMusic;
	t_tape = t_nullMusic;

	usingACC = 1; // default 
	accCnt = 0; _go_(0);
    startmain (2, 1);
}

void correctSensors() {
	cls();
	while (1) {
		colorDiscrimination();
		locate(1,1); printf("f1:%3d f2:%3d", geteadc(1), geteadc(2));        
		locate(2,1); printf("f3:%3d f4:%3d", geteadc(3), geteadc(4));    
		locate(3,1); printf("b1:%3d b2:%3d", geteadc(5), geteadc(6));      
		locate(4,1); printf("b3:%3d b4:%3d", geteadc(7), geteadc(8));  
		locate(5,1); printf("l:%3d r:%3d dis:%3d", getadc(1), getadc(2), getadc(5));  
		locate(6,1); printf("cA:%3d cB:%3d", getadc(3), getadc(4));  
		locate(7,1); printf("color:%d", objectColor);
		locate(8,1); printf("u:%d m:%d d:%d", PLATFORM_UP, PLATFORM_MID, PLATFORM_DOWN);            
		wait(0.1);
	}
}

void transferForTask1(int pos) {
	moveTo(pos);
	int color = catchObject();
	if (color == 0) {
		moveTo(6);
        return;
	}
	int destination = getPosByColor(color);
	cannotTransfer[pos + 8] = 0;
	if(cannotTransfer[destination]) {
		tmpTransforming = 1;
		destination = tmpObjectTo[++ tmpObjectCnt];
	}
	moveTo(destination);
	releaseObject();

	if (destination == getPosByColor(color)) {
		accomplishedObjectNum[color] ++;
	}
	else {
		tmpTransforming = 0;
	}

	moveWithTime(0.5, -1, SLOW_SPEED);
	moveWithTime(0.5, -1, MID_SPEED);
	platformMove("down");
}

void runTask1() {
	cannotTransfer[8] = cannotTransfer[10] = cannotTransfer[12] = 1;
	transferForTask1(0);
	transferForTask1(4);
    transferForTask1(2);
	int i; for(i = 1; i <= tmpObjectCnt; i++) {
		transferForTask1(tmpObjectTo[i]);
	}
}

void transferForTask2(int pos) {
	int tmp[] = { -1, 1, 2, 3, 5, 4 };
	int i; for(i = 1; i <= 5; i++){
		moveTo(pos);
        int color = 0;
        if (tmp[i] == 4) {
            platformMove("down"); clawTo(WIDE_ANGLE);
            moveWithTime(1.5, 1, MID_SPEED);
            color = catchObject();
            moveWithTime(1.5, -1, MID_SPEED);
        }
        else {
            color = catchObjectByHook(tmp[i], pos==15 ? 1 : 2);
        }
		if (color == 0) {
			moveTo(6);
            continue;
		}
		int destination = getPosByColor(color);
		moveTo(destination);
		releaseObject();
		accomplishedObjectNum[color] ++;
		moveWithTime(0.5, -1, SLOW_SPEED);
		moveWithTime(0.5, -1, MID_SPEED);
		platformMove("down");
	}
}

void runTask2() {
	transferForTask2(15);
	transferForTask2(13);
}

// function : check whether a ground sensor is on line
// examples: onLine("f1"); onLine("b3"); onLine("l"); onLine("r");
int onLine(char* op) {
	// front : f1~4 -> eacd1~4
	if (op[0] == 'f') {
		int x = op[1] - '0';
		if (x >= 1 && x <= 4) {
			return geteadc(x) >= frontBaceValue[x];
		}
	}
	// back : b1~4 -> eacd5~8
	if (op[0] == 'b') {
		int x = op[1] - '0';
		if (x >= 1 && x <= 4) {
			return geteadc(x + 4) >= backBaceValue[x];
		}
	}
	// left : l -> acd1
	if (op[0] == 'l') {
		return getadc(1) >= leftBaceValue;
	}
	// right : r -> acd2
	if (op[0] == 'r') {
		return getadc(2) >= rightBaceValue;
	}

	// else all
	throwError("onLine", "unknown sensor type");
	return 0;
}

int onLineDebounce(char* op) {
	int x, val, delta = 50;
	if (op[0] == 'f') {
		x = op[1] - '0';
		if (x >= 1 && x <= 4) {
			val = geteadc(x);
			if (val >= frontBaceValue[x] + delta) return 1;
			else if (val <= frontBaceValue[x] - delta) return 0;
			else return -1;
		}
	}
	if (op[0] == 'b') {
		x = op[1] - '0';
		if (x >= 1 && x <= 4) {
			val = geteadc(x + 4);
			if (val >= backBaceValue[x] + delta) return 1;
			else if (val <= backBaceValue[x] - delta) return 0;
			else return -1;
		}
	}
	if (op[0] == 'l') {
		val = getadc(1);
		if (val >= leftBaceValue + delta) return 1;
		else if (val <= leftBaceValue - delta) return 0;
		else return -1;
	}
	if (op[0] == 'r') {
		val = getadc(2);
		if (val >= rightBaceValue + delta) return 1;
		else if (val <= rightBaceValue - delta) return 0;
		else return -1;
	}

	throwError("onLine", "unknown sensor type");
	return -1;
}

// function : move robot from it's positon to destination
void moveTo(int destination) {
	if (position_ == destination) {
		return;
	}
	if (destination == POS_CENTER) {
		moveToCenter();
	}
	else if (position_ != POS_CENTER && getDirectionByPos(position_) == getDirectionByPos(destination) && position_ < destination) {
		moveWithCountingLine(1, 1, MID_SPEED);
		moveApproach();
		position_ = destination;
	}
	else {
		// first, move to center
		moveToCenter();
		// then, turn to destination's direction
		turnToOnCenter(getDirectionByPos(destination));
		// finally, move to destination from center
		moveFromCenterTo(destination);
	}
}

// function : move robot to center
// only useable when robot is back to center
void moveToCenter() {
	if (position_ == POS_CENTER) {
		return;
	}
	if (direction_ == getDirectionByPos(position_)) {
		moveWithCountingLine(getLineNumToCenter(position_) - 1, -1, FAST_SPEED);
		moveWithCountingLine(1, -1, MID_SPEED);
		_go_(0); // stop immediately
	}
	else {
		throwError("moveToCenter", "not back to center");
	}
	position_ = POS_CENTER;
}

// function : turn the robot to targetDirection
// only be used when robot on center
void turnToOnCenter(int targetDirection) {
	if (position_ != POS_CENTER) {
		throwError("turnToOnCenter", "not at center");
	}
	if (direction_ == targetDirection) {
		return;
	}
	int lineNum = getLineNumWhenTurnTo(targetDirection);
	if (lineNum > 0) {
		// turn right
		turnWithCountingLine(lineNum, 1);
	} 
	else if (lineNum < 0) {
		// turn left
		turnWithCountingLine(-lineNum, -1);
	}
	direction_ = targetDirection;
}

// function : move robot from center to destination
// only be used when robot on center
void moveFromCenterTo(destination) {
	if (position_ != POS_CENTER) {
		throwError("moveFromCenterTo", "not at center");
	}
	if (direction_ != getDirectionByPos(destination)) {
		throwError("moveFromCenterTo", "not face to destination");
	}
	// -2 correction
	moveWithTime(0.6, 1, FAST_SPEED);
	moveWithCountingLine(getLineNumToCenter(destination) - 2, 1, FAST_SPEED);
	moveApproach();
	position_ = destination;
} 

// function : line track with counting line
// op > 0, move front; op < 0, move back 
// we only use left sensor when counting line
void moveWithCountingLine(int lineNum, int op, int speed) {	
	if (!lineNum) return;

    setSpeed(speed * op);
	countLine("init");
	while (lineNum) {
		trackLine(op);
		if (countLine("l")) {
			lineNum --;
		}
	}
	setSpeed(0);
}

// function : line track whih time limit
// op > 0, move front; op < 0, move back 
void moveWithTime(float timeLimit, int op, int speed) {
    setSpeed(speed * op);
	float startTime = seconds(1);
	while (seconds(1) - startTime < timeLimit) {
		trackLine(op);
	}
    setSpeed(0);
}

// function : rotate whih counting line
// op > 0, turn right; op < 0, turn left 
void turnWithCountingLine(int lineNum, int op) {
	if (!lineNum) return;
	
    setSpeed(MID_SPEED);
	char* sid;
	if (op > 0) {
		sid = "f4";
        setTurn(1, -1);
	}
	else {
		sid = "f1";
        setTurn(-1, 1);
	}
	countLine("init");
	while (lineNum) {
		if (countLine(sid)) {
			lineNum --;
		}
	}
	// correct
	wait(0.1);
	setSpeed(0);
}

// function : track line
void trackLine(int op) {
	int s1, s2, s3, s4;
	float lsr, rsr;

	if (op > 0) {
		s1 = onLine("f1");
		s2 = onLine("f2");
		s3 = onLine("f3");
		s4 = onLine("f4");
	}
	else {
		s1 = onLine("b1");
		s2 = onLine("b2");
		s3 = onLine("b3");
		s4 = onLine("b4");
	}

	if ((s2 && s3) || (s1 && s4)) { lsr = 1; rsr = 1; }
	else if (s2 && !s3) { lsr = 0.5; rsr = 1; }
	else if (!s2 && s3) { lsr = 1; rsr = 0.5; }
	else if (s1) { lsr = 0; rsr = 1; }
	else if (s4) { lsr = 1; rsr = 0; }
	else { lsr = 1; rsr = 1; }

	if (op > 0) {
		setTurn(lsr, rsr);
	}
	else {
		setTurn(rsr, lsr);
	}
}

// function : approtch target
void moveApproach() {
	int s1, s2, s3, s4;
	int cnt = 0;
	int speed = MID_SPEED;

	if (transforming_) {
		if (!tmpTransforming) {
			moveWithTime(0.6, 1, MID_SPEED);
			speed = SLOW_SPEED;
		}
		prepareForReleaseObject();
	}
	else {
		clawTo(WIDE_ANGLE);
	}

    setSpeed(speed);
	while (1) {
		s1 = onLineDebounce("f1");
		s2 = onLine("f2");
		s3 = onLine("f3");
		s4 = onLineDebounce("f4");

        if (s1 == 1 && s4 == 1) {
			setSpeed(0);
			if (cnt < 100) cnt ++;
		}
		else {
			cnt = 0;
            if (s1 == 1) { setTurn(0, 1); }
			else if (s4 == 1) { setTurn(1, 0); } 
			else if (s2) { setTurn(0.8, 1); }
            else { setTurn(1, 0.8); }
		}

		if (cnt >= 5) break;
	}
}

// function : line count
// sid : id of line count sensor
// before use, countLine("init") first
int countLine(char* sid) {
	if (sid[0] == 'i') {
		cntW = 0; cntB = 0; crossingLine = 0; timeLock = 0.0;
		return 0;
	}

	float t = seconds(1);
	if (t < timeLock) { return 0; }
	timeLock = t + 0.001;

	int flag = onLineDebounce(sid);
	if (flag == 1) { if (cntB < 100) cntB ++; } 
	else { cntB = 0; }
	if (flag == 0) { if (cntW < 100) cntW ++; }
	else { cntW = 0; }

	if (cntB >= 10 && !crossingLine) {
		crossingLine = 1;
	} 
	else if (cntW >= 10 && crossingLine) {
		crossingLine = 0;
		return 1;
	}
	return 0;
}

void setSpeed(int speed) {
    statedSpeed = speed;
    if (speed == 0) {
        setTurn(1, 1);
    }
	changeSpeed();
}

void setTurn(float lsr, float rsr) {
    leftSpeedRate = lsr;
    rightSpeedRate = rsr;
	_motor_();
}

void _go_(int speed) {
    statedSpeed = actualSpeed = speed;
    leftSpeedRate = rightSpeedRate = 1;
	_motor_();
}

void _motor_() {
	motor(LEFT_MOTOR, -actualSpeed * leftSpeedRate);
    motor(RIGHT_MOTOR, actualSpeed * rightSpeedRate);
}

// function : print error log and stop progrem
void throwError(char* where, char* errLog) {
	cls();
	locate(1,1); printf("ERROR");
	locate(2,1); printf("at %s", where);
	locate(3,1); printf("%s", errLog);
    _go_(0);
    sound(1000, 1000);
	while (1) { ; }
} 

void clawTo(int angle) {
	servo(CLAW_SERVO, angle);
	switch (angle) {
		case CATCH_ANGLE : calwState = 1; break;
		case RELEASE_ANGLE : calwState = 2; break;
		case WIDE_ANGLE : calwState = 3; break;
		case LOOSE_ANGLE : calwState = 4; break;
		default : calwState = 0;
	}
}

// function : catch object
// you should make sure object is close enough to be caught
int catchObject() {
	clawTo(RELEASE_ANGLE);
	platformMove("down");
	clawTo(CATCH_ANGLE);
	wait(0.5);
  	colorDiscrimination();
	clawTo(LOOSE_ANGLE);

	if (objectColor != 0) { 
		transforming_ = 1;
		struckUpWithObjCol();
	}
	return objectColor;
}

// function : release object
void releaseObject() {
	transforming_ = 0;
	objectColor = 0;
	playingMusic = 0;
	m_tape = m_nullMusic;
	t_tape = t_nullMusic;

	// low down platform to place the object
	if (platformState == 2  || platformState == 3) {
		motor(PLATFORM_MOTOR, 100);
		if (platformState == 2) wait(0.5);
		if (platformState == 3) wait(0.7);
		motor(PLATFORM_MOTOR, 0);
		platformState = -1;
	}
	/* ********************************* */
	_servo_(0.5, CATCH_ANGLE, CATCH_ANGLE - 10, CLAW_SERVO);
	clawTo(RELEASE_ANGLE);
	wait(0.5);
}

void prepareForReleaseObject() {
	if (transforming_ && objectColor >= 1 && objectColor <= 5) {
		clawTo(CATCH_ANGLE);
		switch (accomplishedObjectNum[objectColor]) {
			case 0 : platformMove("down"); break;
			case 1 : platformMove("mid"); break;
			case 2 : platformMove("up"); break;
			// default: throwError("prepareForReleaseObject", "accomplishedObjectNum");
			default : platformMove("down");
		}
	}
}

// function : discrimination object color
int colorDiscrimination() {
	objectColor = 0; int i, j = 0, cA, cB;
	while (objectColor == 0 && j++ < 10) {
		cA = getadc(3); cB = getadc(4);
		for (i = 1; i <= 5; i++) {
			if (equal(cA, colorA_baceValue[i], 50) 
			 && equal(cB, colorB_baceValue[i], 50)) 
			{ objectColor = i; break; }
		}
        if (objectColor == 0) wait(0.1);
	} 
	// for(i = 1; i <= objectColor; i++) { sound(1000, 100); wait(0.1); }
	return objectColor;
}

int equal(int a,int b,int x) {
	return (a>b) ? (a-b<=x) : (b-a<=x);
}

int guessColor() {
	sound(1000, 500);
	int mini = 100000, tp, i;
	int cA = getadc(3), cB = getadc(4);
	for (i = 1; i <= 5; i++) {
		tp = (cA - colorA_baceValue[i]) * (cA - colorA_baceValue[i])
		   + (cB - colorB_baceValue[i]) * (cB - colorB_baceValue[i]);
		if (tp < mini) {
			mini = tp; objectColor = i;
		}
	}
	transforming_ = 1;
	return objectColor;
}

// function : platform rise or fall
// op : "up" "mid" "down"
void platformMove(char* op) {
	if (calwState == 3) {
		clawTo(RELEASE_ANGLE);
	}
	
	if (op[0] == 'u') {
		motor(PLATFORM_MOTOR, -PLATFORM_SPEED); 
		while (!PLATFORM_UP) { ; }
		motor(PLATFORM_MOTOR, 0);
		platformState = 3;
	}
	else if (op[0] == 'd') {
		float t = seconds(1);
		motor(PLATFORM_MOTOR, PLATFORM_SPEED); 
		while (!PLATFORM_DOWN) { 
			if (seconds(1) - t > 1.5) {
				platformMove("up");
				moveWithTime(0.5, -1, MID_SPEED);
				motor(PLATFORM_MOTOR, PLATFORM_SPEED);
				t = 100000;
			}
		}
		motor(PLATFORM_MOTOR, 0);
		platformState = 1;
	}
	else if (op[0] == 'm') {
		if (platformState == -1) {
			platformMove("down");
		}
		if (platformState == 2) { 
			if (PLATFORM_MID) return;
			else platformMove("down");
		}
		if (platformState == 3) {
			motor(PLATFORM_MOTOR, PLATFORM_SPEED);
		}
		else if (platformState == 1) {
			motor(PLATFORM_MOTOR, -PLATFORM_SPEED);
		}
		while (!PLATFORM_MID) { ; }
		motor(PLATFORM_MOTOR, 0);
		platformState = 2;
	}
	else {
		throwError("platformMove", "unknown order");
	}
}

// function : in task2, catch object by hook
// id : 1a 2b 3c 4d 5e
// op : 1F 2G
int catchObjectByHook(int id, int op) {
	platformMove("down"); clawTo(WIDE_ANGLE); // init claw and platform
	servo(HOOK_SERVO, 120); servo(TURNPLATE_SERVO, baceTurnplateAngle + turnplateAngle[op][id]); // init hook and turnplant
	moveWithTime(baceTask2ApproachTime, 1, SLOW_SPEED);
    _go_(SLOW_SPEED); wait(task2ApproachTime[id]); _go_(0);
	_servo_(1, 75, 50, HOOK_SERVO);
    // _servo_(2.5, 75, 40, HOOK_SERVO);
	setSpeed(-SLOW_SPEED); wait(0.5); // moveback
    setSpeed(-MID_SPEED); wait(0.3);
	setSpeed(-SLOW_SPEED); // switch to slow speed
	_servo_(0.7, 50, 40, HOOK_SERVO);
	servo(TURNPLATE_SERVO, baceTurnplateAngle + turnplateBackAngle[op][id]); // turnplant move back
	_servo_(0.7, 40, 60, HOOK_SERVO);
	_servo_(0.5, 60, 120, HOOK_SERVO);
	setSpeed(MID_SPEED); wait(0.5); // approach
	setSpeed(0); wait(0.1); // stop
	return catchObject(); // catch
}

void _servo_(float t, int from, int to, int sid) {
	int i, di = from > to ? -1 : 1;
	float dt = t / (float)(from>to ? from-to : to-from);
	for (i = from; i != to; i += di) {
		servo(sid, i);
		wait(dt);
	}
}

int getDirectionByPos(int pos) {
	checkPosition(pos);
	if (pos == POS_CENTER){
		throwError("getDirByPos", "get center");
	}
	return pos % 8;
}

int getLineNumToCenter(int pos) {
	checkPosition(pos);
	if (pos == POS_CENTER) return 0;
	else if (pos == POS_HOME) return 5;
    else return pos/8 + 2;
}

int getLineNumWhenTurnTo(int tarDir) {
	checkDirection(tarDir);
	int lineNum = tarDir - direction_;
	if(lineNum > 4) lineNum -= 8;
	else if(lineNum < -4) lineNum += 8;
	return lineNum;
}

void checkDirection(int dir) {
	if (dir < 0 || dir > 7) {
		throwError("checkDirection", "");
	}
}

void checkPosition(int pos) {
	if (pos < 0 || pos > 16) {
		throwError("checkPosition", "");
	}
}

int reverseDirection(int dir) {
	checkDirection(dir);
	return reDirection[dir];
}

int getPosByColor(int color) {
	if (color >= 1 && color <= 5) { return colorToPosition[color]; }
	else { throwError("getPosByColor", "unknown color"); }
}

void struckUpWithObjCol() {
	if (objectColor == 0) {
		return;
	}
	switch (objectColor) {
		case 1: m_tape = m_humor; t_tape = t_humor; break;
		case 2: m_tape = m_me; t_tape = t_me; break;
		case 3: m_tape = m_pingfan; t_tape = t_pingfan; break;
		case 4: m_tape = m_summer; t_tape = t_summer; break;
		case 5: m_tape = m_sky; t_tape = t_sky; break;
        default: m_tape = m_nullMusic; t_tape = t_nullMusic;
	}
	playingMusic = 1;
}

void main_1(void* p) {
	while (1) {
		if (playingMusic) playMusic();
	}
}

void playMusic() {
	int i, tp; 
	for (i = 1; playingMusic && i <= m_tape[0]; i++) {
		// tp = m_tape[i] < 0 ? -m_tape[i] : m_tape[i] + 7;
        if(m_tape[i]<0) tp=-m_tape[i];
        else if(m_tape[i]>10) tp=m_tape[i]+4;
        else tp=m_tape[i]+7;
		sound(beep[tp], toneTime * t_tape[i]);
	}
	playingMusic = 0;
}

void main_2(void* p) {
    while (1) {
		if (usingACC) {
			changeSpeed();		    
			if (++ accCnt >= 7) accCnt = 0;
		}
    }
}

void changeSpeed() {
	// without ACC
	if (!usingACC) {
		actualSpeed = statedSpeed;
	} 
	else { // ACC online
		if (accCnt == 0) {
			if (statedSpeed > actualSpeed) { 
				actualSpeed ++; 
			} 
			else if (statedSpeed < actualSpeed) { 
				actualSpeed --; 
			}
		}

		if (abs(actualSpeed) <= MID_SPEED) {
			if (abs(statedSpeed) <= MID_SPEED) {
				actualSpeed = statedSpeed;
			} else {
				actualSpeed = MID_SPEED * (statedSpeed > 0 ? 1 : -1);
			}
		}

		if (actualSpeed * statedSpeed < 0) {
			actualSpeed = 0;
		}
	}

    _motor_();
}

int abs(int x) { return x < 0 ? -x : x; }

void main_3(void* p) {}
