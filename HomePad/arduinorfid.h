#ifndef ARDUINORFID_H
#define ARDUINORFID_H
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>


class Arduinorfid
{
public:     //méthodes de la classe Arduino
    Arduinorfid();
    int connect_arduinorfid(); // permet de connecter le PC à Arduino
    int close_arduinorfid(); // permet de femer la connexion
    int write_to_arduinorfid( QByteArray ); // envoyer des données vers arduino
    QByteArray read_from_arduinorfid();  //recevoir des données de la carte Arduino
    QSerialPort* getserial();   // accesseur
    QString getarduinorfid_port_name();
private:
QSerialPort * serial; //Cet objet rassemble des informations (vitesse, bits de données, etc.)
//et des fonctions (envoi, lecture de réception,…) sur ce qu’est une voie série pour Arduino.
static const quint16 arduino_uno_vendor_id=9025 ;
static const quint16 arduino_uno_producy_id=67;
QString arduino_port_name;
bool arduino_is_available;
QByteArray data;  // contenant les données lues à partir d'Arduino
};



#endif // ARDUINORFID_H
