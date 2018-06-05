// 18.5.31
// by ftm

// for dev
//   void motor(int x, int y) {}
//   void servo(int x, int y) {}
//   int seconds(int x) { return 0; }
//   void cls() {}
//   void locate(int x, int y) {}
//   int getadc(int x) { return 0; }
//   int geteadc(int x) { return 0; }
//   void wait(float x) {}
//   int getport(int x) { return 0; }
//   int selector() { return 0; }
//   void sound(int x, int y) {}
//   #include <stdio.h>

// const datas
int frontBaceValue[] = { -1, 478, 617, 435, 434 };
int backBaceValue[] = { -1, 676, 635, 522, 452 };
int leftBaceValue = 521;
int rightBaceValue = 622;

int colorA_baceValue[] = { -1, 630, 544, 410, 264, 396 };
int colorB_baceValue[] = { -1, 623, 520, 270, 206, 552 };

int colorToPosition[] = { -1, 11, 12, 8, 9, 10 };

int turnplateAngle[3][6] = { { -1, -1, -1, -1, -1, -1 },
               { -1, 49, 73, 78, 59, 45 },
               { -1, 73, 50, 40, 60, 78 } };
int turnplateBackAngle[3][6] = { { -1, -1, -1, -1, -1, -1 },
                 { -1, 65, 60, 60, 65, 65 },
                   { -1, 60, 65, 65, 65, 60 } };


#define PLATFORM_DOWN (!getport(9))
#define PLATFORM_MID getport(8)
#define PLATFORM_UP getport(7)

#define POS_CENTER 16
#define POS_HOME 14

#define FAST_SPEED 700
#define MID_SPEED 400
#define SLOW_SPEED 150

#define CLAW_SERVO 4
#define HOOK_SERVO 3
#define TURNPLATE_SERVO 2

#define PLATFORM_MOTOR 3
#define LEFT_MOTOR 4
#define RIGHT_MOTOR 1

#define CATCH_ANGLE 74
#define RELEASE_ANGLE 54
#define WHIDE_ANGLE 43

#define OBJECT_NEAR_SENSOR_VALUE 400
#define OBJECT_CATCHABLE_SENSOR_VALUE 650

// temp vars 
int cannotTransfer[20] = { 0 };
int tmpObject = 0; //????????,???????
int tmpObjectTo[] = { 0, 7, 5 };
int cntW, cntB, crossingLine;
int reDirection[] = { 4, 5, 6, 7, 0, 1, 2, 3 };

// robot datas
int position_;
int direction_;
int calwState; // 1catch 2release 3wide
int platformState; // 3up 2mid 1down
// ??????1??2??3??4??5??
int objectColor;
int catchedNum[10] = { 0 }; // ??????????

// functions
void runTask1();
void transferForTask1(int pos);
void runTask2();
void transferForTask2(int pos);
void correctSensors();

void moveTo(int destination); // ??????????????
int catchObject(); // ??????,???????
int autoCatchObject();
void releaseObject(); // ??????
void platformMove(char* op); // ????????,??:"up","mid","down"
int catchObjectByHook(int id, int op); // ????????????????

int onLine(char* op);
int objectNear();
int colorDiscrimination();

void moveToCenter();
void turnToOnCenter(int targetDirection);
void moveFromCenterTo(int destination);
void moveWithCountingLine(int lineNum, int op, int speed);
void moveWithTime(float timeLimit, int op, int speed);
void turnWithCountingLine(int lineNum, int op);
void trackLine(int op, int speed);
void approachTarget();
int countLine(char* sid);

int getDirectionByPos(int pos);
int getLineNumToCenter(int pos);
int getLineNumWhenTurnTo(int tarDir);
int reverseDirection(int dir);

void init();
void clawTo(int angle);
void setSpeed(int leftSpeed, int rightSpeed);
void throwError(char* where, char* errLog);
int equal(int a,int b,int x);
void checkDirection(int dir);
void checkPosition(int pos);


int main(void) 
{
  int op = selector();
  if (op == 0) {
    moveWithTime(5, 1, FAST_SPEED);
    wait(1); 
    moveWithTime(5, -1, FAST_SPEED);
    wait(1);
  }
  else if (op == 1) {
    moveWithCountingLine(3, 1, FAST_SPEED);
  }
  else if (op == 2) {
    setSpeed(FAST_SPEED, FAST_SPEED);
    wait(1);
    setSpeed(0, 0);
    wait(3);
    setSpeed(MID_SPEED, MID_SPEED);
    wait(1);
    setSpeed(0, 0);
    wait(3);
    setSpeed(SLOW_SPEED, SLOW_SPEED);
    wait(1);
    setSpeed(0, 0);
    wait(3);
  }
  else if (op == 3) {
    approachTarget();
  }
  else if (op == 4) {
    init();
    platformMove("up"); wait(1);
    platformMove("mid"); wait(1);
    platformMove("down"); wait(1); 
    platformMove("mid"); wait(1);
    platformMove("down"); wait(1);
  }
  else if (op == 5) {
    init();
    moveTo(8);
  }
    else if (op == 6) {
    init();
        moveToCenter();
    wait(3);
    turnWithCountingLine(3, 1);
    }
    else if (op == 7) {
    init();
        runTask1();
    }
  else if (op == 8) {
    correctSensors();
  }
  else if (op == 9) {
    turnWithCountingLine(100, 1);
  }
  else if(op == 10) {
    init();
    while(1) {
      catchObject();
      wait(1);
      releaseObject();
      wait(1);
    }
  }
  // while (1) { ; }
}

// init robot datas
void init() {
  position_ = POS_HOME;
  direction_ = getDirectionByPos(POS_HOME);

  clawTo(RELEASE_ANGLE);
  platformMove("down");
  servo(HOOK_SERVO, 120);
  servo(TURNPLATE_SERVO, 60);

  objectColor = 0;
  int i; for(i=1; i<=5; i++) catchedNum[i] = 0;
}

void correctSensors() {
  cls();
  while (1) {
    colorDiscrimination();
    locate(1,2); printf("correct sensors");
    locate(2,1); printf("f1:%3d f2:%3d", geteadc(1), geteadc(2));        
    locate(3,1); printf("f3:%3d f4:%3d", geteadc(3), geteadc(4));    
    locate(4,1); printf("b1:%3d b2:%3d", geteadc(5), geteadc(6));      
    locate(5,1); printf("b3:%3d b4:%3d", geteadc(7), geteadc(8));  
    locate(6,1); printf("l:%3d r:%3d dis=%3d", getadc(1), getadc(2), getadc(5));  
    locate(7,1); printf("cA=%3d cB=%3d", getadc(3), getadc(4));  
    locate(8,1); printf("color=%d", objectColor);
    locate(9,1); printf("u:%d m:%d d:%d", PLATFORM_UP, PLATFORM_MID, PLATFORM_DOWN);            
    wait(0.1);
  }
}

void transferForTask1(int pos) {
  //????????,??????
  moveTo(pos);
  int color = catchObject();
  int destination = colorToPosition[color];
  if(cannotTransfer[destination]) {
    destination = tmpObjectTo[++ tmpObject];
  }
  moveTo(destination);
  releaseObject();
}

void runTask1() {
  cannotTransfer[8] = cannotTransfer[10] = cannotTransfer[12] = 1;
  transferForTask1(2);
  cannotTransfer[10] = 0;
  transferForTask1(4);
  cannotTransfer[12] = 0;
  transferForTask1(0);
  cannotTransfer[8] = 0;
  int i; for(i = 1; i <= tmpObject; i++) {
    transferForTask1(tmpObjectTo[i]);
  }
}

void transferForTask2(int pos) {
  int i; for(i = 1; i <= 5; i++){
    moveTo(pos);
    int color = catchObjectByHook(i, pos==15 ? 1 : 2);
    int destination = colorToPosition[color];
    if(color == -1) {
      throwError("transferForTask2", "color is 0!");
    }
    char* op;
    switch (catchedNum[color]) {
      case 0 : op = "down"; break;
      case 1 : op = "mid"; break;
      case 2 : op = "up"; break;
      default: throwError("catchedNum", "");
    }
    platformMove(op);
    moveTo(destination);
    releaseObject();
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
      int val = geteadc(x);
      if (val < frontBaceValue[x]) return 0;
      else return 1;
    }
  }
  // back : b1~4 -> eacd5~8
  if (op[0] == 'b') {
    int x = op[1] - '0';
    if (x >= 1 && x <= 4) {
      int val = geteadc(x + 4);
      if (val < backBaceValue[x]) return 0;
      else return 1;
    }
  }
  // left : l -> acd1
  if (op[0] == 'l') {
    int val = getadc(1);
    if (val < leftBaceValue) return 0;
    else return 1;
  }
  // right : r -> acd2
  if (op[0] == 'r') {
    int val = getadc(2);
    if (val < rightBaceValue) return 0;
    else return 1;
  }

  // else all
  throwError("onLine", "unknown sensor type");
  return 0;
}

// function : check whether an object is close to robot 
int objectNear() {
  // the bigger, the closer
  if (getadc(5) > OBJECT_NEAR_SENSOR_VALUE) return 1;
  else return 0;
}

// function : check whether an object is close to robot 
int objectCatchable() {
  // the bigger, the closer
  if (getadc(5) > OBJECT_CATCHABLE_SENSOR_VALUE) return 1;
  else return 0;
}

// function : move robot from it's positon to destination
void moveTo(int destination) {
  if (position_ == destination) {
    return;
  }
  if (getDirectionByPos(position_) == getDirectionByPos(destination) && position_ < destination) {
    moveWithCountingLine(1, 1, FAST_SPEED);
    approachTarget();

  }
  else {
    moveToCenter(); // first, move to center
    turnToOnCenter(getDirectionByPos(destination)); // then, turn to destination's direction
    moveWithTime(1, 1, FAST_SPEED);
    moveFromCenterTo(destination); // finally, move to destination from center
  }
  position_ = destination;
}

// function : move robot to center
// only useable when robot is back to center
void moveToCenter() {
  if (position_ == POS_CENTER) {
    return;
  }
  if (direction_ == getDirectionByPos(position_)) {
    moveWithCountingLine(getLineNumToCenter(position_), -1, FAST_SPEED);
    moveWithTime(0.05, -1, MID_SPEED);
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
  moveWithCountingLine(getLineNumToCenter(destination) - 2, 1, FAST_SPEED);
  approachTarget();
  position_ = destination;
} 

// function : line track with counting line
// op > 0, move front; op < 0, move back 
// we only use left sensor when counting line
void moveWithCountingLine(int lineNum, int op, int speed) { 
  if (!lineNum) return;
  
  countLine("init");
  while (lineNum) {
    trackLine(op, speed);
    if (countLine("l")) {
      lineNum --;
    }
  }

  setSpeed(0, 0);
}

// function : line track whih time limit
// op > 0, move front; op < 0, move back 
void moveWithTime(float timeLimit, int op, int speed) {
  float startTime = seconds(1);
  while (seconds(1) - startTime < timeLimit) {
    trackLine(op, speed);
  }
    setSpeed(0, 0);
}

// function : rotate whih counting line
// op > 0, turn right; op < 0, turn left 
void turnWithCountingLine(int lineNum, int op) {
  if (!lineNum) return;
  
  char* sid;
  if (op > 0) {
    sid = "f4";
    setSpeed(MID_SPEED, -MID_SPEED);
  }
  else {
    sid = "f1";
    setSpeed(-MID_SPEED, MID_SPEED);
  }
  countLine("init");
  while (lineNum) {
    if (countLine(sid)) {
      lineNum --;
    }
  }

  lineNum = 1;
  if (op > 0) {
    sid = "f3";
    setSpeed(MID_SPEED, -MID_SPEED);
  }
  else {
    sid = "f2";
    setSpeed(-MID_SPEED, MID_SPEED);
  }
  countLine("init");
  while (lineNum) {
    if (countLine(sid)) {
      lineNum --;
    }
  }

  setSpeed(0, 0);
}

// function : track line
void trackLine(int op, int speed) {
  int s1, s2, s3, s4;
  int lspeed, rspeed;

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

  if ((s2 && s3) || (s1 && s4)) {
    lspeed = speed; rspeed = speed;
  }
  else if (s2 && !s3) {
    lspeed = speed * 0.6; rspeed = speed;
  }
  else if (!s2 && s3) {
    lspeed = speed; rspeed = speed * 0.6;
  }
  else if (s1) {
    lspeed = speed * 0.3; rspeed = speed;
  }
  else if (s4) {
    lspeed = speed; rspeed = speed * 0.3;
  }
  else {
    lspeed = speed; rspeed = speed;
  }

  if (op > 0) {
    setSpeed(lspeed, rspeed);
  }
  else {
    setSpeed(-rspeed, -lspeed);
  }
}

// function : approtch target
void approachTarget() {
  int s1, s2, s3, s4;
  int cnt = 0;
  int speed = MID_SPEED;

  while(1) {
    s1 = onLine("f1");
    s2 = onLine("f2");
    s3 = onLine("f3");
    s4 = onLine("f4");

    if (s1 && s4) {
      setSpeed(0, 0);
      if (cnt < 100) cnt ++;
    }
    else {
      cnt = 0;
      if (objectNear()) speed = SLOW_SPEED;
      else speed = MID_SPEED;

      if (s2 && !s3) {
        setSpeed(speed * 0.6, speed);
      }
      else if (!s2 && s3) {
        setSpeed(speed, speed * 0.6);
      }
      else if (s1) {
        setSpeed(speed * 0.3, speed);
      }
      else if (s4) {
        setSpeed(speed, speed * 0.3);
      } 
      else {
        setSpeed(speed, speed);
      }
    }

    if (cnt >= 3) break;
  }

  setSpeed(0, 0);
}

// function : line count
// sid : id of line count sensor
// before use, countLine("init") first
int countLine(char* sid) {
  if (sid[0] == 'i') {
    cntW = 0; cntB = 0; crossingLine = 0;
    return 0;
  }
  if (onLine(sid)) { 
    if (cntB < 100) cntB ++; 
    cntW = 0;
  }
  else {
    if (cntW < 100) cntW++;
    cntB = 0; 
  }

  if (cntB >= 3 && !crossingLine) {
    crossingLine = 1;
  } 
  else if (cntW >= 3 && crossingLine) {
    crossingLine = 0;
    return 1;
  }
  return 0;
}

// function : set motor speed
void setSpeed(int leftSpeed, int rightSpeed) {
  // left-motor's id is 4
  motor(LEFT_MOTOR, -leftSpeed);
  // right-motor's id is 1
  motor(RIGHT_MOTOR, -rightSpeed);
}

// function : print error log and stop progrem
void throwError(char* where, char* errLog) {
  cls();
  locate(1,1); printf("ERROR");
  locate(2,1); printf("at %s", where);
  locate(3,1); printf("%s", errLog);
    setSpeed(0, 0);
    sound(500, 1000);
  while (1) { ; }
} 

void clawTo(int angle) {
  servo(CLAW_SERVO, angle);
  switch (angle) {
    case CATCH_ANGLE : calwState = 1; break;
    case RELEASE_ANGLE : calwState = 2; break;
    case WHIDE_ANGLE : calwState = 3; break;
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
    return colorDiscrimination();
}

// you should make sure object is in front of you and not too far
int autoCatchObject() {
  clawTo(RELEASE_ANGLE);
  platformMove("down");
  if (objectNear()) {
    setSpeed(SLOW_SPEED, SLOW_SPEED);
    while(!objectCatchable()) { ; }
    setSpeed(0, 0);
  }
  else {
    throwError("catchObject", "can not find obj");
  }
  clawTo(CATCH_ANGLE);
  wait(0.5);
    return colorDiscrimination();
}

// function : release object
void releaseObject() {
  clawTo(RELEASE_ANGLE);
  wait(0.5);
}

// function : discrimination object color
int colorDiscrimination() {
  objectColor = 0;
  int i; for (i = 1; i <= 5; i++) {
    if (equal(getadc(3), colorA_baceValue[i], 50) 
     && equal(getadc(4), colorB_baceValue[i], 50)) 
    { objectColor = i; break; }
  }
  return objectColor;
}

int equal(int a,int b,int x) {
  return (a>b) ? (a-b<=x) : (b-a<=x);
}

// function : platform rise or fall
// op : "up" "mid" "down"
void platformMove(char* op) {
  if (calwState == 3) {
    clawTo(RELEASE_ANGLE);
  }
  if (op[0] == 'u') {
    motor(PLATFORM_MOTOR, -400); 
    while (!PLATFORM_UP) { ; }
    motor(PLATFORM_MOTOR, 0);
    platformState = 3;
  }
  else if (op[0] == 'd') {
    motor(PLATFORM_MOTOR, 400); 
    while (!PLATFORM_DOWN) { ; }
    motor(PLATFORM_MOTOR, 0);
    platformState = 1;
  }
  else if (op[0] == 'm') {
    if (platformState == 2) { 
      if (PLATFORM_MID) return;
      else platformMove("down");
    }
    if (platformState == 3) {
      motor(PLATFORM_MOTOR, 400);
    }
    else if (platformState == 1) {
      motor(PLATFORM_MOTOR, -400);
    }
    while(!PLATFORM_MID) { ; }
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
  clawTo(WHIDE_ANGLE);
  servo(HOOK_SERVO, 120);
  servo(TURNPLATE_SERVO, turnplateAngle[op][id]);
  
  // TODO

  servo(HOOK_SERVO, 60); wait(0.2);
  servo(HOOK_SERVO, 55); wait(0.2);
  servo(HOOK_SERVO, 50); wait(0.2);
  setSpeed(-200, -200);
  servo(HOOK_SERVO, 45); wait(0.2);
  servo(HOOK_SERVO, 40); wait(0.2);
  servo(TURNPLATE_SERVO, turnplateBackAngle[op][id]); wait(0.2);
  servo(HOOK_SERVO, 50); wait(0.2);
  servo(HOOK_SERVO, 55); wait(0.2);
  servo(HOOK_SERVO, 60); wait(0.2);
  servo(HOOK_SERVO, 120); wait(0.2);
  setSpeed(0, 0);
  return autoCatchObject();
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
  else if (pos == POS_HOME) return 4;
    else return pos/16 + 2;
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