#include <iostream>
#include <sstream>

enum switches
{
    LIGHTS_INSIDE = 1,
    LIGHTS_OUTSIDE = 2,
    HEATERS = 4,
    WATER_PIPE_HEATING = 8,
    CONDITIONER = 16
};


void checkIf(float outT , float inT , std::string move , std::string light, int &switches_state , int time)
{
    if (outT<0)
    {
        if (!(switches_state & WATER_PIPE_HEATING))
        {
            std::cout << "The water supply heating system is turned on." << std::endl;
            switches_state|=WATER_PIPE_HEATING;
        }
    }
    if (outT>5)
    {
        if (switches_state & WATER_PIPE_HEATING)
        {
            std::cout << "The water supply heating system is turned off." << std::endl;
            switches_state&=~WATER_PIPE_HEATING;
        }
    }
    if ( ( time > 16 ) || ( time < 5 ) )
    {
        if (move=="yes")
        {
            if (!(switches_state & LIGHTS_OUTSIDE))
            {
                std::cout << "The street light is on." << std::endl;
                switches_state|=LIGHTS_OUTSIDE;
            }
        }
        else
        {
            std::cout << "The lights on the street are turned off." << std::endl;
            if (switches_state & LIGHTS_OUTSIDE) switches_state&=~LIGHTS_OUTSIDE;
        }
    }
    else
    {
        if (switches_state & LIGHTS_OUTSIDE)
        {
            std::cout << "The lights on the street are turned off." << std::endl;
            switches_state&=~LIGHTS_OUTSIDE;
        }
    }
    if (inT<22)
    {
        if (!(switches_state & HEATERS))
        {
            std::cout << "Heating is on." << std::endl;
            switches_state|=HEATERS;
        }
    }
    if (inT>=25)
    {
        if (switches_state & HEATERS)
        {
            std::cout << "Heating is off." << std::endl;
            switches_state&=~HEATERS;
        }
    }
    if (inT>=30)
    {
        if (!(switches_state & CONDITIONER))
        {
            std::cout << "Conditioning is on." << std::endl;
            switches_state|=CONDITIONER;
        }
    }
    if (inT<=25)
    {
        if (switches_state & CONDITIONER)
        {
            std::cout << "Conditioning is off." << std::endl;
            switches_state&=~CONDITIONER;
        }
    }
    if (light=="on")
    {
        if (!(switches_state & LIGHTS_INSIDE))
        {
            std::cout << "Lights in the house are on." << std::endl;
            switches_state|=LIGHTS_INSIDE;
        }
        if ((time>=0) && (time<=16)) std::cout << "Color temperature: 5000K" << std::endl;
        else if ((time>=20) && (time<24)) std::cout << "Color temperature: 2700K" << std::endl;
        else std::cout << "Color temperature: " << (time-20)*575+2300 << std::endl;
    }
    else
    {
        if (switches_state & LIGHTS_INSIDE)
        {
            std::cout << "Lights in the house are off." << std::endl;
            switches_state&=~LIGHTS_INSIDE;
        }
    }
}


int main()
{

    std::stringstream str;
    std::string text;
    float outTemperature;
    float inTemperature;
    std::string move;
    std::string light;
    int switches_state(0);


    for (int i(0) ; i<48 ; i++)
    {
        std::cout << "Now is the time:" << (i%24) <<std::endl;
        std::cout << "Enter all sensor and light readings (outside temperature , inside temperature, is there movement outside(yes/no), is the light on in the house(on/off) ):" << std::endl;
        std::getline(std::cin,text);
        str << text;
        str >>  outTemperature >>  inTemperature >>  move >>  light ;
        checkIf(outTemperature,inTemperature,move,light,switches_state,i);
    }


    return 0;
}
