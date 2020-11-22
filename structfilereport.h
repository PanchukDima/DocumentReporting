#ifndef STRUCTFILEREPORT_H
#define STRUCTFILEREPORT_H

#include <QObject>
#include <QCryptographicHash>
#include <QString>
#include <QByteArray>
#include <QFile>
#include <QFileDevice>

#define TYPE_CALC = 0;
#define TYPE_DOC = 1;


struct Report
{
    QString _name;
    int _type;
    QString _author;
    QByteArray _hash_body;
    QString _params;  //json params params:{name : value, name2 : value2}
    QByteArray _body;
};

class StructFileReport : public QObject
{
    Q_OBJECT
public:
    explicit StructFileReport(QObject *parent = nullptr);
private:
    Report _fileReport;

public slots:
    void SaveToFile(QString p_filename);
    void LoadFile(QString p_filename);

    QString getName(){return _fileReport._name;}
    void setName(QString p_name){_fileReport._name = p_name;}

    int getType(){return _fileReport._type;}
    void setType(int p_type){_fileReport._type = p_type;}

    QString getAuthor(){return _fileReport._author;}
    void setAuthor(QString p_author){_fileReport._author = p_author;}

    QString getParams(){return _fileReport._params;}
    void setParams(QString p_params){_fileReport._params = p_params;}

    QByteArray getBody(){return _fileReport._body;}
    void setBody(QByteArray p_body){_fileReport._body = p_body; _fileReport._hash_body = _getHashBody(_fileReport._body);}

private slots:
    QByteArray _SerializeReport();
    Report _DeserializeReport();
    QByteArray _getHashBody(QByteArray p_body);
signals:

};

#endif // STRUCTFILEREPORT_H
