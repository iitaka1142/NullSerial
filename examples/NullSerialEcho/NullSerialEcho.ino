/**
 * \brief NullSerialEcho, example of NullSerial use
 * \author Takahiro Ii<iitaka1142@gmail.com>
 * \data 2021
 *
 * Copyright (c) 2021 Takahiro Ii all right reserved.
 * 
 * This file is part of NullSerial.
 *
 * NullSerial is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * NullSerial is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with NullSerial.  If not, see <https://www.gnu.org/licenses/>.
 * 
 * https://github.com/iitaka1142/NullSerial/
 *
 */

/**
 * This example sketch shows how to use NullSerial.
 *
 * comment/uncommnet lines below DEBUG and VERBOSE and how the messages change
 */
#define DEBUG
//#define VERBOSE

#if defined(DEBUG)
# define SerialDebug   SERIAL_PORT_MONITOR
# define SerialVerbose SERIAL_PORT_MONITOR
#elif defined(VERBOSE)
# include "NullSerial.h"
# define SerialDebug   NullSerial
# define SerialVerbose SERIAL_PORT_MONITOR
#else
# include "NullSerial.h"
# define SerialDebug   NullSerial
# define SerialVerbose NullSerial
#endif

static bool isStringComplete;
static String inString;

void setup() {
  isStringComplete = false;
  inString.reserve(128);

  SERIAL_PORT_MONITOR.begin(9600);
  while (!Serial) {
    delay(1);
  }

  SerialDebug.print(__func__);
  SerialVerbose.print(F(" Serial Echo "));
  SERIAL_PORT_MONITOR.print("> ");
}

void loop() {
  if (isStringComplete) {
    SERIAL_PORT_MONITOR.print(inString);
    inString = "";
    isStringComplete = false;

    SerialVerbose.println(F("--- wait for next String ---"));
  }
}

void serialEvent() {
  for ( auto c = SERIAL_PORT_MONITOR.read(); c >= 0; c = Serial.read()) {
    auto inChar = (char)c;
    inString += inChar;

    // only for debugging.
    if ( inChar == '\r') SerialDebug.print("[CR]");
    if ( inChar == '\n') SerialDebug.print("[LF]");
    // verbose echo back
    SerialVerbose.print(inChar);

    if (inChar == '\r') {
      isStringComplete = true;
      SerialDebug.println(F("isStringComplete == true by [CR]"));
    }
    else if (inChar == '\n') {
      isStringComplete = true;
      SerialDebug.println(F("isStringComplete == true by [LF]"));
    }
  }

  return;
}
