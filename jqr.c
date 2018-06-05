// 18.5.27
// 18.5.28
// by ftm

// const datas
#define VALUE_SENSOR_FRONT_1 x
#define VALUE_SENSOR_FRONT_2 x
#define VALUE_SENSOR_FRONT_3 x
#define VALUE_SENSOR_FRONT_4 x
#define VALUE_SENSOR_BACK_1 x
#define VALUE_SENSOR_BACK_2 x
#define VALUE_SENSOR_BACK_3 x
#define VALUE_SENSOR_BACK_4 x
#define VALUE_SENSOR_LEFT x
#define VALUE_SENSOR_RIGHT x
#define VALUE_SENSOR_WHITE x
#define VALUE_SENSOR_GREEN x

#define POS_CENTER x

#define FAST_SPEED 700
#define MID_SPEED 400
#define SLOW_SPEED 100
#define VERY_SLOW_SPEED 50


// robot datas
int position;
int direction;


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
