/*
    7: Ամենաուշ ժամ
    Գրել ծրագիր, որում իրակացված է TimeS դասը, որի օբյեկտներն իրնեցից ներկայացնում են ժամանակը։ 
    Ժամանակը տրվում է ժամ (0-ից 23), րոպե (0-ից 59) և վայրկյան (0-ից 59) դաշտերով։ 
    Ծրագիրը մուտքում պետք է ստանա N ժամանակի մասին տեղեկություն՝ ժամ, րոպե և վայրկյան, ապա պետք է արտածի օրվա ամենաուշ պահը։ 
*/

#include <iostream>

class Time
{
private:
    static const int HOURS = 24;
    static const int MINUTES = 60;
    static const int SECONDS = 60;
    int hour;
    int minute;
    int second;

public:
    Time(int h, int m, int s) : hour(h), minute(m), second(s)
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

        if (s < 0)
        {
            second = 0;
        }
        else if (s > SECONDS - 1)
        {
            second %= SECONDS;
        }
    }

    Time() : hour(0), minute(0), second(0) {}

    int getHour()
    {
        return hour;
    }

    int getMinute()
    {
        return minute;
    }

    int getSecond()
    {
        return second;
    }

    bool isEarlier(Time time)
    {
        if (hour > time.getHour())
        {
            return false;
        }
        else if (hour == time.getHour() && minute > time.getMinute())
        {
            return false;
        }
        else if (hour == time.getHour() && minute == time.getMinute() && second > time.getSecond())
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

    int h, m, s;
    for (int i = 0; i < n; i++)
    {
        std::cin >> h >> m >> s;
        times[i] = new Time(h, m, s);
    }

    Time *latestTime = new Time(0, 0, 0);
    Time *referenceTODelete = latestTime;
    for (int i = 0; i < n; i++)
    {
        if (latestTime->isEarlier(*times[i]))
        {
            latestTime = times[i];
        }
    }

    std::cout << latestTime->getHour() << " " << latestTime->getMinute() << " " << latestTime->getSecond() << "\n";

    // Delete allocated objects
    for (int i = 0; i < n; i++)
    {
        delete times[i];
    }
    delete referenceTODelete;
}