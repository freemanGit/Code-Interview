#include "stdafx.h"
#include <vector>

using namespace std;

class ElevatorStatus{
  public:
	  bool up;
	  bool down;
	  bool stand;
	  bool shutdown;
	  int current_persion;
};

class CustomerRequest{
  public:
	  int current_floor;
	  int request_floor;
};

class Customer{
   private:
       int entery_floor;
	   int request_floor;
   public:
	   Customer(int entery_floor, int request_floor);
	   CustomerRequest* setRequest();
	   void Out();
};

class Elevator{
  private:
	  int current_floor;
	  ElevatorStatus* status;
	  int max_weight;
	  int max_person;
  public:
	  vector<CustomerRequest* > requests;
	  vector<Customer* > customer;
	  Elevator();
	  void Run();

};

class ElevatorBank{
  private:
	  Elevator* elevator;

  public:
	  ElevatorBank();
	  void GetRequest(CustomerRequest *request);

};



void ElevatorBank::GetRequest(CustomerRequest* request)
{
	
	
}