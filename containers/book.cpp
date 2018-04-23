#include "book.h"

Book::Book()
{

}

Book::Book(QString author, QString title): m_author(author), m_title(title)
{

}

QString Book::getAuthor() const
{
    return m_author;
}

QString Book::getTitle() const
{
    return m_title;
}
