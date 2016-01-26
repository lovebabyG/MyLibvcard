#include <QFile>
#include <QtCore/QDebug>

#include "include/vcard/vcard.h"
#include "include/vcard/vcardproperty.h"

int main(int argc, char *argv[])
{
//    vCard vcard;

//    vCardPropertyList vcardList;

//    vCardProperty name_prop = vCardProperty::createName("Philipp", "Lahm");
//    vCardProperty tel_pro = vCardProperty::createTelephone("123456789");
//    vcardList.append(name_prop);
//    vcardList.append(tel_pro);
//    vcard.addProperties(vcardList);

//    QByteArray output = vcard.toByteArray();

//    QFile file("../test.vcf");
//    file.open(QIODevice::WriteOnly);
//    file.write(output);
//    file.close();

//   vcard.saveToFile("../test.vcf");

//    QString fileName("../test.vcf");

    QString fileName("../TestVcards/mch.vcf");
    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Error by opening file";
        return 0;
    }

    QByteArray in = file.readAll();

    // Now we can parse it...
    QList<vCard> vcards = vCard::fromByteArray(in);

    // and then we can use it.
    if (!vcards.isEmpty())
    {
        int i=0;
        for (QList<vCard>::iterator iter = vcards.begin(); iter != vcards.end(); ++iter)
        {
            qDebug()<<"i =" << i;
            vCardProperty vCardProp = iter->property(VC_TELEPHONE);
            QString value = vCardProp.value();

            qDebug() << "Phone number value = :" << value;

            QList<vCardParam> vCardparamList = vCardProp.params();
            int j = 0;
            for (QList<vCardParam>::iterator iter1 = vCardparamList.begin(); iter1 != vCardparamList.end(); ++iter1)
            {
                qDebug()<<"    j =" << j;
                qDebug() << "    Param groups: " << iter1->group();
                qDebug() << "    Param Value: " << iter1->value();
                ++j;
            }

            int k= 0;

            vCardProp = iter->property(VC_CALLDATETIME);
            value = vCardProp.value();
            qDebug() << "Call date value = :" << value;

            vCardparamList = vCardProp.params();
            for (QList<vCardParam>::iterator iter1 = vCardparamList.begin(); iter1 != vCardparamList.end(); ++iter1)
            {
                qDebug()<<"    k =" << k;
                qDebug() << "    Param groups: " << iter1->group();
                qDebug() << "    Param Value: " << iter1->value();
                ++k;
            }

            ++i;
        }

    return 0;
}
