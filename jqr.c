// 18.5.29
// by ftm

// const datas
int frontBaceValue[] = { -1, 443, 609, 431, 408 };
int backBaceValue[] = { -1, 667, 643, 554, 456 };
int leftBaceValue = 523;
int rightBaceValue = 586;

int colorA_baceValue[] = { -1 };
int colorB_baceValue[] = { -1 };

int colorToPosition[] = { -1, 11, 12, 8, 9, 10 };

int turnplateAngle[2][6] = { { -1, 49, 73, 78, 59, 45 },
               { -1, 73, 50, 40, 60, 78 } };
int turnplateBackAngle[2][6] = { { -1, 65, 60, 60, 65, 65 },
                   { -1, 60, 65, 65, 65, 60 } };


#define PLATFORM_DOWN (!getport(9))
#define PLATFORM_MID getport(8)
#define PLATFORM_UP getport(7)

#define POS_CENTER 16
#define POS_HOME 14

#define FAST_SPEED 700
#define MID_SPEED 400
#define SLOW_SPEED 100
#define VERY_SLOW_SPEED 50

#define CLAW_SERVO 4
#define HOOK_SERVO 3
#define TURNPLATE_SERVO 2

#define PLATFORM_MOTOR 2
#define LEFT_MOTOR 4
#define RIGHT_MOTOR 1

#define CATCH_ANGLE 74
#define RELEASE_ANGLE 54
#define WHIDE_ANGLE 43

#define OBJECT_NEAR_SENSOR_VALUE 600

// temp vars 
int cannotTransfer [20] = { 0 };
int tmpObject = 0;//涓嶈兘鐩存帴閫佸埌缁堢偣锛岄渶瑕佷复鏃跺瘎锟?
int tmpObjectTo[3] = { 0, 7, 5 };
int cntW, cntB, crossingLine;
int reDirection[8] = {4, 5, 6, 7, 0, 1, 2, 3};

// robot datas
int position;
int direction;
int calwState; // 1catch 2release 3wide
int platformState; // 3up 2mid 1down
// 棰滆壊锟?锟?1锟?2锟?3锟?4锟?5锟?
int objectColor;
int catchedNum[9] = {0}; // 宸茬粡鎶撳彇鐨勭墿鍧楃殑涓暟

// functions
void runTask1();
void transferForTask1(int pos);
void runTask2();
void transferForTask2(int pos);

void moveTo(int destnation); // 浠庡綋鍓嶄綅缃嚭鍙戣蛋鍒版寚瀹氫綅锟?
int catchObject(); // 澶瑰瓙鎶撳彇鐗╁潡锛岃繑鍥炵墿鍧楅锟?
void releaseObject(); // 澶瑰瓙閲婃斁鐗╁潡
void platformMove(char* op); // 璋冩暣澶瑰瓙骞冲彴楂樺害锛屽弬鏁帮細"up","mid","down"
int catchObjectByHook(int id, int op); // 浣跨敤閽╁瓙鎶婄墿鍧楁嫋鍒板悎閫備綅缃悗鎶撳彇

int onLine(char* op);
int objectNear();
int colorDiscrimination();

void moveToCenter();
void turnToOnCenter(int targetDirection);
void moveFromCenterTo(int destnation);
void moveWithCountingLine(int lineNum, int op);
void moveWithTime(float timeLimit, int op);
void turnWithCountingLine(int lineNum, int op);
void trickLine(int op);
void approachTarget();
int countLine(char* sid);

int getDirectionByPos(int pos);
int getLineNumToCenter(int pos);
int getLineNumWhenTurnTo(int tarDir);
int reverseDirection(int dir);

void clawTo(int angle);
void setSpeed(int leftSpeed, int rightSpeed);
void throwError(char* where, char* errLog);
int equal(int a,int b,int x);
void init();
int checkdirValid(int checkNum);
int checkValid(int checkNum, int minNum, int maxNum);


int main() {
  // sound(500, 500); wait(1.0);

  int op = selector();
  if (op == 0) {
    moveWithTime(5, 1);
  }
  else if (op == 1) {
    moveWithCountingLine(3, 1);
  }
  else if (op == 2) {
    turnWithCountingLine(3, 1);
  }
  else if (op == 3) {
    approachTarget();
  }
  else if (op == 4) {
    init();
    platformMove("up"); 
    platformMove("mid");
    platformMove("down");
    platformMove("mid");
  }
  else if (op == 5) {
    init();
    moveTo(8);
  }

  while (1) { ; }
  
  return 0;
}

// init robot datas
void init() {
  position = POS_HOME;
  direction = reverseDirection(getDirectionByPos(POS_HOME));

  clawTo(RELEASE_ANGLE);
  platformMove("down");

  objectColor = 0;
  int i; for(i=1; i<=5; i++) catchedNum[i] = 0;
}

void transferForTask1(int pos) {
  //浠庡摢涓湴鏂瑰彇鐗╁潡锛岃嚜鍔ㄦ惉杩愶拷?
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

// function : move robot from it's positon to destnation
void moveTo(int destnation) {
  if (position == destnation) {
    return;
  }
  moveToCenter(); // first, move to center
  turnToOnCenter(getDirectionByPos(destnation)); // then, turn to destnation's direction
  moveFromCenterTo(destnation); // finally, move to destnation from center
}

// function : move robot to center
void moveToCenter() {
  if (position == POS_CENTER) {
    return;
  }
  if (direction == getDirectionByPos(position)) {
    // if robot back to center, it will move back to
    moveWithCountingLine(getLineNumToCenter(position), -1);
  }
  else if (direction == reverseDirection(getDirectionByPos(position))) {
    // if robot face to center, it will move front to
    moveWithCountingLine(getLineNumToCenter(position), 1);
  }
  else {
    // we won't meet this situation
    throwError("moveToCenter", "not face or back to center");
  }
  position = POS_CENTER;
}

// function : turn the robot to targetDirection
// only be used when robot on center
void turnToOnCenter(int targetDirection) {
  if (position != POS_CENTER) {
    throwError("turnToOnCenter", "not at center");
  }
  if (direction == targetDirection) {
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
  direction = targetDirection;
}

// function : move robot from center to destnation
// only be used when robot on center
void moveFromCenterTo(destnation) {
  if (position != POS_CENTER) {
    throwError("moveFromCenterTo", "not at center");
  }
  if (direction != getDirectionByPos(destnation)) {
    throwError("moveFromCenterTo", "not face to destnation");
  }
  moveWithCountingLine(getLineNumToCenter(destnation) - 1, 1);
  approachTarget();
  position = destnation;
} 

// function : line track with counting line
// op > 0, move front; op < 0, move back 
// we only use left sensor when counting line
void moveWithCountingLine(int lineNum, int op) {  
  if (!lineNum) return;
  
  countLine("init");
  while (lineNum) {
    trickLine(op);
    if (countLine("l")) {
      lineNum --;
    }
  }

  setSpeed(0, 0);
}

// function : line track whih time limit
// op > 0, move front; op < 0, move back 
void moveWithTime(float timeLimit, int op) {
  // float startTime = seconds(1);
  // while (seconds(1) - startTime < timeLimit) {
  //  trickLine(op);
  // }
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

  setSpeed(0, 0);
}

// function : trick line
void trickLine(int op) {
  int s1, s2, s3, s4;
  int lspeed, rspeed;

  if (op < 0) op = -1; else op = 1;
  if (op == 1) {
    s1 = onLine("f1");
    s2 = onLine("f2");
    s3 = onLine("f3");
    s4 = onLine("f4");
  }
  else if (op == -1) {
    s1 = onLine("b1");
    s2 = onLine("b2");
    s3 = onLine("b3");
    s4 = onLine("b4");
  }

  if ((s2 && s3) || (s1 && s4)) {
    lspeed = FAST_SPEED; rspeed = FAST_SPEED;
  }
  else if (s2 && !s3) {
    lspeed = MID_SPEED; rspeed = FAST_SPEED;
  }
  else if (!s2 && s3) {
    lspeed = FAST_SPEED; rspeed = MID_SPEED;
  }
  else if (s1) {
    lspeed = SLOW_SPEED; rspeed = FAST_SPEED;
  }
  else if (s4) {
    lspeed = FAST_SPEED; rspeed = SLOW_SPEED;
  }
  else {
    lspeed = FAST_SPEED; rspeed = FAST_SPEED;
  }

  setSpeed(lspeed * op, rspeed * op);
}

// function : approtch target
void approachTarget() {
  int s1, s2, s3, s4;
  int cnt = 0, flag = 1;

  while(flag) {
    s1 = onLine("f1");
    s2 = onLine("f2");
    s3 = onLine("f3");
    s4 = onLine("f4");

    if ((s2 && s3) || (s1 && s4)) {
      setSpeed(VERY_SLOW_SPEED, VERY_SLOW_SPEED);
      if (cnt < 100) cnt ++;
    }
    else {
      cnt = 0;
      if (s2 && !s3) {
        setSpeed(MID_SPEED, FAST_SPEED);
      }
      else if (!s2 && s3) {
        setSpeed(FAST_SPEED, MID_SPEED);
      }
      else if (s1) {
        setSpeed(SLOW_SPEED, FAST_SPEED);
      }
      else if (s4) {
        setSpeed(FAST_SPEED, SLOW_SPEED);
      }
    }

    if (cnt >= 3) flag = 0;
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
// you should make sure object is in front of you and not too far
int catchObject() {
  clawTo(RELEASE_ANGLE);
  if (!objectNear()) {
    setSpeed(SLOW_SPEED, SLOW_SPEED);
    while(!objectNear()) { ; }
    setSpeed(0, 0);
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
  approachTarget();
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
  return catchObject();
}


int getDirectionByPos(int pos) {
  checkValid(pos, 0, 15);
  if (pos == 15){
    throwError("getDirByPos", "getCenter");
  }
  return pos % 8;
}

int getLineNumToCenter(int pos) {
  return 0;
}

int getLineNumWhenTurnTo(int tarDir) {
  if(checkdirValid(tarDir) == 0){
    throwError("reverseDir", "dir is invalid");
  }
  int _lines = tarDir - direction;
  if(_lines > 4) _lines -= 8;
  else if(_lines < -4) _lines += 8;
  return _lines;
}

//check num in [min, max]
int checkValid(int checkNum, int minNum, int maxNum) {
  if(checkNum >= minNum && checkNum <= maxNum){
    return 1;
  } else return 0;
}
int checkdirValid(int checkNum) {
  return checkValid(checkNum, 0, 7);
}

int reverseDirection(int dir) {
  if(checkdirValid(dir) == 0){
    throwError("reverseDir", "dir is invalid");
  }
  return reDirection[dir];
}
