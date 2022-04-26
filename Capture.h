#ifndef CAPTURE_H
#define CAPTURE_H

#include <QObject>

class Capture : public QObject
{
    Q_OBJECT
public:
    explicit Capture(QObject *parent = nullptr);

signals:
    void hasCaptured(int x, int y);

};

#endif // CAPTURE_H
