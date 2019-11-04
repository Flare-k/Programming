#include "Application.h"


/*====================================================================================
// Function	: default constructor, Initialize member variables.
// Pre		: None
// Post		: None
=====================================================================================*/
Application::Application()
{
	m_NewNode = NULL;
}

/*====================================================================================
// Function	: default destructor,
// Pre		: None
// Post		: None
=====================================================================================*/
Application::~Application()
{
}

/*====================================================================================
// Function	: Program driver
// Pre		: none
// Post		: none
=====================================================================================*/
void Application::Run()
{
	List gObj;
	int ex = 1, tmp;
	while(ex)
	{
		system("cls");
		m_NewNode = NULL;

		switch(tmp = GetCommand())
		{
		case 0:
			ex = 0;
			break;
		case 1:
			//?? 과제 : 원에 대한 정보를 입력받게 하시오.
			//?? assignment : read in a data for a circle
			m_NewNode = new CircleNode();
			m_NewNode->draw();

			break;
		case 2:
			//?? 과제 : 사각형에 대한 정보를 입력받게 하시오.
			//?? assignment : read in a data for a rectangle
			m_NewNode = new RectangleNode();
			m_NewNode->draw();

			break;
		case 3:
			//?? 과제 : 다각형에 대한 정보를 입력받게 하시오.
			//?? assignment : read in a data for a polygon
			m_NewNode = new PolygonNode();
			m_NewNode->draw();

			break;
		case 4:
			gObj.drawAll();

			break;
		default:
			cout << " Invalid Command. Try Again \n";
		}

		if (m_NewNode != NULL)
		{
			m_NewNode->draw();
			gObj.Attach(m_NewNode);
		}

		system("pause");
	}
}

/*====================================================================================
// Function: Display command on screen and get a input from keyboard
// Pre: 
// Post : get command number.
=====================================================================================*/
int Application::GetCommand()
{
	int cmmd;
	cout << "\n << Graphic Object 입력(draw)와 출력(display)  >>\n";
	cout << "     1: Circle Draw       \n";
	cout << "     2: Rectangle Draw   \n";
	cout << "     3: Polygon Draw   \n";
	cout << "     4: Display All    \n";
	cout << "     0: Quit          \n";
	cin >> cmmd;

	return cmmd;
}