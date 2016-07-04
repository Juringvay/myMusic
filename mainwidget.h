#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QMediaPlayer>
//#include <QNetworkCookieJar>
#include <QButtonGroup>
#include <QGridLayout>
#include "getsongplaylistid.h"
#include "getsongreallink.h"

typedef struct _CHANNEL_INFO
{
    QString channelId;
    QString channelName;
}CHANNEL_INFO;

namespace Ui {
class mainWidget;
}

class mainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit mainWidget(QWidget *parent = 0);
    ~mainWidget();
    QList<CHANNEL_INFO> getMusicChannel();

private slots:
    void on_pushButton_clicked();

private:
    Ui::mainWidget *ui;
    QMediaPlayer *m_pPlayer;
    //QNetworkCookieJar *m_cookJar;
    void init();
    void play(int index);
    QList <QString> m_songIdList;
    SONG_INFO m_currentSongInfo;
    QList <CHANNEL_INFO> m_channelList;
    QButtonGroup m_btnGroup;
    QGridLayout *m_gridlayOut;
};

#endif // MAINWIDGET_H
