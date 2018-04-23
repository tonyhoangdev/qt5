#ifndef BOOK_H
#define BOOK_H

#include <QString>

class Book
{
public:
    Book();
    Book(QString, QString);
    QString getAuthor() const;
    QString getTitle() const;

private:
    QString m_author;
    QString m_title;
};

#endif // BOOK_H
