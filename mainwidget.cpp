#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QPushButton>
const QString channelUrl = "http://fm.baidu.com/dev/api/?tn=channellist";
int flag = 0;
mainWidget::mainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainWidget)
{
    ui->setupUi(this);
    m_pPlayer = new QMediaPlayer(this);
    init();
    /*m_gridlayOut = new QGridLayout;
    m_channelList = getMusicChannel();

    for(int i = 0, k = 0; i < m_channelList.size() / 4; i++, k += 4)
    {
        for(int j = 0; j < 4; j++)
        {
            QPushButton *btn = new QPushButton(this);

            btn->setText(m_channelList.at(k + j).channelName);
            //qDebug() << m_channelList.at(k + j).channelName;
            m_gridlayOut->addWidget(btn, i, j);
            //qDebug() << k + j;
            m_btnGroup.addButton(btn, k + j);
        }
    }

    setLayout(m_gridlayOut);*/

}

mainWidget::~mainWidget()
{
    delete ui;
}

QList<CHANNEL_INFO> mainWidget::getMusicChannel()
{
    QList<CHANNEL_INFO> channelInfoList;

    QNetworkRequest networkRequest;
    QNetworkAccessManager *networkManager = new QNetworkAccessManager;

    networkRequest.setUrl(QUrl(channelUrl));

    //networkManager->setCookieJar(m_cookJar);
    QNetworkReply *reply = networkManager->get(networkRequest);

    QEventLoop loop;
    connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
    reply->deleteLater();

    QByteArray buf = reply->readAll();


    QJsonParseError jsonError;
    QJsonDocument jsonRes = QJsonDocument::fromJson(buf, &jsonError);;

    if(jsonError.error == QJsonParseError::NoError)
    {
        if(jsonRes.isObject())
        {
            QVariantMap result = jsonRes.toVariant().toMap();

            foreach(QVariant channel, result["channel_list"].toList())
            {
                QVariantMap channelMap = channel.toMap();


                CHANNEL_INFO channelInfo;
                channelInfo.channelId = channelMap["channel_id"].toString();
                channelInfo.channelName = channelMap["channel_name"].toString();
                //qDebug() << channelInfo.channelName;

                channelInfoList.append(channelInfo);

            }
        }
    }

    return channelInfoList;
}

void mainWidget::init()
{
    GetSongPlayListId getPlayListId;
    m_songIdList = getPlayListId.getSongIdList("public_tuijian_rege");

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

void mainWidget::on_pushButton_clicked()
{
    if(ui->pushButton->text()=="播放")
    {
        if(flag == 0)
            play(0);
        else
            m_pPlayer->play();
        ui->pushButton->setText("停止");
        flag =1;
    }
    else{
         m_pPlayer->pause();
         ui->pushButton->setText("播放");
    }

}
