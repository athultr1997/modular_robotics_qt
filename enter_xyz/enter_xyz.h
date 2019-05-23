/**
 * @class EnterXYZ
 * @file enter_xyz.h
 * @brief Header file contatining definition of Class EnterXYZ
 * @author Athul Thaliyachira Reji
 * @date 22 May 2019
 * @version $Revision: 1.0$
 */
#ifndef ENTER_XYZ
#define ENTER_XYZ

#include <QWidget> /**< For QLineEdit and EnterXYZ */
#include <vector> /**< For using vectors */

class QLineEdit; /**< For entering coordinates */
class QPushButton; /**< For enter button */

/**
 * @brief Class for representing a Qt widget for entering the x, y, and z coordinates
 * @bug Check if the input are numbers else highlight in red
 * @bug Output area for showing status and messages
 * @bug Output area for showing status and messages
 */

class EnterXYZ : public QWidget
{
	Q_OBJECT; /**< EnterXYZ is derived from QObject. */

	public:
		/**
		 * @brief Contructor for EnterXYZ
		 * @param parent Pointer to QWidget type object for QWidget's constructor. 
		 *               Defaulted to nullptr.
		 * @return void
		 * 
		 */
		EnterXYZ(QWidget *parent = 0);

	private Q_SLOTS:
		/**
		 * @brief slot for storing/displaying the entered x,y,z values
		 * @return void
		 * Sends x,y,z coordinates to the currently active interactive marker.
		 * Stores the entered x,y,z coordinate values in EnterXYZ::TSLs and EnterXYZ::BL
		 */
		void send_XYZ();
		// void clear();

	private:
		std::vector<std::vector<double> > TSLs; /**< Data structure to store all the 
													 Task-Space-Locations entered by 
													 the user so far. */
		std::vector<double> BL; /**< Data structure to store the Base-Location (BL).*/

		QPushButton *enter_button; /**< Button for confirming the entry of TSL and BL. */

		QLineEdit *TSL_x_input; /**< Text editor for entering x-coordinate of TSL. */
		QLineEdit *TSL_y_input; /**< Text editor for entering y-coordinate of TSL. */
		QLineEdit *TSL_z_input; /**< Text editor for entering z-coordinate of TSL. */

		double x_max; /** Set from the reconstructed workspace's max x-coordinate + something */
		double y_max;
		double z_max;

};

#endif