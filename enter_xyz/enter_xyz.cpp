/**
 * @file enter_xyz.cpp
 * @brief File contatining implementation of Class EnterXYZ
 * @author Athul Thaliyachira Reji
 * @date 22 May 2019
 */
#include <QtWidgets>
#include "enter_xyz.h" /**< For EnterXYZ class */

EnterXYZ::EnterXYZ(QWidget *parent) : QWidget(parent)
{
	// Creating QLabel to display text
	QLabel *x_label = new QLabel("X:");
	QLabel *y_label = new QLabel("Y:");
	QLabel *z_label = new QLabel("Z:");

	// Setting the initial value of BL to be (0,0,0)
	BL.push_back(0.0); 
	BL.push_back(0.0); 
	BL.push_back(0.0); 

	// Initializing objects
	TSL_x_input = new QLineEdit();
	TSL_y_input = new QLineEdit();
	TSL_z_input = new QLineEdit();

	QDoubleValidator *double_validator = new QDoubleValidator(-1000.0,1000.0,6);
	TSL_x_input->setValidator(double_validator);
	TSL_y_input->setValidator(double_validator);
	TSL_z_input->setValidator(double_validator);

	enter_button = new QPushButton("ENTER");

	connect(enter_button,SIGNAL(released()),this,SLOT(send_XYZ()));

	QGridLayout *mainLayout = new QGridLayout;
	mainLayout->addWidget(x_label,0, 0);
	mainLayout->addWidget(TSL_x_input,0, 1);
	mainLayout->addWidget(y_label,0, 2);
	mainLayout->addWidget(TSL_y_input,0, 3);
	mainLayout->addWidget(z_label,0, 4);
	mainLayout->addWidget(TSL_z_input,0, 5);
	mainLayout->addWidget(enter_button,0, 6);
	setLayout(mainLayout);
}

void EnterXYZ::send_XYZ()
{
	double x = TSL_x_input->text().toDouble();
	double y = TSL_y_input->text().toDouble();
	double z = TSL_z_input->text().toDouble();

	printf("Entered TSL:(%f,%f,%f)\n",x,y,z);
	TSLs.push_back({x,y,z});

	TSL_x_input->clear();
	TSL_y_input->clear();
	TSL_z_input->clear();
}