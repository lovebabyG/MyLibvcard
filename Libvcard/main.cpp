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

    QString fileName("../test.vcf");

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
        vCard vcard = vcards.takeFirst();
        vCardProperty name_prop = vcard.property(VC_TELEPHONE);
        QString value = name_prop.value();
        qDebug() << "Telephone: " << value;
    }

    return 0;
}
