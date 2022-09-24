#ifndef DOCWINDOWIK_H
#define DOCWINDOWIK_H
#include <QTextEdit>

class DocWindowIK: public QTextEdit
{
    Q_OBJECT
private:
    QString m_strFileName;

public:
    DocWindowIK(QWidget* pwgt = 0);
signals:
    void changeWindowTitle(const QString&);
public slots:
    void slotLoad();
    void slotSave();
    void slotSaveAs();
};

#endif // DOCWINDOWIK_H
