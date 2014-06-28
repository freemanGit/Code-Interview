#include "stdafx.h"
#include <mutex>

class SingletonExample 
{
  private:
	  static SingletonExample* _instance;
	  static std::mutex mtx;

  public:
	  SingletonExample();
	  ~SingletonExample();
	  SingletonExample(const SingletonExample &rhs);  //copy constructor
	  SingletonExample& operator=(const SingletonExample &rhs);  //assignment operator

	  static SingletonExample* GetInstance()
	  {
		  if (!_instance)
		  {
			  std::unique_lock<std::mutex> locker(mtx);
			  //locker.lock();
			  if (!_instance)
			     _instance = new SingletonExample();
			  //locker.unlock();
		  }
		  return _instance;
	  }

	  bool SomeFunc()
	  {
		  return true;
	  }
};


SingletonExample* SingletonExample::_instance = NULL;
//SingletonExample::GetInstance()->SomeFunc();
