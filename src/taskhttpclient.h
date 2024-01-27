#ifndef TASKHTTPCLIENT_H
#define TASKHTTPCLIENT_H

#include <QEventLoop>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

class TaskHttpClient
{
public:
    TaskHttpClient();
    QByteArray makeGetRequest(const QUrl &url);
};

#endif // TASKHTTPCLIENT_H
