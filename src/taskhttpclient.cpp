#include "taskhttpclient.h"
#include <QEventLoop>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

TaskHttpClient::TaskHttpClient()
{
    // Constructor code, if any
}

QByteArray TaskHttpClient::GetAllTasks() {
    //QString GET_ALL_TASKS_URL = BASIC_URL + "/task";
    return MakeGetRequest(BASIC_URL);
}

QByteArray TaskHttpClient::MakeGetRequest(const QUrl &url)
{
    QNetworkAccessManager manager;
    QNetworkRequest request(url);
    QNetworkReply *reply = manager.get(request);

    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    if (reply->error() == QNetworkReply::NoError) {
        return reply->readAll();
    } else {
        qWarning() << "Request failed:" << reply->errorString();
        return QByteArray();
    }
}
