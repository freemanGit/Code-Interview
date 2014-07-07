#include <iostream>
using namespace std;

//<class_type>& operator=(const class_type& rhs)
//copy constructor
class CPoint3d
{
private:
	int m_x;
	int m_y;
	int m_z;
	
public:
	CPoint3d()  //constructor 1
	{
		m_x = 0;
		m_y = 0;
		m_z = 0;
	}
	
	CPoint3d(int px, int py, int pz) //constructor 2
	{
		m_x = px;
		m_y	= py;
		m_z = pz;
	}
	
	void Print(char *name)
	{
		cout << name <<endl;  //print char* string: cout << char*_string_name
		cout<<"X :" <<m_x <<endl;
		cout<<"Y :" <<m_y <<endl;
		cout<<"Z :" <<m_z <<endl;
		cout<<endl;
	}
	
	//assignment operator =
	//copy between two objects
	CPoint3d& operator=(const CPoint3d& rhs)
	{
		//this check removes the overhead of self-assignment!!
		if (this == &rhs) 
			return *this;
		else {
			m_x = rhs.m_x;
			m_y = rhs.m_y;
			m_z = rhs.m_z;
			return *this;
		}
	}
	
	//copy between object and value
	//convert int to CPoint3d type
	CPoint3d& operator=(const int& all)
	{
		m_x = m_y = m_z = all;
		return *this;
	}
};

//test class 
int main()
{
	CPoint3d p1(10,20,30);
	CPoint3d p2 = p1;
	p1.Print("P1");
	p2.Print("p2");
	
	
	CPoint3d *pt3 = new CPoint3d(11,12,13);
	pt3 = pt3;
	pt3->Print("pt3");
	
	
	CPoint3d p4;
	p4 = 7;
	p4.Print("p4");
	
	CPoint3d *p5 = new CPoint3d;
	*p5 = 17; //!! p5 = 17 invalid conversion from ‘int’ to ‘CPoint3d*’
	p5->Print("p5");
	
	return 0;
}

