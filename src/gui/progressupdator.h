#ifndef PROGRESSUPDATOR_H
#define PROGRESSUPDATOR_H

#include <QObject>

class ProgressUpdator : public QObject
{
    Q_OBJECT
public:
    explicit ProgressUpdator(QObject *parent = nullptr);

signals:
    void updateProgress(int progress);

public:
    inline void setProgress(int progress)
    {
        emit updateProgress(progress);
    }
};

#endif // PROGRESSUPDATOR_H
