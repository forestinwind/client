#include "memberboxwidget.h"
#include "groupmemberlist.h"
#include "ui_memberboxwidget.h"
#include "..\shared\shared.h"

memberBoxWidget::memberBoxWidget(QString init, QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::memberBoxWidget)
{
    ui->setupUi(this);

    level =divide(init).toInt();
    UID = divide(init).toInt();
    par = dynamic_cast<groupMemberlist*>(parent);

    qDebug() << "this"<<UID << par;
    userName = divide(init, DIV_CMD);
    QString temp = divide(init, DIV_CMD);
    QByteArray tempArray = QByteArray::fromBase64(decrypt(temp).toLocal8Bit());
    signStr = divide(init, DIV_CMD);
    QPixmap thisPixmap;

    thisPixmap.loadFromData(tempArray);
    ui->head->setPixmap(thisPixmap);

    ui->namelabel->setText(userName);
    ui->signlabel->setText(signStr);
}

memberBoxWidget::~memberBoxWidget()//我delete的是item，为什么这个也delete了？
{
    QListWidgetItem* self = par->IDtoItem.value(UID);
    qDebug() <<"self" << self;
//    qDebug() << "pro"<<UID<<self<<par->row(self);
//    par->takeItem(par->row(self));// 为什么不行？
    par->IDtoItem.remove(UID);
    par->IDtoBox.remove(UID);
    par->itemToID.remove(self);
    par->itemParMap.remove(self);
    par->itemShowMap.remove(self);
 //   delete self;
    delete ui;
}
