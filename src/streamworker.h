/* Copyright (C) 2017  Joseph R. Nosie

 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef STREAMWORKER_H
#define STREAMWORKER_H

#include <QObject>
#include <QPixmap>
#include <QtNetwork>

class StreamWorker : public QObject
{
    Q_OBJECT
public:
    StreamWorker();
    ~StreamWorker();

signals:
    void topImageReady(QPixmap img);
    void botImageReady(QPixmap img);
    void streamFailed();

public slots:
    void stream();

private:
    int readJPEG(QByteArray &jpeg);

    QUdpSocket *rcv_sock;
    QSettings s;
};

#endif // STREAMWORKER_H