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
				s_minstance = new SinglePieceMode;
				if (NULL == s_minstance)
				{
					return NULL;					//创建失败
				}
			}
			return  s_minstance;
		}
		
	int m_i;
};
SinglePieceMode * SinglePieceMode::s_minstance = NULL;


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

