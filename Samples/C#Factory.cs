    interface IFileFeedsManager
    {
        void GetDataRepository();
        void FileFeeds();
		//..other tasks
    }
	
    public class PritchettTruckingManager : IFileFeedsManager
    {
        public PritchettTruckingManager(){}//constructor

        public void GetDataRepository(){}//do something

        public void FileFeeds(){}//do something
    }	
	public class AnotherCustomerManager : IFileFeedsManager
    {
        public AnotherCustomerManager(){}//constructor

        public void GetDataRepository(){}//do something

        public void FileFeeds(){}//do something
    }	
	
	public class ManagerFactory
    {
        public void CreateFactory()
        {
            ConcreateFactory(new PritchettTruckingManager());  
            ConcreateFactory(new AnotherCustomerManager());
        }

        private void ConcreateFactory(IFileFeedsManager Customer)
        {
            try
            {
                Customer.GetDataRepository();
                Customer.FileFeeds();
            }
            catch (Exception e)
            {
                Program.Log.Error(String.Format(@"Cannot Process Customer {0}: {1}", Customer.GetType().FullName, e));
            }
        }

    }
	
	