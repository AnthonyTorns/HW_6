/*
Create struct to store data of each airline caller
take in amount of calls from user input
create struct arrauy of arline custormers
for(....){
  take in data for each element of struct array
  if(status of customer is none ) change status to regular
  }
  create for poointers to class Dlist of type airline customer struct
  -one for each status level
  int x & y used to index positions and count the ticks
  int work_time holds the amount of ticks a worker is busy
  Simulate:
  while x is less than the latest  time of the last call or worker is busy a or four pointers to list are empty{
      while customer time element is equal to the current time{ 
        out put the current tick line and store all customer structs from customer array into their repective list
      }
    increment position of airline customer array 
  }
  if(worker is not busy){
    begin to answer calls based on hierarchy of staus level and whether the list of given status level is empty
  }
  increment time 
  de-increment working time of worker
  }
  destrooy pointers
*/

#include <iostream>
#include "dlist.h"
struct airline{
  unsigned int time = 0;
  std::string name = "";
  std::string status = "";
  unsigned int duration;
};
int main() {
  unsigned int calls = 0;
  std::cin>>calls;
  airline customers[calls];
  for (int i = 0; i < calls; i++) {
     std::cin>>customers[i].time;
     std::cin>>customers[i].name;
     std::cin>>customers[i].status;
    if (customers[i].status == "none") {
      customers[i].status = "regular";
    }
     std::cin>>customers[i].duration;
  }
  airline current;
  Dlist<airline>* plat = new Dlist<airline>;
  Dlist<airline>* gold = new Dlist<airline>;
  Dlist<airline>* silv = new Dlist<airline>;
  Dlist<airline>* reg = new Dlist<airline>;
  unsigned int x = 0;
  unsigned int y = 0;

  unsigned int work_time = 0;
  std::cout<<"Starting tick #"<<x<<std::endl;
  while (x <= customers[calls-1].time || work_time > 0 || !plat->IsEmpty() ||!gold->IsEmpty() || !silv->IsEmpty() || !reg->IsEmpty()) {
    while (customers[y].time == x) {
        std::cout<<"Call from "<<customers[y].name<<" a "<<customers[y].status<<" member\n";
        if (customers[y].status == "platinum") {
          plat->InsertBack(customers[y]);
        }
        else if (customers[y].status == "gold") {
          gold->InsertBack(customers[y]);
        }

        else if (customers[y].status == "silver") {
          silv->InsertBack(customers[y]);
        }
        else if (customers[y].status == "regular") {
          reg->InsertBack(customers[y]);
        }
        y++;
    }
      
        if(work_time <= 0) {
          if (!plat->IsEmpty()) {
            current = plat->RemoveFront();
            work_time = current.duration;
            std::cout<<"Answering call from "<<current.name<<std::endl;
          }
          else if (!gold->IsEmpty()) {
            current = gold->RemoveFront();
            work_time = current.duration;
            std::cout<<"Answering call from "<<current.name<<std::endl;
          }
          else if (!silv->IsEmpty()) {
            current = silv->RemoveFront();
            work_time = current.duration;
            std::cout<<"Answering call from "<<current.name<<std::endl;
          }
          else if (!reg->IsEmpty()) {
            current = reg->RemoveFront();
            work_time = current.duration;
            std::cout<<"Answering call from "<<current.name<<std::endl;
          }
        }
        x++;
        if (work_time > 0) {
            work_time--;
        }
        std::cout<<"Starting tick #"<<x<<std::endl;
    }
  plat->~Dlist();
  gold->~Dlist();
  silv->~Dlist();
  reg->~Dlist();
  delete plat;
  delete gold;
  delete silv;
  delete reg;
  
  
  return 0;
}