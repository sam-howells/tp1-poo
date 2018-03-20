#include <iostream>
#include <iomanip>
using namespace std;
namespace{
    class Duree {
    private:
        unsigned long long myDuree;
        unsigned long long mySeconds;
        unsigned long long myMinutes;
        unsigned long long myHours;
        unsigned long long myDays;
        void Normaliser() noexcept;
    public:
        Duree (const unsigned & d=0) noexcept;
        unsigned getDuree() const noexcept;
        void display() const;
        void inc(const unsigned long long & delta) noexcept;
        void dec(const unsigned long long & delta) noexcept;

        unsigned long long getMyHours() const;
        void setMyHours(unsigned long long value);
    }; //Duree
    unsigned long long Duree::getMyHours() const
    {
        return myHours;
    }

    void Duree::setMyHours(unsigned long long value)
{
myHours = value;
}

void Duree::Normaliser() noexcept
    {
        myDays = myDuree / (60*60*24);
        myHours = (myDuree - myDays *60*60*24) / (60*60);
        myMinutes = (myDuree - (myDays*60*60*24) - (myHours *60*60)) / 60;
        mySeconds = myDuree - (myDays*60*60*24) - (myHours *60*60) - (myMinutes * 60);
    }

    Duree::Duree(const unsigned & myDuree_) noexcept :
        myDuree(myDuree_) {
        Normaliser();
    }

    unsigned Duree::getDuree() const noexcept
    {
        return myDuree;
    }

    void Duree::display() const
    {
        cout<< setw(4) << myDays << "jour(s)"
            << setw(4) << myHours << "heure(s)"
            << setw(4) << myMinutes << "minute(s)"
            << setw(4) << mySeconds << "seconde(s)" <<endl;
    }

    void Duree::inc(const unsigned long long &delta) noexcept
    {
        myDuree+= delta;
        Normaliser();
    }

    void Duree::dec(const unsigned long long &delta) noexcept
    {
        if (delta > myDuree ) return;
        myDuree -= delta;
        Normaliser();
    }
}


int main()
{
    Duree D(8705000);
    D.display();
    D.dec(1000);
    D.display();

    return 0;
}


