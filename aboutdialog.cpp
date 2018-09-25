/*!
 * \class AboutDialog aboutdialog.cpp
 * \version 1.00
 * \date 06.05.2011
 * \author Hari Leschner <hari@h9l.net>
 *
 * \par Copyright:
 * See COPYING file that comes with this distribution.
 *
 * \brief About GUI Class.
 *
 * QT interface class used to create About Window.
 */

#include "aboutdialog.h"
#include "ui_aboutdialog.h"
#include "app_types.h"

/*! \brief Constructor.
 *
 * Construct and initialise the data in the About Window Class.
 * \param parent Parent widget/object for the thread.
 */

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);

    QFont dlgFont = font();

    int pointSize = dlgFont.pointSize();
    if( pointSize == -1 )
    {
            pointSize = dlgFont.pixelSize();
    }


    QString buildDate = QString::fromLocal8Bit(BUILDDATE);
    QString buildTime = QString::fromLocal8Bit(BUILDTIME);

    QString smallFontSize = QString::number(pointSize);
    QString largeFontSize = QString::number(pointSize + 2);

    QString aboutText;
    aboutText +=
            "<html>"
                    "<head>"
                            "<meta name=\"qrichtext\" content=\"1\" />"
                    "</head>"
                    "<body style=\" white-space: pre-wrap; font-family:" + dlgFont.family() +
                    "; font-size:" + smallFontSize + "pt; font-weight:400; font-style:normal; text-decoration:none;\">"
                            "<p style=\" -qt-block-indent:0; text-indent:0px; font-size:" + largeFontSize + "pt; font-weight:600;\">"
                                    "<span>"
                                            + tr(PROGRAM_NAME) +
                                            "<br>" "<br>"
                                    "</span>"
                                    "<span style=\" font-size:" + smallFontSize + "pt; font-weight:400;\">"
                                            "Build: <b>" + tr(PROGRAM_VERSION) + "</b> on " + buildDate + " at " + buildTime +
                                            "<br>"
                                            "Based on: " + tr(GUI_PROGRAM_NAME) +
                      /*                      "<br>"
                                            "USB Lib: " + tr(LIB_VERSION) +
                                            "<br>"
                                            "QWT Lib: " + tr(QWT_IDENT) +
                     */
                                            "<br>" "<br>"
                                    "</span>"
                                    "<span style=\" font-size:" + smallFontSize + "pt;\">"
                                            + tr(COPYRIGHT) +
                                            "<br>" "<br>"
                                    "</span>"
                                    "<span style=\" font-size:" + smallFontSize + "pt; font-weight:400;\">"
                                    "More details under: <a href=\" http://www.h9l.net\">http://www.h9l.net </a>"
                                    "<br><br>"
                                    "The program is provided AS IS with NO WARRANTY OF ANY KIND, <br>"
                                    "INCLUDING THE WARRANTY OF DESIGN, MERCHANTABILITY AND <br>"
                                    "FITNESS FOR A PARTICULAR PURPOSE.<br>"
                                    "</span>"
                            "</p>"
                      /*      "<br />"
                            "<p style=\" -qt-block-indent:0; text-indent:0px;\">"
                                    "Using:"
                            "</p>"
                            "<p style=\" -qt-block-indent:0; text-indent:0px; font-size:" + largeFontSize + "pt; font-weight:600\">"
                                    "<span>"
                                            + tr(GUI_PROGRAM_NAME) + " " + tr(GUI_PROGRAM_VERSION) +
                                    "</span>"
                                    "<span style=\" font-size:" + smallFontSize + "pt; font-weight:400;\">"
                                            + " (" + tr(GUI_VERSION_DATE) + ")" +
                                            "<br />"R
                                    "</span>"
                                    "<span style=\" font-size:" + smallFontSize + "pt;\">"
                                            + tr(GUI_COPYRIGHT) +
                                    "</span>"
                            "</p>"
                       */
                    "</body>"
            "</html>";

    ui->AboutLabel->setText(aboutText);

    setWindowTitle ( tr("About..."));
}

/*! \brief Destructor.
 *
 * Clean up any memory usage and destroy the class.
 */
AboutDialog::~AboutDialog()
{
    delete ui;
}
