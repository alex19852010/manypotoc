#include <iostream>
#include <thread>
#include <mutex>
#include <vector>



using namespace std;

mutex mtx;


vector<pair<string, double>> result;

void info(string name, double val)
{
    double distance = 0;
    while (distance < 100)
    {
        this_thread::sleep_for(chrono::seconds(1));
        mtx.lock();
        distance += val;
        if(distance > 100)
        {
            distance = 100;
        }
        cout << name << " swim " << distance << " m" << endl;
        mtx.unlock();
    }

     mtx.lock();
    result.push_back(make_pair(name, distance / val));
     mtx.unlock();
}




int main()
{
  string swimmer1 = "swimmer_1";
  double time1 = 3;
  string swimmer2 = "swimmer_2";
  double time2 = 7;
  string swimmer3 = "swimmer_3";
  double time3 = 5;
  string swimmer4 = "swimmer_4";
  double time4 = 8;
  string swimmer5 = "swimmer_5";
  double time5 = 4;
  string swimmer6 = "swimmer_6";
  double time6 = 6;

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


    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i].first << " took " << i + 1 << " place with a time of " << result[i].second << " seconds" << endl;
    }


  
 return 0;
}