#include <iostream>
using namespace std;
class outer{
	private:
		int count;
	public:
		void getCount()
		{
			cout<<"Count="<<count;
			count++;
		}
	class inner
	{
		public:
			void getFromInner()
			{
				cout<<"Count in inner="<<outer::count;	
			}	
	};
};

int main()
{
//	static outer::count=0;
	outer o;
	o.getCount();
	outer::inner in;
	in.getFromInner();
	return 0;
}
