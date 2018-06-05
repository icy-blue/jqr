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


// robot datas
int position;
int direction;


// function : check if a ground sensor is on line
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

// function : print error log and stop progrem
void throwError(char* where, char* errLog) {
  cls();
  locate(1,1); printf("ERROR");
  locate(2,1); printf("at %s", where);
  locate(3,1); printf("%s", errLog);
  while(1) { ; }
} 
