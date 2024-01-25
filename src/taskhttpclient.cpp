#include "taskhttpclient.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QEventLoop>

TaskHttpClient::TaskHttpClient() {
    // Constructor code, if any
}

QByteArray TaskHttpClient::makeGetRequest(const QUrl& url) {
    QNetworkAccessManager manager;
    QNetworkRequest request(url);
    QNetworkReply *reply = manager.get(request);

    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();  // Wait for the request to finish

    if (reply->error() == QNetworkReply::NoError) {
        return reply->readAll();
    } else {
        // Handle the error, for example:
        qWarning() << "Request failed:" << reply->errorString();
        return QByteArray();
    }
}
