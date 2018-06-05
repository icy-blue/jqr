// 18.5.28
// by ftm

// const datas
int sensorBaceValueFront[] = {};
int sensorBaceValueBack[] = {};
int sensorBaceValueLeft = x;
int sensorBaceValueRight = x;

#define POS_CENTER x

#define FAST_SPEED 700
#define MID_SPEED 400
#define SLOW_SPEED 100
#define VERY_SLOW_SPEED 50

#define OBJECT_NEAR_SENSOR_VALUE x


// robot datas
int position;
int direction;


// function : check whether a ground sensor is on line
// examples: onLine("f1"); onLine("b3"); onLine("l"); onLine("r");
int onLine(char* op) {
  // front : f1~4 -> eacd1~4
  if (op[0] == 'f') {
    int x = op[1] - '0';
    if (x >= 1 && x <= 4) {
      int val = geteadc(x);
      if (val < sensorBaceValueFront[x]) return 0;
      else return 1;
    }
  }
  // back : b1~4 -> eacd5~8
  if (op[0] == 'b') {
    int x = op[1] - '0';
    if (x >= 1 && x <= 4) {
      int val = geteadc(x + 4);
      if (val < sensorBaceValueBack[x]) return 0;
      else return 1;
    }
  }
  // left : l -> acd1
  if (op[0] == 'l') {
    int val = getadc(1);
    if (val < sensorBaceValueLeft) return 0;
    else return 1;
  }
  // right : r -> acd2
  if (op[0] == 'r') {
    int val = getadc(2);
    if (val < sensorBaceValueRight) return 0;
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
}

// function : turn the robot to targetDirection
// only be used when robot on center
void turnToOnCenter(int targetDirection) {
  if (position != POS_CENTER) {
    throwError("turnToOnCenter", "not at center");
  }
  if (destnation == targetDirection) {
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
  moveWithCountingLine(getLineNumToCenter(destnation), 1);
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

  if (objectNear()) {
    lspeed /= 2; rspeed /= 2;
  }

  setSpeed(lspeed * op, rspeed * op);
}

// function : line track with counting line
// op > 0, move front; op < 0, move back 
// we only use left sensor when counting line
int moveWithCountingLine(int lineNum, int op) { 
  int sl;  int cntB = 0, cntW = 0, crossingLine = 0;

  while (lineNum) {
    trickLine(op);
    // count line
    if (sl) { 
      if (cntB < 100) cntB ++; 
      cntW = 0;
    }
    else {
      if (cntW < 100) cntW++;
      cntB = 0; 
    }

    if (cntB >= 3 && !crossingLine) {
      crossingLine = 1;
      lineNum --;
    } 
    if (cntW >= 3 && crossingLine) {
      crossingLine = 0;
    }
  }
  setSpeed(0, 0);
}

// function : line track whih counting line
// op > 0, move front; op < 0, move back 
int moveWithTime(int timeLimit, int op) {
  float startTime = second(1);
  while (second(1) - startTime < timeLimit) {
    trickLine(op);
  }
}

// function : rotate whih time limit
// op > 0, turn right; op < 0, turn left 
int turnWithCountingLine(int lineNum, int op) {
  int s; 
  if (op > 0) {
    setSpeed(MID_SPEED, -MID_SPEED);
  }
  else {
    setSpeed(-MID_SPEED, MID_SPEED);
  }
  while (lineNum) {
    if (op < 0) { s = onLine("f1"); }
    else { s = onLine("f4"); }

    if (s) { 
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
    if (cntW >= 3 && crossingLine) {
      crossingLine = 0;
      lineNum --;
    }
  }
  setSpeed(0, 0);
}

// function : set motor speed
int setSpeed(int leftSpeed, int rightSpeed) {
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