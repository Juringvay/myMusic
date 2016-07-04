#ifndef GETSONGPLAYLISTID_H
#define GETSONGPLAYLISTID_H

#include <QObject>
#include <QString>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QEventLoop>

class GetSongPlayListId : public QObject
{
    Q_OBJECT
public:
    explicit GetSongPlayListId(QObject *parent = 0);

signals:

public slots:

public:
     QList<QString> getSongIdList(QString channelId);
};

#endif // GETSONGPLAYLISTID_H
