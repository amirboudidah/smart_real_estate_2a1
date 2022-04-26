#include "arduinorfid.h"
Arduinorfid::Arduinorfid()
{
    data="";
    arduino_port_name="";
    arduino_is_available=false;
    serial=new QSerialPort;
}

QString Arduinorfid::getarduinorfid_port_name()
{
    return arduino_port_name;
}

QSerialPort *Arduinorfid::getserial()
{
   return serial;
}
int Arduinorfid::connect_arduinorfid()
{   // recherche du port sur lequel la carte arduino identifée par  arduino_uno_vendor_id
    // est connectée

    foreach (const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts()){
        qDebug() << "new " << serial_port_info.productIdentifier() << serial_port_info.vendorIdentifier() << serial_port_info.portName();
        qDebug() << "hasVID" << serial_port_info.hasVendorIdentifier() << "hasPID" << serial_port_info.hasProductIdentifier();
           if(serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier()){
               if(serial_port_info.vendorIdentifier() == arduino_uno_vendor_id && serial_port_info.productIdentifier()
                       == arduino_uno_producy_id) {
                   qDebug() << "arduino Available";
                   arduino_is_available = true;
                   arduino_port_name=serial_port_info.portName();
               } } }
        qDebug() << "arduino_port_name is :" << arduino_port_name;
        if(arduino_is_available){ // configuration de la communication ( débit...)
            qDebug()<<"dkhal";
            serial->setPortName(arduino_port_name);
//            qDebug()<<serial->open(QSerialPort::ReadWrite);
            if(serial->open(QSerialPort::ReadWrite)){
                qDebug()<<"dkhal2";
                serial->setBaudRate(QSerialPort::Baud115200); // débit : 115200 bits/s
                serial->setDataBits(QSerialPort::Data8); //Longueur des données : 8 bits,
                serial->setParity(QSerialPort::NoParity); //1 bit de parité optionnel
                serial->setStopBits(QSerialPort::OneStop); //Nombre de bits de stop : 1
                serial->setFlowControl(QSerialPort::NoFlowControl);
                return 0;
            }
            return 1;
        }
        return -1;
}

int Arduinorfid::close_arduinorfid()

{

    if(serial->isOpen()){
            serial->close();
            return 0;
        }
    return 1;


}


 QByteArray Arduinorfid::read_from_arduinorfid()
{
    if(serial->isReadable()){
         data=serial->readAll(); //récupérer les données reçues

         return data;
    }
 }


int Arduinorfid::write_to_arduinorfid( QByteArray d)

{

    if(serial->isWritable()){

        serial->write(d);  // envoyer des donnés vers Arduino
        qDebug() << d << "in write" ;
    }else{
        qDebug() << "Couldn't write to serial!";
    }
}
