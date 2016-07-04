#include "mainwidget.h"
#include "ui_mainwidget.h"

mainWidget::mainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainWidget)
{
    ui->setupUi(this);
    m_pPlayer = new QMediaPlayer(this);
    init();
}

mainWidget::~mainWidget()
{
    delete ui;
}

void mainWidget::init()
{
    GetSongPlayListId getPlayListId;
    m_songIdList = getPlayListId.getSongIdList("public_tuijian_rege");
    play(0);
}

void mainWidget::play(int index)
{
    if(index > m_songIdList.size())
        return;

    GetSongRealLink getSongLink;
    m_currentSongInfo = getSongLink.getSongRealLinkById(m_songIdList.at(index));

    m_pPlayer->setMedia(QUrl(m_currentSongInfo.songRealLink));
    m_pPlayer->play();

}
