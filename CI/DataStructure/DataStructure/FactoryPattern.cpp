#include "stdafx.h"
#include <unordered_map>

using namespace std;

class IProduct{
   virtual void Func1() = 0;
   virtual void Func2() = 0;
};

class CreateFactory{
    private:
		static CreateFactory* instance;
		unordered_map<int, Product*> product_table;
    public:
		Product* CreateProduct(int id)
		{
			auto it = product_table.find(id);
			if( it != product_table.end())
				return it->second;
			else
				return NULL;
		}

		static CreateFactory* GetInstance()
		{
			if (!instance)
				instance = new CreateFactory;
			return instance;
		}

		void RegisterProduct(int id, Product* prod)
		{

		}

};

class ConcreateProd1 : public Product{
    private:
		int id;

    public:
	  Func1 () {}
	  Func2 () {}
};
