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
	char cor_type;			//��Ϣ���ͣ�1��ʾ���㶨λ��4��ʾrtk�̶��⣬5��ʾrtk�����
};

    void GGA_coordinate(Position &pos,std::string &gga_mes);
    void GGA_test(Position &pos);
