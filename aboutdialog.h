/*!
 * \class AboutDialog aboutdialog.h
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

#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>

namespace Ui {
    class AboutDialog;
}

class AboutDialog : public QDialog
{
    Q_OBJECT

public:

    /*! \brief Constructor.
     *
     * Construct and initialise the data in the About Window Class.
     * \param parent Parent widget/object for the thread.
     */
    explicit AboutDialog(QWidget *parent = 0);

    /*! \brief Destructor.
     *
     * Clean up any memory usage and destroy the class.
     */
    ~AboutDialog();

private:

    /*! \brief About Dialog widget information.
     *
     * Contains all of the information/widgets needed to created the dialog.
     * This information is stored in AboutDialog.ui and is auto-generated by Qt.
     */
    Ui::AboutDialog *ui;
};

#endif // ABOUTDIALOG_H
