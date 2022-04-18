#include <opencv/highgui.h>
int main()
{

	IplImage * img = cvLoadImage("3.png");
	cvShowImage("week09", img);
	cvWaitKey(0);

}
