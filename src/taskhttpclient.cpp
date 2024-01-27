#include "taskhttpclient.h"
#include <QEventLoop>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

TaskHttpClient::TaskHttpClient()
{
    // Constructor code, if any
}

QByteArray TaskHttpClient::makeGetRequest(const QUrl &url)
{
    QNetworkAccessManager manager;
    QNetworkRequest request(url);
    QNetworkReply *reply = manager.get(request);

    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec(); // Wait for the request to finish

    if (reply->error() == QNetworkReply::NoError) {
        return reply->readAll();
    } else {
        qWarning() << "Request failed:" << reply->errorString();
        return QByteArray();
    }
}
