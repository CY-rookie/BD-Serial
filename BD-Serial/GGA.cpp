#include "libserial/GGA.h"
//#include <string>

void GGA_coordinate(Position &pos, std::string &gga_mes)
{
    std::string gga_head;    //消息头
    std::string gga_time_hour;   //GGA消息中的时间字符串
    std::string gga_time_min;   //GGA消息中的时间字符串
    std::string gga_time_sec;   //GGA消息中的时间字符串
    std::string gga_lon_int;    //GGA消息中的经度整数部分字符串
    std::string gga_lon_dec;    //GGA消息中的经度小数部分字符串
    std::string gga_lat_int;    //GGA消息中的纬度整数部分字符串
    std::string gga_lat_dec;    //GGA消息中的纬度小数部分字符串
    //$GPGGA,020319.00,3030.73261017,N,11424.43641499,E,1,08,3.3,38.
    //275,M,-12.665,M,,*78
    
    gga_head = gga_mes.substr(1,5);
    
    if(gga_head == "GPGGA" && gga_mes.size() >30)
    {
        for(int i=0;i<2;i++)
            gga_time_hour[i]=gga_mes[7+i];
        for(int i=0;i<2;i++)
            gga_time_min[i]=gga_mes[9+i];
        for(int i=0;i<5;i++)
            gga_time_sec[i]=gga_mes[11+i];
        for(int i=0;i<2;i++)
            gga_lat_int[i]=gga_mes[17+i];
        for(int i=0;i<11;i++)
            gga_lat_dec[i]=gga_mes[19+i];
        for(int i=0;i<3;i++)
            gga_lon_int[i]=gga_mes[33+i];
        for(int i=0;i<11;i++)
            gga_lon_dec[i]=gga_mes[36+i];
        pos.lon_indicator=gga_mes[31];
        pos.lat_indicator=gga_mes[48];
		pos.cor_type = gga_mes[50];
        pos.GGA_time_hour=stoi(gga_time_hour);
        pos.GGA_time_min=stoi(gga_time_min);
        pos.GGA_time_sec=stod(gga_time_sec);

        pos.longitude=stoi(gga_lon_int)+stod(gga_lon_dec)/60.0;
        pos.latitude=stoi(gga_lat_int)+stod(gga_lat_dec)/60.0;
        
        std::cout << pos.GGA_time_hour << ":" << pos.GGA_time_min << ":" << pos.GGA_time_sec << std::endl ;
        std::cout << "精度为：" << pos.lon_indicator << pos.longitude << std::endl ;
        std::cout << "纬度为：" << pos.lat_indicator << pos.latitude << std::endl ;
    }
}

//测试坐标数据显示是否正常的函数，主要用于在GGA消息中坐标小数位数改变时用来调整GGA_coordinate()中的数组偏置
void GGA_test(Position &pos)
{
    std::string aab="$GPGGA,020319.25,4230.73261017,N,10024.43641499,E,1,08,3.3,38.275,M,-12.665,M,,*78";
    GGA_coordinate(pos, aab);
}
