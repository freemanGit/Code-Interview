//http://www.codeproject.com/Articles/363338/Factory-Pattern-in-Cplusplus

class IFileFeedsManager  //abstract Interface class
{
public:
  virtual void GetDataRepository() = 0;
  virtual void FileFeeds() = 0;
};

class PritchettTruckingManager : public IFileFeedsManager
{
private:
   AnotherCustomerManager(){}//constructor
public:
   void GetDataRepository(){}//do something
   void FileFeeds(){}//do something
};
class AnotherCustomerManager : public IFileFeedsManager
{
private:
   AnotherCustomerManager(){}//constructor
public:
   void GetDataRepository(){}//do something
   void FileFeeds(){}//do something
};

class ManagerFactory
{
private:
   ManagerFactory();
   ManagerFactory(const ManagerFactory&) {}
   ManagerFactory &operator=(const ManagerFactory &){return *this;}
   
public:
   ~ManagerFactory(){}   
   
   void CreateFactory()
   {
       IFileFeedsManager *PritchettTruckingManager = new PritchettTruckingManager();
       ConcreateFactory(PritchettTruckingManager);
	   
	   IFileFeedsManager *AnotherCustomerManager = new AnotherCustomerManager();
	   ConcreateFactory(AnotherCustomerManager);
	   
   }
   
   void ConcreateFactory(IFileFeedsManager *customer)
   {
       customer->GetDataRepository();
       cusotmer->FileFeeds();
   }



}