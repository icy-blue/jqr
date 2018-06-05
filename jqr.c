// 18.5.29
// by ftm

// const datas
int frontBaceValue[] = {};
int backBaceValue[] = {};
int leftBaceValue = x;
int rightBaceValue = x;

int colorA_baceValue[] = {};
int colorB_baceValue[] = {};


#define POS_CENTER x

#define FAST_SPEED 700
#define MID_SPEED 400
#define SLOW_SPEED 100
#define VERY_SLOW_SPEED 50

#define CLAW_SERVO 4
#define PLATFORM_SERVO x
#define HOOK_SERVO x

#define CATCH_ANGLE x
#define RELEASE_ANGLE x

#define OBJECT_NEAR_SENSOR_VALUE x


// robot datas
int position;
int direction;
int platformState;
int hookState;
// 棰滆壊锛?绌?1榛?2钃?3缁?4鐧?5绾?
int objectColor;
int catchedNum[9] = {0}; // 宸茬粡鎶撳彇鐨勭墿鍧楃殑涓暟

// functions
void moveTo(int destnation); // 浠庡綋鍓嶄綅缃嚭鍙戣蛋鍒版寚瀹氫綅缃?
int catchObject(); // 澶瑰瓙鎶撳彇鐗╁潡锛岃繑鍥炵墿鍧楅鑹?
void releaseObject(); // 澶瑰瓙閲婃斁鐗╁潡
void platformMove(char* op); // 璋冩暣澶瑰瓙骞冲彴楂樺害锛屽弬鏁帮細"up","mid","down"


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
  turnToOnCenter(getDirection(destnation)); // then, turn to destnation's direction
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
  if (direction != getDirection(destnation)) {
    throwError("moveFromCenterTo", "not face to destnation");
  }
  moveWithCountingLine(getLineNumToCenter(destnation) - 1, 1);
  approachTarget();
  position = destnation;
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
int moveWithTime(float timeLimit, int op) {
  float startTime = second(1);
  while (second(1) - startTime < timeLimit) {
    trickLine(op);
  }
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

// function : line count
// sid : id of line count sensor
// before use, countLine("init") first
int cntW, cntB, crossingLine;
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
  motor(4, -leftSpeed);
  // right-motor's id is 1
  motor(1, -rightSpeed);
}

// function : print error log and stop progrem
void throwError(char* where, char* errLog) {
  cls();
  locate(1,1); printf("ERROR");
  locate(2,1); printf("at %s", where);
  locate(3,1); printf("%s", errLog);
  while (1) { ; }
} 

// function : catch object
int catchObject() {
  servo(CLAW_SERVO, CATCH_ANGLE);
  wait(0.5);
    return colorDiscrimination();
}

// function : release object
void releaseObject() {
  servo(CLAW_SERVO, RELEASE_ANGLE);
  wait(0.5);
}

// function : discrimination object color
int colorDiscrimination() {
  objectColor = 0;
  for (i = 1; i <= 5; i++) {
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
  if (op[0] == 'u') {

  }
  else if (op[0] == 'd') {

  }
  else if (op[0] == 'm') {

  }
  else {
    throwError("platformMove", "unknown order");
  }
}