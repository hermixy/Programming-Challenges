#include "threadquote.h"
#include <QDataStream>

ThreadQuote::ThreadQuote(int socket, const QString & quote, QObject *parent)
    : QThread(parent),
      quoteContent(quote),
      socketDescriptor(socket){

}

void ThreadQuote::run(){
    QTcpSocket tcpSocket;

    if(!tcpSocket.setSocketDescriptor(socketDescriptor)){
        emit error(tcpSocket.error());
        return;
    }

    QByteArray block;
    QDataStream data(&block, QIODevice::WriteOnly);

    data << quoteContent;

    tcpSocket.write(block);
    tcpSocket.disconnectFromHost();
    tcpSocket.waitForDisconnected();
}
