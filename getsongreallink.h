#ifndef GETSONGREALLINK_H
#define GETSONGREALLINK_H

#include <QObject>
#include <QString>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QEventLoop>
typedef struct _SONG_INFO
{
    QString songRealLink;
    QString songName;
    QString artistName;
    QString songPicSmall;
    QString songPicRadio;
    QString time;
    QString albumName;
    QString lrcLink;
    QString size;
}SONG_INFO;
class GetSongRealLink : public QObject
{
    Q_OBJECT
public:
    explicit GetSongRealLink(QObject *parent = 0);

public slots:

    SONG_INFO getSongRealLinkById(QString songId);

signals:

public slots:
};

#endif // GETSONGREALLINK_H
