#include "myQueue.h"

int main()
{
	MyQueue qHead;

	//³õÊ¼»¯
	initQueue(&qHead);

	cout << "Èë¶Ó:";
	enQueue(&qHead, 1);
	enQueue(&qHead, 2);
	enQueue(&qHead, 3);
	enQueue(&qHead, 4);
	enQueue(&qHead, 5);
	printQueueData(&qHead);

	cout << "³ö¶Ó:";
	delQueue(&qHead);
	printQueueData(&qHead);

	getQueueFrontData(&qHead);

	getQueueRearData(&qHead);
	system("pause");
	return 0;
}

