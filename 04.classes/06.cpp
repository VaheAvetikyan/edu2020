/*
    6: Կեսօրին մոտ
    Գրել ծրագիր, որում իրակացված է Time դասը, որի օբյեկտներն իրենցից ներկայցնում են ժամանակը։ 
    Ժամանակը տրվում է ժամ (0-ից 23) և րոպե (0-ից 59) դաշտերով։ 
    Ծրագիրը մուտքում պետք է ստանա N ժամանակի մասին տեղեկություն՝ ժամ և րոպե, ապա պետք է արտածի կեսօրին ամենամոտ 2 ժամանակները։ 
    Սկզբում պետքէ արտածվի այն ժամը, որը օրվա ընթացքում գալիս է ավելի շուտ։
*/

#include <iostream>
#include <limits.h>

class Time
{
private:
    static const int HOURS = 24;
    static const int MINUTES = 60;
    int hour;
    int minute;

public:
    Time(int h, int m) : hour(h), minute(m)
    {
        if (h < 0)
        {
            hour = 0;
        }
        else if (h > HOURS - 1)
        {
            hour %= HOURS;
        }

        if (m < 0)
        {
            minute = 0;
        }
        else if (m > MINUTES - 1)
        {
            minute %= MINUTES;
        }
    }

    Time() : hour(0), minute(0) {}

    int getHour()
    {
        return hour;
    }

    int getMinute()
    {
        return minute;
    }

    int absMinutesToTime(Time time)
    {
        int minutes;
        int h = (hour - time.getHour()) % HOURS;
        if (h >= 0)
        {
            int m = (minute - time.getMinute()) % MINUTES;
            minutes = h * MINUTES + m;
        }
        else
        {
            int m = (minute - time.getMinute()) % MINUTES;
            minutes = std::abs(h) * MINUTES - m;
        }

        return minutes;
    }

    bool isEarlier(Time time)
    {
        if (hour > time.getHour() || (hour == time.getHour() && minute > time.getMinute()))
        {
            return false;
        }
        return true;
    }
};

int main()
{
    int n;
    std::cin >> n;
    Time *times[n];
    Time clock12 = Time(12, 0);

    int h, m;
    for (int i = 0; i < n; i++)
    {
        std::cin >> h >> m;
        times[i] = new Time(h, m);
    }

    Time *index[2];
    for (int i = 0; i < 2; i++)
    {
        index[i] = new Time(23, 59);
    }

    int minDistance = INT_MAX;
    int minDistance2 = INT_MAX;
    int currentDistance;
    for (int i = 0; i < n; i++)
    {
        currentDistance = times[i]->absMinutesToTime(clock12);
        if (currentDistance <= minDistance)
        {
            index[1] = index[0];
            index[0] = times[i];
            minDistance2 = minDistance;
            minDistance = currentDistance;
        }
        else if (currentDistance <= minDistance2)
        {
            index[1] = times[i];
            minDistance2 = currentDistance;
        }
    }

    if (index[1]->isEarlier(*index[0]))
    {
        Time *temp;
        temp = index[0];
        index[0] = index[1];
        index[1] = temp;
    }

    for (int i = 0; i < 2; i++)
    {
        std::cout << index[i]->getHour() << " " << index[i]->getMinute() << "\n";
    }

    // Delete allocated objects
    for (int i = 0; i < n; i++)
    {
        delete times[i];
    }

    // Delete allocated objects
    for (int i = 0; i < 2; i++)
    {
        delete index[i];
    }
}