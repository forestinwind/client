#ifndef MEMBERBOXWIDGET_H
#define MEMBERBOXWIDGET_H

#include <QWidget>

namespace Ui {
class memberBoxWidget;
}
class groupMemberlist;
class memberBoxWidget : public QWidget
{
    Q_OBJECT

public:
    explicit memberBoxWidget(QString,QWidget *parent = nullptr);
    ~memberBoxWidget();
    qint32 UID;
    qint32 level;

private:
    Ui::memberBoxWidget *ui;
    QString userName;
    QString signStr;
    groupMemberlist* par;
};

#endif // MEMBERBOXWIDGET_H
