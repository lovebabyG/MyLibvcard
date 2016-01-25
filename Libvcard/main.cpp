#include <iostream>
#include <QFile>
#include <QtCore/QDebug>

#include "/home/yoctoadm/Workspace/MyLibvcard/Libvcard/include/vcard/vcard.h"
#include "/home/yoctoadm/Workspace/MyLibvcard/Libvcard/include/vcard/vcardproperty.h"

int main(int argc, char *argv[])
{
    vCard vcard;

    vCardPropertyList vcardList;

    vCardProperty name_prop1 = vCardProperty::createName("Philipp", "Lahm");
    vcardList.append(name_prop1);
    vcard.addProperties(vcardList);



    QByteArray output = vcard.toByteArray();

    QFile file("/home/yoctoadm/Workspace/MyLibvcard/test.vcf");
    file.open(QIODevice::WriteOnly);
    file.write(output);
    file.close();

//    vcard.saveToFile("/home/yoctoadm/Workspace/LibVcardTest/test.vcf");

    return 0;
}
