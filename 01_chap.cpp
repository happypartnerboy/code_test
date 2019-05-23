#include <iostream>
using namespace std;

class SinglePieceMode
{
	
	private:
		SinglePieceMode()		//声明为私有成员变量,这样在类外就不能创建
		{
			m_i = 4;
		}
	public:
		static SinglePieceMode * s_minstance ;
		static SinglePieceMode * CreateSinglePieceMode()
		{
			if ( NULL == s_minstance)
			{
				sm_instance = new SinglePieceMode;
				if (NULL == sm_instance)
				{
					return NULL;					//创建失败
				}
			}
			return  sm_instance;
		}
		
	int m_i;
};
SinglePieceMode * SinglePieceMode::sm_instance = NULL;


int main()
{
	SinglePieceMode * psingtest = NULL;    //用来测试单例模式
	psingtest = SinglePieceMode::CreateSinglePieceMode();	//调用静态成员函数
	if( NULL == psingtest)
	{
		return -1;
	}	
	cout << psingtest->m_i << endl;	
}

