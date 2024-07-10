/* Arduino Rotary Table Control Program

  **************************************************************
    WARNING! THIS IS A BETA VERSION OF THE PROGRAM FOR
    TESTING AND DE-BUGGING PURPOSES ONLY.
  **************************************************************

  4x4 matrix keypad and a 20 x 4 LCD.
  A4988 Stepstick/Pololu driver

  Inspired by sketches written by bmac2 and tjwal;
  See here: http://www.homemodelenginemachinist.com/showthread.php?t=26744

  New sketch written by K. Quiggle 2019

      This sketch improves on the original in these ways:

      - movement is implemented with acceleration and deceleration
      - movement accuracy is improved by calculating moves using float variables before converting to int steps,
        so as to avoid cumulative rounding errors
      - an option is included for continuous rotation with varying speed settings
      - an option is included for arc movements (rotation between within a fixed angle)

  WARNING! : This may not be the most recent version of this program, and may have uncorrected errors.
            See the link below for more information and links to more recent versions (if any):

            https://sites.google.com/site/lagadoacademy/miscellaneous-projects/stepper-motor---accelstepper-h


            See this link for hardware details:

            https://sites.google.com/site/lagadoacademy/machining---lathes-mills-etc/build---electronic-indexing-head



  NOTES ON FIRST USE:

  1. You may need to change the address in the line  starting "LiquidCrystal_I2C lcd(0x3F,20,4)" to match the address of your display.
    If 0x3F doesnot work try 0x27 and vice-versa.

  2. The first time you use the sketch, use the Settings option to enter the appropriate settings for your indexer.
     Settings are stored in permanent memory, so you only need to do this once unless you change your hardware or
     decide to change a setting.

     Note that you can set the "clockwise" direction in settings. The defintion of clockwise is somewhat arbitrary as
     it depends on both your point of view and the dearing in your set-up. In any case, you can use this setting to
     set "clockwise" for your hardware.

  3.  You MUST set the backlash correction to either 0 (no correction) or to the correct value for your hardware. Any other
     setting will give erratic results when changing rotational direction.

  4.  On first use you should rotate a full rotation in the direction you plan to use your rotary table, so as to remove
     any initial backlash in the system and to establish the initial rotation direction.

  5.  Rotation directions are clockWise and counterClockWise - these are indicated on the display. If your table rotation
     does not match the display, reverse the values of these two variables in the program.

  Instructions:

  This program enables operation of a rotary index table in four modes:

  Mode 1: Index mode: Move the table in indexed steps
          - step size may be set either in degrees of number of sides (or gear teeth)

  Mode 2: Jog mode: Move the table in jog steps; that is, move the stepper motor in increments of 1, 10 or 100 steps.
          This mode is used to to set arc movement position, and to help determine backlash correction.

  Mode 3: Arc mode: Move the table in a defined arc, with back and forth movement between set positions.

  Mode 4: Continuous Mode: Move the table continuously until stopped.

  The program also enables backlash compensation. The amount of backlash must first be experimentally determined (see
  instructions); this can then be entered into the program settings. Backlash correction can be turned on or off
  as desired. When backlash correction is turned on, a ← back-arrow symbol is shown in the relevant displays.

  Program initialization:

     When the program is first started, the program version number is displayed, along with an option for "Initial rotation"
     in either the clockwise (CW) or counterclockwise (CCW) direction.

                        START-UP MENU
                    +--------------------+
                    |Rotary Table Control|
                    |V2-Rev.4.67  2019   |
                    |Initial rotation?   |
                    |#=EXIT   A=CW  B=CCW|
                    +--------------------+

             Note: IF YOUR ARE USING THE PROGRAM (OR AN UPDATE) FOR THE FIRST TIME, then use the #=EXIT key
             to move to the Main Menu and select D=Settings to enter your data. You can also use the #=EXIT key to
             just skip this step.

     If you have previously entered the program settings for your stepper motor and rotary table, then it is still advised to
     perform an initial rotation for two reasons:

       1. Remove any backlash from your system to establish a well defined start position
       2. Provide the program with a defined "direction of last move" (clockDir in the program); the
          program needs this information to make accurate moves. Otherwise the default setting is
          clockDir = CW

  MAIN MENU:

     The main menu looks like this:
        +--------------------+
        |1: Degrees  3: Sides|
        |4: Jog      6: Arc  |
        |7: Continuous       |
        |9: Settings         |
        +--------------------+

     The selection numbers are chosen so that the keypad position and the display position approximately correspond.

     The above keypad choices select the following:

     1: Enter the desired number of degrees per move. Move the rotary table the specified number of degrees
        with each move, in either CW or CCW direction.

     3: Enter the desired number of polygon sides or gear teeth; from this the required number of degrees per
        move will be calculated. Move the rotary table the calculated  number of degrees with each move,
        in either CW or CCW direction.

     4: Move the rotary table by motor steps in increments of 1, 10, or 100 steps in either the forward or reverse
        direction. This enables miving the rotary table to a specific position.

     6: Moving the rotary table back and forth in an arc, starting at the current position, and ending at a second
        position CW from the starting position. A sub-menu of this choice enables setting the second position either
        by specifying a number of degrees, or by jog moves.

     7: Move the rotary table continuously in either the CW or CCW direction. A sub-menu for this choice enables
        setting the motor speed and acceleration for this choice.

     9: This option enters the settings mode, which enables entering (and storing in permanent memory) the
        program settings explained below.


  PROGRAM SETTINGS:

     The first time you use the program, the required settings for your stepper motor and rotary table are undefined.
     The 9=Settings option enables you to enter the intial settings for your system, or to change the settings as
     needed. All settings entered will be stored in permanent memory, so you do not need to re-enter them if you turn
     off the program. You may change the initial settings at any time by using the Settings option again. The values
     stored by this option are as follows:

     1. The total number of full steps in a complete stepper motor rotation (typically 200, but other values are possible)
     2. The number of micro-steps per full step (as set on the stepper motor controller hardware)
     3. The rotary table gear ratio
     5. Backlash setting - On (use backlash compensation) or Off (do not compensate for backlash)
     6. Backlash compensation: The total number of micro-steps of backlash in the system (see BACKLASH CORRECTION below).
         Note: If backlash compensation is turned off you will not be asked for a backlash compensation value
     7. Beeper start setting - On or Off ; this is for an optional hardware beeper (see comments below). If a beeper is used
        and this is set on, then the controller will beep on start of a move.
     8. Beeper halt setting - On or Off ; this is for an optional hardware beeper (see comments below). If a beeper is used
        and this is set on, then the controller will beep on completion of a move, or to alert to the need for keypad entry.
     9. Maximum speed setting for the stepper motor. This will be different for every stepper motor and rotary table
        combination. See MAXIMUM SPEED and ACCELERATION below.
     10. Acceleration - how quickly the motor acclerates to maximum speed, and decelerates to a stop. See
        MAXIMUM SPEED and ACCELERATION below.
    10. Percent maximum speed - this setting enables the stepper motor to be run at some percentage of the full
        maximum speed. The percentage can be less that 100% or greater than 100%. This is used to quickly select
        different motor speeds when rotating continuously.
    11. Stop mode - the method for stopping continuous rotation. This is explained in more detail under Continuous
        Mode below.


  MAXIMUM SPEED and ACCELERATION:

     If you are using this program for the first time, or you have made hardware changes or changed the micro-stepping
     value, you should set the maximum motor speed and acceleration first. The easiest way to quickly determine
     good speed and acceleration values is to use the Continuous Mode, which has an option for setting these values
     (see more on this mode below).

     The maximum motor speed should be set to a "conservative" value that will prevent stalling or skipping. The
     maximum possible value found through experiment is 4000 (steps/sec), but your actual setting will be much
     less than this. My indexer uses the values below, but your vaues will likely be very different.

     Similarly, set acceleration to a value that will not cause your system to "lose position." Since this program
     receives no feedback on the actual physical positionof the rotary table, it assumes that the table moves one step
     for every step signal given; if for any reason the table fails to advance when a step signal is given then
     the table and program will be out of sync and table movements will no longer be accurate.

           Micro-     Max
           stepping   speed  Acceleration
           --------   -----  ------------
               1       850       200
               2      2500      1000

     The only way to determine the best values for speed and acceleration is by trial and error. Start with low values
     that work well, and then increase the values until the motor starts to stall, hesitate,or skip. Then set the
     values for actual use to numbers 10% or 20% below the stall values to allow a margin of safety. Because mass
     inertia is a big factor in these settings, the trial runs should be made with the rotary table PLUS a typical
     workpiece so that the "working load" of the table is taken into account.

            Per the AccelStepper documentation: "The fastest motor
            speed that can be reliably supported is about 4000 steps per second
            at a clock frequency of 16 MHz on Arduino such as Uno etc."

  BACKLASH CORRECTION:

     The procedure for determining backlash correction is as follows:

     1. Using Settings, turn backlash correction to OFF
     2. Put the Arduino into Degree Mode and set for 360 degrees.
     3. Advance the motor CCW one full turn.
     4. Mark the existing position of the rotary table. A good way to do this is to mount a laser pointer on the
        rotary table and shine the laser dot on a nearby surface; mark the position of the laser dot at the
        existing position (a black dot on a sticky-note works well for this).
     5. Move one full turn in the opposite direction (CW). You will see that the laser dot did not return to the
        marked position - this is the backlash error.
     5. Exit and switch to JogMode. Using Jog Mode rotate the table in CW direction until the spot returns to the
        original position. The total number of steps shown is the amount of required backlash compensation.
     6. Repeat the procedure several times to verify that the backlash compensation is accurate and repeatable.
     7. Use the Settings option to save the backlash compensation value.

  Note on settings: After setting maximum speed, acceleration, and backlash compensation, I recommend retesting
  your chosen values by rotating the indexer back and forth by 360 degrees using the laser pointer method to mark
  position. If you find that the pointer is off by a tiny amount, you may be missing steps. Try reducing the
  speed or accleration to see if this corrects the problem.Alternatively, you may beed to adjust the backlash by
  a step or two.


  PROGRAM MODES: This program enables rotary table movement in several different modes.
  -------------------------------------------------------------------------------------

  INDEX MODE: Degrees or Sides)

     This mode moves the rotary table in a pre-defined increment with each move, in either the CW or CCW direction.
     Backlash compensation may be switched on or off for this mode. After the increment is defiend the display will
     show the increment in degrees at the top-left of the display, and the totalnumber of degrees moved at the
     top-right of the display. Total degrees moved resets to 0 after a full rotation, so this number will always be
     between 0 and 360.

     The pre-defined move increments can be set in one of two ways:

     1. Degrees: Specify a number of degrees for each move. The number of degrees can be any positive number,
        including fractional degrees and 0 (0 will of course result in no movement).

     2. Sides (or teeth): Specify the number of sides of a polygon, or the number of teeth in a gear; the controller
        will calculate the required number of degrees per increment.

     Backlash compensation may be switched on or off for this mode.

     You must set backlash compensation ON for this mode, unless you make index steps in only one direction. Note
     also that (regardless of backlash setting) it is considered good practice to make index moves in only one
     direction for best machining accuracy.


  JOG MODE:

     Jog mode moves the stepper motor in increments of 1, 10, or 100 steps in either the CW or CCW direction. Backlash
     compensation may be switched on or off for this mode.

     You must set backlash compensation ON for this mode, unless you make jog steps in only one direction.


  ARC MODE:

     Arc mode moves back and forth between a start position and an end position. When arc mode is selected, the
     table position at that time is set as the start position, so you should move the table to the desired arc
     start position before selecting this mode. The suggested method is to first use degree mode to move the
     table to the approximate start position, and then use jog mode to fine tune the desired start position.

     Once arc mode has been selected, the end position can be set in a simlar manner:

     1. By degrees: Enter the number of degrees to rotate CW from the current position. When you enter degrees the
        table will rotate immediately to that position.

     2. Then move by jog steps (either CW or CCW) to fine tune the desired end position.

     To summarize:

          - use Degrees mode to move to approximate start position
          - use Jog mode to fine tune start position
          - enter Arc mode
          - use Degrees to set arc end position
          - if necessary, use Jog to fine tune end position

     Once the start and end positions have been set (these will show on the display), press the Go key to move in
     the defined arc; the display will show the direction of the next move. Each Go key press will move to the end
     of the arc and then stop; pressing the Go key again will move in reverse to the other end of the arc. Backlash
     compensation may be switched on or off for this mode.

     You must set backlash compensation ON for this mode, unless you make an arc move in only one direction.

  CONTINUOUS MODE:

     This mode moves the motor continuously in either the CW or CCW direction. Backlash compensation does NOT work
     in this mode, and the backlash compensation status is not shown in the display menu for this mode regardless
     of the setting.

     This mode includes an option for setting speed, acceleration, and stop mode. The LCD display for this mode
     looks like this:

               +--------------------+
               |CONTINUOUS [stopkey]|   [stopkey] indicates the current stop mode setting
               |sp= 80%=1840 ac=1000|   sp is the % of maximum speed setting, and the resulting speed,
               |C=settings    D=STOP|          acis the current acceleration setting
               |A=CW  B=CCW   #=EXIT|
               +--+-----------------+

     In this mode you can set the motor speed as a percentage of the maximum speed setting. This % setting applies only to
     continuous run mode. However, this setting is stored so if changed the changed value will be restored on
     the next program run. The sp setting can be any integer > 0,including numbers greater than 100%.

     Entering a % sp greater than 100% is useful when trying to determine the maximum useful motor speed. In this mode
     different acceleration and speed combinations can be tested relatively quickly. If you are using this option
     to help determine optimal maximum motor speed, then be sure to update that value in the Settings Mode. Note that
     the choice of stop mode affects the maximum speed value as explained below.

     Continuous running Stop Modes:

     The AccelStepper.h library used with this program does not have a built in method for accelerating to and then
     running at a set speed. In order to emulate this the continuous run mode simply defines a rotation end position
     as the highest possible number (so "continuous" is actually "continuous for several days" which is the same
     thing for practical use).

     The problem then becomes: How to stop continuous rotation on demand? The obvious method of waiting for a keypad
     keypress has the drawback that the keypad scan introduces a fairly large delay time which has the result of
     reducing the maximum usable run speed. The ideal solution might be to use an interrupt, but I have not yet been able
     to make this work. On an interim basis, this program instead provides three options for stopping continuous mode;
     these options are set and saved in Settings. The options are as follows:

     Option   Option
     Number   Type                Comments
     ======   =================  =======================================================================
       1      stopkey            Press a defined key on the keypad.
                                   - works reliably
                                   - stops with deceleration
                                   - limits maximum practical speed

       2*     detect key press   Detect a key press directly without scanning the entire keypad
                                   - works, but not reliably
                                       - may require several keypad presses to work; I get best results
                                         when I hold down the key for 1 second before releasing
                                   - stops with deceleration
                                   - does not limit maximum practical speed

       3      reset              Press the Arduino reset button to stop
                                   - works reliably
                                   - STOPS IMMEDIATELY - no deceleration
                                   - does not limit maximum practical speed
                                   - results in program restart


   * The key press detection is essentially treating a keypad key as a "button" which is not ideal from
     an electronic/hardware point of view, although it does (sort of) work.


   ====================================================================================================

   Comments about this program:

    - int variables start with a lower case letter
    - float variables starting with an Uppercase letter
    - you might see comments with "debug" in them; these are notes to myself to check or remove program code.
      You will likely find these in beta releases of the program, or I may have neglected to remove some of these.

   If using optional beeper:
    - Connect speaker or piezo buzzer to pin 13 and ground
    - Adjust frequency between 2000 - 5000 for desired tone by setting beepFrequency variable

   Possibility of overflow in step counting variables unlikely:

       When the stepper motor drives the rotary table through a complete rotation and then
       continues to rotate, the AccelStepper step count will continue to accumulate. In theory,
       if there are enough rotations the step count variable could overflow leading to program errors.
       However, consider this: Assume a "worst case scenario" of a 400 step stepper motor with
       microstepping set to 64, and a gear ratio of 40; then

           400 x 64 x 40 = 1,024,000

           The step count variable is an int long (max possible value 2,147,483,647; this means
           the table would have to rotate 2,147,483,647/1,024,000 ≈ 2,097 times and this is highly
           unlikely to happen in actual practice. Consequently, this program does no error checking
           for this possibility.

     Revision changes:

          Rev.4.60 - removed rounding in step calculations; this is already done by AccelStepper.h
                   - program settings are now all undefined on first use
                   - added option at start for an initial rotation to remove backlash and set logical direction
                   - modified moveToTarget to include backlash correction
                   - added backlash on/off indicator to display (back-arrow symbol)
                   - modifed display text for consistency

          Rev.4.61 - revise Jog Mode to use moveToTarget ("standard" move subroutine)
          Rev.4.63 - initial settings set to "conservative" values
                   - many menu changes to make menus more consistent
                   - menu changes to reduce levels of menus
                   - jog mode changes to make jog mode work with arc mode
                   - single subroutine used for motor movement in index, jog, and arc modes
          Rev.4.64 - added selectable options for continuous run stop method
                         - defined stop key
                         - detect key press
                         - reset
          Rev.4.65 - Settings now read from memory on every program start
                   - quick patch to prevent leftover bits from breaking stop mode setting
                   - fixed bugs in moving by Sides
          Rev.4.66 - fixed bug in Sides "Moving" display not clearing
                   - additional edits to introductory comments
                   - revised display for showing indexing moves (removed step count
                     and other changes to improve clarity)
          Rev.4.67 - removed unused "settings changed" stored variable
                   - added beep to end of settings
                   - removed old debug code
                   - added "Percent of max speed" to Settings (otherwise there is a random
                     value for first time users)
                   - fixed bug in Jog menu display
                   - improved continuous run menu to remove stop-key option in [reset] mode display
          Rev.4.68 - code refactoring to improve clarity of program flow and simplify code
                   - arc degree entry now shows 2 decimal places
                   - arc position entry changed:
                           - degrees and jog sum together instead of reset
                           - immediate move after degree entry to enable fine tuning of end position
                   - option added to continuous run menu to set speed, accelerations, and stop mode
                   - expanded beep options to independently choose beep on start and beep on halt
                   - updated explanatory comments above
          Rev.4.69 - fixed display bug in index move when number of degrees per move > 360
                   - revised code to prevent arc move when number of degrees entered = 0.0
          Rev.4.69B - relay control option added by VK
          Rev.4.70 - added option to reverse CW and CCW to match physical set-up
                   - added visual acknowledgement to start-up screen when direction is selected
          Rev.4.71 - added setting for "clockwise" direction
          Rev.4.72 - modified arc move selection so that movement does not occur after degree selection, but only
                     when GO is selected

         SW01
          /         +---+
   o----o/  o-------|24V|-----------+--------------------------------------------------------------------------------------------------------+
110V      /         |   |           |                                                                                                        |
   o----o/  o-------|   |---+       |                                                                                                        |
                    +---+   |       |                                                                                                        |
                           ___      |                                                       +-----------------+                          +-----------------+
                           || |     |                +-----------------+                    |              A0 |--------------------------| Ena             |
                                    |                | Step Down       |                    |ARDU          2  |--------------------------| step   Stepper  |
                                    |24V             |                 |5V                  |              3  |--------------------------| Dir    Driver   |
                                    +----------------|Input     output |--------------------|                 |                          +-----------------+
                                                     |                 |                    |                 |                          +-----------------+
                                                     |                 |                    |              4  |--------------------------| col1      k     |
                                                     +-----------------+                    |              5  |--------------------------| col2      e     |
                                                                                            |              6  |--------------------------| col3      y     |
                                                                                            |              7  |--------------------------| col4      b     |
                                                                    +---+                   |                 |                          |           o     |
                                                                    | B |-------------------|13            8  |--------------------------| row1      a     |
                                                                    | u |                   |              9  |--------------------------| row2      r     |
                                                                    | z |---+               |             10  |--------------------------| row3      d     |
                                                                    | z |   |               |             11  |--------------------------| row4            |
                                                                    | e |   |               |             12  |--------------------------| row5            |
                                                                    | r |   |               |                 |                          +-----------------+
                                                                    +---+   |               |   scl  sda      |
                                                                          __|_              +-----------------+         +-----------------+
                                                                         | | |                   |    |                 | Dislplay LCD    |
                                                                                                 |    +-----------------|                 |
                                                                                                 +----------------------| 4x16            |
                                                                                                                        |                 |
                                                                                                                        +-----------------+

   ==============================================================================================================================================
   ==============================================================================================================================================

*/

#include <AccelStepper.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <EEPROM.h>

String ProgramName = "Rotary Table Control";  // Name of this program
String VersionNumber = "V2-Rev4.72d  2022";   // The version Number of this program

// SET indicates a variable that will be stored in EEPROM if changed.
//     The variable settings below will be used unless changed via the
//     program Settings function.


int stepsPerFullRotation = 200;           // SET Number of *full* steps per full 360 degree rotation for your motor
int microStepping = 1;                    // SET microsteps per full step; 1,2,4,8,16,etc.
float TableRatio = 1.0;                   // SET TableRatio for indexer = 26.851239669 for my hardware
int backlash = 0;                         // SET Number of microsteps needed to cancel out backlash
boolean backlashOn = false;               // SET backlash correction is switched on (true) or off (false)
//                                               - set to 0 if no backlash correction is desired
boolean beepStart = false;                // SET beep on start of a move (true=ON, false=OFF)
boolean beepHalt  = false;                // SET beep on completion of a move (true=ON, false=OFF)
boolean start = 1;
boolean halt = 0;
byte beepPin = 13;                        // the pin to which the beeper is connected
int beepFrequency = 3800;                 // the beep audio frequency

float MicroStepsPerFullRotation = 0.0;     // actual value calculated when values saved/retrieved from EEPROM

//stepper motor settings
/* SET maximum stepper speed.
    Per the AccelStepper documentation: "The fastest motor
    speed that can be reliably supported is about 4000 steps per second
    at a clock frequency of 16 MHz on Arduino such as Uno etc.
*/
float StepperMaximumSpeed = 500.0;        // SET maximum allowed stepper speed
float StepperAcceleration = 100.0;        // SET acceleration rate for stepper motor
int percentMaxSpeed = 100;                // SET percentage of maximum speed to use for reduced speed setting
int continuousRunStopMode = 1;            // SET the method for stopping continuous running (see program comments above)
String stopMode[] = {"stopkey", "keypress", "reset" };  //Names of the stop modes
String prompt = "";

boolean flipRotation = false;             // Flag to reverse default roation direction
int clockWise = 1;                        // clockwise direction
int counterClockWise = -1;                // counter-clockwise direction
int clockDir = clockWise;                         // Direction of rotation initially set to clockWise
boolean stopFlag = false;                 // flag to show whether the stopKey was used to stop the motor

// Set up key pad
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'.', '0', '#', 'D'}
};
byte rowPINS[ROWS] = {11, 10, 9, 8};
byte colPINS[COLS] = {7, 6, 5, 4};
Keypad kpd = Keypad(makeKeymap(keys), rowPINS, colPINS, ROWS, COLS);

LiquidCrystal_I2C lcd(0x3F, 20, 4);   // set the LCD address to 0x20 for a 16 chars and 4 line display
//                                       some displays may use 0x3F for the address.
//                                       Connections: SCL->A5, SDA->A4, VCC->+5, Gnd->Gnd


// Relay control
byte relayPin = 12;				   // set pin 12 for relay
float RelayDelay = 2000;	       // waiting time (milliseconds) after when relay set on and before continue the program

// stepper motor
const int stp = 2;                // connect pin 2 to step
const int dir = 3;                // connect pin 3 to dir
// Define a stepper and the pins it will use
AccelStepper stepper(1, stp, dir);

float Degrees = 0.0;                       // Number of degrees in a move
float TotalDegrees = 0.0;                  // total Number of degrees moved
float StepsPerIncrementTheoretical = 0.0;  // Number of *theoretical* microsteps to move (can be a fractional Number)
float TotalStepsTheoretical = 0.0;         // Theoretical total Number of steps moved

long stepToMoveTo = 0;                     // Target step value for the next move
//                                            This information is needed for backlash correction. On initial start-up,
//                                            the clockDir is undefined.
char key = kpd.getKey();


//=====================================================================================================
//=====================================================================================================


void setup() {

  //debug Serial.begin( 9600 );
  //debug Serial.println("ready");

  getSettings();                 // Read the stored program settings

// Set physical rotation direction

      //clockWise                            // clockwise direction comes from getSettings
      counterClockWise = clockWise * -1;     // set counter-clockwise direction to reverse of clockWise
      clockDir = clockWise;                  // Direction of rotation initially set to clockWise


  pinMode(relayPin, OUTPUT);	   // Set relayPin mode to OUTPUT
  digitalWrite(relayPin, HIGH);  // Assumes active LOW relay board; set relay off before start of program

  lcd.init();        // initialize the lcd
  lcd.backlight();   // turn on backlight

  // Print welcome message and greeting menu to the LCD.
  lcd.setCursor(0, 0); lcd.print(ProgramName);
  lcd.setCursor(0, 1); lcd.print(VersionNumber);
  lcd.setCursor(0, 2); lcd.print("Initial rotation?");
  lcd.setCursor(0, 3); lcd.print("#=EXIT   A=CW  B=CCW");
  makeBeep(halt);

  stepperInitialize();     //reset stepper settings, steps and degrees to initial values
  choiceInitialize();           //select choice from greeting menu


} //end Setup

//=====================================================================================================
//=====================================================================================================

void loop() {

  stepperInitialize();     //reset stepper settings, steps and degrees to initial values
  mainMenu();              //display the main menu
  /*
    Main menu choice values are:

    key  value
    ---  -------------------------
     1   move by degrees
     3   move by sides or teeth
     4   jog move
     6   arc move
           end set degrees
           end set jog
     7   continuous move
     9   update settings
  */

  key = NO_KEY;        //clear exit from previous menu
  while (key != '#')   //select choice from main menu
  {
    key = kpd.getKey();
    switch (key)
    {
      case NO_KEY:
        break;

      case '1':                    //Move by degrees
        Degrees = updateNumber("Degrees per move", 0, 0);
        StepsPerIncrementTheoretical = Degrees / 360.0 * MicroStepsPerFullRotation;
        indexMove();
        key = '#';                //exit this loop
        break;

      case '3':                   //Move by sides
        Degrees = 360.0 / (float) updateNumber("Sides or Teeth", 0, 0);
        StepsPerIncrementTheoretical = Degrees / 360.0 * MicroStepsPerFullRotation;
        indexMove();
        key = '#';               //exit this loop
        break;

      case '4':                  //Jog move
        getJog();
        key = '#';               //exit this loop
        break;

      case '6':                 //Arc movement
        StepsPerIncrementTheoretical = 0.0;   //Initialize steps in arc move
        TotalStepsTheoretical = 0.0;          //Initialize steps in arc move
        choiceArc();
        key = '#';              //exit this loop
        break;

      case '7':                 //Continuous movement
        choiceContinuous();     //choose options for continuous running
        key = '#';              //exit this loop
        break;

      case '9':                 // Update Settings
        Settings();
        key = '#';              //exit this loop
        break;
    }
  } //end switchcase

} //end loop


//=====================================================================================================
//=====================================================================================================




/*  updateNumber gets a float value with the prompt string provided. If a new number is not
    entered then the current value of the float is returned.
    To  get an integer Number use

         int getNumber("prompt", float someinteger, 0);

    Screen display looks like this:

         +--------------------+
         | Provided prompt str|
         | Value =            |
         |                    |
         | #=ENTER     D=CLEAR|
         +--------------------+

*/
float updateNumber(String prompt, float FloatValue, int decPlaces)      //decPlaces is the number of decimal places to display
{
  float Num = 0.0;
  float Decimal = 0.0;
  float DecNum = 0.0;
  int counter = 0;
  lcd.clear();
  lcd.print(prompt);
  lcd.setCursor(0, 1); lcd.print("Value = ");

  lcd.print(FloatValue, decPlaces);

  lcd.setCursor(0, 3); lcd.print("#=EXIT       D=CLEAR");

  lcd.setCursor(8, 1);
  boolean decOffset = false;
  char key = kpd.getKey();

  while (key != '#')
  {
    switch (key)
    {
      case NO_KEY:
        break;

      case '.':
        if (!decOffset)
        {
          decOffset = true;                       //Set Decimal flag and print Decimal point (but not if already printed)
          lcd.print(key);
        }
        break;

      case 'D':                                   //Clear data entry and reset Decimal point flag
        Num = 0.0;
        lcd.setCursor(8, 1);
        lcd.print("            ");      //clear data field with spaces
        lcd.setCursor(8, 1);
        decOffset = false;
        break;

      case '0': case '1': case '2': case '3': case '4':
      case '5': case '6': case '7': case '8': case '9':

        if (Num == 0.0)                            //Clear data entry field if new entry
        {
          lcd.setCursor(8, 1);
          lcd.print("            ");      //clear data field with spaces
          lcd.setCursor(8, 1);
        }


        if (!decOffset)
        {
          Num = Num * 10.0 + (key - '0');
          lcd.print(key);
        }
        else if ((decOffset) && (counter <= 4))     //Counter Number = Number of Decimal places minus one
        {
          Num = Num * 10.0 + (key - '0');
          lcd.print(key);
          counter++;
        }
        break;
    }    //end switchcase
    DecNum = Num / pow(10, counter);
    key = kpd.getKey();
  }    //end while not #

  if (DecNum != 0) {
    return DecNum;        //return new number if one is entered
  }
  else
  {
    return FloatValue;   //return the original number if no change
  }
  return DecNum;
}  //end getNumber


// getBoolean toggles a yes/no or true/false and returns the result.
boolean getBoolean(String prompt, boolean flip)
{
  lcd.clear();
  lcd.home();
  lcd.print(prompt);
  lcd.setCursor(0, 1); lcd.print("Value = ");
  lcd.setCursor(8, 1); if (flip) {                   //If the beep setting is currently set to True
    lcd.print("ON/YES");
  } else {
    lcd.print("OFF/NO");
  }
  lcd.setCursor(0, 3); lcd.print("#=EXIT      D=Toggle");

  char key = kpd.getKey();

  while (key != '#')
  {

    switch (key)
    {
      case NO_KEY:
        break;

      case 'D':                                   // Toggle boolean value
        flip = !flip;
        lcd.setCursor(8, 1); if (flip) {
          lcd.print("ON/YES");
        } else {
          lcd.print("OFF/NO");
        }
        break;
    }  //end switchcase

    key = kpd.getKey();

  }  //end while
  return flip;
}  //end getBoolean



void mainMenu()         //The initial menu for the system
{
  lcd.clear();

  lcd.setCursor(0, 0);  lcd.print("1: Degrees  3: Sides");
  lcd.setCursor(0, 1);  lcd.print("4: Jog      6: Arc"  );
  lcd.setCursor(0, 2);  lcd.print("7: Continuous");
  lcd.setCursor(0, 3);  lcd.print("9: Settings"          );

} //end mainMenu



void choiceInitialize()   //select choice from greeting menu
{


  while (key != '#')
  {
    key = kpd.getKey();
    switch (key)
    {

      case NO_KEY:
        break;
      case 'A': //Move one full rotation CW
        {
          stepperInitialize();
          TotalStepsTheoretical = MicroStepsPerFullRotation;
          lcd.setCursor(0, 3);  lcd.print("  WAIT : Moving...  ");
          moveToTarget();
          lcd.setCursor(0, 3);  lcd.print("#=EXIT  A=CW   B=CCW");
          break;
        }
      case 'B': //Move one full rotation CCW
        {
          stepperInitialize();
          TotalStepsTheoretical = -MicroStepsPerFullRotation;
          moveToTarget();
          break;
        }

    }      // end case
  }      // end while choice != #
}  //end choiceInitialize



void jogMenu()         //Menu for jog entry - used for jog move and arc end setting by jog
{

  lcd.clear();
  lcd.setCursor(0, 0); lcd.print("JOG sum=");
  if (backlashOn) {
    lcd.print(char(127));
  };             //Include a back-arrow symbol if backlash is on

  //print the current steps and degrees totals
  lcd.setCursor(10, 0); lcd.print("          ");
  lcd.setCursor(10, 0); lcd.print(TotalStepsTheoretical, 0);
  /*                  */lcd.print(" "); lcd.print(TotalDegrees, 1); lcd.print((char)223);


  lcd.setCursor(0, 1);
  for (int i = 1; i < 4; i++)
  {
    lcd.print((float)i, 0); lcd.print("=+"); lcd.print((float)pow(10, i - 1), 0); lcd.print(" ");
  }

  lcd.setCursor(0, 2);
  for (int i = 4; i < 7; i++)
  {
    lcd.print((float)i, 0); lcd.print("=-"); lcd.print((float)pow(10, i - 4), 0); lcd.print(" ");
  }

  lcd.setCursor(0, 3); lcd.print("#=EXIT");

}



void getJog()                                      //Calculate jog movements
{

  jogMenu();                                       //display the jog menu

  char key = kpd.getKey();
  while (key != '#')
  {
    key = kpd.getKey();
    switch (key)
    {
      case NO_KEY: break;

      case '1': case '2': case '3':
        {
          StepsPerIncrementTheoretical = pow(10.0, (float)(key - '0') - 1.0);
          //clockWise factor set physical direction of rotation
          TotalStepsTheoretical = TotalStepsTheoretical + StepsPerIncrementTheoretical * clockWise;
          TotalDegrees = (TotalStepsTheoretical / MicroStepsPerFullRotation) * 360.0;
          lcd.setCursor(10, 0); lcd.print("          ");
          lcd.setCursor(10, 0); lcd.print(TotalStepsTheoretical, 0);
          /*                  */lcd.print(" "); lcd.print(TotalDegrees, 1); lcd.print((char)223);
          moveToTarget();
          break;
        }

      case '4': case '5': case '6':
        {
          StepsPerIncrementTheoretical = -(pow(10.0, (float)(key - '0') - 4.0));
          //clockWise factor set physical direction of rotation
          TotalStepsTheoretical = TotalStepsTheoretical + StepsPerIncrementTheoretical * clockWise;
          TotalDegrees = (TotalStepsTheoretical / MicroStepsPerFullRotation) * 360.0;

          lcd.setCursor(10, 0); lcd.print("          ");
          lcd.setCursor(10, 0); lcd.print(TotalStepsTheoretical, 0);
          /*                  */lcd.print(" "); lcd.print(TotalDegrees, 1); lcd.print((char)223);
          moveToTarget();
          break;
        }

      case '#':
        break;
    }
  } //end while
}  //end getJog


void continuousMenu()
{
  //LCD LINE 0
  lcd.clear();
  lcd.setCursor(0, 0); lcd.print("CONTINUOUS ["); lcd.print((String) stopMode[continuousRunStopMode]); lcd.print(']');

  //LCD LINE 1 - note extra spaces to clear data fields
  lcd.setCursor(0, 1);  lcd.print("sp= ");
  lcd.setCursor(3, 1);  lcd.print(float (percentMaxSpeed), 0); lcd.print("%=     ");
  lcd.setCursor(8, 1);  lcd.print( (percentMaxSpeed / 100.0) * StepperMaximumSpeed, 0);
  lcd.setCursor(13, 1); lcd.print("ac=    ");
  lcd.setCursor(16, 1); lcd.print(float (StepperAcceleration), 0);

  //LCD LINE 2
  lcd.setCursor(0, 2); lcd.print("C=settings          ");
  if (continuousRunStopMode < 2)                //If stop mode != reset then print stop-key option
  {
    lcd.setCursor(14, 2); lcd.print("D=STOP");
  }
  else
  {
    lcd.setCursor(13, 2); lcd.print(":reset:");
  }

  //LCD LINE 3
  lcd.setCursor(0, 3); lcd.print("A=CW  B=CCW         ");
  if (continuousRunStopMode < 2)                  //If stop mode != reset then print EXIT option
  {
    lcd.setCursor(14, 3); lcd.print("#=EXIT");
  }
  else
  {
    lcd.setCursor(13, 3); lcd.print(": STOP:");
  }
}

void choiceContinuous()
{
  continuousMenu();

  while (key != '#')    //select choice from continuousMenu
  {
    key = kpd.getKey();
    switch (key)
    {
      case NO_KEY:
        break;

      case 'A': //Move clockWise
        {
          //Reset the maximum stepper speed as a percentage of the stored maximum
          //StepperContinuousSpeed = (percentMaxSpeed / 100.0) * StepperMaximumSpeed;

          accelerateThenRun(StepperAcceleration, (percentMaxSpeed / 100.0) * StepperMaximumSpeed , clockWise, 'D');
          makeBeep(2);
          break;

        }
      case 'B': //Move counterClockWise
        {

          //Reset the maximum stepper speed as a percentage of the stored maximum
          //StepperContinuousSpeed = (percentMaxSpeed / 100.0) * StepperMaximumSpeed;

          accelerateThenRun(StepperAcceleration, (percentMaxSpeed / 100.0) * StepperMaximumSpeed , counterClockWise, 'D');
          makeBeep(2);
          break;
        }

      case 'C': //Set new percent of max speed
        {
          choiceSettingsContinuous();
          continuousMenu();
          key = NO_KEY;                       //clear # from settings menu
          break;
        }  //end case C


      case '#': //Exit
        {
          break;
        }


    }      // end case
  }      // end while choice != #
}  //end choiceContinuous()


//Sub-menu for settings in Continuous mode
void choiceSettingsContinuous()
{
  //Set percent of maximum speed
  percentMaxSpeed = updateNumber("% of max speed:", percentMaxSpeed, 0);

  //Set acceleration value
  StepperAcceleration = updateNumber("Acceleration rate:", StepperAcceleration, 0);

  //Set stop mode
  getStopMode();

  putSettings();                            //save the new values to permanent storage

} // end choiceSettingsContinuous


void arcMenu()
{
  lcd.clear();
  lcd.print("ARC Movement");
  if (backlashOn) {
    lcd.print(char(127));
  };             //Include a back-arrow symbol if backlash is on

  if (StepsPerIncrementTheoretical == 0.0  || TotalStepsTheoretical != 0.0)                  //show next rotation direction
  {
    lcd.setCursor(8, 1); lcd.print ("CW>>");
  }
  else
  {
  lcd.setCursor(8, 1); lcd.print ("<CCW");
  }

  lcd.setCursor(2, 1); lcd.print (0.0, 2); lcd.print((char)223); //print 0.0 start position
  lcd.setCursor(14, 1); lcd.print (TotalStepsTheoretical / MicroStepsPerFullRotation * 360.0, 2); lcd.print((char)223);                                                 //print value
  lcd.setCursor(0, 2); lcd.print ("end set: B=Deg C=Jog");
  lcd.setCursor(0, 3); lcd.print ("#=EXIT         A=GO");

}


void choiceArc()
{
  arcMenu();

  while (key != '#')    //select choice for arc move
  {
    key = kpd.getKey();
    switch (key)
    {
      case NO_KEY:
        break;

      case 'A': //Move back and forth in arc; current position is start position
        {
          if ( TotalStepsTheoretical != 0.0 )                          // If stepper is at start of arc
          {

            moveToTarget();                           //target is always TotalStepsTheoretical for moveToTarget
            StepsPerIncrementTheoretical = TotalStepsTheoretical;   //save current value of StepsPerIncrementTheoretical
            TotalStepsTheoretical = 0.0;
            lcd.setCursor(8, 1); lcd.print ("<CCW");              //Set direction for *next* move
          }
          else                                                    //else stepper is at start of arc
          {

            moveToTarget();                           //target is always TotalStepsTheoretical for moveToTarget
            TotalStepsTheoretical = StepsPerIncrementTheoretical;
            lcd.setCursor(8, 1); lcd.print ("CW>>");              // Set direction for *next* move
          }

          break;

        }
      case 'B': //Set arc end position by number of degrees
        {
          TotalDegrees = updateNumber("Degrees in arc/move", TotalDegrees, 2);

          //TotalStepsTheoretical is the position at the end of the arc
          TotalStepsTheoretical =  TotalDegrees / 360.0 * MicroStepsPerFullRotation;
          StepsPerIncrementTheoretical = TotalStepsTheoretical;   // save the current value of TotalStepsTheoretical
          arcMenu();

          break;
        }

      case 'C': //Set arc end position by jog moving rotary table to desired position
        {
          getJog();
          StepsPerIncrementTheoretical = TotalStepsTheoretical;   // (debug - need this?) save the current value of TotalStepsTheoretical
          arcMenu();
          break;
        } //end case C

      case '#': //Exit
        {
          break;
        }

    }      // end switchcase
  }      // end while != #
}  //end choiceArc()




void Settings()   //Get the basic settings for the stepper motor, gear reduction, etc.
//Display the current value for each setting
//If no new Number is entered, keep the current value
{


  //Change physical clock-wise rotation direction if desired

    flipRotation = false;   //Initialize flipRotation to FALSE.
    if ( clockWise == 1)
    {
      flipRotation = getBoolean("Reverse CW = >> ?", flipRotation);
    }
    else
    {
    flipRotation = getBoolean("Reverse CW = << ?", flipRotation);
    }

  if (flipRotation)
    {
    clockWise = clockWise * -1;                 // reverse clockwise direction
    counterClockWise = counterClockWise * -1;   // reverse counter-clockwise direction
    clockDir = clockWise;                       // re-initialize clockDir

    }


  //Get Number of steps per full revolution of the stepper motor
  String prompt = "Full steps in 360";
  prompt +=  char(223);               //degree symbol
  prompt += ":";
  stepsPerFullRotation = updateNumber(prompt, stepsPerFullRotation, 0);

  //Get the micro-stepping setting
  microStepping = updateNumber("Micro-stepping:", microStepping, 0);


  //Get the table (gear) ratio
  TableRatio = updateNumber("Table Gear Ratio:", TableRatio, 6);

  //Get the backlash correction
  //If a number is entered for backlash correction, it will be stored even if backlash correction is turned off.
  backlashOn = getBoolean("Fix backlash? ", backlashOn);
  if (backlashOn) // If backlash correction is switched on
  {
    backlash = updateNumber("Backlash amount:", backlash, 0);
  }

  //Set start beep on or off
  beepStart = getBoolean("Beep on start?", beepStart);

  //Set halt beep on or off
  beepHalt = getBoolean("Beep on stop?", beepHalt);

  //Get the maximum motor speed
  StepperMaximumSpeed = updateNumber("Max motor speed:", StepperMaximumSpeed, 0);

  //Get the motor acceleration
  StepperAcceleration = updateNumber("Acceleration rate:", StepperAcceleration, 0);

  //Get the % of maximum speed for continuous run
  percentMaxSpeed = updateNumber("% of max speed:", percentMaxSpeed, 0);

  //Set the delay before continue program after turning relay on
  RelayDelay = updateNumber("Delay for relay:", RelayDelay, 0);

  //Get the continuousRunStopMode
  getStopMode();

  putSettings();                         // Save the new settings to EEPROM
  makeBeep(halt);

}  //end settings


void getStopMode()
{
  lcd.clear();
  lcd.print("Continuous-stop mode");
  lcd.setCursor(0, 1); lcd.print("Mode =");
  lcd.setCursor(0, 3); lcd.print("#=EXIT      D=Toggle");


  int i = continuousRunStopMode;
  if (i < 0 || i > 2) {
    i = 0; //If stray bits are read from storage, default to a true value
  }


  lcd.setCursor(8, 1); lcd.print("            ");        //Print the current mode value
  lcd.setCursor(8, 1); lcd.print((String) stopMode[i]);

  key = NO_KEY;                 //Clear previous # keypress
  while (key != '#')
  {
    key = kpd.getKey();

    switch (key)
    {
      case 'D':
        {
          i = i + 1;              //Increment i, if > 2 start over at 0
          if (i > 2) {
            i = 0;
          }
          continuousRunStopMode = i;
          lcd.setCursor(8, 1); lcd.print("            ");
          lcd.setCursor(8, 1); lcd.print((String) stopMode[i]);
        }

      case '#':
        break;
    }
  }
}


// Relay control
// This is made for active LOW relay board. If you have a different setup then swap HIGH & LOW values
void relaySwitchedOn(boolean relayMode)
{
  if (relayMode)
  {
    digitalWrite(relayPin, LOW);  //Set relay on
  delay(RelayDelay);        //Waiting before continue program
  }
  else
  {
  delay(150);           //Small delay before set relay off
    digitalWrite(relayPin, HIGH); //Set relay off
  }
} // end relaySwitchedOn

void getSettings()
{
  EEPROM.get(0, stepsPerFullRotation);    // 2 byte int
  EEPROM.get(2, microStepping);           // 2 byte int
  EEPROM.get(4, TableRatio);              // 4 byte float
  EEPROM.get(8, backlash);                // 2 byte int
  EEPROM.get(10, backlashOn);             // 1 byte boolean
  EEPROM.get(11, beepStart);              // 1 byte boolean
  EEPROM.get(12, beepHalt);               // 1 byte boolean
  EEPROM.get(13, StepperMaximumSpeed);    // 4 byte float
  EEPROM.get(17, StepperAcceleration);    // 4 byte float
  EEPROM.get(21, percentMaxSpeed);        // 2 byte int
  EEPROM.get(23, continuousRunStopMode);  // 2 byte int
  EEPROM.get(25, RelayDelay);			        // 4 byte float
  EEPROM.get(29, clockWise);              // 2 byte int

  // Set counterClockwise to opposite of clockWise
  counterClockWise = clockWise * -1;

  // Set the total theoretical number of microsteps required for a full 360 degree revolution:

  // clockWise factor sets physical direction of rotation
  MicroStepsPerFullRotation = (float) stepsPerFullRotation * (float) microStepping * TableRatio * clockWise;

} //end getSettings

void putSettings()
{
  EEPROM.put(0, stepsPerFullRotation);        // 2 byte int
  EEPROM.put(2, microStepping);               // 2 byte int
  EEPROM.put(4, TableRatio);                  // 4 byte float
  EEPROM.put(8, backlash);                    // 2 byte int
  EEPROM.put(10, backlashOn);                 // 1 byte boolean
  EEPROM.put(11, beepStart);                  // 1 byte boolean
  EEPROM.put(12, beepHalt);                   // 1 byte boolean
  EEPROM.put(13, StepperMaximumSpeed);        // 4 byte float
  EEPROM.put(17, StepperAcceleration);        // 4 byte float - also changed/stored via choiceContinuous function
  EEPROM.put(21, percentMaxSpeed);            // 2 byte int - also changed/stored via choiceContinuous function
  EEPROM.put(23, continuousRunStopMode);      // 2 byte int
  EEPROM.put(25, RelayDelay);			            // 4 byte float
  EEPROM.put(29, clockWise);                  // 2 byte int



  // Re-calculate the MicroStepsPerFullRotation from the updated values
  MicroStepsPerFullRotation = (float) stepsPerFullRotation * (float) microStepping * TableRatio * clockWise;

}  //end putSettings

//Initialize the AccelStepper settings, and degree and step position variables
void stepperInitialize()
{
  // Initialize variables
  Degrees = 0.0;
  TotalDegrees = 0.0;
  stepToMoveTo = 0;                                         //Target position for stepper.moveTo()
  stepper.setCurrentPosition(0);                            // Set stepper current position and speed to zero
  TotalStepsTheoretical = 0.0;
  stepper.setMaxSpeed(StepperMaximumSpeed);
  stepper.setAcceleration(StepperAcceleration);
}


// indexMove calculates the theoretical step position and the end of the next move
void indexMove()
{
  lcd.clear();
  lcd.print("INDEXING =");

  if (backlashOn) {
    lcd.print(char(127));
  };             //Include a back-arrow symbol if backlash is on

  lcd.setCursor(11, 0); lcd.print(Degrees, 2); lcd.print((char)223);  //print degrees per index step



  lcd.setCursor(0, 1);   lcd.print("Position =");
  lcd.setCursor(11, 1); lcd.print(TotalDegrees, 2); lcd.print((char)223);   //print total degrees moved

  lcd.setCursor(0, 3); lcd.print("#=EXIT  A=CW   B=CCW");

  while (key != '#')   // # will return to start menu
  {
    key = kpd.getKey();

    if (key == 'A')           // MOVE CLOCKWISE
    {

      TotalDegrees  = TotalDegrees + Degrees;
      // When making a full rotation, restart count at 360 degrees
      TotalDegrees = ((TotalDegrees / 360.0) - int (TotalDegrees / 360.0)) * 360.0;

      TotalStepsTheoretical = TotalStepsTheoretical + StepsPerIncrementTheoretical;

      lcd.setCursor(6, 2); lcd.print("Moving");
      lcd.setCursor(11, 1); lcd.print("       ");                          // clear print field
      lcd.setCursor(11, 1);
      lcd.print(TotalDegrees, 2); lcd.print((char)223);

      moveToTarget();



      lcd.setCursor(6, 2); lcd.print("      ");

    }

    if (key == 'B')           // MOVE COUNTERCLOCKWISE
    {

      TotalDegrees  = TotalDegrees - Degrees;
      // When making a full rotation, restart count at 360 degrees
      TotalDegrees = ((TotalDegrees / 360.0) - int (TotalDegrees / 360.0)) * 360.0;
      TotalStepsTheoretical = TotalStepsTheoretical - StepsPerIncrementTheoretical;  // For reverse moves steps are negative

      lcd.setCursor(6, 2); lcd.print("Moving");
      lcd.setCursor(11, 1); lcd.print("       ");                          // clear print field
      lcd.setCursor(11, 1);
      lcd.print(TotalDegrees, 2); lcd.print((char)223);

      moveToTarget();

      lcd.setCursor(6, 2); lcd.print("      ");

    }
  }      // end while not # loop
}

// Update display and move to the a target step number; apply backlash correction if
// rotation has reversed and backlash correction is on. Backlash correction is applied
// by resetting the stepper.currentPosition by an amount equal to the backlash correction
void moveToTarget()
{
  relaySwitchedOn(true);		  //set relay on
  makeBeep(start);
  //Check to see if reversing direction
  //
  if (clockDir == clockWise && TotalStepsTheoretical < stepper.currentPosition() )              //change from CW to CCW?
  {
    stepper.setCurrentPosition( stepper.currentPosition() + (backlashOn *  backlash) );         //apply backlash correction
    clockDir = counterClockWise;
  }

  if (clockDir == counterClockWise && TotalStepsTheoretical > stepper.currentPosition() )  //change from CCW to CW?
  {
    stepper.setCurrentPosition( stepper.currentPosition() - (backlashOn *  backlash) );         //apply backlash correction
    clockDir = clockWise;
  }


  /* debug include this code to enable stopKey
    while ( stepper.isRunning() && kpd.getKey() != 'D') //loop until motor stops or stopKey is pressed
    {
    stepper.run();
    }

    if (stepper.speed() != 0.0) {
    stopFlag = true; //If stopKey was used set the stopFlag
    }
    stepper.stop();                                           //Reset target for deceleration and then stop
  */

  stepper.moveTo(TotalStepsTheoretical);                      //Set target position for move
  stepper.runToPosition();

  relaySwitchedOn(false);
  makeBeep(halt);
} //end moveToTarget


//*makeBeep beeps the specified number of times if the beeper function is switched on.
void makeBeep( int mode)
{
  if (mode == start && beepStart)                           //Beep at start if beep switched on
  {
    tone(beepPin, beepFrequency, 290);   //tone(pin,frequency,duration-milliseconds)
    delay(340);
  }
  if (mode == halt && beepHalt)                           //Beep at stop if beep switched on
  {
    tone(beepPin, beepFrequency, 290);   //tone(pin,frequency,duration-milliseconds)
    delay(340);
  }
}




/*Accelerate to designated speed and then continue running until key is pressed
         - if key is pressed then decelerate to a stop
         - if key pressed while decelerating then immediate stop

  The initial target position is the highest possible long int = 2,147,483,647

           Ignoring the acceleration phase, and assuming a highest possible speed of 4,000 steps/second
           this is

           2,147,483,647/4,000 = 536870 seconds or approx 6.2 days

           In other words, the motor will run "continuously" until the stop button is pushed, or stop by itself
           in 6.2 days (longer for lower maximum speeds). While this is not true continuous running, it should
           be a good compromise for rotary table use.

  acceleration = the acceleration rate in steps/sec/sec
  StepperMaximumSpeed = speed to accelerate to and then run at
  clockDir = direction of rotation  (CW=1, CCW=-1)
  stopKey = designated key to press to stop running

  When numsteps is negative rotation is reversed and speed becomes negative also; this is addressed
  by the clockDir variable.
*/
void accelerateThenRun(float acceleration, float StepperContinuousSpeed, int rotateDirection, char stopKey)
{
  makeBeep(start);
  switch (continuousRunStopMode)
  {
    case 0:    //stop with stopkey
	  relaySwitchedOn(true);
      stepper.setCurrentPosition(0);                            //Initialize position and speed to zero for next start
      stepper.move(long (rotateDirection * 2147483647));        //Set direction; set target position to number that will not be reached

      stepper.setMaxSpeed(rotateDirection * StepperContinuousSpeed);
      stepper.setAcceleration(acceleration);


      while ( kpd.getKey() != stopKey )             //Press stop key to stop acceleration phase

      {
        stepper.run();
      }

      //decelerate to a stop
      stepper.stop();                                           //Reset target for deceleration
      stepper.runToPosition();
      makeBeep(halt);
	  relaySwitchedOn(false);
      break;

    case 1:    //stop with detect key press

      //Variation Rev4.50b : Use a digital pin read to check for stop button in continuous run. You will need to hold the
      //  stop button down for 1 - 3 seconds. There is no immediate stop option, but there is deceleration to a stop.

      {
		relaySwitchedOn(true);
        stepper.setCurrentPosition(0);                            //Initialize position and speed to zero for next start
        stepper.move(long (rotateDirection * 2147483647));        //Set direction; set target position to number that will not be reached

        stepper.setMaxSpeed(rotateDirection * StepperContinuousSpeed);
        stepper.setAcceleration(acceleration);


        //while ( digitalRead(4) == HIGH )             //Press stop key to stop acceleration phase
        while ( PIND & 0b00010000)                     //Read pin 4 "directly" for fastest read

        {
          stepper.run();
        }

        //decelerate to a stop
        stepper.stop();                                           //Reset target for deceleration
        stepper.runToPosition();
        makeBeep(halt);
      }
	  relaySwitchedOn(false);
      break;

    case 2:    //stop with reset
	  relaySwitchedOn(true);
      stepper.setCurrentPosition(0);                            //Initialize position and speed to zero for next start
      stepper.move(long (rotateDirection * 2147483647));        //Set direction; set target position to number that will not be reached

      stepper.setMaxSpeed(rotateDirection * StepperContinuousSpeed);
      stepper.setAcceleration(acceleration);

      stepper.runToPosition();
      relaySwitchedOn(false);
      break;

  } //end switch case

}
