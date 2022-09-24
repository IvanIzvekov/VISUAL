#ifndef SDIPROGRAMIK_H
#define SDIPROGRAMIK_H

#include <QMainWindow>
#include<QtWidgets>
#include"docwindowik.h"
#include "sdiprogramik.h"//Возможно надо удалить

namespace Ui {
class SDIProgramIK;
}

class SDIProgramIK : public QMainWindow
{
    Q_OBJECT

public:


    SDIProgramIK(QWidget *pwgt = 0): QMainWindow(pwgt){
        QMenu* pmnuFile = new QMenu("&File");
        QMenu* pmnuHelp = new QMenu("&Help");
        DocWindowIK* pdoc = new DocWindowIK;

        pmnuFile->addAction("&Open...",
                            pdoc,
                            SLOT(slotLoad()),
                            QKeySequence("CTRL+O")
                            );
        pmnuFile->addAction("&Save...",
                            pdoc,
                            SLOT(slotSave()),
                            QKeySequence("CTRL+S")
                            );
        pmnuFile->addAction("&SaveASS...",
                            pdoc,
                            SLOT(slotSaveAs()),
                            QKeySequence("CTRL+A")
                            );
        pmnuHelp->addAction("&About...",
                            this,
                            SLOT(slotAbout()),
                            QKeySequence("Qt::Key_F1")
                            );
    menuBar()->addMenu(pmnuFile);
    menuBar()->addMenu(pmnuHelp);

    setCentralWidget(pdoc);

    connect(pdoc,
            SIGNAL(changeWindowTitle(const QString&)),
            SLOT(slotChangeWindowTitle(const QString&))
            );

    statusBar()->showMessage("Ready",2000);
    }
public slots:
    void slotAbout()
    {
        QMessageBox::about(this, "Application", "SDI Example");
    }
    void slotChangeWindowTitle(const QString& str){
        setWindowTitle(str);
    }
private:
    Ui::SDIProgramIK *ui;
};

#endif // SDIPROGRAMIK_H
