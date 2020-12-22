/**
 *  @example example_project.cpp
 */

#include "libserial/SerialPort.h"
#include "libserial/SerialStream.h"
#include "libserial/GGA.h"
#include <iostream>
//#include <string>
int main()
{
    using LibSerial::SerialStream ;

    // You can instantiate a Serial Port or a Serial Stream object, whichever you'd prefer to work with.
    // For this example, we will demonstrate by using both types of objects.
    SerialStream serial_stream ;

    // Open hardware serial ports using the Open() method.
    serial_stream.Open( "/dev/ttyUSB0" ) ;

    // Set the baud rates.
    using LibSerial::BaudRate ;
    serial_stream.SetBaudRate( BaudRate::BAUD_19200 ) ;

    std::string buff;
    Position posi;
    //GGA_test(posi);
    //GGA_coordinate(posi, aab);
   
    // With SerialStream objects you can read/write to the port using iostream operators.
    serial_stream << "$JSHOW\r\n" ;


    while(1)
    {
        serial_stream >> buff ;
        std::cout << buff << std::endl ;
        GGA_coordinate(posi,buff) ;
    }

    serial_stream.Close() ;

}
