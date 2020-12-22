#include <iostream>
#include <string>


struct Position {
    int GGA_time_hour;		
    int GGA_time_min;		
    double GGA_time_sec;	
    double longitude;		
    char lon_indicator;		
    double latitude;		
    char lat_indicator;		
	char cor_type;			//消息类型，1表示单点定位，4表示rtk固定解，5表示rtk浮点解
};

    void GGA_coordinate(Position &pos,std::string &gga_mes);
    void GGA_test(Position &pos);
