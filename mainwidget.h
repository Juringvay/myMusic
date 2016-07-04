#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QMediaPlayer>
//#include <QNetworkCookieJar>


#include "getsongplaylistid.h"
#include "getsongreallink.h"
namespace Ui {
class mainWidget;
}

class mainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit mainWidget(QWidget *parent = 0);
    ~mainWidget();

private:
    Ui::mainWidget *ui;
    QMediaPlayer *m_pPlayer;
    //QNetworkCookieJar *m_cookJar;
    void init();
    void play(int index);
    QList <QString> m_songIdList;
    SONG_INFO m_currentSongInfo;
};

#endif // MAINWIDGET_H
