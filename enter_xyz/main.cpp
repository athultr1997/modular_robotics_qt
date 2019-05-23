#include <QApplication>

#include "enter_xyz.h"

int main(int argc, char *argv[])
{
	QApplication app(argc,argv);
	EnterXYZ enter_xyz;
	enter_xyz.show();
	return app.exec();
}