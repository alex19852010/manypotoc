#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;

void info(string name, int val)
{
    
    int distance = 0;
    while(distance < 100)
    {
       
       this_thread :: sleep_for(chrono :: seconds(1));
       mtx.lock();
       distance += val;
       cout << name << ": " << distance << endl;
       mtx.unlock();
    }
   
}



int main()
{
  string swimmer1 = "swimmer_1";
  int time1 = 3;
  string swimmer2 = "swimmer_2";
  int time2 = 4;
  string swimmer3 = "swimmer_3";
  int time3 = 5;
  string swimmer4 = "swimmer_4";
  int time4 = 6;
  string swimmer5 = "swimmer_5";
  int time5 = 7;
  string swimmer6 = "swimmer_6";
  int time6 = 8;

  thread t1 (info, swimmer1, time1);
  thread t2 (info, swimmer2, time2);
  thread t3 (info, swimmer3, time3);
  thread t4 (info, swimmer4, time4);
  thread t5 (info, swimmer5, time5);
  thread t6 (info, swimmer6, time6);

  t1.join();
  t2.join();
  t3.join();
  t4.join();
  t5.join();
  t6.join();
  
 return 0;
}